#include "City.h"

using namespace std;

City::City() {
	code = -1;
}

City::City(string line) {
	string first = line.substr(0, 8);
	code = atoi(first.c_str());
	string second = line.substr(8, 2);
	state = second;
	line = line.substr(10);
	int pos = line.find("  "); //two spaces cause some cities can have a space in the name
	string city = line.substr(0, pos);
	name = city;
	line = line.substr(pos);
	int count = 0;
	while (line.compare(count, 1, " ") == 0) {
		count++;
	}
	line = line.substr(count);
	pos = line.find("  ");
	string third = line.substr(0, pos);
	population = atoi(third.c_str());
	line = line.substr(pos);
	count = 0;
	while (line.compare(count, 1, " ") == 0) {
		count++;
	}
	line = line.substr(count);
	pos = line.find(".");
	string area = line.substr(0, pos + 7);
	area = atof(area.c_str());
	line = line.substr(pos + 7);
	count = 0;
	while (line.compare(count, 1, " ") == 0) {
		count++;
	}
	line = line.substr(count);
	pos = line.find(".");
	string latitude = line.substr(0, pos + 7);
	latitude = atof(latitude.c_str());
	line = line.substr(pos + 7);
	count = 0;
	while (line.compare(count, 1, " ") == 0) {
		count++;
	}
	line = line.substr(count);
	pos = line.find(".");
	string longitude = line.substr(0, pos + 7);
	longitude = atof(longitude.c_str());
	line = line.substr(pos + 7);
	count = 0;
	while (line.compare(count, 1, " ") == 0) {
		count++;
	}
	line = line.substr(count);
	string intersection = line.substr(0, 5 - count);
	intersection = atoi(intersection.c_str());
	line = line.substr(5 - count);
	count = 0;
	while (line.compare(count, 1, " ") == 0) {
		count++;
	}
	string distance = line.substr(count);
	distance = atof(distance.c_str());
}