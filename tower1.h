#ifndef TOWER1_H
#define TOWER1_H

#include "tower.h"

//Ëþ1
class Tower1 : public Tower
{
public:
    Tower1();
    void initialtower(int x,int y);
    void attack();
    void upgrade();
};

#endif // TOWER1_H
