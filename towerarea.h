#ifndef TOWERAREA_H
#define TOWERAREA_H


class Towerarea
{
private:
    const int mx, my;           //位置坐标
    const int mwidth, mheight;  //宽高

public:
    //构造    参数：防御塔坑坐标、宽高
    Towerarea(int x, int y, int width = 80, int height = 80);

    int GetX() const;     //获取横坐标
    int GetY() const;     //获取横坐标
    int GetWidth() const; //获取宽
    int GetHeight() const;//获取高
};

#endif // TOWERAREA_H
