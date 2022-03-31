#ifndef PLAYERR_H
#define PLAYERR_H
#include<QMediaPlayer>
#include<QTimer>
#include<QMouseEvent>
#include<QMessageBox>
#include"ui_player.h"
#include"musiclist.h"
class Player:public QWidget
{
    Q_OBJECT
public:
    Player(QWidget *parent=0);
    void updateDuration();
    void updatePosition();
    void setPlayerPosition(int value);
public slots:
    void showMessage();
    void switchSong(QListWidgetItem *item);
    void on_playButton_clicked();

protected:
    void mousePressEvent(QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent *event);
    void mouseReleaseEvent(QMouseEvent *event);
    QPoint mousePoint=QPoint(1000,1000);
private:
    Ui::Player *ui;
    QMediaPlayer *player;
    MusicList *songList;
    QPalette *topColor;
    void connectAction();
    void decorate();
};
#endif