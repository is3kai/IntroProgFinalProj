//
// Created by Elijah Newcome on 12/11/2023.
//
#include "playerfunctions.h"
#include "enemyfunctions.h"
#include "gamefunctions.h"
#include <string>
#include <random>
#include <iostream>
#include <fstream>
using namespace std;

int generateRandomNumber() {
    return rand() % 900000 + 100000; // Generates a random number between 100000 and 999999
}

void play(string charName, int &str, int &cha, int &dex, int &con, int &sp, int &lvl, int &xp, int &mxp, int &dmg, int &ehp, int &hp, int &mhp, int ac, int &distance){
    typeStory();
    awaitPlayerResponse(charName, str, cha, dex, con, sp, lvl, xp, mxp, dmg, ehp, hp, mhp, ac);
}
void typeStory(){
    ifstream storyFile;
    storyFile.open ("story.txt");
    string line;
    while (getline(storyFile, line) && line.find('#') == string::npos) {
        // Process each line (you can replace this with your specific logic)
        cout << line << endl;
    }

}
void save(string charName, int &str, int &cha, int &dex, int &con, int &sp, int &lvl, int &xp, int &mxp, int &dmg, int &ehp, int &hp, int &mhp){
    fstream saveFile;
    saveFile.open ("save.txt");
    int key = generateRandomNumber();
    saveFile << key << endl;
    saveFile << charName << endl << str << endl << cha << endl << dex << endl << con << endl;
    saveFile << sp << endl << lvl << endl << xp << endl << mxp << endl << dmg << endl;
    saveFile.close();
    saveFile.open ("save.txt");
    saveFile >> key;
    saveFile.ignore();
    char ch;
    while (saveFile.get(ch)) {
        // Simple shift encryption (you can replace this with a more secure algorithm)
        ch = static_cast<char>(ch + key);
        saveFile.put(ch);
    }
    saveFile.close();
}
void load(string charName, int &str, int &cha, int &dex, int &con, int &sp, int &lvl, int &xp, int &mxp, int &dmg, int &ehp, int &hp, int &mhp){
    fstream saveFile;
    saveFile.open ("save.txt");
    int key;
    saveFile >> key;
    saveFile.ignore();
    char ch;
    while (saveFile.get(ch)) {
        // Simple shift decryption (reverse of the encryption process)
        ch = static_cast<char>(ch - key);
        saveFile.put(ch);
    }
    saveFile.close();
    saveFile.open ("save.txt");
    saveFile >> key;
    saveFile.ignore();
    saveFile >> charName >> str >> dex >> cha >> con >> sp >> lvl >> xp >> mxp >> dmg;
}
void openStatPage(int &str, int &cha, int &dex, int &con, int &sp, int &lvl, int &xp, int &mxp){
    cout << "STR: " << str << endl << "CHA: " << cha << endl<< "DEX: " << dex << endl<< "CON: " << con << endl;
    cout << "Statpoints Remaining: " << sp << endl;
}
void statBalance(int con, int &ac, int &hp, int &mhp){
    hp = hp*(1+(con/10));
    ac = 10 + ((con-10)/2);
    mhp = hp;
}
void check(int stat){
    int random;
    random = rand() %20 + 1;
    random = random + ((stat-10)/2);
}
void allotStatPoint(int &stat, int &sp){
    stat++;
    sp--;
}

void charMaker(string charName, int &str, int &dex, int &cha, int & con, int &sp){
    cout << "What is your Name: ";
    cin >> charName;
    cout << endl;
    cout << "You have " << sp << " stat points remaing. Use the allot command to add points to stats";
}
void awaitPlayerResponse(string charName, int &str, int &cha, int &dex, int &con, int &sp, int &lvl, int &xp, int &mxp, int &dmg, int &ehp, int &hp, int &mhp, int &ac){
    string input;
    cin >> input;
    if(input == "continue"){
        typeStory();
    }else if (input == "menu"){
        openStatPage(str,cha,dex,con,sp,lvl,xp,mxp);
    }else if (input == "allot"){
        string stat;
        cout << "What Stat? ";
        cin >> stat;
        if (stat == "str"){
            allotStatPoint(str, sp);
        }else if (stat == "cha"){
            allotStatPoint(cha, sp);
        }else if (stat == "dex"){
            allotStatPoint(str, dex);
        }else if (stat == "con") {
            allotStatPoint(con, sp);
            statBalance(con,ac,hp,mhp);
        }
        openStatPage(str, cha, dex, con, sp, lvl, xp, mxp);
    }else if (input == "save"){
        save(charName, str, cha, dex, con, sp, lvl, xp, mxp, dmg, ehp, hp, mhp);
    }else if (input == "load"){
        load(charName,str, cha, dex, con, sp, lvl, xp, mxp, dmg, ehp, hp, mhp);
    }else if (input == "character"){
        charMaker(charName, str, dex, cha, con, sp);
    }else if (input == "return"){
        typeStory();
    }
    awaitPlayerResponse(charName, str, cha, dex, con, sp, lvl, xp, mxp, dmg, ehp, hp, mhp, ac);
}

