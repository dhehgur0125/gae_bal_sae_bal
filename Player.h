#pragma once
#include <iostream>
#include <vector>
#include <string>
#include "Skill.h"
#include "Item.h"
#include "Inventory.h"
#include "board.h"
#include <Windows.h>

using namespace std;

class Player{
    vector<Monster> team;
    Inventory inventory;
    int active_index = 0;
    bool run = false;
public:
    Player() {
        Monster mon1 = Monster("계곡고래", 3500, 3500, '@', 120, 0, 10, 10);
        mon1.set_skill();
        team.push_back(mon1);
        Monster mon2 = Monster("용암재떨이", 3900, 3900, '<', 100, 0, 10, 10);
        mon2.set_skill();
        team.push_back(mon2);
        Monster mon3 = Monster("나뭇잎아몬드", 3900, 3900, '#', 100, 0, 10, 10);
        mon3.set_skill();
        team.push_back(mon3);

        inventory.addItem(Item("상처약", ItemType::Heal, 20, 3));
        inventory.addItem(Item("힘의알", ItemType::Buff, 5, 1));
    }

    void set_run(bool run)
    {
        this->run = run;
    }

    bool get_run()
    {
        return run;
    }

    Monster& getActiveMonster() {
        return team[active_index];
    }

    void printActiveMonsterStatus() {
        Monster& mon = getActiveMonster();

        if (mon.get_type() == '@')
        {
            if(mon.get_name() == "계곡고래")
                print_Ascii(whale_1);
            else if (mon.get_name() == "폭포고래")
                print_Ascii(whale_2);
            else if (mon.get_name() == "해일고래")
                print_Ascii(whale_3);
        }
        else if (mon.get_type() == '#')
        {
            if (mon.get_name() == "나뭇잎아몬드")
                print_Ascii(almond_1);
            else if (mon.get_name() == "수풀아몬드")
                print_Ascii(almond_2);
            else if (mon.get_name() == "실바아몬드")
                print_Ascii(almond_3);
        }
        else if (mon.get_type() == '<')
        {
            if (mon.get_name() == "용암재떨이")
                print_Ascii(ashtray_1);
            else if (mon.get_name() == "화산잿더미")
                print_Ascii(ashtray_2);
            else if (mon.get_name() == "잿불제왕")
                print_Ascii(ashtray_3);
        }
            

        cout << "\n[현재 몬스터 상태]\n";
        cout << "[" << mon.get_type() << "] ";

        cout << mon.get_name() << " | HP: " << mon.get_hp() << " / " << mon.get_max_hp();
        cout << " | 공격력: " << mon.get_dmg();
        cout << " | 마나: " << mon.get_mpcost();
        cout << " | 레벨: " << mon.get_level() << "\n";
        cout << endl;
    }


    void printEnemyStatus(Monster& enemy) {
        if (enemy.get_name() == "스파키")
        {
            print_Ascii(sparky);
        }
        else if (enemy.get_name() == "슬라임")
        {
            print_Ascii(slime);
        }
        else if (enemy.get_name() == "스파크레인")
        {
            print_Ascii(sparkrain);
        }
        else if (enemy.get_name() == "미카엘")
        {
            print_Ascii(micael);
        }
        else if (enemy.get_name() == "아이언클래드")
        {
            print_Ascii(ironcled);
        }
        else if (enemy.get_name() == "파이로스")
        {
            print_Ascii(piros);
        }
        else if (enemy.get_name() == "네오스")
        {
            print_Ascii(neos);
        }
        else if (enemy.get_name() == "루시퍼")
        {
            print_Ascii(lusiper);
        }
        else if (enemy.get_name() == "사이버론")
        {
            print_Ascii(ciberon);
        }
        else if (enemy.get_name() == "엘리시온")
        {
            print_Ascii(elision);
        }
        else if (enemy.get_name() == "라이트닝쉐도우")
        {
            print_Ascii(lightningshadow);
        }
        else if (enemy.get_name() == "메카트론")
        {
            print_Ascii(mekatron);
        }
        else
        {
            print_Ascii(enemy_view);
        }
        cout << "\n[상대 몬스터 상태]\n";
        cout << "[" << enemy.get_type() << "] ";
        cout << enemy.get_name() << " | HP: " << enemy.get_hp() << " / " << enemy.get_max_hp();
        cout << " | 공격력: " << enemy.get_dmg();
        cout << " | 속성공격 까지 남은 공격: " << enemy.get_cooltime();
        cout << " | 레벨: " << enemy.get_level() << "\n";
    }

