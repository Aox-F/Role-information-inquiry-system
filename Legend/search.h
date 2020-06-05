#ifndef SEARCH_H
#define SEARCH_H

#include <QWidget>
#include <QString>

#include "config.h"

namespace Ui {
class search;
}

class Search : public QWidget
{
    Q_OBJECT

public:
    explicit Search(QWidget *parent = nullptr);
    ~Search();
    void paintEvent(QPaintEvent *event);

    QString NAME = "aegwynn";
    QString LEVEL;
    QString BLOOD;
    QString DAMAGE;
    QString DAMAGE_SCALE;
    QString DEFENSE;

    bool God_On = GOD_ON_HUMAN;
    double level;
    double blood;
    double damage;
    double damage_scale;
    double defense;

private:
    Ui::search *ui;
};

#endif // SEARCH_H
