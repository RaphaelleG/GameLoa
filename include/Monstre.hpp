#ifndef MONSTRE
#define MONSTRE

#include "Pion.hpp"

class Monstre : public Pion{
private:
    // je sais pas

public:
    Monstre (int x, int y);
    //virtual ~Monstre ();
    virtual void teleport(int x, int y, Plateau& p);
};


#endif
