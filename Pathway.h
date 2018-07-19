#ifndef PATHWAY_H
#define PATHWAY_H

#include "Entity.h"

class Pathway : public Entity{
        public :
        Pathway(size_t x,y);
        void notify();
};
#endif
