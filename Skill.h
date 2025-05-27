#pragma once
#include<iostream>
#include<string>
#include"Monster.h"

using namespace std;
void skill_f(char skilltype, double skilldmg, Monster& mon, Monster& enermy);
void bubblebeam(Monster& mon, Monster& enermy);

void fireball(Monster& mon, Monster& enermy);

void grasswhip(Monster& mon, Monster& enermy);

void heal(Monster& mon);