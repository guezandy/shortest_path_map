#ifndef INTERSECTION_H_
#define INTERSECTION_H_

#include "Connection.h"
#include "City.h"
#include "Minheap.h"

using namespace std;

class Intersection {
public:
	//basic information about the intersection
	double longitude;
	double latitude;
	double distance;
	string city;
	string state;
	//constructors
	Intersection();
	Intersection(string line);
	//all connections that connect from this intersection
	vector<Connection*> connect;
	//print the intersections information
	void print();
	
	//min heap of all routes from the starting point that lead to this point to help our efficiency
	MinHeap* allPaths = new Minheap();
};

#endif