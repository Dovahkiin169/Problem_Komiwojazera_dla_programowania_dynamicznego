#pragma once
#include<iostream>
#include<cmath>
#include "TSP.h"
#undef max
using namespace std;
static const double MAX1 = numeric_limits<double>::infinity();
class Obsluga
{
private:

public:
	int size = 0;
	int *order = nullptr;
	double** distances = nullptr;
	double** coordinates = nullptr;
	void getObjectFromFile(string filename);
	void ReadFromFileK(string filename);

	void printRoute(int*) const;
};