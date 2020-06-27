#ifndef TOWER2_H
#define TOWER2_H

#include "tower.h"

//Ëþ2
class Tower2 : public Tower
{
public:
    Tower2();
    void initialtower(int x,int y);
    void attack();
    void upgrade();
};

#endif // TOWER2_H
