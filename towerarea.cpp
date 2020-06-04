#include "towerarea.h"


Towerarea::Towerarea(int x, int y, int width, int height): mx(x), my(y), mwidth(width), mheight(height) {}

int Towerarea::GetX() const     //获取横坐标
{
    return mx;
}

int Towerarea::GetY() const     //获取横坐标
{
    return my;
}

int Towerarea::GetWidth() const //获取宽
{
    return mwidth;
}

int Towerarea::GetHeight() const //获取高
{
    return mheight;
}
