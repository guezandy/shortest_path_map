#ifndef HASHTABLE_H_
#define HASHTABLE_H_

#include "City.h"
using namespace std;

class Hashtable {
public:
	City * cities;
	int hashsize, numentries, collisionCount;
	Hashtable();
	Hashtable(int size);
	unsigned int thash(string s);
	void add(int key, City *entry);
	void print();
	City search(string CityName);
	City* search(string city, string state);
};

#endif