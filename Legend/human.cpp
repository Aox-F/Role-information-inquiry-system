#include "search.h"
#include "math.h"
#include "config.h"
#include "search1.h"
#include "search2.h"

#include <iostream>
#include <fstream>
#include <string>

#include <QApplication>
#include <QString>

using namespace std;

class blood
{
public:
    double Blood;
    blood()
    {
        Blood = Basic_Blood;
    }
    virtual int blood_add(double &Blood)
    {
        Blood = 2 * Basic_Blood;
        return Blood;
    }

private:
    double Basic_Blood = BASIC_BLOOD;
};

class defense
{
public:
    double Defense;
    defense()
    {
        Defense = Basic_Defense;
    }
    virtual int defense_add(double &Defense)
    {
        Defense = 2 * Basic_Defense;
        return Defense;
    }

private:
    double Basic_Defense = BASIC_DEFENSE;
};

class damageAnddamageScale
{
public:
    double damage;
    double damage_scale;
    damageAnddamageScale()
    {
        damage = Basic_Damage;
        damage_scale = Basic_Damage_Scale;
    }
    virtual int damage_add(double &damage)
    {
        damage = 2 * Basic_Damage;
        return damage;
    }
    virtual int damagescale_add(double &damage_scale)
    {
        damage_scale = 2 * Basic_Damage_Scale;
        return damage_scale;
    }
private:
    double Basic_Damage = BASIC_DAMAGE;
    double Basic_Damage_Scale = BASIC_DAMAGE_SCALE;
};

class Human :public blood, public damageAnddamageScale, public defense {
public:
    Human()
    {
        blood_human = blood_human + 100 * pow(level_human, 2);
        damage_human = damage_human + 50 * log(level_human+1);
        damage_scale_human = damage_scale_human + 25 * level_human;
        defense_human = defense_human + 30 * log(level_human+1);
    }
    virtual int blood_add(double &blood_human)
    {
        blood_human = 10000;
        return blood_human;
    }
    virtual int defense_add(double &defense_human)
    {
        defense_human = 10000;
        return defense_human;
    }
    virtual int damage_add(double &damage_human)
    {
        damage_human = 10000;
        return damage_human;
    }
    virtual int damagescale_add(double &damage_scale_human)
    {
        damage_scale_human = 10000;
        return damage_scale_human;
    }
    bool God_ON = GOD_ON_HUMAN;
    int level_human = BASIC_LEVEL;
    double blood_human = Blood;
    double damage_human = damage;
    double damage_scale_human = damage_scale;
    double defense_human = Defense;
};

class Orc :public blood, public damageAnddamageScale, public defense {
public:
    Orc()
    {
        blood_orc = blood_orc + 150 * pow(level_orc, 2);
        damage_orc = damage_orc + 40 * log(level_orc+1);
        damage_scale_orc = damage_scale_orc + 10 * level_orc;
        defense_orc = defense_orc + 40 * log(level_orc+1);
    }
    virtual int blood_add(double &blood_orc)
    {
        blood_orc = 10000;
        return blood_orc;
    }
    virtual int defense_add(double &defense_orc)
    {
        defense_orc = 10000;
        return defense_orc;
    }
    virtual int damage_add(double &damage_orc)
    {
        damage_orc = 10000;
        return damage_orc;
    }
    virtual int damagescale_add(double &damage_scale_orc)
    {
        damage_scale_orc = 10000;
        return damage_scale_orc;
    }
    bool God_ON = GOD_ON_ORC;
    int level_orc = BASIC_LEVEL;
    double blood_orc = Blood;
    double damage_orc = damage;
    double damage_scale_orc = damage_scale;
    double defense_orc = Defense;
};

class Elf :public blood, public damageAnddamageScale, public defense {
public:
    Elf()
    {
        blood_elf = blood_elf + 80 * pow(level_elf, 2);
        damage_elf = damage_elf + 70 * log(level_elf+1);
        damage_scale_elf = damage_scale_elf + 30 * level_elf;
        defense_elf = defense_elf + 20 * log(level_elf+1);
    }
    virtual int blood_add(double &blood_elf)
    {
        blood_elf = 10000;
        return blood_elf;
    }
    virtual int defense_add(double &defense_elf)
    {
        defense_elf = 10000;
        return defense_elf;
    }
    virtual int damage_add(double &damage_elf)
    {
        damage_elf = 10000;
        return damage_elf;
    }
    virtual int damagescale_add(double &damage_scale_elf)
    {
        damage_scale_elf = 10000;
        return damage_scale_elf;
    }
    bool God_ON = GOD_ON_ELF;
    int level_elf = BASIC_LEVEL;
    double blood_elf = Blood;
    double damage_elf = damage;
    double damage_scale_elf = damage_scale;
    double defense_elf = Defense;
};


