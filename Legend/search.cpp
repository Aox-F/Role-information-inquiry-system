#include "search.h"
#include "ui_search.h"
#include "config.h"
#include "math.h"
#include <QIcon>
#include <QPainter>
#include <QSound>

Search::Search(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::search)
{
    ui->setupUi(this);
    setWindowTitle(QString("Role-Information"));
    setWindowIcon(QIcon(":/res/1.png"));
    level = BASIC_LEVEL;
    blood = BASIC_BLOOD;
    damage = BASIC_DAMAGE;
    damage_scale = BASIC_DAMAGE_SCALE;
    defense = BASIC_DEFENSE;
    blood = blood + 100 * pow(level, 2);
    damage = damage + 50 * log(level+1);
    damage_scale = damage_scale + 25 * level;
    defense = defense + 30 * log(level+1);
    LEVEL = QString::number(level);
    if(God_On == true)
    {
        QSound::play(GOD_ON_SOUND);
        blood = 10000;
        defense = 10000;
        damage = 10000;
        damage_scale = 10000;
    }
    else
    {
        QSound::play(NORMAL_SOUND);
    }
    BLOOD = QString::number(blood);
    DAMAGE = QString::number(damage);
    DAMAGE_SCALE = QString::number(damage_scale);
    DEFENSE = QString::number(defense);
    ui->name->setText(NAME);
    ui->level->setText(LEVEL);
    ui->blood->setText(BLOOD);
    ui->damage->setText(DAMAGE);
    ui->damage_scale->setText(DAMAGE_SCALE);
    ui->defense->setText(DEFENSE);
}

Search::~Search()
{
    delete ui;
}

void Search::paintEvent(QPaintEvent *)
{

        QPainter painter(this);
        QPixmap pix;
        pix.load(":res/1.jpg");
        painter.drawPixmap(0, 0, this->width(), this->height(), pix);

        pix.load(":/res/2.jpg");
        painter.drawPixmap(0, 0, width(), height(), pix);

}
