#include"player.h"

Player::Player(QWidget* parent):
    QWidget(parent),
    ui(new Ui::Player)
{
    ui->setupUi(this);
    player=new QMediaPlayer;
    songList= new MusicList(this, this);
    ui->addItemButton->raise();
    songList->lower();
    decorate();
    connectAction();
    QIcon icon;
    icon.addFile(":/icon/resources/icons/rick.png");
    setWindowIcon(icon);
}

void Player::decorate()
{
    setWindowFlag(Qt::FramelessWindowHint);
    setStyleSheet("background-color: pink;");
    songList->setStyleSheet("background-color: pink; border-style: none;");
    ui->prospect->setStyleSheet("border-image: url(:/image/resources/images/1.png); ");
    ui->line->setStyleSheet("background-color: transparent;");
    QFile topStyleFile(":/stylesheet/topStyle.qss");
    topStyleFile.open(QIODevice::ReadOnly);
    QTextStream out(&topStyleFile);
    QString qss;
    qss=out.readAll();
    ui->iconButton->setStyleSheet(qss);
    ui->topBorder->setStyleSheet(qss);
    ui->closeButton->setStyleSheet(qss);
    ui->maximizeButton->setStyleSheet("background-color: rgba(50,50,50,0.3); border-style:flat;");
    ui->maximizeButton->setEnabled(false);
    ui->minimizeButton->setStyleSheet(qss);
    ui->nextSongButton->setStyleSheet(qss);
    ui->playButton->setStyleSheet(qss);
    ui->preSongButton->setStyleSheet(qss);
    ui->addItemButton->setStyleSheet("QPushButton{border-style: hidden; background-color: transparent; border-image: url(:/icon/resources/icons/add.png);} :hover{border-image: url(:/icon/resources/icons/add_hover.png);}");
}

void Player::connectAction()
{
    connect(ui->closeButton, &QPushButton::pressed, this, &Player::close);
    connect(ui->maximizeButton, &QPushButton::pressed, this, &Player::showFullScreen);
    connect(ui->minimizeButton, &QPushButton::pressed, this, &Player::showMinimized);
    connect(ui->addItemButton, &QPushButton::pressed, songList, &MusicList::newMusicItem);
    connect(ui->nextSongButton, &QPushButton::pressed, songList, &MusicList::nextRow);
    connect(ui->preSongButton, &QPushButton::pressed, songList, &MusicList::prevRow);
    connect(ui->iconButton, &QPushButton::pressed, this, &Player::showMessage);

    connect(songList, &QListWidget::itemDoubleClicked, this, &Player::switchSong);
    connect(songList, &QListWidget::itemDoubleClicked, songList, &MusicList::switchRow);

    connect(player, &QMediaPlayer::durationChanged, this, &Player::updateDuration);
    connect(player, &QMediaPlayer::positionChanged, this, &Player::updatePosition);
    connect(ui->rateSlider, &QSlider::valueChanged, this, &Player::setPlayerPosition);
}

void Player::showMessage()
{
    QMessageBox* message=new QMessageBox(this);
    message->setWindowTitle("RickPlayer! Get schwifty!");
    message->setText(tr("\1\1\1              版本：1.0              \1\1\1\n\nmade by xyt."));
    message->show();
}

void Player::switchSong(QListWidgetItem *item)
{
    ui->presentTime->setText(tr("%1:%2").arg(0).arg(0));
    ui->songNameLabel->setText(item->data(Qt::UserRole).value<SongItem>().name);
    player->setMedia(QUrl::fromLocalFile(item->data(Qt::UserRole).value<SongItem>().filePath));
    player->play();
    QIcon icon;
    icon.addFile(QString::fromUtf8(":/icon/resources/icons/pause.png"));
    ui->playButton->setIcon(icon);
}

void Player::updatePosition()
{
    qint64 position=player->position();
    qint64 sec=position/1000%60;
    qint64 min=position/1000/60%60;
    ui->presentTime->setText(tr("%1:%2").arg(min).arg(sec));
    ui->rateSlider->setValue(min*60+sec);
}

void Player::updateDuration()
{
    qint64 duration=player->duration();
    qint64 sec=duration/1000%60;
    qint64 min=duration/1000/60%60;
    ui->endTime->setText(tr("%1:%2").arg(min).arg(sec));
    ui->rateSlider->setMaximum(min*60+sec);
}

void Player::setPlayerPosition(int value)
{
    if(value>player->position()/1000+1||value<player->position()/1000-1){
        player->setPosition(value*1000);
    }
}

void Player::on_playButton_clicked()
{
    QIcon icon;
    
    if(player->state()==QMediaPlayer::StoppedState||player->state()==QMediaPlayer::PausedState){
        player->play();
        icon.addFile(QString::fromUtf8(":/icon/resources/icons/pause.png"));
        ui->playButton->setIcon(icon);
    }
    else if(player->state()==QMediaPlayer::PlayingState){
        player->pause();
        icon.addFile(QString::fromUtf8(":/icon/resources/icons/play.png"));
        ui->playButton->setIcon(icon);
    }
}

void Player::mousePressEvent(QMouseEvent *event)
{
    if(event->button()==Qt::LeftButton){
        mousePoint=event->globalPos()-this->pos();
    }
    
    QWidget::mousePressEvent(event);
}

void Player::mouseReleaseEvent(QMouseEvent *event)
{
    mousePoint=QPoint(1000,1000);//�ͷ����λ��
}

void Player::mouseMoveEvent(QMouseEvent *event)
{
    if(event->buttons()&Qt::LeftButton && mousePoint.y()<=ui->topBorder->geometry().height() ){
        move(event->globalPos()-mousePoint);
    }
    QWidget::mouseMoveEvent(event);
}
