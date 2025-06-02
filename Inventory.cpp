#include "Inventory.h"
#include "Player.h"

using namespace std;

void Inventory::printInventory() const {
    if (items.empty()) {
        cout << "\n[인벤토리] 아이템이 없습니다.\n";
        return;
    }

    cout << "\n[인벤토리]\n";
    for (int i = 0; i < items.size(); ++i) {
        const Item& item = items[i];
        cout << i + 1 << ". " << item.name
            << " (" << item.power << ") x" << item.count << "\n";
    }
    cout << "\n" << "6. 뒤로가기\n";
}

void Inventory::use(Player& player, int choice) {
    if (items.empty()) {
        cout << "\n아이템이 없습니다.\n";
        return;
    }

   

    if (choice < 0 || choice >= items.size()) {
        cout << "잘못된 선택입니다.\n";
        return;
    }

    Item& item = items[choice];
    Monster& mon = player.getActiveMonster();

    switch (item.type) {
    case ItemType::Heal:
        mon.set_hp(mon.get_hp() + item.power);
        if (mon.get_hp() > mon.get_max_hp()) mon.set_hp(mon.get_max_hp());
        cout << "\n" << mon.get_name() << "의 체력이 " << item.power << " 회복되었습니다!\n";
        break;
    case ItemType::Buff:
        mon.set_dmg(mon.get_dmg() + item.power);
        cout << "\n" << mon.get_name() << "의 공격력이 " << item.power << " 증가했습니다!\n";
        break;
    case ItemType::ManaPotion:
        mon.set_mpcost(mon.get_mpcost() + item.power);
        cout << "\n" << mon.get_name() << "의 마나가 " << item.power << "회복되었습니다!\n";
        break;
    case ItemType::Revive: {
        Monster& mon = player.getActiveMonster();
        if (!mon.isFainted()) {
            cout << "\n" << mon.get_name() << "은(는) 기절하지 않았습니다. 사용할 수 없습니다.\n";
            return;
        }
        mon.set_fainted(false);
        mon.set_hp(item.power);
        cout << "\n" << mon.get_name() << "이(가) 기절에서 회복되었습니다! HP: " << mon.get_hp() << "\n";
        break;
    }
    case ItemType::FullRecover: {
        Monster& mon = player.getActiveMonster();
        int hp_gain = 15;
        int mp_gain = 3;
        mon.set_hp(mon.get_hp() + hp_gain);
        if (mon.get_hp() > mon.get_max_hp())
            mon.set_hp(mon.get_max_hp());

        mon.set_mpcost(mon.get_mpcost() + mp_gain);

        std::cout << "\n" << mon.get_name() << "이(가) 종합회복약을 사용했습니다!\n";
        std::cout << "체력이 " << hp_gain << " 회복되고, 마나가 " << mp_gain << " 회복되었습니다!\n";
        break;
    }

    default:
        cout << "\n이 아이템은 전투 중 사용할 수 없습니다.\n";
        return;
    }

    item.count--;
    if (item.count <= 0) {
        items.erase(items.begin() + choice);
    }
}