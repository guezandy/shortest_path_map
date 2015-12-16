#ifndef CITY_H_
#define CITY_H_

using namespace std;

class City {
public:
	int code;
	string state;
	string name;
	int population;
	double area;
	double latitude;
	double longitude;
	int intersection;
	double distance;

	City();
	City(string s);
};

#endif