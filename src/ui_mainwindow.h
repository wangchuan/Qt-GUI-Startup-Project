/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QWidget>

#include "Viewer.h"

QT_BEGIN_NAMESPACE

class Ui_ARViewer
{
public:
    QAction *action_open;
    QAction *action_exit;
    QWidget *wgt_central;
    QGridLayout *gridLayout_3;
    QGridLayout *grid_layout_exit;
    QPushButton *pb_restart;
    QPushButton *pb_quit;
    QTabWidget *tbwgt_display_settings;
    QWidget *wgt_display;
    QGridLayout *gridLayout_2;
    QCheckBox *chbox_not_in_use_3;
    QCheckBox *chbox_grid;
    QCheckBox *chbox_fps;
    QCheckBox *chbox_not_in_use_1;
    QPushButton *pb_stop;
    QCheckBox *chbox_not_in_use_2;
    QCheckBox *chbox_axis;
    QCheckBox *chbox_not_in_use_4;
    QCheckBox *chbox_wire_mode;
    QPushButton *pb_reset;
    QPushButton *pb_bgd_color;
    QPushButton *pb_wire_color;
    QGridLayout *grid_layout_screenshot;
    QLabel *lb_screenshot_ratio;
    QDoubleSpinBox *dspinbox_screenshot_ratio;
    QPushButton *pb_screenshot;
    QSpacerItem *vspacer_in_tab_display;
    QPushButton *pb_checkable_button;
    QPushButton *pb_not_in_use_1;
    QWidget *wgt_other;
    QGridLayout *gridLayout;
    QPushButton *pb_capture_photo;
    QSpacerItem *vspacer_in_tab_other;
    QLabel *lb_expo_compensation;
    QSlider *slider_expo_compensation;
    QLabel *lb_file;
    QLineEdit *line_edit_video_path;
    QGridLayout *grid_layout_load;
    QPushButton *pb_load_video;
    QPushButton *pb_run_camera;
    QTextBrowser *text_brower_show_text;
    Viewer *gfx_view_canvas;
    QMenuBar *menu_bar;
    QMenu *menu_file;
    QStatusBar *status_bar;

