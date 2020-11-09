#include <iostream>
#include "random.h"

Random::Random()
{
srand((unsigned) time(0));
}
int Random::getrand(int limit)
{//gives  random number 1 to limit size
        return rand()%limit +1;
}


