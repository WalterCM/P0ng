
#ifndef BALL_HPP
#define BALL_HPP

#include "paddle.hpp"

class Ball : public Entity
{
public:
    Ball(Paddle *, Paddle *);
    void update();
//    ~Ball();
protected:
private:
    Paddle *p0;
    Paddle *p1;
};


#endif // BALL_HPP
