#ifndef __MAP
#define __MAP

using namespace std;

class Map {
public:
	int row;
	int col;
	int bbp;
	int spp;
	int lls;
	int tls;
	int min;
	int max;
	int sv;
	short int** values;
	Map();
	Map(string mRow, string mCol, string mBbp, string mSpp, string mLls, string mTls, string mMin, string mMax, string mSv);
};

#endif