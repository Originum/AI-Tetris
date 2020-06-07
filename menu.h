#ifndef MENU_H
#define MENU_H

#include <QWidget>
#include "mainwindow.h"
#include <QSoundEffect>

namespace Ui {
class menu;
}

class MainWindow;

class menu : public QWidget
{
    Q_OBJECT

public:
    explicit menu(QWidget *parent = 0);
    ~menu();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

    void on_radioButton_5_clicked();

    void on_radioButton_8_clicked();

    void on_radioButton_6_clicked();

    void on_radioButton_7_clicked();

    void on_radioButton_9_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_6_clicked();

    void on_horizontalSlider_sliderMoved(int position);

    void on_pushButton_8_clicked();

    void on_pushButton_7_clicked();

    void on_radioButton_10_clicked();

    void on_radioButton_11_clicked();

    void on_radioButton_clicked();

    void on_radioButton_2_clicked();

    void on_radioButton_3_clicked();

    void on_radioButton_4_clicked();

private:
    Ui::menu *ui;
    MainWindow *w; //开始一局
    int rank; //用户选择难度
    int backpictureID; //用户选择背景图片
    int aiLead;
    QSoundEffect* effect;
    QSoundEffect* effect2;
    int flag=0;
    int flag2=1;
};

#endif // MENU_H
