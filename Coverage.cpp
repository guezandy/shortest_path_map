#include "Coverage.h"
#include <string>

Coverage::Coverage(string s) {
	int pos = s.find(" ");
	north = stoi(s.substr(0, pos));

	s = s.substr(pos + 1);
	pos = s.find(" ");
	south = stoi(s.substr(0, pos));

	s = s.substr(pos + 1);
	pos = s.find(" ");
	west = stoi(s.substr(0, pos));

	s = s.substr(pos + 1);
	pos = s.find(" ");
	east = stoi(s.substr(0, pos));

	file = s.substr(pos + 1);
}