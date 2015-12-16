#include "Route.h"
#include "Connection.h"
#include <string>

Route::Route() {
	distance = 0;
}

void Route::addIntersection(Connection* c, Intersection* leg) {
	path.push_back(leg);
	distance += c->distance;
}

void Route::print() {
	cout<<"were at: "<<path[path.size()-1]->city<<" "<<path[path.size()-1]->state<<"Route has: "<<path.size()<<" steps and a total distance of: "<<distance<<endl;
}

void Route::printPath() {
	for(int i = 0; i < path.size(); i++) {
		cout<<"\t"<<path[i]->city<<" , "<<path[i]->state<<endl;
	}
}

bool Route::isIntersectionAlreadyInRoute(Intersection* inter) {
	for(int i = 0; i < path.size(); i++) {
		if(path[i] == inter) {
			return true;
		}
	}
	return false;
}