#include <iostream>
#include <fstream>
#include <algorithm>
#include <string>
#include <time.h>
#include <vector>
//#include "Coverage.h"
//#include "Map.h"
#include "Hashtable.h"
#include "Hashtable.cpp"
#include "City.h"
#include "City.cpp"
#include "Intersection.h"
#include "Intersection.cpp"
#include "Connection.h"
#include "Connection.cpp"
#include "MinHeap.h"
#include "MinHeap.cpp"
#include "Route.h"
#include "Route.cpp"

const int hashsize = 60000;

using namespace std;

unsigned int myhash(string s) {
	unsigned int h = 278364;
	int len = s.length();
	for (int i = 0; i < len; i += 1)
		h = h * 69 + s[i];
	return h % hashsize;
}


Hashtable * makeCitiesHt(string filename) {
	Hashtable *h = new Hashtable(hashsize);
	ifstream myfile(filename);
	string line;
	if (myfile) {
		getline(myfile,line); //get rid of first line
		while (getline(myfile, line)) {
			City* newestCity = new City(line);
			//get the hash of the city name
			string cityAsLowercase = newestCity->name;
			std::transform(cityAsLowercase.begin(), cityAsLowercase.end(), cityAsLowercase.begin(), ::tolower);
			int hashOfLine = myhash(cityAsLowercase);
			h->add(hashOfLine, newestCity);
		}
		myfile.close();
	} else {
		cout << "Unable to open file";
	}
	return h;
}

vector<Intersection*> makeIntersections(string filename, Hashtable* cities) {
	vector<Intersection*> intersects;
	ifstream myfile(filename);
	string line;
	bool firstline = true;
	if (myfile) {
		//getline(myfile,line); //ignore first line
		while (getline(myfile, line)) {
			Intersection *newInt = new Intersection(line);
			intersects.push_back(newInt);
		}
		myfile.close();
	} else {
		cout << "Unable to open file";
	}
	return intersects;
}

vector<Connection*> makeConnections(string filename) {
	vector<Connection*> connections;
	ifstream myfile(filename);
	string line;
	if (myfile) {
		while (getline(myfile, line)) {
			Connection *newCon = new Connection(line);
			connections.push_back(newCon);
		}
		myfile.close();
	} else {
		cout << "Unable to open file";
	}
	return connections;
}

void findRoute(Route current_path, vector<Intersection*> nearDes, Minheap* solutions, vector<Intersection*> allIntersections) {
	//cout<<"HELLO"<<endl;
	if(solutions->size() > 50) {
		return;
	}
	if(solutions->size() > 1 && current_path.distance > solutions->allRoutes[1].distance) {
		//cout<<"Ending route size is: "<<current_path.distance<<endl;
		return;
	}
	if(current_path.path.size() > 100) {
		return;
	}

	Intersection* here = current_path.path[current_path.path.size()-1];
	for(int r = 0; r < nearDes.size(); r++) {
		if(here->city == nearDes[r]->city && here->state == nearDes[r]->state) {
			//found a possible path
			solutions->add(current_path);
			cout<<"FOUND A SOLUTION: "<<solutions->size()<<" "<<solutions->allRoutes[1].distance<<endl;
			return;
		}
	}
	//go through the current path's connections and try each route
	vector<Connection*> nextSteps;
	for(int i = 0; i < here->connect.size(); i++) {
		bool A = current_path.isIntersectionAlreadyInRoute(allIntersections[here->connect[i]->A]);
		bool B = current_path.isIntersectionAlreadyInRoute(allIntersections[here->connect[i]->B]);
		//cout<<"A is: "<<A<<" B is: "<<B<<endl;
		if(A && B) {
			//both locations in this connection are already in the table ignore it
		} else if(!A || !B) {
			nextSteps.push_back(here->connect[i]);
		}
	}
	if(nextSteps.size() == 0) return;

	for(int c = 0; c < nextSteps.size(); c++) {
	//int c = 0;
		Connection* testConnection = nextSteps[c];
		//if its A then add b to route 
//CHANGE THIS BACK SO IT WORKS 
		//if(allIntersections[testConnection->A] == here) {
		if(allIntersections[testConnection->A]->city == here->city && allIntersections[testConnection->A]->state == here->state) {
			current_path.addIntersection(testConnection, allIntersections[testConnection->B]);
			findRoute(current_path, nearDes, solutions, allIntersections);
		} else if(allIntersections[testConnection->B] == here) {
		//else if(allIntersections[testConnection->B]->city == here->city && allIntersections[testConnection->B]->state == here->state) {//if B then add A to route
			current_path.addIntersection(testConnection, allIntersections[testConnection->A]);
			findRoute(current_path, nearDes, solutions, allIntersections);
		} else {
			cout<<"In the find route else"<<endl;
		}
	}
	return;
}

int main() {
	//input data into data structures
	Hashtable *cities = makeCitiesHt("files/named-places.txt");
	vector<Intersection*> intersections = makeIntersections("files/intersections.txt", cities);
	vector<Connection*> connections = makeConnections("files/connections.txt");

	//add each connection to their appropriate intersections class help us a little later
	for(int i = 0; i < connections.size(); i++) {
		intersections[connections[i]->A]->connect.push_back(connections[i]);
		intersections[connections[i]->B]->connect.push_back(connections[i]);
	}

	string city1 = "Miami";
	string state1 = "Fl";
	string city2 = "orlando";
	string state2 = "Fl";

	//search hash table for our city (user gets prompted if multiple cities with same name)
	City c1 = cities->search(city1);
	City c2 = cities->search(city2);
	cout<<"City 1: "<<c1.name<<" "<<c1.state<<endl;
	cout<<"City 2: "<<c2.name<<" "<<c2.state<<endl;

	//vector of all the intersections near each city
	//objective is to get from an intersection near city1 to an intersection near city2
	vector<Intersection*> nearCity1;
	vector<Intersection*> nearCity2;

	for(int i = 0; i < intersections.size(); i++) {
		if(intersections[i]->city == c1.name && intersections[i]->state == c1.state) {
			nearCity1.push_back(intersections[i]);
		} 
		if(intersections[i]->city == c2.name && intersections[i]->state == c2.state) {
			nearCity2.push_back(intersections[i]);
		}
	}

	cout<<"City 1 has "<<nearCity1.size()<<" near it"<<endl;
	cout<<"City 2 has "<<nearCity2.size()<<" near it"<<endl;
	if(nearCity1.size() == 0 || nearCity2.size() == 0) {
		cout<<"NO intersections near this city cannot calculate"<<endl;
		return 0;
	}
	Minheap* solutions = new Minheap();
	/*for(int i = 0; i < nearCity1.size(); i++) {
		Route cur_route;
		cur_route.path.push_back(nearCity1[i]);
		findRoute(cur_route, nearCity2, solutions, intersections);
	}

	cout<<"Solutions: "<<solutions->size()-1<<endl;
	for(int i = 1; i < 2; i++) {
		//Route* min = solutions->removeMin();
		Route min = solutions->allRoutes[i];
		cout<<"Solution: "<<i-1<<" distance: "<<min.distance<<endl;
		min.printPath();
	}
	*/
	return 0;
}
