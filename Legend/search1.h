#ifndef SEARCH1_H
#define SEARCH1_H

#include <QWidget>
#include <QString>

#include "config.h"

namespace Ui {
class search1;
}

class Search1 : public QWidget
{
    Q_OBJECT

public:
    explicit Search1(QWidget *parent = nullptr);
    ~Search1();

    void paintEvent(QPaintEvent *event);

    QString NAME = "Brox saroufal";
    QString LEVEL;
    QString BLOOD;
    QString DAMAGE;
    QString DAMAGE_SCALE;
    QString DEFENSE;

    bool God_On = GOD_ON_ORC;
    double level;
    double blood;
    double damage;
    double damage_scale;
    double defense;

private:
    Ui::search1 *ui;
};

#endif // SEARCH1_H
