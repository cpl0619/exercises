#include <iostream>
#include <stdio.h>
#include <time.h>
#include <climits>
#include <assert.h>

class specialarray{
private:
	int size;
public:
	int *array;
	specialarray();
	specialarray(int arrsize);
	~specialarray();
	void selection_sort_ascending();
	void selection_sort_descending();
	void bubble_sort_ascending();
	void bubble_sort_descending();
	int search(int a);
	int getsize();
	void printarray();
	int sum();
	int multiply();
	int average();
	int front();
	int back();
	int at(int idx);
	void initarray();
	int relational(specialarray a, specialarray b);
	int relationalNOT(specialarray a, specialarray b);
	int relationalLESS(specialarray a, specialarray b);
	int relationalMORE(specialarray a, specialarray b);
	int relationalLESSEQUAL(specialarray a, specialarray b);
	int relationalMOREEQUAL(specialarray a, specialarray b);
	int swap(specialarray *a, specialarray *b);
	// add these member functions:
	// push back, pop back, resize, empty, swap
	// overload operator[], insert
	// relational operators (==, !=, <, >, <=, >=)
};

int specialarray::swap(specialarray *a, specialarray *b){
	int temp; 
	if(a->getsize() != b->getsize()){
		return -1;
	}
	for(int i = 0;i < a->getsize() - 1; i++){
		temp = a->array[i];
		a->array[i] = b->array[i];
		b->array[i] = temp;
	}
	return 0;
}

int specialarray::relationalLESSEQUAL(specialarray a, specialarray b){
	if (a.size != b.size){
		return 0;
	} else {
		if(a.sum() <= b.sum()){
			return 0;
		}
	}
	return 0;
}
int specialarray::relationalMOREEQUAL(specialarray a, specialarray b){
	if (a.size != b.size){
		return 0;
	} else {
		if(a.sum() >= b.sum()){
			return 0;
		}
	}
	return 0;
}
int specialarray::relationalNOT(specialarray a, specialarray b){
	if (a.size != b.size){
		return 0;
	} else {
		if(a.sum() != b.sum()){
			return 0;
		}
	}
	return 0;
}

int specialarray::relational(specialarray a, specialarray b){
	if (a.size != b.size){
		return 0;
	} else {
		if(a.sum() == b.sum()){
			return 0;
		}
	}
	return 0;
}


int specialarray::relationalLESS(specialarray a, specialarray b){
	if (a.size != b.size){
		return 0;
	} else {
		if(a.sum() < b.sum()){
			return 0;
		}
	}
	return 0;
}


int specialarray::relationalMORE(specialarray a, specialarray b){
	if (a.size != b.size){
		return 0;
	} else {
		if(a.sum() > b.sum()){
			return 0;
		}
	}
	return 0;
}


void specialarray::initarray(){
	srand(time(NULL));
	for(int i = 0; i < size - 1; i++) {
		// This is dereference method for pointers only
			*(array + i) = rand() % 50;
			// This is a normal array method, this also works with pointers
			//array[i] = rand() % 50;
		}
}

int specialarray::at(int idx){
	assert(idx < size - 1 && idx > 0);
	return array[idx];
}

int specialarray::front(){
	return array[0];
}

int specialarray::back(){
	return array[size - 1];
}

void specialarray::bubble_sort_ascending(){
	int temp;
	for(int i = 0; i < size - 1; i++){
		for(int j = 0; j < size - 2; j++){
			if(array[j] > array[j + 1]){
				temp = array[j];
				array[j] = array[j + 1];
				array[j + 1] = temp;
			}
		}
	}
}

void specialarray::bubble_sort_descending(){
	int temp;
	for(int i = 0; i < size - 1; i++){
		for(int j = 0; j < size - 2; j++){
			if(array[j] < array[j + 1]){
				temp = array[j];
				array[j] = array[j + 1];
				array[j + 1] = temp;
			}
		}
	}
}


int specialarray::average(){
	return sum() / size;
}

int specialarray::multiply(){
	int a = 0;
	for (int i = 0; i < size - 1; i++){
		a = a * array[i];
	}
	return a;
}

int specialarray::sum(){
	int a = 0;
	for (int i = 0; i < size - 1; i++){
		a = a + array[i];
	}
	//this function will return 0 for empty array
	return a;
}

int specialarray::search(int a){
    for (int i = 0; i < size - 1; i++){
    	if (array[i] == a){
    		return i;
    	}
    }
    return -1;
}

int specialarray::getsize(){
	return size;
}

specialarray::specialarray(){
	size = 0;
	array = NULL;
}

specialarray::specialarray(int arrsize){
	std::cout << "Constructor" << std::endl;
	size = arrsize;
	array = new int[size];
	initarray();
}

specialarray::~specialarray(){
	std::cout << "Destructor" << std::endl;	
	delete[]array;
}
void specialarray::selection_sort_ascending(){
	int lowest = INT_MAX;
	int lowin;
	int temp;
	for(int i = 0; i < size - 1; i++){
		for (int j = i; j < size - 1; j++){
			if (array[j] < lowest){
				lowin = j;
				lowest = array[j];
			}
		}
		temp = array[i];
		array[i] = array[lowin];
		array[lowin] = temp;
		lowest = INT_MAX;
	}
}

void specialarray::selection_sort_descending(){
	int highest = INT_MIN;
	int highin;
	int temp;
	for(int i = 0; i < size - 1; i++){
		for (int j = i; j < size - 1; j++){
			if (array[j] > highest){
				highin = j;
				highest = array[j];
			}
		}
		temp = array[i];
		array[i] = array[highin];
		array[highin] = temp;
		highest = INT_MIN;
	}
}

void specialarray::printarray(){
	if (size == 0) {
		std::cout << "empty array" << std::endl;
	}
	for (int i = 0; i < size - 1; i++){
		std::cout << *(array + i) << std::endl;
	}
}


int main(int argc, char **argv) {
	specialarray a2(10);	
	specialarray a(10);
	a.printarray();
	int userinput;
	std::cout << "choose a number to find: ";
	std::cin >> userinput;
	int b = a.search(userinput);
	if(b == -1){
		std::cout << "not found" << std::endl;
	} else {
		std::cout << " at index " << b << std::endl;
	}
	std::cout << std::endl;
	a.bubble_sort_ascending();
	a.printarray();
	std::cout << "testing assert in function at()" << std::endl;
	a.at(4);
	a.printarray();
	std::cout << std::endl;
	a2.printarray();
	a.swap(&a, &a2);	
	a.printarray();
	
	return 0;
}
