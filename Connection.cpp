#include "Connection.h"
#include <string>

Connection::Connection() {

}

Connection::Connection(string line) {
		int pos = line.find(" ");
	name = line.substr(0, pos);
		line = line.substr(pos+1);
		pos = line.find(" ");
	type = line.substr(0,pos);
		line = line.substr(pos+1);
		pos = line.find(" ");
	A = stoi(line.substr(0,pos));	
		line = line.substr(pos+1);
		pos = line.find(" ");
	B = stoi(line.substr(0,pos));
	distance = atof(line.substr(pos+1).c_str());
}

void Connection::print() {
	cout<<"CONNECTS: "<<A<<" and "<<B<<"with distance "<<distance<<endl;
}