int main(int argc, char *argv[]) {
    QApplication a(argc, argv);


    Human lena;
    Orc nike;
    Elf lihua;
    string name;

    if(lena.God_ON == true)
    {
        lena.blood_human = lena.blood_add(lena.blood_human);
        lena.damage_human = lena.damage_add(lena.damage_human);
        lena.defense_human = lena.defense_add(lena.defense_human);
        lena.damage_scale_human = lena.damagescale_add(lena.damage_scale_human);
    }

    if(nike.God_ON == true)
    {
        nike.blood_orc = nike.blood_add(nike.blood_orc);
        nike.damage_orc = nike.damage_add(nike.damage_orc);
        nike.defense_orc = nike.defense_add(nike.defense_orc);
        nike.damage_scale_orc = nike.damagescale_add(nike.damage_scale_orc);
    }

    if(lihua.God_ON == true)
    {
        lihua.blood_elf = lihua.blood_add(lihua.blood_elf);
        lihua.damage_elf = lihua.damage_add(lihua.damage_elf);
        lihua.defense_elf = lihua.defense_add(lihua.defense_elf);
        lihua.damage_scale_elf =lihua.damagescale_add(lihua.damage_scale_elf);
    }

    cout << "Please enter a query object:\n";
    cin >> name;
    if (name == "human")
    {
        ofstream fout("F:/Qt/Legend/text.txt", ios::out);
        if (!fout)
        {
            cout << "Cannot open output file \n";
            return -1;
        }
        fout << "Hero's name:" << " " << "aegwynn" << endl;
        fout << "Hero's career:" << " " << "HUMAN" << endl;
        fout << "Hero's level:" << " " << lena.level_human << endl;
        fout << "hero's blood:" << " " << lena.blood_human << endl;
        fout << "Hero's damage:" << " " << lena.damage_human << endl;
        fout << "Hero's damage_scale:" << " " << lena.damage_scale_human << endl;
        fout << "Hero's defense:" << " " << lena.defense_human << endl;
        fout.close();
        ifstream fin("F:/Qt/Legend/text.txt", ios::in);
        if (!fin)
        {
            cout << " Cannot open output file.\n";
            return 1;
        }
        char str[1000];
        while (fin)
        {
            fin.getline(str, 1000);
            cout << str << endl;
        }
        fin.close();
        Search w;
        w.show();
        return a.exec();
    }
    else if (name == "orc")
    {
        ofstream fout("F:/Qt/Legend/text.txt", ios::out);
        if (!fout)
        {
            cout << "Cannot open output file \n";
            return -1;
        }
        fout << "Hero's name:" << " " << "Brox saroufal" << endl;
        fout << "Hero's career:" << " " << "ORC" << endl;
        fout << "Hero's level:" << " " << nike.level_orc << endl;
        fout << "hero's blood:" << " " << nike.blood_orc << endl;
        fout << "Hero's damage:" << " " << nike.damage_orc << endl;
        fout << "Hero's damage_scale:" << " " << nike.damage_scale_orc << endl;
        fout << "Hero's defense:" << " " << nike.defense_orc << endl;
        fout.close();
        ifstream fin("F:/Qt/Legend/text.txt", ios::in);
        if (!fin)
        {
            cout << " Cannot open output file.\n";
            return 1;
        }
        char str[1000];
        while (fin)
        {
            fin.getline(str, 1000);
            cout << str << endl;
        }
        fin.close();
        Search1 w;
        w.show();
        return a.exec();
    }
    else if (name == "elf")
    {
        ofstream fout("F:/Qt/Legend/text.txt", ios::out);
        if (!fout)
        {
            cout << "Cannot open output file \n";
            return -1;
        }
        fout << "Hero's name:" << " " << "dandan" << endl;
        fout << "Hero's career:" << " " << "ELF" << endl;
        fout << "Hero's level:" << " " << lihua.level_elf << endl;
        fout << "hero's blood:" << " " << lihua.blood_elf << endl;
        fout << "Hero's damage:" << " " << lihua.damage_elf << endl;
        fout << "Hero's damage_scale:" << " " << lihua.damage_scale_elf << endl;
        fout << "Hero's defense:" << " " << lihua.defense_elf << endl;
        fout.close();
        ifstream fin("F:/Qt/Legend/text.txt", ios::in);
        if (!fin)
        {
            cout << " Cannot open output file.\n";
            return 1;
        }
        char str[1000];
        while (fin)
        {
            fin.getline(str, 1000);
            cout << str << endl;
        }
        fin.close();
        Search2 w;
        w.show();
        return a.exec();
    }
    else
    {
        cout<<"Search failed!!!\n";
    }

}


