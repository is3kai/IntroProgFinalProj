//
// Created by Elijah Newcome on 12/11/2023.
//

#ifndef INTROPROGFINALPROJ_PLAYERFUNCTIONS_H
#define INTROPROGFINALPROJ_PLAYERFUNCTIONS_H

void levelUp(int &xp, int &mxp, int &sp);
void attack(int str, int dmg, int &ehp, int &hp, int mdmg, int ac, int &xp, int &mxp, int  &sp);
void travel(int dex, int distance, int lvl, int &ehp, int &hp, int &mdmg, int str, int dmg, int ac, int &xp, int &mxp, int  &sp);


#endif //INTROPROGFINALPROJ_PLAYERFUNCTIONS_H
