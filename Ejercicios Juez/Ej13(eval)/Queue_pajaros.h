#pragma once
#include "PriorityQueue.h"
#include <vector>
class queue_pajaros {

	PriorityQueue<long int, std::greater<long int>> jovenes;
	PriorityQueue<long int, std::less<long int>> viejos;
	//long int mediana;

public:
	queue_pajaros(long int edad) {
		jovenes.push(edad);
		//mediana = edad;
	}
	void addElement(long int edad) {
		if (edad < jovenes.top()) {
			jovenes.push(edad);
		}
		else viejos.push(edad);
		if (jovenes.size() > viejos.size()+1) {
			viejos.push(jovenes.top());
			jovenes.pop();
		}
		else if(viejos.size()>jovenes.size()){
			jovenes.push(viejos.top());
			viejos.pop();
		}
		/*if (edad < mediana) {
			if (jovenes.size() <= viejos.size()) {
				jovenes.push(edad);
			}
			else {
				viejos.push(mediana);
				if (jovenes.top() < edad) {
					mediana = edad;
				}
				else {
					mediana = jovenes.top();
					jovenes.pop();
					jovenes.push(edad);
				}
			}
		}
		else {
			if (viejos.size() <= jovenes.size()) {
				viejos.push(edad);
			}
			else {
				jovenes.push(mediana);
				if (viejos.top() > edad) {
					mediana = edad;
				}
				else {
					mediana = viejos.top();
					viejos.pop();
					viejos.push(edad);
				}
			}
		}*/
	}
	long int consultaMediana() {
		return jovenes.top();
	}
protected:
};