    void commandAttack(Monster& enemy, Player& player) {
        auto& mon = getActiveMonster();
        mon.set_skill();
        if (mon.isFainted()) {
            cout << mon.get_name() << "은(는) 기절했습니다. 공격할 수 없습니다.\n";
            return;
        }
        mon.set_skill();
        cout << "\n" << mon.get_name() << "의 스킬 목록:\n";
        mon.printSkills();
        cout << "\n";

        int choice;
        cout << "사용할 스킬 번호를 입력하세요: ";
        cin >> choice;
        for (int i = 2; i < 6; i++)
        {
            if (choice == i)
            {
                choice = mon.get_skill(i - 2);
            }
        }
        if (choice == 6)
        {
            system("cls");
            playerTurn(enemy, player);
        }
        useSkill(choice, mon, enemy);
    }

    void switchMonster(int index, Monster& enemy, Player& player) {

        if (index == 3)
        {
            system("cls");
            playerTurn(enemy, player);
        }
        if (index < 0 || index >= team.size()) {
            cout << "\n" << "잘못된 몬스터 번호입니다.\n";
            Sleep(1500);
            system("cls");
            playerTurn(enemy, player);
        }

        if (team[index].isFainted()) {
            cout << "\n" << "해당 몬스터는 기절했습니다.\n";
            Sleep(1500);
            system("cls");
            playerTurn(enemy, player);
        }
        if (active_index == index)
        {
            cout << "\n이미 출전 중입니다.\n";
            Sleep(1500);
            system("cls");
            playerTurn(enemy, player);
        }

        active_index = index;
        cout << "\n" << team[active_index].get_name() << "을(를) 내보냈습니다!\n";
    }

    bool playerTurn(Monster& enemy, Player& player) {
        printActiveMonsterStatus();
        printEnemyStatus(enemy);
        int cmd;
        while (true) {
            printActionMenu();
            cin >> cmd;
            if (cmd >= 1 && cmd <= 4) break;
            cout << "\n" << "잘못된 입력입니다. 다시 선택하세요.\n";
        }
        return executeCommand(cmd, enemy, player);
    }

    bool executeCommand(int cmd, Monster& enemy, Player& player) {
        switch (cmd) {
        case 1:
            commandAttack(enemy, player);
            break;
        case 2:
            useItem(enemy, player);
            break;
        case 3: {
            printTeam();
            int idx;
            cout << "\n" << "교체할 몬스터 번호를 입력하세요: ";
            cin >> idx;
            switchMonster(idx - 1, enemy, player);
            break;
        }
        case 4:
            if (attemptEscape()) {
                cout << "\n" << "도망에 성공했습니다!\n";
                run = true;
                return false;
            }
            else {
                cout << "\n" << "도망에 실패했습니다!\n";
            }
            break;
        default:
            cout << "\n" << "잘못된 입력입니다.\n";
            break;
        }
        enemyTurn(enemy, player);
        return true;
    }

    void enemyTurn(Monster& enemy, Player& player) {
        if (enemy.isFainted()) {
            cout << enemy.get_name() << "은(는) 기절해 행동할 수 없습니다.\n";
            return;
        }

        Monster& target = player.getActiveMonster();

        cout << "\n야생 " << enemy.get_name() << "의 차례입니다!\n";
        auto atk = enemy.attack(target);

        target.set_hp(target.get_hp() - atk.damage);
        if (target.get_hp() <= 0) {
            target.set_hp(0);
            target.set_fainted(true);
            cout << target.get_name() << "이(가) 기절했습니다!\n";
        }

        cout << enemy.get_name() << "의 공격! ";
        if (atk.type == 'n')
            cout << "일반 공격으로 ";
        else
            cout << atk.type << " 속성 스킬로 ";

        cout << atk.damage << "의 데미지를 입혔습니다! (남은 체력: " << target.get_hp() << ")\n";
    }

    void printActionMenu() {
        cout << "\n===== 행동 선택 =====\n";
        cout << "1. 공격\n";
        cout << "2. 아이템 사용\n";
        cout << "3. 몬스터 교체\n";
        cout << "4. 도망\n";
        cout << "=====================\n";
        cout << "명령을 선택하세요: ";
    }

