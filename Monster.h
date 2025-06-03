#pragma once
#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <string>

using namespace std;


class Monster {
    string name;
    double hp;
    char type;
    double dmg;
    int cooltime;
    int level;
    int mpcost;
    bool fainted = false;
    double max_hp;
    int skill[4];
public:
    Monster(string name=0, double hp=0, double max_hp=0, char type=0, double dmg=0, int cooltime=0, int mpcost=0, int level=0) {
        this->name = name;
        this->hp = hp;
        this->type = type;
        this->dmg = dmg;
        this->cooltime = cooltime;
        this->mpcost = mpcost;
        this->max_hp = max_hp;
        this->level = level;
        for (int i = 0; i < 4; i++)
            skill[i] = 0;
    }
    ~Monster() {}
    int get_skill(int i) {
        return skill[i];
    }
    void set_skill() {
        if (level >= 1&& level<4)
            if (type == '@') 
            {
                skill[0] = 10;
            }
            else if (type == '<') skill[0] = 11;
            else skill[0] = 12;
        else if(level >= 4 && level < 8)
        {
            if (type == '@') 
            {
                skill[0] = 10;
                skill[1] = 13;
            }
            else if (type == '<') 
            { 
                skill[0] = 11;
                skill[1] = 14; 
            }
            else
            {
                skill[0] = 12;
                skill[1] = 15;
            }
        }
        else if (level >= 8)
        {
            if (type == '@') 
            {
                skill[0] = 10;
                skill[1] = 13;
                skill[2] = 16;
            }
            else if (type == '<')
            {
                skill[0] = 11;
                skill[1] = 14;
                skill[2] = 17;
            }

            else
            {
                skill[0] = 12;
                skill[1] = 15;
                skill[2] = 18;
            }
        }
    }

    void printSkills() {
        cout << "\n" << "1. 일반 공격\n";
        if (skill[0] == 10) {
            cout << "\n" << "2.  [@] 거품광선 | 마나 요구량 : 5\n";
        }
        else if (skill[0] == 11) {
            cout << "\n" << "2. [<] 불공 | 마나 요구량 : 5\n";
        }
        else if (skill[0] == 12) {
            cout << "\n" << "2. [#] 풀채찍 | 마나 요구량 : 5\n";
        }
        if (skill[1] == 13) {
            cout << "\n" << "3.  [@] 워터 제트 | 마나 요구량 : 5\n";
        }
        else if (skill[1] == 14) {
            cout << "\n" << "3. [<] 블레이즈 빔 | 마나 요구량 : 5\n";
        }
        else if (skill[1] == 15) {
            cout << "\n" << "3. [#] 리프 나이프 | 마나 요구량 : 5\n";
        }
        if (skill[2] == 16) {
            cout << "\n" << "4.  [@] 해일 | 마나 요구량 : 5\n";
        }
        else if (skill[2] == 17) {
            cout << "\n" << "4. [<] 볼케이노 | 마나 요구량 : 5\n";
        }
        else if (skill[2] == 18) {
            cout << "\n" << "4. [#] 세계수의 힘 | 마나 요구량 : 5\n";
        }
        cout << "\n" << "6. 뒤로가기\n";
    }

    void levelUp() { //레벨업
        level++;
        dmg += 5;
        max_hp += 20;
        hp = max_hp;
        cout << name << "의 레벨이 " << level << "이(가) 되었습니다!\n";
        checkEvolution();
    }

    void checkEvolution() { //진화 체크
        if (level >= 4 && name == "계곡고래") {
            name = "폭포고래";
            cout << "★ " << "계곡고래가 폭포고래로 진화했습니다! ★\n";
        }
        if (level >= 4 && name == "용암재떨이") {
            name = "화산잿더미";
            cout << "★ " << "용암재떨이가 화산잿더미로 진화했습니다! ★\n";
        }
        if (level >= 4 && name == "나뭇잎아몬드") {
            name = "수풀아몬드";
            cout << "★ " << "나뭇잎아몬드가 수풀아몬드로 진화했습니다! ★\n";
        }
        if (level >= 8 && name == "폭포고래") {
            name = "해일고래";
            cout << "★ " << "폭포고래가 해일고래로 진화했습니다! ★\n";
        }
        if (level >= 8 && name == "화산잿더미") {
            name = "잿불제왕";
            cout << "★ " << "화산잿더미가 잿불제왕으로 진화했습니다! ★\n";
        }
        if (level >= 8 && name == "수풀아몬드") {
            name = "실바아몬드";
            cout << "★ " << "수풀아몬드가 실바아몬드로 진화했습니다! ★\n";
        }
    }


    bool isFainted() const { return fainted; }
    double get_max_hp() { return max_hp; }
    string get_name() { return name; }
    double get_hp() { return hp; }
    char get_type() { return type; }
    double get_dmg() { return dmg; }
    int get_cooltime() { return cooltime; }
    int get_level() { return level; }
    int get_mpcost() { return mpcost; }

    void set_name(string name) { this->name = name; }
    void set_hp(double hp) { this->hp = hp; }
    void set_type(char type) { this->type = type; }
    void set_dmg(double dmg) { this->dmg = dmg; }
    void set_cooltime(int cooltime) { this->cooltime = cooltime; }
    void set_level(int level) { this->level = level; }
    void set_mpcost(int mpcost) { this->mpcost = mpcost; }
    void set_max_hp(int max_hp) { this->max_hp = max_hp; }
    void set_fainted(bool fainted) { this->fainted = fainted; }

    struct attack1
    {
        char type;
        double damage;
    };
    attack1 attack(Monster& mon) {
        attack1 x;
        if (cooltime == 0)
        {
            x.damage = dmg * 2;
            x.type = this->type;
            if ((type == '@' && mon.type == '<') || (type == '<' && mon.type == '#') || (type == '#' && mon.type == '@'))
            {
                x.damage *= 1.5;
            }
            else if ((type == '@' && mon.type == '#') || (type == '<' && mon.type == '@') || (type == '#' && mon.type == '<'))
            {
                x.damage *= 0.5;
            }
            else if (type == mon.type)
            {
                x.damage *= 1;
            }
            cooltime = 3;
            return x;
        }
        else {
            x.damage = dmg;
            x.type = 'n';
            cooltime -= 1;
            return x;
        }
    }
    Monster& operator=(const Monster& other) {
        if (this == &other) return *this; // 자기 자신과의 대입 방지

        name = other.name;
        hp = other.hp;
        type = other.type;
        dmg = other.dmg;
        cooltime = other.cooltime;
        level = other.level;
        mpcost = other.mpcost;
        fainted = other.fainted;
        max_hp = other.max_hp;
        for (int i = 0; i < 4; i++) {
            skill[i] = other.skill[i];
        }

        return *this;
    }
};