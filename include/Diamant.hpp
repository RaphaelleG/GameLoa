#ifndef DIAMANT
#define DIAMANT

#include "Pion.hpp"

class Diamant : public Pion{
private:
    // je ne sais pas ce qu'il y a en plus

public:
    Diamant (int x, int y);
    //virtual ~Diamant ();

    virtual void actionPion(Personne p);

};

#endif
