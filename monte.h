#ifndef Monte_H
#define Monte_H

#include <iostream>
#include <vector>
#include<fstream>
#include "random.h"
#include <sstream>
#include <limits>
using namespace std;

class Monte
{
public:
Monte();
void Run(double batches, double samples,double items);
fstream& GotoLine(fstream& file, unsigned int num);
private:
};
#endif

