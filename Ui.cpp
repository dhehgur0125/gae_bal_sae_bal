#include "UI.h"
#include "board.h"     
#include <conio.h>     
#include <iostream>    
#include <Windows.h>   

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
    std::cout << "스 토 리" << std::endl;
    std::cout << "\n\n\n\n" << std::endl;
    std::cout << "스 킵 하 기" << std::endl;

    _getwch();
    system("cls");
    //스토리는 추후에 추가 할 것.
}

void function_game_over() {
    hideCursor();
    system("cls");

    print_Ascii(game_over);
    std::cout << "게임 종료" << std::endl;

    showCursor();
}