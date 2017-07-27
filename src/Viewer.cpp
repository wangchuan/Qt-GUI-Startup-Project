#include "Viewer.h"
#include <iostream>

using namespace std;

Viewer::Viewer(QWidget* parent) : QGraphicsView(parent)
{
	sc = new QGraphicsScene(this);
	render();
}

Viewer::~Viewer()
{
	if (sc) { delete sc; sc = NULL; }
}

void Viewer::wheelEvent(QWheelEvent *event)
{
	if (filelist.empty())
		return;
	const int degrees = event->delta() / 8;
	int steps = degrees / 15;
// 	double prev_scale = scale_val;
// 	scale_val = steps > 0 ? scale_val * 1.1 : scale_val / 1.1;
// 	scale_val = max(min(max_scale, scale_val), min_scale);
// 	this->scale(scale_val / prev_scale, scale_val / prev_scale);
	QMatrix q = this->matrix();
	cout << q.m11() << " ";
	cout << q.m12() << " ";
	cout << q.m21() << " ";
	cout << q.m22() << " ";
	cout << scale_val << endl;
}

void Viewer::mouseMoveEvent(QMouseEvent *event)
{
	int x = event->x();
	int y = event->y();
	emit send_coord(x, y);
	this->update();
}

void Viewer::show_image_at(int idx)
{
	if (idx >= filelist.count())
		return;
	QString filename = filelist.at(idx);
	render(filename);
// 	for (int i = 0; i < filelist.count(); i++)
// 	{
// 		QString s = filelist.at(i);
// 		QByteArray QFilename = s.toLatin1();
// 		string filename(QFilename.constData(), QFilename.length());
// 		cout << filename << endl;
// 	}
}

void Viewer::render(const QString& s)
{
	bool loaded = pxlmap.load(s);
	if (loaded)
	{
		cout << "h, w: " << pxlmap.height() << " " << pxlmap.width() << endl;
		this->scale(1.0 / scale_val, 1.0 / scale_val);
	}
	sc->addPixmap(pxlmap);
	sc->setSceneRect(pxlmap.rect());
	this->setScene(sc);
}
