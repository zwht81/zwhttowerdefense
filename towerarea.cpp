#include "towerarea.h"


Towerarea::Towerarea(int x, int y, int width, int height): mx(x), my(y), mwidth(width), mheight(height) {}

int Towerarea::GetX() const     //��ȡ������
{
    return mx;
}

int Towerarea::GetY() const     //��ȡ������
{
    return my;
}

int Towerarea::GetWidth() const //��ȡ��
{
    return mwidth;
}

int Towerarea::GetHeight() const //��ȡ��
{
    return mheight;
}
