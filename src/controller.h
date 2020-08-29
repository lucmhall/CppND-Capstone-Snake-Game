#ifndef CONTROLLER_H
#define CONTROLLER_H

#include "snake.h"

class Controller
{
public:
    bool HandleInput(bool &running, Snake &snake) const;

private:
    void ChangeDirection(Snake &snake, Snake::Direction input,
                         Snake::Direction opposite) const;
};

#endif