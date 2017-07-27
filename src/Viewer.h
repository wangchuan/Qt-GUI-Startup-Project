#ifndef _VIEWER_H_
#define _VIEWER_H_

#include <QGraphicsView>
#include <QWidget>
#include <QWheelEvent>

class Viewer : public QGraphicsView
{
	Q_OBJECT

public:
	Viewer(QWidget* parent);
	~Viewer();

	void wheelEvent(QWheelEvent *event);
	void mouseMoveEvent(QMouseEvent *event);

	inline void set_filelist(const QStringList& qsl) { filelist = qsl; }
	void show_image_at(int idx);

Q_SIGNALS:
	void send_coord(int, int);

private:
	void render(const QString& s = QString());

private:
	QGraphicsScene* sc;
	QPixmap pxlmap;
	QStringList filelist;

	int x, y;
	double scale_val = 1.0;
	const double max_scale = 5.0;
	const double min_scale = 0.5;
};

#endif