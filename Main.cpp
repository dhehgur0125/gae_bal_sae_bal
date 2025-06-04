#include "UI.h"
#include "Player.h"
#include <Windows.h>
#include <cstdlib>
#include <ctime>

using namespace std;

void normalStage(Player& player, int stageNum);
void itemOrHealStage(Player& player);
void bossStage(Player& player, int stageNum);
void restStage(Player& player, int stageNum);

int main() {
    srand(time(0));
    function_game_start();

    Player player;
    string stage_name = "암흑의 숲";
    for (int stage = 1; stage <= 15; ++stage) {
        if (stage <= 5)
            stage_name = "암흑의 숲";
        else if (stage > 5 && stage <= 10)
            stage_name = "더러워진 바닷가";
        else
            stage_name = "시공간이 일그러진 바위산";
        cout << "\n===== " << stage_name<<"  ||  스테이지 " << stage << " 시작 ===== \n";
        Sleep(1500);

        if (stage % 5 == 0) {
            bossStage(player, stage);
        }
        else if (stage % 5 == 4 && stage != 1 && stage != 6 && stage != 11) {
            itemOrHealStage(player);
        }
        else if (stage % 5 == 1)
        {
            restStage(player, stage);
        }
        else {
            normalStage(player, stage);
        }

        if (!player.hasAliveMonster()) {
            cout << "모든 몬스터가 기절했습니다. \n";
            Sleep(1500);

            int recoveryStage = 1;
            if (stage >= 1 && stage <= 5)
                recoveryStage = 1;
            else if (stage >= 6 && stage <= 10)
                recoveryStage = 6;
            else
                recoveryStage = 11;

            cout << "⚡ 회복 스테이지(" << recoveryStage << ")로 이동합니다...\n";
            Sleep(1500);
            restStage(player, recoveryStage);

            if (!player.hasAliveMonster()) {
                cout << "기적은 일어나지 않았습니다... 게임 오버!\n";
                function_game_over();
                return 0;
            }

            if (stage <= 5) {
                Sleep(2000);
                stage = 1; // → 다음 루프에서 ++되어 1부터 다시 시작됨
            }
            else if (stage >= 6 && stage <= 10)
            {
                Sleep(2000);
                stage = 7;
            }
            else
            {
                Sleep(2000);
                stage = 12;
            }

            continue;
        }

        cout << "\n===== " << stage_name << "  ||  스테이지 " << stage << " 클리어!\n";
        if (player.get_run() == true || stage == 1 || stage == 4 || stage == 6 || stage == 9 || stage == 11 || stage == 14) 
        { 
            player.set_run(false);
        }
        else 
        {
            player.getActiveMonster().levelUp(); 
        } //레벨업 Monster.h 참고
        Sleep(2000);
        system("cls");
    }

    cout << "\n모든 스테이지를 클리어했습니다! 축하합니다!\n";
    return 0;
}

void normalStage(Player& player, int stageNum) {
    // Monster(string name, double hp, double max_hp, char type, double dmg, int cooltime, int mpcost, int level)
    Monster enemy("0",0,0,0,0,0,0,0);
    if (stageNum <= 4)
    {
        if (rand() % 3 == 0)
        {
            Monster enemy_1("슬라임", 30 + stageNum * 2, 30 + stageNum * 2, '<', 8, 3, 0, 1);
            enemy = enemy_1;
        }
        else if (rand() % 3 == 1)
        {
            Monster enemy_2("스파크레인", 30 + stageNum * 2, 30 + stageNum * 2, '#', 8, 3, 0, 1);
            enemy = enemy_2;
        } 
        else
        {
            Monster enemy_3("스파키", 30 + stageNum * 2, 30 + stageNum * 2, '@', 8, 3, 0, 1);
            enemy = enemy_3;
        }
    }
    else if (stageNum > 4 && stageNum <= 8)
    {
        if (rand() % 3 == 0)
        {
            Monster enemy_4("아이언클래드", 50 + stageNum * 2, 50 + stageNum * 2, '@', 14, 3, 0, 1);
            enemy = enemy_4;
        }
        else if (rand() % 3 == 1)
        {
            Monster enemy_5("파이로스", 50 + stageNum * 2, 50 + stageNum * 2, '#', 14, 3, 0, 1);
            enemy = enemy_5;
        }
        else
        {
            Monster enemy_6("네오스", 50 + stageNum * 2, 50 + stageNum * 2, '<', 14, 3, 0, 1);
            enemy = enemy_6;
        }
    }
    else if (stageNum > 8 && stageNum <= 12)
    {
        if (rand() % 3 == 0)
        {
            Monster enemy_7("사이버론", 70 + stageNum * 2, 70 + stageNum * 2, '#', 20, 3, 0,1);
            enemy = enemy_7;
        }
        else if (rand() % 3 == 1)
        {
            Monster enemy_8("엘리시온", 70 + stageNum * 2, 70 + stageNum * 2, '<', 20, 3, 0, 1);
            enemy = enemy_8;
        }
        else
        {
            Monster enemy_9("라이트닝쉐도우", 70 + stageNum * 2, 70 + stageNum * 2, '@', 20, 3, 0, 1);
            enemy = enemy_9;
        }
    }
   //Monster enemy("야생몬" + to_string(stageNum), 30 + stageNum * 2, 30 + stageNum * 2, '#', 8, 3, 0, 1);

    while (!enemy.isFainted()) {
        if (!player.playerTurn(enemy, player)) return;
        if (player.getActiveMonster().isFainted()) {
            if (!player.hasAliveMonster()) return;
            player.printTeam();

            int newIdx;
            while (true) {
                cout << "교체할 몬스터 번호를 선택하세요: ";
                cin >> newIdx;
                --newIdx;

                if (newIdx >= 0 && newIdx < player.teamSize() &&
                    !player.getMonster(newIdx).isFainted()) {
                    player.switchMonster(newIdx, enemy, player);
                    break;
                }
                cout << "잘못된 선택입니다. 다시 입력하세요.\n";
            }
        }
        Sleep(1500);
        system("cls");
    }
}