    void printTeam() {
        cout << "\n[보유 몬스터 목록]\n";
        for (int i = 0; i < team.size(); ++i) {
            Monster& mon = team[i];
            cout << i + 1 << ". " << "[" << mon.get_type() << "] " << mon.get_name()
                << " | HP: " << mon.get_hp() << " / " << mon.get_max_hp()<< " | 레벨:" << mon.get_level();
            if (i == active_index) cout << "  (전투 중)";
            if (mon.isFainted()) cout << "  [기절]";
            cout << "\n";
        }
        cout << "\n" << "4. 뒤로가기\n";
    }

    bool attemptEscape() {
        int chance = rand() % 100;
        return chance < 50;
    }

    void useSkill(int index, Monster& mon, Monster& target) {
        if (index == 1) {
            cout << "\n" << mon.get_name() << "의 일반 공격!\n";
            mon.set_mpcost(mon.get_mpcost() + 1);
            takeDamage(mon.get_dmg(), index, mon, target);
        }
        else if (index == 10) {
            cout << "\n" << mon.get_name() << "의 거품광선!\n";
            takeDamage(mon.get_dmg(), index, mon, target);
        }
        else if (index == 11) {
            cout << "\n" << mon.get_name() << "의 불공!\n";
            takeDamage(mon.get_dmg(), index, mon, target);
        }
        else if (index == 12) {
            cout << "\n" << mon.get_name() << "의 풀채찍!\n";
            takeDamage(mon.get_dmg(), index, mon, target);
        }
        else if (index == 13) {
            cout << "\n" << mon.get_name() << "의 워터 제트!!\n";
            takeDamage(mon.get_dmg(), index, mon, target);
        }
        else if (index == 14) {
            cout << "\n" << mon.get_name() << "의 블레이즈 빔!!\n";
            takeDamage(mon.get_dmg(), index, mon, target);
        }
        else if (index == 15) {
            cout << "\n" << mon.get_name() << "의 리프 나이프!!\n";
            takeDamage(mon.get_dmg(), index, mon, target);
        }
        else if (index == 16) {
            cout << "\n" << mon.get_name() << "의 해일!!!\n";
            takeDamage(mon.get_dmg(), index, mon, target);
        }
        else if (index == 17) {
            cout << "\n" << mon.get_name() << "의 볼케이노!!!\n";
            takeDamage(mon.get_dmg(), index, mon, target);
        }
        else if (index == 18) {
            cout << "\n" << mon.get_name() << "의 세계수의 힘!!!\n";
            takeDamage(mon.get_dmg(), index, mon, target);
        }
    }

    void takeDamage(int dmg, int skillnum, Monster& mon, Monster& target) {
        double origin_hp = target.get_hp();
        if (skillnum == 1) {
            target.set_hp(target.get_hp() - dmg);
        }
        else if (skillnum == 10) {
            bubblebeam(mon, target);
        }
        else if (skillnum == 11) {
            fireball(mon, target);
        }
        else if (skillnum == 12) {
            grasswhip(mon, target);
        }
        else if (skillnum == 13) {
            waterjett(mon, target);
        }
        else if (skillnum == 14) {
            blazebeam(mon, target);
        }
        else if (skillnum == 15) {
            leaf_knife(mon, target);
        }
        else if (skillnum == 16) {
            tidal_wave(mon, target);
        }
        else if (skillnum == 17) {
            volcano(mon, target);
        }
        else if (skillnum == 18) {
            the_power_of_the_world_tree(mon, target);
        }

        if (target.get_hp() <= 0) {
            target.set_hp(0);
            target.set_fainted(true);
            cout << "\n" << target.get_name() << "이(가) 기절했습니다!\n";
        }
        else {
            cout << "\n" << target.get_name() << "이(가) " << origin_hp - target.get_hp() << "의 데미지를 입었습니다! (남은 체력: " << target.get_hp() << ")\n";
        }
    }
    bool hasAliveMonster() {
        for (auto& mon : team) {
            if (!mon.isFainted()) return true;
        }
        return false;
    }

    Monster& getMonster(int index) {
        return team[index];
    }

    int teamSize() const {
        return team.size();
    }
    void printInventory() {
        inventory.printInventory();
    }
    void useItem(Monster& enemy, Player& player) {
        int choice;
        printInventory();
        cout << "\n사용할 아이템 번호를 선택하세요: ";
        cin >> choice;
        choice--;
        if (choice == 5)
        {
            system("cls");
            playerTurn(enemy, player);
        }
        inventory.use(*this, choice);
    }
    Inventory& getInventory() {
        return inventory;
    }
};