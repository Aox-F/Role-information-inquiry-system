#include "search1.h"
#include "ui_search1.h"
#include "config.h"
#include "math.h"
#include <QIcon>
#include <QPainter>
#include <QSound>

Search1::Search1(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::search1)
{
    ui->setupUi(this);
    setWindowTitle(QString("Role-Information"));
    setWindowIcon(QIcon(":/res/1.png"));
    level = BASIC_LEVEL;
    blood = BASIC_BLOOD;
    damage = BASIC_DAMAGE;
    damage_scale = BASIC_DAMAGE_SCALE;
    defense = BASIC_DEFENSE;
    blood = blood + 150 * pow(level, 2);
    damage = damage + 40 * log(level+1);
    damage_scale = damage_scale + 10 * level;
    defense = defense + 40 * log(level+1);
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

Search1::~Search1()
{
    delete ui;
}

void Search1::paintEvent(QPaintEvent *)
{
    QPainter painter(this);
    QPixmap pix;
    pix.load(":res/1.jpg");
    painter.drawPixmap(0, 0, this->width(), this->height(), pix);

    pix.load(":/res/3.jpg");
    painter.drawPixmap(0, 0, width(), height(), pix);

}