void itemOrHealStage(Player& player) {
    int choice = rand() % 2;

    if (choice == 0) {
        std::cout << "🔹 아이템 획득 스테이지!\n";

        std::vector<Item> rewardPool = {
            Item("상처약", ItemType::Heal, 20),
            Item("힘의알", ItemType::Buff, 5),
            Item("마나물약", ItemType::ManaPotion, 5),
            Item("기력의돌", ItemType::Revive, 8),
            Item("종합회복약", ItemType::FullRecover, 15)
        };

        int index = rand() % rewardPool.size();
        Item reward = rewardPool[index];

        player.getInventory().addItem(reward);
        std::cout << "아이템 '" << reward.name << "'을(를) 얻었습니다!\n";
    }
    else {
        cout << "🔹 힐 스테이지! 모든 몬스터가 회복됩니다.\n";
        for (int i = 0; i < player.teamSize(); ++i) {
            auto& mon = player.getMonster(i);
            mon.set_hp(mon.get_max_hp());
            mon.set_fainted(false);
        }
        cout << "모든 몬스터가 회복되었습니다!\n";
    }

    Sleep(2000);
}

void bossStage(Player& player, int stageNum) {
    string bossName;
    if (stageNum == 4) bossName = "미카엘";
    else if (stageNum == 8) bossName = "루시퍼";
    else bossName = "메카트론";

    Monster boss(bossName, 45 + stageNum * 3, 45 + stageNum * 3, '@', 12, 2, 0, 2);

    cout << "WARNING!!! 보스 '" << boss.get_name() << "' 등장!\n";

    while (!boss.isFainted()) {
        if (!player.playerTurn(boss, player)) return;

        if (player.getActiveMonster().isFainted()) {
            if (!player.hasAliveMonster()) return;
            player.printTeam();

            int newIdx;
            while (true) {
                cout << "교체할 몬스터 번호를 선택하세요: ";
                cin >> newIdx;
                --newIdx;

                if (newIdx >= 0 && newIdx < player.teamSize() &&
                    !player.getMonster(newIdx).isFainted()) {
                    player.switchMonster(newIdx, boss, player);
                    break;
                }
                cout << "잘못된 선택입니다. 다시 입력하세요.\n";
            }
        }
        Sleep(2000);
        system("cls");
    }
}

void restStage(Player& player, int stageNum) {
    cout << "\n⚡ 기적의 쉼터에 도착했습니다...\n";
    Sleep(1500);
    cout << "찬란한 빛이 아군 몬스터들을 감쌉니다...\n";
    Sleep(1500);

    bool anyRevived = false;

    for (int i = 0; i < player.teamSize(); ++i) {
        Monster& mon = player.getMonster(i);
        if (mon.isFainted()) {
            mon.set_hp(mon.get_max_hp());         // 체력 100% 회복
            mon.set_fainted(false);               // 기절 상태 해제
            anyRevived = true;

            cout << "✨ " << mon.get_name() << "이(가) 완전히 회복되었습니다! (HP: "
                << (int)mon.get_max_hp() << "/" << (int)mon.get_max_hp() << ")\n";
            Sleep(1000);
        }
    }

    if (anyRevived) {
        cout << "\n모든 몬스터가 기적적으로 완전히 회복되었습니다! 다시 싸울 준비가 되었습니다!\n";
    }
    else {
        cout << "모든 몬스터가 이미 살아 있습니다. 회복할 필요가 없습니다.\n";
    }
    Sleep(2000);
}