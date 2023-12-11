//
// Created by Elijah Newcome on 12/11/2023.
//

#include "enemyfunctions.h"
#include "playerfunctions.h"
#include <iostream>
#include <iomanip>
#include <random>
using namespace std;

void encounter(int lvl, int &ehp, int &hp, int &mdmg, int str, int dmg, int ac, int &xp, int &mxp, int  &sp){
    ehp = 100 * lvl;
    mdmg = 2 * lvl;
    attack(str, dmg, ehp, hp, mdmg, ac, xp, mxp,sp);
}
void enemyattack(int &ehp, int &hp, int &mdmg, int str, int dmg, int ac, int &xp, int &mxp, int  &sp){
    if(ehp <= 0){
        grantXP(xp);
        levelUp(xp,mxp,sp);
    }else{
        hp -= mdmg - ac;
        attack(str, dmg, ehp, hp, mdmg, ac, xp, mxp,sp);
    }
}
void grantXP(int &xp){
    xp += 10;
}