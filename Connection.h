#ifndef CONNECTION_H_
#define CONNECTION_H_

#include "Intersection.h"

using namespace std;

class Connection {
public:
	string name;
	string type;
	int A;
	int B;
	double distance;
	Connection();
	Connection(string line);
	void print();
};

#endif