#ifndef TOWERAREA_H
#define TOWERAREA_H

//������
class Towerarea
{
private:
    const int mx, my;           //λ������
    const int mwidth, mheight;  //���

public:
    //����    �����������������ꡢ���
    Towerarea(int x, int y, int width = 80, int height = 80);

    int GetX() const;     //��ȡ������
    int GetY() const;     //��ȡ������
    int GetWidth() const; //��ȡ��
    int GetHeight() const;//��ȡ��
};

#endif // TOWERAREA_H
