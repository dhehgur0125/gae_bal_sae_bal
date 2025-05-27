#include "Skill.h"

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

void bubblebeam(Monster& mon, Monster& enermy) {

    if (mon.get_mpcost() < 5)
        cout << "마나가 부족합니다!\n공격 실패!\n";
    else
    {
        mon.set_mpcost(mon.get_mpcost() - 5);
        skill_f('@', 5, mon, enermy);
    }

}

void fireball(Monster& mon, Monster& enermy) {
    if (mon.get_mpcost() < 5)
        cout << "마나가 부족합니다!\n공격 실패!\n";
    else
    {
        mon.set_mpcost(mon.get_mpcost() - 5);
        skill_f('<', 5, mon, enermy);
    }
}

void grasswhip(Monster& mon, Monster& enermy) {
    if (mon.get_mpcost() < 5)
        cout << "마나가 부족합니다!\n공격 실패!\n";
    else
    {
        mon.set_mpcost(mon.get_mpcost() - 5);
        skill_f('#', 5, mon, enermy);
    }

}

void heal(Monster& mon) {
    mon.set_hp(mon.get_hp() + 10);
}