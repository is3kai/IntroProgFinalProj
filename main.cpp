#include <iostream>
#include <string>
#include "gamefunctions.h"
using namespace std;


int main() {
    string charName = "";
    int str, cha, dex, con, sp, lvl, xp, mxp, dmg, ehp, hp, mhp, ac, distance;
    str = 0;
    cha = 0;
    dex = 0;
    con = 0;
    sp = 40;
    lvl = 1;
    xp = 0;
    mxp = 10;
    dmg = 5;
    ehp = 0;
    hp = 100;
    mhp = 100;
    ac = 10;
    distance = 0;
    play(charName,str, cha, dex, con, sp, lvl, xp, mxp, dmg, ehp, hp, mhp, ac, distance);
    return 0;
}
