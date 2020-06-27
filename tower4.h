#ifndef TOWER4_H
#define TOWER4_H

#include "tower.h"


//Ëþ4
class Tower4 : public Tower
{
public:
    Tower4();
    void initialtower(int x,int y);
    void attack();
    void upgrade();
};

#endif // TOWER4_H
