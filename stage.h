#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
#include "Monster.h"
#include "Player.h"
#include "Item.h"
using namespace std;

enum class StageType {
    Normal,
    Boss,
    Heal,
    Item
};

class Stage {
    int step;
    bool isCleared;
    StageType type;

public:
    Stage(int step, StageType type = StageType::Normal)
        : step(step), isCleared(false), type(type) {
    }

    int get_step() const { return step; }
    bool get_isCleared() const { return isCleared; }
    StageType get_type() const { return type; }

    void set_step(int s) { step = s; }
    void set_isCleared(bool cleared) { isCleared = cleared; }
    void set_type(StageType t) { type = t; }

    Monster generateEnemy() {
        double multiplier = (type == StageType::Boss) ? 1.3 : 1.1;
        int hp = static_cast<int>(100 * step * multiplier);
        int dmg = static_cast<int>(20 * step * multiplier);
        char symbol = (type == StageType::Boss) ? 'B' : 'E';

        Monster enemy("적 몬스터", hp, dmg, symbol, 10, 0, 0, step);
        enemy.set_skill();
        return enemy;
    }

    void healStage(Player& player) {
        cout << "\n[힐 스테이지] 아군 몬스터들의 체력이 회복됩니다!\n";
        for (int i = 0; i < player.teamSize(); ++i) {
            Monster& mon = player.getMonster(i);
            if (!mon.isFainted()) {
                int healed = static_cast<int>(mon.get_max_hp() * 0.3);
                mon.set_hp(min(mon.get_hp() + healed, mon.get_max_hp()));
                cout << mon.get_name() << " 회복: " << healed << " → 현재 체력: " << mon.get_hp() << "\n";
            }
        }
    }

    void giveItem(Player& player) {
        cout << "\n[아이템 스테이지] 아이템을 획득합니다!\n";

        vector<Item> itemPool = {
            Item("상처약", ItemType::Heal, 20, 1),
            Item("하급 힘의알", ItemType::Buff, 5, 1)
        };

        int index = rand() % itemPool.size();
        Item item = itemPool[index];
        player.getInventory().addItem(item);

        cout << "획득한 아이템: " << item.name << "\n";
    }
};