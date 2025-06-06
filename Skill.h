#pragma once
#include<iostream>
#include<string>
#include"Monster.h"

using namespace std;
void skill_f(char skilltype, double skilldmg, Monster& mon, Monster& enermy);
void bubblebeam(Monster& mon, Monster& enermy);

void fireball(Monster& mon, Monster& enermy);

void grasswhip(Monster& mon, Monster& enermy);

void waterjett(Monster& mon, Monster& enemy);

void tidal_wave(Monster& mon, Monster& enemy);

void blazebeam(Monster& mon, Monster& enemy);

void volcano(Monster& mon, Monster& enemy);

void leaf_knife(Monster& mon, Monster& enemy);

void the_power_of_the_world_tree(Monster& mon, Monster& enemy);
