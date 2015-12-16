#include "Hashtable.h"


Hashtable::Hashtable() {
	//empty contructor
}
Hashtable::Hashtable(int size) {
	cities = new City[size]; //array of cities
	hashsize = size; //size of array large value normally
	numentries = 0; //how many entries we got as of now
	collisionCount = 0;
}

unsigned int Hashtable::thash(string s) {
	unsigned int h = 278364;
	int len = s.length();
	for (int i = 0; i < len; i += 1)
		h = h * 69 + s[i];
	return h % hashsize;
}

void Hashtable::add(int key, City *entry) {
	if (numentries == 0) {
		cities[key] = *entry;
		numentries++;
	}
	else if (cities[key].code == -1) {
		cities[key] = *entry;
		numentries++;
	}
	else { //collision
		collisionCount++;
		int originalKey = key;
		while (key != (originalKey - 1)) {
			if (cities[key].code == -1) {
				cities[key] = *entry;
				numentries++;
				break; //get out of while loop
			} else {
				key++; //iterate til you find an empty spot
			}
		}
	}
}

void Hashtable::print() {
	int emptyCount = 0;
	cout << "==============PRINTING TREEE===================" << endl;
	for (int i = 0; i < hashsize; i++) {
		if (cities[i].code != -1) {
			cout << "i: " << i << " '" << cities[i].name << "'" << " , " << cities[i].name << endl;
		}
		else {
			cout << "i: " << i << " is empty" << endl;
			emptyCount++;
		}
	}
	cout << "===============END TREE =======================" << endl;
	cout << "STATS: " << endl;
	cout << "Num entries: " << numentries << endl;
	cout << "Collision Count: " << collisionCount << endl;
	cout << "Empty locations: " << emptyCount << endl;
}

City Hashtable::search(string cityName) {
	int which = 0;
	int whichOne;
	bool found = false;
	int theHash;
	do { //do until a city is found
		cout << "Search for: " << cityName << endl;
		std::transform(cityName.begin(), cityName.end(), cityName.begin(), ::tolower);
		int theOriginalHash = thash(cityName);
		theHash = theOriginalHash;//TODO: duplicate to know if we made it all the way round the list
		//cout << "Hash: " << theHash << endl;
		if (cities[theHash].code == -1) {
			cout << "No cities with that name!" << endl;
			found = false;
			cout << "Enter new city: " << endl;
			cin >> cityName;
		}
		else {
			//start at the hash and go until null (not until the next != to cityName)
			//because if miami is entered then another with the same hash then another miami then it'll come out in the middle
			//TODO: accounts for making it all the way around the hash table
			while (cities[theHash].code != -1) {
				//transform the name to lowercase to compare
				string theCity = cities[theHash].name;
				std::transform(theCity.begin(), theCity.end(), theCity.begin(), ::tolower);
				if (theCity == cityName) { //city name is still lowercase
					cout <<" Select " << which << " for: " << cities[theHash].name << " , " << cities[theHash].state << endl;
				}
				theHash++;
				which++;
			}
			cout << "Select one of the cities above: ";
			do {
				cin >> whichOne;
				//cout << "HI" << endl;
			} while (whichOne > which);
			theHash = theHash - which;
			//cout << "Were here city is: " << cities[theHash + whichOne].name << " , " << cities[theHash + whichOne].state << endl;
			found = true;
		}
	} while (!found);
	return cities[theHash + whichOne];
}

City* Hashtable::search(string cityName, string state) {
	int which = 0;
	int whichOne;
	bool found = false;
	int theHash;
	do { //do until a city is found
		std::transform(cityName.begin(), cityName.end(), cityName.begin(), ::tolower);
		std::transform(state.begin(), state.end(), state.begin(), ::tolower);
		int theOriginalHash = thash(cityName);
		theHash = theOriginalHash;//TODO: duplicate to know if we made it all the way round the list
		if (cities[theHash].code == -1) {
			cout << "No cities with that name!" << endl;
			found = true;
			return NULL;
			//cout << "Enter new city: " << endl;
			//cin >> cityName;
		}
		else {
			//start at the hash and go until null (not until the next != to cityName)
			//because if miami is entered then another with the same hash then another miami then it'll come out in the middle
			//TODO: accounts for making it all the way around the hash table
			while (cities[theHash].code != -1) {
				//transform the name to lowercase to compare
				string theCity = cities[theHash].name;
				string theState = cities[theHash].state;
				std::transform(theCity.begin(), theCity.end(), theCity.begin(), ::tolower);
				std::transform(theState.begin(), theState.end(), theState.begin(), ::tolower);
				if(theCity == cityName && theState == state) {
					cout<<" FOUND"<<endl;
					return &cities[theHash];
				}
				if (theCity == cityName) { //city name is still lowercase
					cout <<" Select " << which << " for: " << cities[theHash].name << " , " << cities[theHash].state << endl;
				}
				theHash++;
				which++;
			}
			found = true;
		}
	} while (!found);
	cout<<" Found"<<endl;
	return &cities[theHash + whichOne];
}
