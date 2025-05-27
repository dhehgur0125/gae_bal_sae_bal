#pragma once
#include <string>
using namespace std;

enum class ItemType {
    Heal,
    Buff,
    ManaPotion,
    Revive,
    FullRecover
};

struct Item {
    string name;
    ItemType type;
    int power;
    int count = 1;

    Item(string name, ItemType type, int power, int count = 1)
        : name(name), type(type), power(power), count(count) {
    }
};