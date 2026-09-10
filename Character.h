/*
DIG3873 Fall 2025
Project: 3
Author: Jenna Besignano
Description: This is the header file for Character.cpp. 

 On my honor this is 100% my own work. I did not collaborate with anyone else on this assignment.
 I did not use AI or any type of code generator to write this code nor did I use code snippets
 from another source.
*/

#ifndef CHARACTER_H
#define CHARACTER_H
#include <string>
using namespace std;

class Character{
public:
    string race;
    string profession;
    string personality_trait;
    int strength;
    int magical_ability;
    Character(string r, string p, string pt, int s, int ma);
};

#endif

