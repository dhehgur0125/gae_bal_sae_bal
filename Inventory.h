#pragma once
#include <vector>
#include <iostream>
#include "Item.h"
using namespace std;

class Player;

class Inventory {
    vector<Item> items;

public:
    void addItem(const Item& item) {
        for (auto& i : items) {
            if (i.name == item.name) {
                i.count += item.count;
                return;
            }
        }
        items.push_back(item);
    }

    void printInventory() const;

    void use(Player& player);

    bool isEmpty() const {
        return items.empty();
    }
};