#pragma once
#include <string>

void print_Ascii(void (*artFunc)(std::wstring&));

void AsciiArt(std::wstring& art);
void game_start(std::wstring& art);
void game_over(std::wstring& art);
void monster1_view(std::wstring& art);
void monster2_view(std::wstring& art);
void monster3_view(std::wstring& art);
void enemy_view(std::wstring& art);
void whale_2(std::wstring& art);