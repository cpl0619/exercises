#include <iostream>
#include <vector>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void initvectornumorder(std::vector<int> *a, int limit){
	for (int i = 0; i < limit; i++){
		a->push_back(i);
	}
}

void initvectorrand(std::vector<int> *a, int limit, int randlim){
	srand(time(NULL));
	int random;
	for (int i = 0; i < limit; i++){
		random = rand() % randlim;
		a->push_back(random);
	}
}

void printvector(std::vector<int> a){
	for (int i = 0; i < a.size(); i++){
		std::cout << a.at(i) << std::endl;
	}
}

int main(int argc, char **argv) {
	std::vector<int> a;
	std::vector<int> a2;
	initvectornumorder(&a, 5);
	printvector(a);
	initvectorrand(&a2, 10, 50);
	std::cout << "testing a2" << std::endl;
	printvector(a2);
}
