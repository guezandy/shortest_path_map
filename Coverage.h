#ifndef __COVERAGE
#define __COVERAGE

using namespace std;

class Coverage {
public:
	int north;
	int south;
	int east;
	int west;
	string file;

	Coverage();
	Coverage(string s);
};

#endif