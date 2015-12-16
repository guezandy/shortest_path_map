#include "Minheap.h"
#include <string>

Minheap::Minheap() {
	Route *r = new Route();
	allRoutes.push_back(*r);
}

void Minheap::heapifyUp(int i) {
	int parent = i/2;
	if(parent <= 0) {
		return;
	} else if(parent == 1) { //parent is in the top
		if(allRoutes[i].distance < allRoutes[parent].distance) {
			Route temp = allRoutes[i];
			allRoutes[i] = allRoutes[parent];
			allRoutes[parent] = temp;
		}
		return; //finish
	} else {
		if(allRoutes[i].distance < allRoutes[parent].distance) {
			Route temp = allRoutes[i];
			allRoutes[i] = allRoutes[parent];
			allRoutes[parent] = temp;
			heapifyUp(parent);
		}
	}
}

void Minheap::add(Route route) {
	if(allRoutes.empty()) {
		Route *r = new Route();
		allRoutes.push_back(*r);
		allRoutes.push_back(route);
	} else if(allRoutes.size() == 1){
		allRoutes.push_back(route);
	} else {
		allRoutes.push_back(route);
		heapifyUp(allRoutes.size()-1);
	}
}

bool Minheap::isEmpty() {
	return (allRoutes.size() == 1);
}

int Minheap::size() {
	return allRoutes.size();
}

Route* Minheap::peek() {
	return &allRoutes[1];
}

void Minheap::heapifyDown(int i) {
	int child1 = 2*i;
	int child2 = 2*i+1;
	if(child1 < allRoutes.size() && child2 <= allRoutes.size()) { //has both children in the vector
		if(allRoutes[i].distance > allRoutes[child1].distance && allRoutes[child1].distance < allRoutes[child2].distance){ //child1 is smaller than parent
			Route temp = allRoutes[child1];
			allRoutes[child1] = allRoutes[i];
			allRoutes[i] = temp;
			heapifyDown(child1);
		} else if(allRoutes[i].distance > allRoutes[child2].distance && allRoutes[child2].distance < allRoutes[child1].distance) { //child 2 is smaller than parent
			Route temp = allRoutes[child2];
			allRoutes[child2] = allRoutes[i];
			allRoutes[i] = temp;
			heapifyDown(child2);
		}
		//allRoutes[i].distance is smaller than both children
	} else if(child1 <= allRoutes.size() -1 && allRoutes[child1].distance < allRoutes[i].distance) { 
	//has one child in the vector and its smaller swap
		Route temp = allRoutes[child1];
		allRoutes[child1] = allRoutes[i];
		allRoutes[i] = temp;
		heapifyDown(child1);
	} 
}

Route* Minheap::removeMin() {
	if(allRoutes.size() < 1) 
		return NULL;
	Route* temp = &allRoutes[1];
	allRoutes[1] = allRoutes[allRoutes.size()-1];
	heapifyDown(1);
	return temp;
}











