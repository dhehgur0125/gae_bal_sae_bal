﻿#include "Skill.h"

void skill_f(char skilltype, double skilldmg, Monster& mon, Monster& enermy) {
    if ((enermy.get_type() == '@' && skilltype == '<') ||
        (enermy.get_type() == '<' && skilltype == '#') ||
        (enermy.get_type() == '#' && skilltype == '@')) {
        enermy.set_hp(enermy.get_hp() - (mon.get_dmg() * 0.5 + skilldmg));
    }
    else if ((enermy.get_type() == '@' && skilltype == '#') ||
        (enermy.get_type() == '<' && skilltype == '@') ||
        (enermy.get_type() == '#' && skilltype == '<')) {
        enermy.set_hp(enermy.get_hp() - (mon.get_dmg() * 1.5 + skilldmg));
    }
    else if (enermy.get_type() == skilltype) {
        enermy.set_hp(enermy.get_hp() - (mon.get_dmg() + skilldmg));
    }
}

void attack(Monster& mon, Monster& enermy)
{
    mon.set_mpcost(mon.get_mpcost() + 1);
    if ((enermy.get_type() == '@' && mon.get_type() == '<') ||
        (enermy.get_type() == '<' && mon.get_type() == '#') ||
        (enermy.get_type() == '#' && mon.get_type() == '@')) {
        enermy.set_hp(enermy.get_hp() - (mon.get_dmg() * 0.5));
    }
    else if ((enermy.get_type() == '@' && mon.get_type() == '#') ||
        (enermy.get_type() == '<' && mon.get_type() == '@') ||
        (enermy.get_type() == '#' && mon.get_type() == '<')) {
        enermy.set_hp(enermy.get_hp() - (mon.get_dmg() * 1.5 ));
    }
    else if (enermy.get_type() == mon.get_type()) {
        enermy.set_hp(enermy.get_hp() - (mon.get_dmg()));
    }
}

//10
void bubblebeam(Monster& mon, Monster& enermy) {

    if (mon.get_mpcost() < 3)
        cout << "마나가 부족합니다!\n공격 실패!\n";
    else
    {
        mon.set_mpcost(mon.get_mpcost() - 3);
        skill_f('@', 5, mon, enermy);
    }

}
//11
void fireball(Monster& mon, Monster& enermy) {
    if (mon.get_mpcost() < 3)
        cout << "마나가 부족합니다!\n공격 실패!\n";
    else
    {
        mon.set_mpcost(mon.get_mpcost() - 3);
        skill_f('<', 5, mon, enermy);
    }
}
//12
void grasswhip(Monster& mon, Monster& enermy) {
    if (mon.get_mpcost() < 3)
        cout << "마나가 부족합니다!\n공격 실패!\n";
    else
    {
        mon.set_mpcost(mon.get_mpcost() - 3);
        skill_f('#', 5, mon, enermy);
    }

}

void heal(Monster& mon) {
    mon.set_hp(mon.get_hp() + 10);
}
//13
void waterjett(Monster& mon, Monster& enemy)
{
    if (mon.get_mpcost() < 5)
        cout << "마나가 부족합니다!\n공격 실패!\n";
    else
    {
        mon.set_mpcost(mon.get_mpcost() - 5);
        skill_f('@', 10, mon, enemy);
    }
}
//16
void tidal_wave(Monster& mon, Monster& enemy)
{
    if (mon.get_mpcost() < 7)
        cout << "마나가 부족합니다!\n공격 실패!\n";
    else
    {
        mon.set_mpcost(mon.get_mpcost() - 7);
        skill_f('@', 15, mon, enemy);
    }
}
//14
void blazebeam(Monster& mon, Monster& enemy)
{
    if (mon.get_mpcost() < 5)
        cout << "마나가 부족합니다!\n공격 실패!\n";
    else
    {
        mon.set_mpcost(mon.get_mpcost() - 5);
        skill_f('<', 10, mon, enemy);
    }
}
//17
void volcano(Monster& mon, Monster& enemy)
{
    if (mon.get_mpcost() < 7)
        cout << "마나가 부족합니다!\n공격 실패!\n";
    else
    {
        mon.set_mpcost(mon.get_mpcost() - 7);
        skill_f('<', 15, mon, enemy);
    }
}
//15
void leaf_knife(Monster& mon, Monster& enemy)
{
    if (mon.get_mpcost() < 5)
        cout << "마나가 부족합니다!\n공격 실패!\n";
    else
    {
        mon.set_mpcost(mon.get_mpcost() - 5);
        skill_f('#', 10, mon, enemy);
    }
}
//18
void the_power_of_the_world_tree(Monster& mon, Monster& enemy)
{
    if (mon.get_mpcost() < 7)
        cout << "마나가 부족합니다!\n공격 실패!\n";
    else
    {
        mon.set_mpcost(mon.get_mpcost() - 7);
        skill_f('#', 15, mon, enemy);
    }
}