#ifndef Filesystem_H
#define Filesystem_H

#include <iostream>
#include "monte.h"
#include "random.h"
#include <vector>
#include<fstream>
#include <sstream>
#include<string>
#include <stdio.h>
#include <cmath>
using namespace std;

class FileSystem
{
public:
FileSystem();
void Run();
void Read();
void Delete();
void Display();
void Compute();
private:
ifstream file;
ofstream write;
double batches; //number of batches (boxes of chips)
double numitems; // number of chips in a batch
double percbatch; // percentage of batches that are bad  (0-100)%
double percitems; // percentage of items bad in bad batch (0-100)%
double samples; // number of samples we will pass into monte (we will pass this and batches into it)
};
#endif


