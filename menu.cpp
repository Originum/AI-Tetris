#include "menu.h"
#include "ui_menu.h"
 #include <QPixmap>
#include <QPalette>
#include <QBitmap>

menu::menu(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::menu)
{
    //音乐播放
       effect = new QSoundEffect (this);
       effect->setLoopCount(QSoundEffect::Infinite);
       effect->setSource(QUrl::fromLocalFile("D:/Testeluosi/Testeluosi/music/music1.wav"));
       effect->setVolume(0.5);

       effect2 = new QSoundEffect (this);
       effect2->setSource(QUrl::fromLocalFile("D:/Testeluosi/Testeluosi/clickmusic.wav"));
       effect2->setVolume(0.5);
    ui->setupUi(this);
    ui->radioButton->hide();
    ui->radioButton_2->hide();
    ui->radioButton_3->hide();
    ui->radioButton_4->hide();
    ui->radioButton_5->hide();
    ui->radioButton_6->hide();
    ui->radioButton_7->hide();
    ui->radioButton_8->hide();
    ui->radioButton_9->hide();
    ui->radioButton_10->hide();
    ui->radioButton_11->hide();
    ui->label->hide();
    ui->label_2->hide();
    ui->label_3->hide();
    ui->label_4->hide();
    ui->label_5->hide();
    ui->pushButton_4->hide();
    ui->pushButton_6->hide();
    ui->pushButton_7->hide();
    ui->pushButton_8->hide();
    ui->horizontalSlider->hide();

    rank = 4;//默认为困难
    backpictureID = 1;
    aiLead = 0;
    ui->buttonGroup->setId(ui->radioButton,7);
    ui->buttonGroup->setId(ui->radioButton_2,4);
    ui->buttonGroup->setId(ui->radioButton_3,2);
    ui->buttonGroup->setId(ui->radioButton_4,1);

    ui->buttonGroup_2->setId(ui->radioButton_5,1);
    ui->buttonGroup_2->setId(ui->radioButton_6,2);
    ui->buttonGroup_2->setId(ui->radioButton_7,3);
    ui->buttonGroup_2->setId(ui->radioButton_8,4);
    ui->buttonGroup_2->setId(ui->radioButton_9,5);

    ui->buttonGroup_3->setId(ui->radioButton_10,0);
    ui->buttonGroup_3->setId(ui->radioButton_11,1);

    QPixmap bgImages(":/new/prefix1/menu.jpg");
    QPalette bgPalette = this->palette();
    bgPalette.setBrush(QPalette::Background,bgImages);
    this->setPalette(bgPalette);
    setMask(bgImages.mask());// set background mask attribute same as background's image


}

menu::~menu()
{
    delete ui;
    delete w;
}

void menu::on_pushButton_clicked()
{
    Board *board = new Board();

    w = new MainWindow(board,rank,backpictureID,aiLead);

     this->hide(); //实现先隐藏再进入游戏

     w->show();
}

void menu::on_pushButton_2_clicked()
{
    ui->pushButton->hide();
    ui->pushButton_2->hide();
    ui->pushButton_3->hide();
    ui->pushButton_5->hide();


    QPixmap bgImages(":/new/prefix1/menu2.JPG");
    QPalette bgPalette = this->palette();
    bgPalette.setBrush(QPalette::Background,bgImages);
    this->setPalette(bgPalette);
    setMask(bgImages.mask());

    ui->pushButton_4->show();
    ui->radioButton->show();
    ui->pushButton_7->show();
    ui->pushButton_8->show();
    ui->horizontalSlider->show();
    ui->radioButton_2->show();
    ui->radioButton_3->show();
    ui->radioButton_4->show();
    ui->radioButton_5->show();
    ui->radioButton_6->show();
    ui->radioButton_7->show();
    ui->radioButton_8->show();
    ui->radioButton_9->show();
    ui->radioButton_10->show();
    ui->radioButton_11->show();
    ui->label->show();
    ui->label_2->show();
    ui->label_5->show();

     QPixmap pixmap(":/new/prefix1/background1.jpg");
     pixmap.scaled(ui->label_3->size(), Qt::KeepAspectRatio);
     ui->label_3->setScaledContents(true);
     ui->label_3->setPixmap(pixmap);
}


void menu::on_pushButton_3_clicked()
{
    this -> close();
}


void menu::on_pushButton_4_clicked()
{
    rank = ui->buttonGroup->checkedId();
    backpictureID = ui->buttonGroup_2->checkedId();
    aiLead = ui->buttonGroup_3->checkedId();

    if (rank == -1) rank = 4;
    if (backpictureID == -1) backpictureID = 1;
    if (aiLead == -1) aiLead = 0;

    ui->radioButton->hide();
    ui->radioButton_2->hide();
    ui->radioButton_3->hide();
    ui->radioButton_4->hide();
    ui->radioButton_5->hide();
    ui->radioButton_6->hide();
    ui->radioButton_7->hide();
    ui->radioButton_8->hide();
    ui->radioButton_9->hide();
    ui->radioButton_10->hide();
    ui->radioButton_11->hide();
    ui->label->hide();
    ui->label_2->hide();
    ui->label_5->hide();
    ui->pushButton_4->hide();
    ui->pushButton_7->hide();
    ui->pushButton_8->hide();
    ui->horizontalSlider->hide();
    ui->pushButton->show();
    ui->pushButton_2->show();
    ui->pushButton_3->show();
    ui->pushButton_5->show();

    QPixmap bgImages(":/new/prefix1/menu.jpg");
    QPalette bgPalette = this->palette();
    bgPalette.setBrush(QPalette::Background,bgImages);
    this->setPalette(bgPalette);
    setMask(bgImages.mask());

    ui->label_3->hide();

}

