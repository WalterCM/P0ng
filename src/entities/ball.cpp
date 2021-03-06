#include <iostream>
#include <cmath>
#include "ball.hpp"
#include "../core/game_constants.hpp"

Ball::Ball(Paddle *p0, Paddle *p1)
{
    this->load("ball.png");

    this->p0 = p0;
    this->p1 = p1;
    velocity.x = -BALL_BASE_SPEED;
    velocity.y = -BALL_BASE_SPEED;
}

void Ball::update()
{
    Entity::update();
    bounce(p0);
    bounce(p1);
}
