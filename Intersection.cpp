#include "Intersection.h"
#include <string>

Intersection::Intersection() {

}

Intersection::Intersection(string line) {
	int pos = line.find(" ");
	if(pos == 0) {
		line = line.substr(1);
		pos = line.find(" ");
	}
	longitude = atof(line.substr(0, pos).c_str());
	//cout<<"long: "<<pos<<" "<<longitude<<endl;
		line = line.substr(pos+1);
		int count = 0;
		while (line.compare(count, 1, " ") == 0) {
			count++;
		}
		line = line.substr(count);
		pos = line.find(" ");
	latitude = atof(line.substr(0,pos).c_str());
		line = line.substr(pos+1);
		count = 0;
		while (line.compare(count, 1, " ") == 0) {
			count++;
		}
		line = line.substr(count);	
		pos = line.find(" ");
		//cout<<"LINE BEOFRE DISTANCE: "<<line<<endl;
	distance = atof(line.substr(0,pos).c_str());	
		//cout<<"DIstance: "<<distance<<endl;
		line = line.substr(pos+1);
		//cout<<"Line after distance"<<line<<endl;
	state = line.substr(0,2);
	city = line.substr(3);
}

void Intersection::print() {
	cout<<"Were in "<<city<<","<<state<<" "<<connect.size()<<" connections from here"<<endl;
}