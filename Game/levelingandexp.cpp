int levelup(float xp, float xpr){
    if (xp > xpr){
        xp = xp-xpr;
        xpr *= 1.5;
    }else{
        return -1;
    }
    return xp;
}

int expgain(int exp, int lvl, float xpr, float xp){

}