//
// Created by Elijah Newcome on 12/11/2023.
//
#include "playerfunctions.h"
#include "enemyfunctions.h"
#include <iostream>
#include <iomanip>
#include <chrono>
#include <random>
#include <thread>
using namespace std;

void levelUp(int &xp, int &mxp, int &sp){
    if(xp>=mxp){
        cout << "You Leveled Up!" << endl;
        xp = 0;
        mxp *= 2;
        sp += 2;
    }
}

void attack(int str, int dmg, int &ehp, int &hp, int mdmg, int ac, int &xp, int &mxp, int  &sp){
    if (ehp <= 0){
        grantXP(xp);
        levelUp(xp, mxp, sp);
    }
    cout << "Enemy: " << ehp << endl << "Player: " << hp << endl;
    ehp -= (((str-10)/2) + dmg);
    enemyattack(ehp, hp, mdmg, str, dmg, ac, xp, mxp, sp);
}

void travel(int dex, int distance, int lvl, int &ehp, int &hp, int &mdmg, int str, int dmg, int ac, int &xp, int &mxp, int  &sp){
    int time, tI;
    time = (distance/dex)*2;
    chrono::seconds delayDuration(5);
    tI = time/5;
    for(int i; i < tI; i++){
        int randNum;
        randNum = rand() % 100 + 1;
        if (randNum <= 75){

        }else if (randNum > 75){
            encounter(lvl, ehp, hp, mdmg, str, dmg, ac, xp, mxp, sp);
        }
        this_thread::sleep_for(delayDuration);
    }
}