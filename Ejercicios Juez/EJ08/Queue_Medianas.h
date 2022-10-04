#pragma once
#include "PriorityQueue.h"

using namespace std;

class queue_medianas
{
	PriorityQueue<long int, greater<long int>> menores;
	PriorityQueue<long int, less<long int>>mayores;
public:
	queue_medianas() {
	}
	void addElemento(long int el) {
		if (menores.empty()) menores.push(el);
		else {
			if (el > menores.top())
				mayores.push(el);
			else menores.push(el);
		}

		//Equilibra las colas
		if (menores.size() > mayores.size() + 1) {
			mayores.push(menores.top());
			menores.pop();
		}
		else if (mayores.size() > menores.size()) {
			menores.push(mayores.top());
			mayores.pop();
		}
	}
	void getMediana() {
		if (menores.empty()) {
			std::cout << "ECSA ";
		}
		else {
			std::cout << menores.top() << " ";
			menores.pop();
		}
	}

protected:
};