    void setupUi(QMainWindow *ARViewer)
    {
        if (ARViewer->objectName().isEmpty())
            ARViewer->setObjectName(QStringLiteral("ARViewer"));
        ARViewer->resize(857, 660);
        QFont font;
        font.setFamily(QStringLiteral("Microsoft YaHei UI"));
        font.setPointSize(8);
        ARViewer->setFont(font);
        action_open = new QAction(ARViewer);
        action_open->setObjectName(QStringLiteral("action_open"));
        action_exit = new QAction(ARViewer);
        action_exit->setObjectName(QStringLiteral("action_exit"));
        wgt_central = new QWidget(ARViewer);
        wgt_central->setObjectName(QStringLiteral("wgt_central"));
        gridLayout_3 = new QGridLayout(wgt_central);
        gridLayout_3->setObjectName(QStringLiteral("gridLayout_3"));
        gridLayout_3->setHorizontalSpacing(1);
        gridLayout_3->setVerticalSpacing(2);
        gridLayout_3->setContentsMargins(-1, -1, -1, 9);
        grid_layout_exit = new QGridLayout();
        grid_layout_exit->setObjectName(QStringLiteral("grid_layout_exit"));
        grid_layout_exit->setSizeConstraint(QLayout::SetDefaultConstraint);
        pb_restart = new QPushButton(wgt_central);
        pb_restart->setObjectName(QStringLiteral("pb_restart"));
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(pb_restart->sizePolicy().hasHeightForWidth());
        pb_restart->setSizePolicy(sizePolicy);
        pb_restart->setMinimumSize(QSize(0, 40));

        grid_layout_exit->addWidget(pb_restart, 0, 0, 1, 1);

        pb_quit = new QPushButton(wgt_central);
        pb_quit->setObjectName(QStringLiteral("pb_quit"));
        sizePolicy.setHeightForWidth(pb_quit->sizePolicy().hasHeightForWidth());
        pb_quit->setSizePolicy(sizePolicy);
        pb_quit->setMinimumSize(QSize(0, 40));

        grid_layout_exit->addWidget(pb_quit, 0, 1, 1, 1);


        gridLayout_3->addLayout(grid_layout_exit, 5, 3, 1, 1);

        tbwgt_display_settings = new QTabWidget(wgt_central);
        tbwgt_display_settings->setObjectName(QStringLiteral("tbwgt_display_settings"));
        QSizePolicy sizePolicy1(QSizePolicy::Fixed, QSizePolicy::Expanding);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(tbwgt_display_settings->sizePolicy().hasHeightForWidth());
        tbwgt_display_settings->setSizePolicy(sizePolicy1);
        tbwgt_display_settings->setMinimumSize(QSize(0, 0));
        tbwgt_display_settings->setMaximumSize(QSize(16777215, 16777215));
        QFont font1;
        font1.setFamily(QStringLiteral("Microsoft YaHei UI"));
        font1.setPointSize(8);
        font1.setKerning(true);
        font1.setStyleStrategy(QFont::PreferDefault);
        tbwgt_display_settings->setFont(font1);
        tbwgt_display_settings->setToolTipDuration(-1);
        tbwgt_display_settings->setLayoutDirection(Qt::LeftToRight);
        tbwgt_display_settings->setTabPosition(QTabWidget::North);
        tbwgt_display_settings->setTabShape(QTabWidget::Rounded);
        wgt_display = new QWidget();
        wgt_display->setObjectName(QStringLiteral("wgt_display"));
        gridLayout_2 = new QGridLayout(wgt_display);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        chbox_not_in_use_3 = new QCheckBox(wgt_display);
        chbox_not_in_use_3->setObjectName(QStringLiteral("chbox_not_in_use_3"));

        gridLayout_2->addWidget(chbox_not_in_use_3, 10, 0, 1, 1);

        chbox_grid = new QCheckBox(wgt_display);
        chbox_grid->setObjectName(QStringLiteral("chbox_grid"));

        gridLayout_2->addWidget(chbox_grid, 8, 0, 1, 1);

        chbox_fps = new QCheckBox(wgt_display);
        chbox_fps->setObjectName(QStringLiteral("chbox_fps"));

        gridLayout_2->addWidget(chbox_fps, 7, 0, 1, 1);

        chbox_not_in_use_1 = new QCheckBox(wgt_display);
        chbox_not_in_use_1->setObjectName(QStringLiteral("chbox_not_in_use_1"));

        gridLayout_2->addWidget(chbox_not_in_use_1, 9, 0, 1, 1);

        pb_stop = new QPushButton(wgt_display);
        pb_stop->setObjectName(QStringLiteral("pb_stop"));

        gridLayout_2->addWidget(pb_stop, 4, 0, 1, 1);

        chbox_not_in_use_2 = new QCheckBox(wgt_display);
        chbox_not_in_use_2->setObjectName(QStringLiteral("chbox_not_in_use_2"));

        gridLayout_2->addWidget(chbox_not_in_use_2, 9, 1, 1, 1);

        chbox_axis = new QCheckBox(wgt_display);
        chbox_axis->setObjectName(QStringLiteral("chbox_axis"));

        gridLayout_2->addWidget(chbox_axis, 7, 1, 1, 1);

        chbox_not_in_use_4 = new QCheckBox(wgt_display);
        chbox_not_in_use_4->setObjectName(QStringLiteral("chbox_not_in_use_4"));

        gridLayout_2->addWidget(chbox_not_in_use_4, 10, 1, 1, 1);

        chbox_wire_mode = new QCheckBox(wgt_display);
        chbox_wire_mode->setObjectName(QStringLiteral("chbox_wire_mode"));

        gridLayout_2->addWidget(chbox_wire_mode, 8, 1, 1, 1);

        pb_reset = new QPushButton(wgt_display);
        pb_reset->setObjectName(QStringLiteral("pb_reset"));
        pb_reset->setEnabled(true);
        QSizePolicy sizePolicy2(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(pb_reset->sizePolicy().hasHeightForWidth());
        pb_reset->setSizePolicy(sizePolicy2);
        pb_reset->setBaseSize(QSize(0, 0));
        pb_reset->setLayoutDirection(Qt::LeftToRight);
        pb_reset->setAutoFillBackground(false);
        pb_reset->setFlat(false);

        gridLayout_2->addWidget(pb_reset, 3, 0, 1, 1);

        pb_bgd_color = new QPushButton(wgt_display);
        pb_bgd_color->setObjectName(QStringLiteral("pb_bgd_color"));
        sizePolicy.setHeightForWidth(pb_bgd_color->sizePolicy().hasHeightForWidth());
        pb_bgd_color->setSizePolicy(sizePolicy);

        gridLayout_2->addWidget(pb_bgd_color, 3, 1, 1, 1);

        pb_wire_color = new QPushButton(wgt_display);
        pb_wire_color->setObjectName(QStringLiteral("pb_wire_color"));

        gridLayout_2->addWidget(pb_wire_color, 4, 1, 1, 1);

        grid_layout_screenshot = new QGridLayout();
        grid_layout_screenshot->setObjectName(QStringLiteral("grid_layout_screenshot"));
        lb_screenshot_ratio = new QLabel(wgt_display);
        lb_screenshot_ratio->setObjectName(QStringLiteral("lb_screenshot_ratio"));

        grid_layout_screenshot->addWidget(lb_screenshot_ratio, 0, 1, 1, 1);

        dspinbox_screenshot_ratio = new QDoubleSpinBox(wgt_display);
        dspinbox_screenshot_ratio->setObjectName(QStringLiteral("dspinbox_screenshot_ratio"));
        dspinbox_screenshot_ratio->setDecimals(1);
        dspinbox_screenshot_ratio->setMinimum(0.1);
        dspinbox_screenshot_ratio->setMaximum(10);
        dspinbox_screenshot_ratio->setSingleStep(0.1);

        grid_layout_screenshot->addWidget(dspinbox_screenshot_ratio, 0, 2, 1, 1);

        pb_screenshot = new QPushButton(wgt_display);
        pb_screenshot->setObjectName(QStringLiteral("pb_screenshot"));
        QSizePolicy sizePolicy3(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(pb_screenshot->sizePolicy().hasHeightForWidth());
        pb_screenshot->setSizePolicy(sizePolicy3);

        grid_layout_screenshot->addWidget(pb_screenshot, 0, 0, 1, 1);


        gridLayout_2->addLayout(grid_layout_screenshot, 2, 0, 1, 2);

        vspacer_in_tab_display = new QSpacerItem(20, 50, QSizePolicy::Minimum, QSizePolicy::MinimumExpanding);

        gridLayout_2->addItem(vspacer_in_tab_display, 6, 0, 1, 2);

        pb_checkable_button = new QPushButton(wgt_display);
        pb_checkable_button->setObjectName(QStringLiteral("pb_checkable_button"));
        pb_checkable_button->setCheckable(true);

        gridLayout_2->addWidget(pb_checkable_button, 5, 0, 1, 1);

        pb_not_in_use_1 = new QPushButton(wgt_display);
        pb_not_in_use_1->setObjectName(QStringLiteral("pb_not_in_use_1"));

        gridLayout_2->addWidget(pb_not_in_use_1, 5, 1, 1, 1);

        tbwgt_display_settings->addTab(wgt_display, QString());
        wgt_other = new QWidget();
        wgt_other->setObjectName(QStringLiteral("wgt_other"));
        gridLayout = new QGridLayout(wgt_other);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        pb_capture_photo = new QPushButton(wgt_other);
        pb_capture_photo->setObjectName(QStringLiteral("pb_capture_photo"));
        pb_capture_photo->setEnabled(false);

        gridLayout->addWidget(pb_capture_photo, 0, 0, 1, 1);

        vspacer_in_tab_other = new QSpacerItem(20, 161, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(vspacer_in_tab_other, 1, 0, 1, 1);

        lb_expo_compensation = new QLabel(wgt_other);
        lb_expo_compensation->setObjectName(QStringLiteral("lb_expo_compensation"));

        gridLayout->addWidget(lb_expo_compensation, 2, 0, 1, 1);

        slider_expo_compensation = new QSlider(wgt_other);
        slider_expo_compensation->setObjectName(QStringLiteral("slider_expo_compensation"));
        slider_expo_compensation->setMinimum(-4);
        slider_expo_compensation->setMaximum(4);
        slider_expo_compensation->setPageStep(2);
        slider_expo_compensation->setOrientation(Qt::Horizontal);
        slider_expo_compensation->setTickPosition(QSlider::TicksAbove);

        gridLayout->addWidget(slider_expo_compensation, 3, 0, 1, 1);

        tbwgt_display_settings->addTab(wgt_other, QString());

        gridLayout_3->addWidget(tbwgt_display_settings, 3, 3, 1, 1);

        lb_file = new QLabel(wgt_central);
        lb_file->setObjectName(QStringLiteral("lb_file"));
        lb_file->setEnabled(true);
        QSizePolicy sizePolicy4(QSizePolicy::Fixed, QSizePolicy::Preferred);
        sizePolicy4.setHorizontalStretch(0);
        sizePolicy4.setVerticalStretch(0);
        sizePolicy4.setHeightForWidth(lb_file->sizePolicy().hasHeightForWidth());
        lb_file->setSizePolicy(sizePolicy4);

        gridLayout_3->addWidget(lb_file, 0, 0, 1, 1);

        line_edit_video_path = new QLineEdit(wgt_central);
        line_edit_video_path->setObjectName(QStringLiteral("line_edit_video_path"));
        QFont font2;
        font2.setFamily(QStringLiteral("Segoe UI"));
        font2.setItalic(true);
        line_edit_video_path->setFont(font2);

        gridLayout_3->addWidget(line_edit_video_path, 0, 1, 1, 2);

        grid_layout_load = new QGridLayout();
        grid_layout_load->setObjectName(QStringLiteral("grid_layout_load"));
        pb_load_video = new QPushButton(wgt_central);
        pb_load_video->setObjectName(QStringLiteral("pb_load_video"));

        grid_layout_load->addWidget(pb_load_video, 1, 0, 1, 1);

        pb_run_camera = new QPushButton(wgt_central);
        pb_run_camera->setObjectName(QStringLiteral("pb_run_camera"));

        grid_layout_load->addWidget(pb_run_camera, 1, 1, 1, 1);


        gridLayout_3->addLayout(grid_layout_load, 0, 3, 1, 1);

        text_brower_show_text = new QTextBrowser(wgt_central);
        text_brower_show_text->setObjectName(QStringLiteral("text_brower_show_text"));
        QSizePolicy sizePolicy5(QSizePolicy::Ignored, QSizePolicy::Fixed);
        sizePolicy5.setHorizontalStretch(0);
        sizePolicy5.setVerticalStretch(0);
        sizePolicy5.setHeightForWidth(text_brower_show_text->sizePolicy().hasHeightForWidth());
        text_brower_show_text->setSizePolicy(sizePolicy5);

        gridLayout_3->addWidget(text_brower_show_text, 4, 3, 1, 1);

        gfx_view_canvas = new Viewer(wgt_central);
        gfx_view_canvas->setObjectName(QStringLiteral("gfx_view_canvas"));
        gfx_view_canvas->viewport()->setProperty("cursor", QVariant(QCursor(Qt::CrossCursor)));
        QBrush brush(QColor(64, 128, 128, 255));
        brush.setStyle(Qt::SolidPattern);
        gfx_view_canvas->setBackgroundBrush(brush);
        QBrush brush1(QColor(255, 170, 255, 255));
        brush1.setStyle(Qt::NoBrush);
        gfx_view_canvas->setForegroundBrush(brush1);
        gfx_view_canvas->setTransformationAnchor(QGraphicsView::AnchorUnderMouse);
        gfx_view_canvas->setResizeAnchor(QGraphicsView::AnchorUnderMouse);
		gfx_view_canvas->setRenderHint(QPainter::Antialiasing);
		gfx_view_canvas->setCacheMode(QGraphicsView::CacheBackground);

        gridLayout_3->addWidget(gfx_view_canvas, 3, 0, 3, 3);

        ARViewer->setCentralWidget(wgt_central);
        menu_bar = new QMenuBar(ARViewer);
        menu_bar->setObjectName(QStringLiteral("menu_bar"));
        menu_bar->setGeometry(QRect(0, 0, 857, 21));
        menu_file = new QMenu(menu_bar);
        menu_file->setObjectName(QStringLiteral("menu_file"));
        ARViewer->setMenuBar(menu_bar);
        status_bar = new QStatusBar(ARViewer);
        status_bar->setObjectName(QStringLiteral("status_bar"));
        status_bar->setSizeGripEnabled(true);
        ARViewer->setStatusBar(status_bar);

        menu_bar->addAction(menu_file->menuAction());
        menu_file->addAction(action_open);
        menu_file->addAction(action_exit);

        retranslateUi(ARViewer);

        tbwgt_display_settings->setCurrentIndex(0);

		connectSignals(ARViewer);
        QMetaObject::connectSlotsByName(ARViewer);
    } // setupUi

    void retranslateUi(QMainWindow *ARViewer)
    {
        ARViewer->setWindowTitle(QApplication::translate("ARViewer", "Camera", 0));
        action_open->setText(QApplication::translate("ARViewer", "Open", 0));
        action_exit->setText(QApplication::translate("ARViewer", "Exit", 0));
        pb_restart->setText(QApplication::translate("ARViewer", "Restart", 0));
        pb_quit->setText(QApplication::translate("ARViewer", "Quit", 0));
        chbox_not_in_use_3->setText(QApplication::translate("ARViewer", "CheckBox", 0));
        chbox_grid->setText(QApplication::translate("ARViewer", "Grid", 0));
        chbox_fps->setText(QApplication::translate("ARViewer", "FPS", 0));
        chbox_not_in_use_1->setText(QApplication::translate("ARViewer", "CheckBox", 0));
        pb_stop->setText(QApplication::translate("ARViewer", "Stop", 0));
        chbox_not_in_use_2->setText(QApplication::translate("ARViewer", "CheckBox", 0));
        chbox_axis->setText(QApplication::translate("ARViewer", "Axis", 0));
        chbox_not_in_use_4->setText(QApplication::translate("ARViewer", "CheckBox", 0));
        chbox_wire_mode->setText(QApplication::translate("ARViewer", "WireMode", 0));
        pb_reset->setText(QApplication::translate("ARViewer", "Reset", 0));
        pb_bgd_color->setText(QApplication::translate("ARViewer", "Bgd Color", 0));
        pb_wire_color->setText(QApplication::translate("ARViewer", "Wire Color", 0));
        lb_screenshot_ratio->setText(QApplication::translate("ARViewer", "Ratio", 0));
        dspinbox_screenshot_ratio->setPrefix(QString());
        pb_screenshot->setText(QApplication::translate("ARViewer", "ScreenShot", 0));
        pb_checkable_button->setText(QApplication::translate("ARViewer", "TogButton", 0));
        pb_not_in_use_1->setText(QApplication::translate("ARViewer", "PushButton", 0));
        tbwgt_display_settings->setTabText(tbwgt_display_settings->indexOf(wgt_display), QApplication::translate("ARViewer", "Display", 0));
        pb_capture_photo->setText(QApplication::translate("ARViewer", "Capture Photo", 0));
        lb_expo_compensation->setText(QApplication::translate("ARViewer", "Exposure Compensation:", 0));
        tbwgt_display_settings->setTabText(tbwgt_display_settings->indexOf(wgt_other), QApplication::translate("ARViewer", "Other", 0));
        lb_file->setText(QApplication::translate("ARViewer", "File ", 0));
        line_edit_video_path->setText(QApplication::translate("ARViewer", "video file dir here", 0));
        pb_load_video->setText(QApplication::translate("ARViewer", "Load Video", 0));
        pb_run_camera->setText(QApplication::translate("ARViewer", "Run Camera", 0));
        menu_file->setTitle(QApplication::translate("ARViewer", "File", 0));
    } // retranslateUi
	void connectSignals(QMainWindow *ARViewer)
	{
		QObject::connect(gfx_view_canvas, SIGNAL(send_coord(int, int)), ARViewer, SLOT(update_status_bar(int, int)));
		QObject::connect(gfx_view_canvas, SIGNAL(send_filename(const QString&)), ARViewer, SLOT(update_window_title(const QString&)));
		QObject::connect(action_open, SIGNAL(triggered()), ARViewer, SLOT(open()));
	}
};

namespace Ui {
    class ARViewer: public Ui_ARViewer {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
