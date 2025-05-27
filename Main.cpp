/*#include "UI.h"
#include "Player.h"
#include<Windows.h>
#include <io.h>
#include <fcntl.h>
#include <cstdlib>

int main() {
    // 콘솔 출력 인코딩을 UTF-8로 설정
   // SetConsoleOutputCP(CP_UTF8);
    //_setmode(_fileno(stdout), _O_U8TEXT);
    srand(time(0));

    function_game_start();

    Player player;
    Monster wild("잔디장수풍뎅이", 10, 300, '#', 8, 3, 0, 1);

    while (!wild.isFainted()) {
        if (!player.playerTurn(wild, player)) {
            cout << "\n전투 종료!\n";
            Sleep(3000); // 3000대신 조금 작은 숫자를 사용해야됨
            function_game_over();
            break;
        }

        if (wild.isFainted()) {
            cout << "\n전투 종료!\n";
            Sleep(3000);
            function_game_over();
            break;
        }
        if (player.getActiveMonster().isFainted()) {
            cout << "\n당신의 몬스터가 쓰러졌습니다!\n";

            if (!player.hasAliveMonster()) {
                cout << "사용 가능한 몬스터가 없습니다... 패배했습니다!\n";
                break;
            }

            player.printTeam();

            int newIdx = -1;
            while (true) {
                cout << "교체할 몬스터 번호를 선택하세요: ";
                cin >> newIdx;
                newIdx--;

                if (newIdx >= 0 && newIdx < player.teamSize() &&
                    !player.getMonster(newIdx).isFainted()) {
                    player.switchMonster(newIdx);
                    break;
                }

                cout << "잘못된 선택입니다. 다시 입력하세요.\n";
            }
        }
        Sleep(3000);
        system("cls");
    }
    return 0;
};*/

#include "UI.h"
#include "Player.h"
#include <Windows.h>
#include <cstdlib>
#include <ctime>

void normalStage(Player& player, int stageNum);
void itemOrHealStage(Player& player);
void bossStage(Player& player, int stageNum);

int main() {
    srand(time(0));
    function_game_start();

    Player player;

    for (int stage = 1; stage <= 12; ++stage) {
        cout << "\n===== 스테이지 " << stage << " 시작 =====\n";
        Sleep(1500);

        if (stage % 4 == 0) {
            bossStage(player, stage);
        }
        else if (stage % 4 == 3) {
            itemOrHealStage(player);
        }
        else {
            normalStage(player, stage);
        }

        if (!player.hasAliveMonster()) {
            cout << "모든 몬스터가 기절했습니다. 게임 오버!\n";
            function_game_over();
            return 0;
        }

        cout << "\n스테이지 " << stage << " 클리어!\n";
        player.getActiveMonster().levelUp(); //레벨업 Monster.h 참고
        Sleep(2000);
        system("cls");
    }

    cout << "\n모든 스테이지를 클리어했습니다! 축하합니다!\n";
    return 0;
}

void normalStage(Player& player, int stageNum) {
    Monster enemy("야생몬" + to_string(stageNum), 30 + stageNum * 2, 30 + stageNum * 2, '#', 8, 3, 0, 1);

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
                    player.switchMonster(newIdx);
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
    if (stageNum == 4) bossName = "보스 쥐왕";
    else if (stageNum == 8) bossName = "보스 불곰";
    else bossName = "최종보스 용왕";

    Monster boss(bossName, 45 + stageNum * 3, 45 + stageNum * 3, '@', 12, 2, 0, 2);

    cout << "⚠ 보스 '" << boss.get_name() << "' 등장!\n";

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
                    player.switchMonster(newIdx);
                    break;
                }
                cout << "잘못된 선택입니다. 다시 입력하세요.\n";
            }
        }
        Sleep(2000);
        system("cls");
    }
}