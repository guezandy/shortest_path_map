#include "Map.h"

using namespace std;

Map::Map(string mRow, string mCol, string mBbp, string mSpp, string mLls, string mTls, string mMin, string mMax, string mSv) {
	row = stoi(mRow);
	col = stoi(mCol);
	bbp = stoi(mBbp);
	spp = stoi(mSpp);
	lls = stoi(mLls);
	tls = stoi(mTls);
	min = stoi(mMin);
	max = stoi(mMax);
	sv = stoi(mSv);
}