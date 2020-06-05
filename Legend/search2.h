#ifndef SEARCH2_H
#define SEARCH2_H

#include <QWidget>
#include <QString>

#include "config.h"

namespace Ui {
class search2;
}

class Search2 : public QWidget
{
    Q_OBJECT

public:
    explicit Search2(QWidget *parent = nullptr);
    ~Search2();

    void paintEvent(QPaintEvent *event);

    QString NAME = "dandan";
    QString LEVEL;
    QString BLOOD;
    QString DAMAGE;
    QString DAMAGE_SCALE;
    QString DEFENSE;

    bool God_On = GOD_ON_ELF;
    double level;
    double blood;
    double damage;
    double damage_scale;
    double defense;

private:
    Ui::search2 *ui;
};

#endif // SEARCH2_H
