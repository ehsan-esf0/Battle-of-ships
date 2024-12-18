#include "turret_q8.h"
#include "gamepage.h"

Turret_Q8::Turret_Q8(QWidget *parent) : ClickableLabel(parent) {
    setStyleSheet("background-color: red;");
    setText("Label 1");
    timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, &Turret_Q8::shotBullet);
    i = 0;
}


void Turret_Q8::shotBullet ()
{
    if ( i < Gamepage::enimi.size() )
    {
        Bullet *b = new Bullet(parentWidget());
        b->shoot(this->pos() , Gamepage::enimi[i++] );
        bullet.append(bullet);
    }
}

void Turret_Q8::startShotBullet()
{
    timer->start(500);
}

void Turret_Q8::getLabel( QVector<QLabel*> l )
{
    label = l;
}
