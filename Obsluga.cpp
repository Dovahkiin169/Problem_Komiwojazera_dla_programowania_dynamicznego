#include "Obsluga.h"
#include <ctime>
#include <fstream>
#include <string>
#include <cmath>

using namespace std;
TSP *S = new TSP();

void Obsluga::getObjectFromFile(string filename)
{
	if (distances != nullptr)
	{
		for (int i = 0; i < size; i++)
		{
			if (distances[i] != nullptr)
			{
				delete distances[i];
			}
		}
		delete[] distances;
	}

	ifstream fin;
	fin.open(filename, ios::in);
	string buf = "";
	while (buf != "DIMENSION:")
	{
		fin >> buf;
	}

	fin >> this->size;

	while (buf != "EDGE_WEIGHT_SECTION")
	{
		fin >> buf;
	}
	distances = new double*[this->size];
	double bufor;
	for (int i = 0; i < this->size; i++)
	{
		distances[i] = new double[this->size];
		for (int j = 0; j < this->size; j++)
		{
			fin >> bufor;
			if (bufor != 0)
			{
				distances[i][j] = bufor;
			}
			else
			{
				distances[i][j] = MAX;
			}

		}
	}
	if (order != nullptr) delete[]order;
	order = new int[size];
	for (int i = 0; i < size - 1; i++)
		order[i] = i + 1;
	order[size - 1] = 0;
	fin.close();

}

void Obsluga::ReadFromFileK(string filename)
 {
	if (coordinates != nullptr)
	 {
		for (int i = 0; i < this->size; i++)
			if (coordinates[i] != nullptr) delete[]coordinates[i];
		delete[] coordinates;
	 }
	if (distances != nullptr)
	 {
		for (int i = 0; i < this->size; i++)
			if (distances[i] != nullptr) delete[] distances[i];
		delete[] distances;
	}

	ifstream fin;
	string input;
	fin.open(filename, ios::in);
	while (input != "DIMENSION:")
		fin >> input;
	fin >> this->size;
	coordinates = new double*[this->size];

	while (input != "NODE_COORD_SECTION")
		fin >> input;
	for (int i = 0; i < this->size; i++)
	{
		coordinates[i] = new double[2];
		fin >> input;
		fin >> coordinates[i][0];
		fin >> coordinates[i][1];
	}

	if (order != nullptr) delete[]order;
	order = new int[size];
	for (int i = 0; i < size - 1; i++)
		order[i] = i + 1;
	order[size - 1] = 0;
	fin.close();


	for (int i = 0; i < size; i++)
	{
		cout << "[" << i << "] " << coordinates[i][0] << " " << coordinates[i][1] << endl;
	}

	S->computeDistances();
 }


void Obsluga::printRoute(int *route) const
 {
	for (int i = 0; i < size; i++)
		cout << route[i] << " -> ";
	cout << route[0] << endl;
	int optimal = 6905;
	cout << "Calkowita dlugosc: " << S->GetRouteLen(route) << endl;
	cout << "Blad:" << ((S->GetRouteLen(route) - optimal) * 100) / optimal << "%" << endl;

 }
