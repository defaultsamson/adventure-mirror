#ifndef WALL_H
#define WALL_H

#include "Entity.h"

class Wall : public Entity{
        public :
        Wall(size_t x,size_t y, char icon);
        void notify();
}
#endif
