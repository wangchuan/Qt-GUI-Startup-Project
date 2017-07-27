#include "Viewer.h"
#include "keypoint.h"
#include <fstream>
#include <QFileInfo>
#include <QDir>
#include <iostream>

using namespace std;

void fileparts(const QString& filename, QString& path, QString& name, QString& ext)
{
	QFileInfo fi(filename);
	path = fi.absolutePath();
	name = fi.baseName();
	ext = fi.suffix();
}

string find_pts_filename(const QString& filename)
{
	QString path, name, ext;
	fileparts(filename, path, name, ext);
	QString coord_filename = path + "/" + name + ".pts";
	string fs = coord_filename.toLatin1().constData();
	return fs;
}

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

void Viewer::save_bones()
{
	if (img_idx == -1)
		return;
	QString filename = filelist[img_idx];
	string filename_pts = find_pts_filename(filename);
	QList<QGraphicsItem*> list =  sc->items();
	ofstream ofile(filename_pts);
	ofile << "version: 1" << endl;
	vector<KeyPoint*> keypts;
	for (int i = 0; i < list.size(); i++)
	{
		KeyPoint* p = dynamic_cast<KeyPoint*>(list[i]);
		if (!p)
			continue;
		keypts.push_back(p);
	}
	ofile << "n_points:  " << keypts.size() << endl;
	ofile << "{" << endl;
	sort(keypts.begin(), keypts.end(), 
		[](const KeyPoint* a, const KeyPoint* b)	{ return a->id() < b->id(); });
	for (int i = 0; i < keypts.size(); i++)
	{
		KeyPoint* p = keypts[i];
		double x = p->pos().x() + p->width() / 2;
		double y = p->pos().y() + p->height() / 2;
		ofile << x << " " << y << endl;
	}
	ofile << "}";
	ofile.close();
}

void Viewer::render(const QString& filename)
{
	bool loaded = pxlmap.load(filename);
	if (!loaded)
		return;
	//resetMatrix();
	//scale_val = 1.0;
	sc->clear();
	sc->addPixmap(pxlmap);
	string pts_filename = find_pts_filename(filename);
	QFileInfo fi(QString(pts_filename.c_str()));
	if (fi.isFile())
		load_pts_file(pts_filename);
	else
		load_template(pxlmap.height(), pxlmap.width());
	sc->setSceneRect(pxlmap.rect());
}

void Viewer::mousePressEvent(QMouseEvent *event)
{
	if (event->button() == Qt::LeftButton && key_modifiers == (Qt::ControlModifier | Qt::AltModifier))
		this->setDragMode(QGraphicsView::ScrollHandDrag);
	if (event->button() == Qt::LeftButton && key_modifiers == Qt::ControlModifier)
		this->setDragMode(QGraphicsView::RubberBandDrag);
	QGraphicsView::mousePressEvent(event);
}

void Viewer::mouseReleaseEvent(QMouseEvent *event)
{
	QGraphicsView::mouseReleaseEvent(event);
	setDragMode(QGraphicsView::NoDrag);
}

void Viewer::load_template(int h, int w)
{
	vector<vector<double>> coords = 
	{
		{ 0.514, 0.768 }, { 0.647, 0.689 }, { 0.768, 0.561 }, { 0.857, 0.463 }, { 0.927, 0.398 },
		{ 0.586, 0.662 }, { 0.583, 0.420 }, { 0.578, 0.250 }, { 0.578, 0.150 }, { 0.571, 0.092 },
		{ 0.514, 0.652 }, { 0.472, 0.429 }, { 0.416, 0.242 }, { 0.379, 0.132 }, { 0.352, 0.056 },
		{ 0.462, 0.654 }, { 0.385, 0.478 }, { 0.291, 0.317 }, { 0.240, 0.221 }, { 0.200, 0.153 },
		{ 0.422, 0.680 }, { 0.307, 0.535 }, { 0.189, 0.446 }, { 0.122, 0.401 },	{ 0.072, 0.355 }
	};
	for (int i = 0; i < 25; i++)
	{
		QColor color(qrand() % 256, qrand() % 256, qrand() % 256, 64);
		QGraphicsItem* item = new KeyPoint(color, i);
		item->setPos(QPointF(coords[i][0] * (double)w, coords[i][1] * (double)h));
		sc->addItem(item);
	}
}

void Viewer::load_pts_file(const std::string& filename)
{
	ifstream ifile(filename);
	if (!ifile)
		return;
	string line;
	getline(ifile, line); // Version
	getline(ifile, line); // n_points
	int found = line.find(':');
	int n = stoi(line.substr(found + 1));
	getline(ifile, line); // {
	for (int i = 0; i < n; i++)
	{
		getline(ifile, line);
		found = line.find(' ');
		float x = stof(line.substr(0, found));
		float y = stof(line.substr(found + 1));
		QColor color(qrand() % 256, qrand() % 256, qrand() % 256, 127);
		KeyPoint* item = new KeyPoint(color, i);
		item->setPos(QPointF(x - item->width() / 2, y - item->height() / 2));
		sc->addItem(item);
	}
	ifile.close();
}

void Viewer::keyPressEvent(QKeyEvent *event)
{
	key = event->key();
	key_modifiers = event->modifiers();
	if ((key == Qt::Key_D || key == Qt::Key_Right) && img_idx < filelist.count() - 1)
		show_image_at(++img_idx);
	if ((key == Qt::Key_A || key == Qt::Key_Left) && img_idx > 0)
		show_image_at(--img_idx);
	if (key == Qt::Key_S && key_modifiers == Qt::ControlModifier)
		save_bones();
}

void Viewer::keyReleaseEvent(QKeyEvent *event)
{
	key = -1;
	key_modifiers = -1;
}
