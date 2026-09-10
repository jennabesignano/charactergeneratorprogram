/*
DIG3873 Fall 2025
Project: 3
Author: Jenna Besignano
Description: This file contains majority of my logic, which allows for the running of a main menu and character database menu. All of my global variables and functions are within this file. The main menu allows users to add traits to the database, display the user-entered traits, generate a list of characters based on user entered traits, print the generated list of characters, and quit the program. The character trait database menu allows users to add races, professions, and personality traits to the Character traits database.  

 On my honor this is 100% my own work. I did not collaborate with anyone else on this assignment.
 I did not use AI or any type of code generator to write this code nor did I use code snippets
 from another source.
*/

#include <iostream>
#include <string>
#include <vector>
#include <ctime>
#include "Character.h"
using namespace std;

vector<vector<string>> traits(3);
vector<Character> characters;
string selection[3] = {"Race", "Profession", "Personality trait"};

void seedRandomNumber(){
    srand((unsigned)time(0));
}
//function that returns a random number between 0 and the max.
int randomMaxNumber(int max){
    int randomNumber = rand() % max;
    return randomNumber;
}
//function that adds the sum of the random dice rolls.
int randomNumber(){
    return (rand() % 6 + 1) + (rand() % 6 + 1) + (rand() % 6 + 1);
}
//function that checks to make sure the string is an integer.
bool isInteger(string str){
   bool validInt= true;
    if (str.length() == 0)
        validInt= false;

    for (size_t i = 0; i < str.length() && validInt; i++){
        char c = str[i];
        if (c < '0' || c > '9'){
            validInt = false;
        }
    }
    return validInt;
}
//function that converts strings to integer values.
int stringToInt(string str){
    int num = 0;
    for (size_t i = 0; i < str.length(); i++){
        num = num * 10 + (str[i] - '0');
    }
    return num;
}
//function that prompts user to enter an integer that is between the minimum and maximum, then validates the input. Also handles separator formatting.
int getNumberBetween(int min, int max, string question){
    int temp;
    bool valid = false;
    do{
        cout << question << "[" << min << " - " << max << "]: ";
        string temporary;
        cin >> temporary;

        if (isInteger(temporary)){
            temp = stringToInt(temporary);

            if (temp >= min && temp <= max){
            if(temp !=5){
                    if(question == "Please make a selection: " && temp == 4){

                    }
                    else{
                        cout << "============================================================" << endl;
                    }
            }
                valid = true;
            }
            else{
                cout << "Please enter an integer value within the range " << min << " to " << max << endl;
            }
        }
        else{
            cin.clear();
            cin.ignore(50, '\n');

            cout << "Please enter an integer value within the range " << min << " to " << max << endl;
        }
    } 
    while (!valid);
    return temp;
}

//function that asks the user to enter a POSITIVE integer, then validates if the user did so. 
int getNumber(string question){
    int temp;
    bool valid = false;
    do{
        cout << question;
        string temporary;
        cin >> temporary;
        if (isInteger(temporary)){
            temp = stringToInt(temporary);
            if (temp > 0){
                valid = true;
            }
            else{
                cout << "Please enter a positive integer" << endl;
            }
        }
        else{
            cin.clear();
            cin.ignore(50, '\n');
            cout << "Please enter a positive integer" << endl;
        }
    } while (!valid);
    return temp;
}

//makes a string uppercase.
string toUpperCase(string s){
    for (long unsigned int i = 0; i < s.length(); i++){
        s[i] = toupper(s[i]);
    }
    return s;
}

//function to check if the string is in the specified section of the database, returns a true or false (true if the string has already been entered in the database before).
bool findInVector(int section, string item){
    long unsigned int i = 0;
    bool found = false;
    while (i < traits[section - 1].size()){
        if (toUpperCase(traits[section - 1][i]) == toUpperCase(item)){
            found = true;
        }
        i++;
    }
    return found;
}

//Function that lets the user enter multiple strings within each trait category until the user types quit. Makes sure Quit is not case sensitive.
void getString(string question, int section){
    bool badInput = true;
    string rtn;
    cin.ignore(50, '\n');
    while (badInput){
        cout << question;
        string temp;

        getline(cin, temp);
        if (toUpperCase(temp) == "QUIT"){
            cout << "============================================================" << endl;
            badInput = false;
        }
        else{
            if (findInVector(section, temp)){
                cout << "Cannot add duplicate name: " << temp << endl;
            }
            else{
                traits[section - 1].push_back(temp);
            }
        }
    }
}
//Displays character traits database menu
void addTrait(){

    int temp = 0;

    while (temp != 4){
        cout << "ADD CHARACTER TRAITS TO DATABASE" << endl;
        cout << "[1] Add races" << endl;
        cout << "[2] Add professions" << endl;
        cout << "[3] Add personality traits" << endl;
        cout << "[4] Return to main menu" << endl;
        cout << endl;
        temp = getNumberBetween(1, 4, "What would you like to do? ");
        if (temp != 4){
            getString("Enter a new " + selection[temp - 1] + " or enter QUIT when done: ", temp);
        }
    }
}

// Function for formatting the string spacing
string repeatString(string str, int times){
    string result = "";
    for (int i = 0; i < times; i++){
        result += str;
    }
    return result;
}

