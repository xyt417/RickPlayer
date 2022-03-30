/********************************************************************************
** Form generated from reading UI file 'player.ui'
**
** Created by: Qt User Interface Compiler version 5.12.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PLAYER_H
#define UI_PLAYER_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Player
{
public:
    QLabel *topBorder;
    QPushButton *iconButton;
    QFrame *line;
    QLabel *songNameLabel;
    QPushButton *addItemButton;
    QPushButton *closeButton;
    QPushButton *minimizeButton;
    QPushButton *maximizeButton;
    QPushButton *playButton;
    QPushButton *preSongButton;
    QPushButton *nextSongButton;
    QSlider *rateSlider;
    QLabel *endTime;
    QLabel *presentTime;
    QLabel *prospect;

    void setupUi(QWidget *Player)
    {
        if (Player->objectName().isEmpty())
            Player->setObjectName(QString::fromUtf8("Player"));
        Player->resize(991, 649);
        Player->setMinimumSize(QSize(991, 649));
        topBorder = new QLabel(Player);
        topBorder->setObjectName(QString::fromUtf8("topBorder"));
        topBorder->setGeometry(QRect(0, 0, 1011, 65));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(topBorder->sizePolicy().hasHeightForWidth());
        topBorder->setSizePolicy(sizePolicy);
        iconButton = new QPushButton(Player);
        iconButton->setObjectName(QString::fromUtf8("iconButton"));
        iconButton->setEnabled(true);
        iconButton->setGeometry(QRect(0, 0, 200, 65));
        QFont font;
        font.setFamily(QString::fromUtf8("Pristina"));
        font.setPointSize(20);
        font.setBold(true);
        font.setItalic(false);
        font.setWeight(75);
        iconButton->setFont(font);
        iconButton->setStyleSheet(QString::fromUtf8(""));
        iconButton->setAutoDefault(false);
        iconButton->setFlat(false);
        line = new QFrame(Player);
        line->setObjectName(QString::fromUtf8("line"));
        line->setGeometry(QRect(0, 573, 991, 20));
        line->setFrameShadow(QFrame::Sunken);
        line->setLineWidth(1);
        line->setFrameShape(QFrame::HLine);
        songNameLabel = new QLabel(Player);
        songNameLabel->setObjectName(QString::fromUtf8("songNameLabel"));
        songNameLabel->setGeometry(QRect(22, 595, 151, 41));
        QFont font1;
        font1.setFamily(QString::fromUtf8("\346\226\271\346\255\243\347\262\227\351\273\221\345\256\213\347\256\200\344\275\223"));
        font1.setPointSize(12);
        songNameLabel->setFont(font1);
        songNameLabel->setAlignment(Qt::AlignCenter);
        songNameLabel->setIndent(2);
        addItemButton = new QPushButton(Player);
        addItemButton->setObjectName(QString::fromUtf8("addItemButton"));
        addItemButton->setGeometry(QRect(82, 548, 31, 31));
        addItemButton->setCursor(QCursor(Qt::ArrowCursor));
        addItemButton->setStyleSheet(QString::fromUtf8("background:transparent;"));
        addItemButton->setIconSize(QSize(32, 32));
        addItemButton->setFlat(false);
        closeButton = new QPushButton(Player);
        closeButton->setObjectName(QString::fromUtf8("closeButton"));
        closeButton->setGeometry(QRect(940, 17, 31, 31));
        closeButton->setStyleSheet(QString::fromUtf8(""));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/icon/resources/icons/close.png"), QSize(), QIcon::Normal, QIcon::Off);
        closeButton->setIcon(icon);
        closeButton->setFlat(false);
        minimizeButton = new QPushButton(Player);
        minimizeButton->setObjectName(QString::fromUtf8("minimizeButton"));
        minimizeButton->setGeometry(QRect(860, 17, 31, 31));
        minimizeButton->setStyleSheet(QString::fromUtf8(""));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/icon/resources/icons/minimize.png"), QSize(), QIcon::Normal, QIcon::Off);
        minimizeButton->setIcon(icon1);
        minimizeButton->setIconSize(QSize(32, 16));
        minimizeButton->setFlat(false);
        maximizeButton = new QPushButton(Player);
        maximizeButton->setObjectName(QString::fromUtf8("maximizeButton"));
        maximizeButton->setGeometry(QRect(900, 17, 31, 31));
        maximizeButton->setStyleSheet(QString::fromUtf8(""));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/icon/resources/icons/maximize.png"), QSize(), QIcon::Normal, QIcon::Off);
        maximizeButton->setIcon(icon2);
        maximizeButton->setCheckable(false);
        maximizeButton->setAutoDefault(false);
        maximizeButton->setFlat(false);
        playButton = new QPushButton(Player);
        playButton->setObjectName(QString::fromUtf8("playButton"));
        playButton->setGeometry(QRect(460, 592, 61, 24));
        QFont font2;
        font2.setFamily(QString::fromUtf8("Arial"));
        font2.setPointSize(20);
        playButton->setFont(font2);
        playButton->setStyleSheet(QString::fromUtf8("background:transparent;"));
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/icon/resources/icons/play.png"), QSize(), QIcon::Normal, QIcon::Off);
        playButton->setIcon(icon3);
        playButton->setFlat(false);
        preSongButton = new QPushButton(Player);
        preSongButton->setObjectName(QString::fromUtf8("preSongButton"));
        preSongButton->setGeometry(QRect(380, 592, 61, 24));
        preSongButton->setStyleSheet(QString::fromUtf8("background:transparent;"));
        QIcon icon4;
        icon4.addFile(QString::fromUtf8(":/icon/resources/icons/prevsong.png"), QSize(), QIcon::Normal, QIcon::Off);
        preSongButton->setIcon(icon4);
        preSongButton->setFlat(false);
        nextSongButton = new QPushButton(Player);
        nextSongButton->setObjectName(QString::fromUtf8("nextSongButton"));
        nextSongButton->setGeometry(QRect(540, 592, 61, 24));
        nextSongButton->setStyleSheet(QString::fromUtf8("background:transparent;"));
        QIcon icon5;
        icon5.addFile(QString::fromUtf8(":/icon/resources/icons/nextsong.png"), QSize(), QIcon::Normal, QIcon::Off);
        nextSongButton->setIcon(icon5);
        nextSongButton->setFlat(false);
        rateSlider = new QSlider(Player);
        rateSlider->setObjectName(QString::fromUtf8("rateSlider"));
        rateSlider->setGeometry(QRect(254, 616, 471, 22));
        rateSlider->setOrientation(Qt::Horizontal);
        endTime = new QLabel(Player);
        endTime->setObjectName(QString::fromUtf8("endTime"));
        endTime->setGeometry(QRect(738, 614, 41, 24));
        presentTime = new QLabel(Player);
        presentTime->setObjectName(QString::fromUtf8("presentTime"));
        presentTime->setGeometry(QRect(200, 615, 41, 24));
        prospect = new QLabel(Player);
        prospect->setObjectName(QString::fromUtf8("prospect"));
        prospect->setGeometry(QRect(196, 65, 795, 518));

        retranslateUi(Player);

        QMetaObject::connectSlotsByName(Player);
    } // setupUi

    void retranslateUi(QWidget *Player)
    {
        Player->setWindowTitle(QApplication::translate("Player", "Emotional Damage Player", nullptr));
        topBorder->setText(QString());
        iconButton->setText(QApplication::translate("Player", "Rick", nullptr));
        songNameLabel->setText(QApplication::translate("Player", "select music", nullptr));
        addItemButton->setText(QString());
        closeButton->setText(QString());
        minimizeButton->setText(QString());
        maximizeButton->setText(QString());
        playButton->setText(QString());
        preSongButton->setText(QString());
        nextSongButton->setText(QString());
        endTime->setText(QApplication::translate("Player", "00 : 00", nullptr));
        presentTime->setText(QApplication::translate("Player", "00 : 00", nullptr));
        prospect->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class Player: public Ui_Player {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PLAYER_H
