#ifndef ROUTE_H_
#define ROUTE_H_

using namespace std;

class Route {
public:
	vector<Intersection*> path;
	double distance;
	Route();
	void addIntersection(Connection* con, Intersection* leg);
	void print();
	bool isIntersectionAlreadyInRoute(Intersection* inter);
	void printPath();
};

#endif