/*
DIG3873 Fall 2025
Project: 3
Author: Jenna Besignano
Description: This file contains the Character class, used to store the user-entered trait data. 

 On my honor this is 100% my own work. I did not collaborate with anyone else on this assignment.
 I did not use AI or any type of code generator to write this code nor did I use code snippets
 from another source.
*/

#include "Character.h"
#include <string>
using namespace std;

Character::Character(string r, string p, string pt, int s, int ma){
    race = r;
    profession = p;
    personality_trait = pt;
    strength = s;
    magical_ability = ma;
}
