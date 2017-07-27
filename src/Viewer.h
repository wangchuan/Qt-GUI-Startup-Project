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

public slots:
	void wheelEvent(QWheelEvent *event);
	void mouseMoveEvent(QMouseEvent *event);
	void mousePressEvent(QMouseEvent *event);
	void mouseReleaseEvent(QMouseEvent *event);
	void keyPressEvent(QKeyEvent *event);
	void keyReleaseEvent(QKeyEvent *event);

public:
	inline void set_filelist(const QStringList& qsl) { filelist = qsl; }
	void show_image_at(int idx);
	void save_bones();

Q_SIGNALS:
	void send_coord(int, int);
	void send_filename(const QString&);

private:
	void render(const QString& s = QString());
	void load_template(int h, int w);
	void load_pts_file(const std::string& filename);


private:
	QGraphicsScene* sc;
	QPixmap pxlmap;
	QStringList filelist;
	int img_idx = -1;

	int x, y;
	double scale_val = 1.0;
	double max_scale = 10.0;
	double min_scale = 0.3;

	int m_orig_x, m_orig_y;

	int key = -1, key_modifiers = -1;
};

#endif