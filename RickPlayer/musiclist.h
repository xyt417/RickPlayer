#ifndef MUSICLIST_H 
#define MUSICLIST_H
#include<QListWidget>
#include<QFileDialog>
#include<QFileInfo>
#include<QMap>
#include<QDir>
class Player;
struct SongItem
{
    QString name;
    QString filePath;
};
Q_DECLARE_METATYPE(SongItem)
class MusicList:public QListWidget
{
    Q_OBJECT
public:
    MusicList(QWidget *parent_base=0, Player *parent=0);
    void newMusicItem();
    void addMusicItem(QString filepath);
    void loadLib();
    QAction *del;
public slots:
    void switchRow(QListWidgetItem *item);
    void nextRow();
    void prevRow();
    void delItem();
protected:

private:
    Player *parent=0;
    int rowNum=0;
    int presentRow=0;
};


#endif