#ifndef TOWER3_H
#define TOWER3_H

#include "tower.h"


//Ëþ3
class Tower3 : public Tower
{
public:
    Tower3();
    void initialtower(int x,int y);
    void attack();
    void upgrade();
};

#endif // TOWER3_H
