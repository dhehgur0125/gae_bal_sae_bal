#include "UI.h"
#include "board.h"     
#include <conio.h>     
#include <iostream>    
#include <Windows.h> 
#include<vector>
#include<thread>
#include<chrono>

void hideCursor() {
    HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_CURSOR_INFO cursorInfo;
    GetConsoleCursorInfo(hOut, &cursorInfo);
    cursorInfo.bVisible = FALSE;
    SetConsoleCursorInfo(hOut, &cursorInfo);
}

void showCursor() {
    HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_CURSOR_INFO cursorInfo;
    GetConsoleCursorInfo(hOut, &cursorInfo);
    cursorInfo.bVisible = TRUE;
    SetConsoleCursorInfo(hOut, &cursorInfo);
}

void function_game_start() {
    hideCursor();

    print_Ascii(game_start);
    std::cout << "[ 아무 키나 누르면 게임을 시작합니다.. ]";
    _getwch();  // 콘솔 입력 대기
    system("cls");

    function_story();
    /*_getwch();
    system("cls");*/

    showCursor();
}

void function_story() {
    std::vector<std::string> story_lines = {
        "어느 평화로운 날, 작은 마을 아스키월드는 아름다운 자연과 따뜻한 사람들이 가득 차 있었습니다.",
        "푸른 숲과 맑은 강, 그리고 친근한 이웃들이 어우러져 조용하고 평화로운 일상을 보내고 있었죠.",
        "마을 사람들은 서로를 돕고, 함께 웃으며 행복한 나날을 보내고 있었습니다.",
        "하지만 그 평화는 오래가지 못했습니다.",
        "어느 날, 하늘이 어둠에 잠기고, 알 수 없는 이유로 난폭해진 아스키 몬스터들이 나타나기 시작했습니다.",
        "이 몬스터들은 평소보다 훨씬 난폭해지고, 공격성이 강해졌으며, 마을을 파괴하고 사람들을 두려움에 떨게 만들기 시작했죠.",
        "마을 사람들은 힘을 모아 몬스터들과 맞서 싸우려 했지만, 그들의 힘만으로는 역부족이었습니다.",
        "이때, 아직 어린 아스키몬들이 등장합니다.",
        "이들은 아직 미성숙하고 약하지만, 앞으로 성장하며 함께 힘을 합칠 가능성을 품고 있습니다.",
        "마을을 지키기 위해, 그리고 점차 강해지기 위해, 이 작은 영웅들을 모아야 합니다.",
        "이제, 당신은 이 미성숙한 아스키몬들과 함께, 아스키월드를 구하는 여정을 시작하게 됩니다.",
        "첫 번째 목표는 몬스터들이 가장 먼저 침입한 '어둠의 숲'입니다.",
        "이곳에서 펼쳐질 전투는, 포켓로그와 유사한 시스템으로 진행됩니다.",
        "기본 공격과 고유 스킬을 전략적으로 사용하고, 아이템으로 체력을 회복하거나 공격력을 강화하며 몬스터들을 물리쳐야 합니다.",
        "당신의 선택과 용기, 그리고 지혜가 이 이야기를 결정짓습니다.",
        "아스키월드를 지키기 위한 첫 걸음을 내딛어 주세요!"
    };

    std::cout << "[스토리 중 아무 키나 누르면 스킵됩니다...]\n" << std::endl;

    for (const auto& line : story_lines) {
        std::cout << line << std::endl;

        // 3초 동안 키 입력 대기, 0.1초 단위로 체크
        for (int i = 0; i < 30; ++i) {
            if (_kbhit()) {
                _getwch(); // 남아있는 키 입력 제거
                std::cout << "\n[스토리 스킵됨]\n" << std::endl;
                goto skip_story;
            }
            std::this_thread::sleep_for(std::chrono::milliseconds(100));
        }
    }

skip_story:
    std::cout << "\n\n\n\n";
    std::cout << "계속하려면 아무 키나 누르세요..." << std::endl;

    _getwch();
    system("cls");
}

/*void function_story() {
    std::cout << "﻿어느 평화로운 날, 작은 마을 아스키월드는 아름다운 자연과 따뜻한 사람들이 가득 차 있었습니다. 푸른 숲과 맑은 강, 그리고 친근한 이웃들이 어우러져 조용하고 평화로운 일상을 보내고 있었죠. 마을 사람들은 서로를 돕고, 함께 웃으며 행복한 나날을 보내고 있었습니다. \n하지만 그 평화는 오래가지 못했습니다.어느 날, 하늘이 어둠에 잠기고, 알 수 없는 이유로 난폭해진 아스키 몬스터들이 나타나기 시작했습니다.이 몬스터들은 평소보다 훨씬 난폭해지고, 공격성이 강해졌으며, 마을을 파괴하고 사람들을 두려움에 떨게 만들기 시작했죠.마을 사람들은 힘을 모아 몬스터들과 맞서 싸우려 했지만, 그들의 힘만으로는 역부족이었습니다.\n이때, 아직 어린 아스키몬들이 등장합니다.이들은 아직 미성숙하고 약하지만, 앞으로 성장 함께 힘할 가능성을 품고 있습니다.마을을 지키기 위해, 그리고 점차 강해지기 위해, 이 작은 영웅들은을 모아야 합니다.\n이제, 당신은 이 미성숙한 아스키몬들과 함께, 아스키월드를 구하는 여정을 시작하게 됩니다.첫 번째 목표는 몬스터들이 가장 먼저 침입한** '어둠의 숲' * *입니다.이곳에서 펼쳐질 전투는, 포켓로그와 유사한 시스템으로 진행됩니다.기본 공격과 고유 스킬을 전략적으로 사용하고, 아이템으로 체력을 회복하거나 공격력을 강화하며 몬스터들을 물리쳐야 합니다.\n당신의 선택과 용기, 그리고 지혜가 이 이야기를 결정짓습니다.아스키월드를 지키기 위한 첫 걸음을 내딛어 주세요!" << std::endl;
    std::cout << "\n\n\n\n" << std::endl;
    std::cout << "스 킵 하 기" << std::endl;

    _getwch();
    system("cls");
    //스토리는 추후에 추가 할 것.
}*/

void function_game_over() {
    hideCursor();
    system("cls");

    print_Ascii(game_over);
    std::cout << "게임 종료" << std::endl;

    showCursor();
}