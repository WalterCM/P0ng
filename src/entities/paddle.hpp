
#ifndef PADDLE_HPP
#define PADDLE_HPP

#include "entity.hpp"

class Paddle : public Entity
{
public:
    Paddle(int);
    void update();

private:
    int playerNumber;
};


#endif // PADDLE_HPP