void menu::on_radioButton_5_clicked()
{

    QPixmap pixmap(":/new/prefix1/background1.jpg");
    ui->label_3->setPixmap(pixmap);
    ui->label_3->show();
    effect2->play();

}

void menu::on_radioButton_8_clicked()
{
    QPixmap pixmap(":/new/prefix1/background4.jpg");
    ui->label_3->setPixmap(pixmap);
    ui->label_3->show();
    effect2->play();

}

void menu::on_radioButton_6_clicked()
{
    QPixmap pixmap(":/new/prefix1/background2.jpg");
    ui->label_3->setPixmap(pixmap);
    ui->label_3->show();
    effect2->play();

}

void menu::on_radioButton_7_clicked()
{
    QPixmap pixmap(":/new/prefix1/background3.jpg");
    ui->label_3->setPixmap(pixmap);
    ui->label_3->show();
    effect2->play();

}

void menu::on_radioButton_9_clicked()
{
    QPixmap pixmap(":/new/prefix1/background5.jpg");
    ui->label_3->setPixmap(pixmap);
    ui->label_3->show();
    effect2->play();

}

void menu::on_pushButton_5_clicked()
{
    QPixmap bgImages(":/new/prefix1/menu2.JPG");
    QPalette bgPalette = this->palette();
    bgPalette.setBrush(QPalette::Background,bgImages);
    this->setPalette(bgPalette);
    setMask(bgImages.mask());

    ui->pushButton->hide();
    ui->pushButton_2->hide();
    ui->pushButton_3->hide();
    ui->pushButton_5->hide();

    int scoreRank[10];
    FILE *fd =fopen("score.bin","rb+");
    for(int i=0;i<10;i++)
    fscanf(fd, "%d", scoreRank+i);

    QFont font ("Microsoft YaHei", 13, 75);
    ui->label_4->setFont(font);
    ui->label_4->setStyleSheet("color:white;");
    ui->label_4->setText("冠军：         "+QString::number(scoreRank[0])
            +"\n亚军:           "+QString::number(scoreRank[1])
            +"\n季军:           "+QString::number(scoreRank[2])
            +"\n第4名:          "+QString::number(scoreRank[3])
            +"\n第5名:          "+QString::number(scoreRank[4])
            +"\n第6名:          "+QString::number(scoreRank[5])
            +"\n第7名:          "+QString::number(scoreRank[6])
            +"\n第8名:          "+QString::number(scoreRank[7])
            +"\n第9名:          "+QString::number(scoreRank[8])
            +"\n第10名:        "+QString::number(scoreRank[9])
            );
    ui->label_4->show();
    ui->pushButton_6->show();
}

void menu::on_pushButton_6_clicked()
{

    QPixmap bgImages(":/new/prefix1/menu.jpg");
    QPalette bgPalette = this->palette();
    bgPalette.setBrush(QPalette::Background,bgImages);
    this->setPalette(bgPalette);
    setMask(bgImages.mask());
    ui->label_4->hide();
    ui->pushButton_6->hide();
    ui->pushButton->show();
    ui->pushButton_2->show();
    ui->pushButton_3->show();
    ui->pushButton_5->show();
}

void menu::on_horizontalSlider_sliderMoved(int position)
{
    double d_position=position*1.0/100.0;
    effect->setVolume(d_position);
    effect2->setVolume(d_position);

}

void menu::on_pushButton_8_clicked()
{
    if(flag%2==0)
       {
           effect->play();
           ui->pushButton_8->setStyleSheet(tr("border-image: url(:/new/prefix1/musicStop.png);"));
           flag++;
       }
       else
       {
           effect->stop();
           ui->pushButton_8->setStyleSheet(tr("border-image: url(:/new/prefix1/musicStart.png);"));
           flag++;
       }
}

void menu::on_pushButton_7_clicked()
{
        flag2++;
        switch(flag2%7)
        {
        case 1:
            effect->setSource(QUrl::fromLocalFile("://music1.wav"));
            break;
        case 2:
            effect->setSource(QUrl::fromLocalFile("://music2.wav"));
            break;
        case 3:
            effect->setSource(QUrl::fromLocalFile("://music3.wav"));
            break;
        case 4:
            effect->setSource(QUrl::fromLocalFile("://music8.wav"));
            break;
        case 5:
            effect->setSource(QUrl::fromLocalFile("://music5.wav"));
            break;
        case 6:
            effect->setSource(QUrl::fromLocalFile("://music6.wav"));
            break;
        case 7:
            effect->setSource(QUrl::fromLocalFile("://music7.wav"));
            break;
        }
        if(flag%2==1)
        {
            effect->play();
        }
}

void menu::on_radioButton_10_clicked()
{
    effect2->play();

}

void menu::on_radioButton_11_clicked()
{
    effect2->play();

}

void menu::on_radioButton_clicked()
{
    effect2->play();

}

void menu::on_radioButton_2_clicked()
{
    effect2->play();

}

void menu::on_radioButton_3_clicked()
{
    effect2->play();

}

void menu::on_radioButton_4_clicked()
{
    effect2->play();

}
