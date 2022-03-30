#include"musiclist.h"
#include"player.h"
#include<QAction>
#include<QMessageBox>

MusicList::MusicList(QWidget *parent_base, Player *parent):QListWidget(parent_base)
{
    this->parent=parent;
    setGeometry(QRect(-1, 63, 200, 520));
    loadLib();
    del=new QAction(tr("移除"));
    addAction(del);
    connect(del, &QAction::triggered, this, &MusicList::delItem);
    setContextMenuPolicy(Qt::ActionsContextMenu);
}

void MusicList::addMusicItem(QString filepath)
{
    QFileInfo info(filepath);
    SongItem data;
    data.filePath=info.absoluteFilePath();
    data.name=info.completeBaseName();
    QVariant vdata;
    vdata.setValue(data);
    QListWidgetItem *item=new QListWidgetItem;
    item->setText(data.name);
    item->setData(Qt::UserRole, vdata);
    item->setSizeHint(QSize(50, 30));
    item->setTextAlignment(Qt::AlignCenter);
    QFont font;
    font.setPointSize(10);
    font.setFamily("幼圆");
    item->setFont(font);
    this->addItem(item);
    rowNum++;
}

void MusicList::newMusicItem()
{
    QString filepath=QFileDialog::getOpenFileName(this, "添加emo", ".", "Music(*.mp3)");
    addMusicItem(filepath);

    QFile fromMusicFile(filepath);
    fromMusicFile.open(QIODevice::ReadOnly);
    QFileInfo fromFileInfo(filepath);
    QByteArray musicData;
    musicData=fromMusicFile.readAll();
    QDir musicLib(qApp->applicationDirPath());
    musicLib.mkdir("RickLib");
    QFile toMusicFile(qApp->applicationDirPath()+"/RickLib/"+fromFileInfo.fileName());
    toMusicFile.open(QIODevice::WriteOnly);
    toMusicFile.write(musicData);
    fromMusicFile.close();
    toMusicFile.close();
}

void MusicList::loadLib()
{
    QDir musicLib(qApp->applicationDirPath()+"/RickLib/");
    musicLib.setFilter(QDir::Files);
    musicLib.setNameFilters(QStringList("*.mp3"));
    QList<QFileInfo> libMusicList=musicLib.entryInfoList();
    QFileInfo libItem;
    foreach(libItem, libMusicList){
        addMusicItem(libItem.absoluteFilePath());
        
    }
}

void MusicList::switchRow(QListWidgetItem *item) {presentRow=row(item);}
void MusicList::nextRow() {parent->switchSong(item(presentRow=(presentRow+1)%rowNum));}
void MusicList::prevRow() {parent->switchSong(item(presentRow=(presentRow-1+rowNum)%rowNum));}

void MusicList::delItem()
{
    QList<QListWidgetItem *> items=selectedItems();
    if(!items.empty())
    {
        foreach(QListWidgetItem *item, items)
        {
            QFile delFile(item->data(Qt::UserRole).value<SongItem>().filePath);
            delFile.remove();
            delete item;
            rowNum--;
            nextRow();
        }
    }
}