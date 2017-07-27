#include "Viewer.h"
#include "keypoint.h"

#include <iostream>

using namespace std;

Viewer::Viewer(QWidget* parent) : QGraphicsView(parent)
{
	sc = new QGraphicsScene(this);
	render();
	this->setScene(sc);
}

Viewer::~Viewer()
{
	if (sc) 
	{
		delete sc; 
		sc = NULL; 
	}
}

void Viewer::wheelEvent(QWheelEvent *event)
{
	if (key_modifiers == (Qt::ControlModifier | Qt::AltModifier))
	{
		if (filelist.empty())
			return;
		const int degrees = event->delta() / 8;
		int steps = degrees / 15;
		if (steps == 0)
			return;
		double m1 = 1.3, m2 = 1.0 / m1;
		double cur_scale = scale_val;
		scale_val = steps > 0 ? min(max_scale, scale_val * m1) : max(min_scale, scale_val * m2);
		m1 = scale_val / cur_scale;
		this->scale(m1, m1);
	}
}

void Viewer::mouseMoveEvent(QMouseEvent *event)
{
	QGraphicsView::mouseMoveEvent(event);
	QPointF pt = mapToScene(event->pos());
	if (pt.x() < 0 || pt.y() < 0 || pt.x() >= pxlmap.width() || pt.y() >= pxlmap.height())
		return;
	emit send_coord(pt.x(), pt.y());
	this->update();
}

void Viewer::show_image_at(int idx)
{
	if (idx >= filelist.count())
		return;
	QString filename = filelist.at(idx);
	img_idx = idx;
	render(filename);
	emit send_filename(filename);
	this->update();
}

void Viewer::render(const QString& s)
{
	bool loaded = pxlmap.load(s);
	if (!loaded)
		return;
	resetMatrix();
	scale_val = 1.0;
	sc->clear();
	sc->addPixmap(pxlmap);
	load_template(pxlmap.height(), pxlmap.width());
	sc->setSceneRect(pxlmap.rect());
}

void Viewer::mousePressEvent(QMouseEvent *event)
{
	if (event->button() == Qt::LeftButton && key_modifiers == (Qt::ControlModifier | Qt::AltModifier))
		this->setDragMode(QGraphicsView::ScrollHandDrag);
	QGraphicsView::mousePressEvent(event);
}

void Viewer::mouseReleaseEvent(QMouseEvent *event)
{
	QGraphicsView::mouseReleaseEvent(event);
	if (event->button() == Qt::LeftButton && key_modifiers == (Qt::ControlModifier | Qt::AltModifier))
		this->setDragMode(QGraphicsView::NoDrag);
}

void Viewer::load_template(int h, int w)
{
	int id = 0;
	for (int i = 0; i < 1000; i += 100)
	{
		for (int j = 0; j < 1000; j += 100)
		{
			QColor color(qrand() % 256, qrand() % 256, qrand() % 256, 64);
			QGraphicsItem* item = new KeyPoint(color, id++);
			item->setPos(QPointF(i, j));
			sc->addItem(item);
		}
	}
}

void Viewer::keyPressEvent(QKeyEvent *event)
{
	key = event->key();
	key_modifiers = event->modifiers();
	if ((key == Qt::Key_D || key == Qt::Key_Right) && img_idx < filelist.count() - 1)
		show_image_at(++img_idx);
	if ((key == Qt::Key_A || key == Qt::Key_Left) && img_idx > 0)
		show_image_at(--img_idx);
}

void Viewer::keyReleaseEvent(QKeyEvent *event)
{
	key = -1;
	key_modifiers = -1;
}