//This function takes the input from the main function and implements it. Input 1 runs the addTrait function, input 2 prints a formatted database, input 3 generates a list of new characters, and input 4 prints the formatted generated list of characters. 
void menu(int input){
    //add new character traits
    if (input == 1){
        addTrait();
    }
    //print character trait database
    else if (input == 2){
        cout << "DATABASE OF CHARACTER TRAITS" << endl;
        cout << "------------------------------------------------------------" << endl;
        cout << "Races:" << endl;
        for (long unsigned int i = 0; i < traits[0].size(); i++){
            cout << "       " << traits[0][i] << endl;
        }
        cout << "------------------------------------------------------------" << endl;
        cout << "Professions:" << endl;
        for (long unsigned int i = 0; i < traits[1].size(); i++){
            cout << "       " << traits[1][i] << endl;
        }
        cout << "------------------------------------------------------------" << endl;
        cout << "Personality traits:" << endl;
        for (long unsigned int i = 0; i < traits[2].size(); i++){
            cout << "       " << traits[2][i] << endl;
        }
        cout << "============================================================" << endl;
    }
    //generate new list of characters
    else if (input == 3){
        if (traits[0].size() == 0 || traits[1].size() == 0 || traits[2].size() == 0){
            cout << "Cannot generate characters" << endl;
            cout << "There must be at least 1 entry for each character trait." << endl;
            cout << "Number of races: " << traits[0].size() << endl;
            cout << "Number of professions: " << traits[1].size() << endl;
            cout << "Number of personalities: " << traits[2].size() << endl;
        }
        else{
            cout << "This will generate a completely new list of characters." << endl;
            cout << "The old list will be replaced by the new list." << endl;
            cout << endl;
            int num = getNumber("Enter the number of characters to generate: ");
            characters.clear();
            for (int i = 0; i < num; i++){
                Character temp(traits[0][randomMaxNumber(traits[0].size())], traits[1][randomMaxNumber(traits[1].size())], traits[2][randomMaxNumber(traits[2].size())], randomNumber(), randomNumber());
                characters.push_back(temp);
            }
            cout << "=== " << num << " new characters created. ===" << endl;
        }
        cout << "============================================================" << endl;
    }
    //print the generated list of characters
    else if (input == 4){
        //prompt for if the list hasn't been generated
        if (characters.size() == 0){
            cout << "Character list is empty. You must first generate the characters." << endl;
        }
        else{
            //formatting for the race column 
            size_t r_max = 4;
            for (size_t i = 0; i < traits[0].size(); i++){
                if (traits[0][i].length() > r_max){
                    r_max = traits[0][i].length();
                }
            }
            //formatting for the profession column 
            size_t p_max = 10;
            for (size_t i = 0; i < traits[1].size(); i++){
                if (traits[1][i].length() > p_max){
                    p_max = traits[1][i].length();
                }
            }
            //formatting for the personality traits column 
            size_t pt_max = 18;
            for (size_t i = 0; i < traits[2].size(); i++){
                if (traits[2][i].length() > pt_max){
                    pt_max = traits[2][i].length();
                }
            }
            //table space formatting based on string character lengths
            int place = 11;

            size_t howLong = to_string(characters.size()).length();
            if (howLong == 2){
                place = 12;
            }
            else if (howLong == 3){
                place = 13;
            }
            //table header sizing
            size_t entireLength = (repeatString(" ", howLong) + "#" + " | " + "Race" + repeatString(" ", r_max) + " | " + "Profession" + repeatString(" ", p_max) + " | " + repeatString(" ", pt_max) + " |" + "    " + " |" + "    ").length() - place;
            //print table header with proper formatting
            cout << repeatString("-", entireLength) << endl;
            cout << repeatString(" ", 2) << "#" << " | " << "Race" << repeatString(" ", r_max - 4) << " | " << "Profession" << repeatString(" ", p_max - 10) << " | " << "Personality" << repeatString(" ", pt_max - 11) << " | " << "STR"
                                                                                                                                                                                                                                            " | "
                 << "Magic" << endl;
            cout << repeatString("-", entireLength) << endl;

            //prints the characters in the formatted table
            for (long unsigned int i = 0; i < characters.size(); i++){
                string num = to_string(i + 1);
                string rs = repeatString(" ", r_max - characters[i].race.length());
                string ps = repeatString(" ", p_max - characters[i].profession.length());
                string pts = repeatString(" ", pt_max - characters[i].personality_trait.length());
                string ss = repeatString(" ", 4 - to_string(characters[i].strength).length());
                string mas = repeatString(" ", 4 - to_string(characters[i].magical_ability).length());
                
                //align numbers 
                int dif = 3 - num.length();
                if (dif < 0){
                    dif = 0;
                }
                cout << repeatString(" ", dif) << (i + 1) << " | " << characters[i].race << rs << " | " << characters[i].profession << ps << " | " << characters[i].personality_trait << pts << " |" << ss << characters[i].strength << " |" << mas << characters[i].magical_ability << endl;
            }
            //print the bottom border for the table
            cout << repeatString("-", entireLength) << endl;
            cout << endl << endl;
        }
        cout << "============================================================" << endl;
    }
}

//Displays main menu, allows program to run until the user quits.
int main(){
    seedRandomNumber();
    cout << "============================================================" << endl;
    cout << "===          Welcome to the character generator          ===" << endl;
    cout << "============================================================" << endl;
    cout << "This program lets you enter a database of character traits." << endl;
    cout << "You can then generate a list of characters, print out the" << endl;
    cout << "list of characters and print out all the character traits." << endl;
    cout << "============================================================" << endl;
    int temp;
    do{
        cout << "MAIN MENU" << endl;
        cout << "[1] Add character traits to the database." << endl;
        cout << "[2] Print character trait database." << endl;
        cout << "[3] Generate new list of characters." << endl;
        cout << "[4] Print list of characters." << endl;
        cout << "[5] Quit" << endl;
        cout << endl;

        temp = getNumberBetween(1, 5, "Please make a selection: ");
        menu(temp);

    } while (temp != 5);
    return 0;
}

