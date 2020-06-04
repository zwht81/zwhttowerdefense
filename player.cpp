#include "player.h"

Player::Player()
{

}


void Player::Initialplayer(){
    health=20;
    money=100;


}

void Player::healthminus(int n){
    health-=n;
}

void Player::show(QPainter * painter){

    QString playername = "Player1";
    QFont font;
    font.setPointSize(25);
    painter->setFont(font);
    painter->drawText(1100,280,playername);
    font.setPointSize(25);
    painter->setFont(font);
    QPen pen(Qt::red);
    painter->setPen(pen);
    painter->drawText(1100,330,"health: "+QString::number(health));
    pen.setColor(QColor(255,215,0));
    painter->setPen(pen);
    painter->drawText(1100,380,"money:  "+QString::number(money));


}

int Player::getmoney(){
    return money;
}

void Player::spendmoney(int n){
    money-=n;
}

void Player::gainmoney(){
    money+=10;
}
