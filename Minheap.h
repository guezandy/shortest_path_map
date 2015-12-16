#ifndef MINHEAP_H_
#define MINHEAP_H_

#include "Intersection.h"
#include "Route.h"

using namespace std;

class Minheap {
public:
	Minheap();
	vector<Route> allRoutes;
	void add(Route route);
	Route* peek();
	Route* removeMin();
	bool isEmpty();
	void heapifyUp(int i);
	void heapifyDown(int i);
	int size();
};

#endif