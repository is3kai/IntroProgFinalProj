//
// Created by Elijah Newcome on 12/11/2023.
//

#ifndef INTROPROGFINALPROJ_GAMEFUNCTIONS_H
#define INTROPROGFINALPROJ_GAMEFUNCTIONS_H
#include <string>
using namespace std;

void play(string charName, int &str, int &cha, int &dex, int &con, int &sp, int &lvl, int &xp, int &mxp, int &dmg, int &ehp, int &hp, int &mhp, int ac, int &distance);
void typeStory();
void save(string charName, int &str, int &cha, int &dex, int &con, int &sp, int &lvl, int &xp, int &mxp, int &dmg, int &ehp, int &hp, int &mhp);
void load(string charName, int &str, int &cha, int &dex, int &con, int &sp, int &lvl, int &xp, int &mxp, int &dmg, int &ehp, int &hp, int &mhp);
void openStatPage(int &str, int &cha, int &dex, int &con, int &sp, int &lvl, int &xp, int &mxp);
void statBalance(int con, int &ac, int &hp, int &mhp);
void check(int stat);
void charMaker(string charName, int &str, int &dex, int &cha, int & con, int &sp);
void allotStatPoint(int &stat, int &sp);
void awaitPlayerResponse(string harName, int &str, int &cha, int &dex, int &con, int &sp, int &lvl, int &xp, int &mxp, int &dmg, int &ehp, int &hp, int &mhp, int &ac);

#endif //INTROPROGFINALPROJ_GAMEFUNCTIONS_H
