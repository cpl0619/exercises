#include <iostream>
#include <stdio.h>
#include <time.h>
#include <climits>
#include <assert.h>

class specialarray{
private:
	int size;
	int *array;
public:
	specialarray();
	specialarray(int arrsize);
	specialarray(const specialarray &r);
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
	specialarray addarrays(specialarray b);
	int sumarrays(specialarray a, specialarray b);
	int subtractarrays(specialarray a, specialarray b);
	int multiplyarrays(specialarray a, specialarray b);
	int dividearrays(specialarray a, specialarray b);
	specialarray& operator=(const specialarray &r);
	specialarray& operator+(const specialarray &r);
	specialarray& operator-(const specialarray &r);
	specialarray& operator*(const specialarray &r);
	specialarray& operator/(const specialarray &r);
	specialarray& operator+=(const specialarray &r);
	int& operator[](int r);
	int operator>(specialarray &r);
	int operator<(specialarray &r);
	int operator==(specialarray &r);
	// add these member functions:
	// push back, pop back, resize, empty, swap
	// overload operator[], insert
	// relational operators (==, !=, <, >, <=, >=)
	// +, -, *, /, %, a+=b,
};
//this function builds and compiles okay but does not work until
//we overload the assignment operator "="

int& specialarray::operator[](int r){
	assert (r >= 0 && r < this->size);
	return this->array[r];
}


int specialarray::operator<(specialarray &r){
	if(this->sum() < r.sum()){
		return 1;
	}
	return 0;
}

int specialarray::operator>(specialarray &r){
	if(this->sum() > r.sum()){
		return 1;
	}
	return 0;
}

int specialarray::operator==(specialarray &r){
	if(this->size == r.size && this->sum() == r.sum()){
		return 1;
	}
	return 0;
}


specialarray& specialarray::operator+(const specialarray &r){
	//condition 1; r.size == 0

	//condition 2: r.size != 0
	if (r.size != 0){
		if (this->size == 0){
			//specialarray a
			//specialarray b(5)
			//specialarray c = a + b;
			//created new array for this object
			this->size = r.size;
			array = new int[r.size];
			for(int i = 0; i < r.size; i++){
				this->array[i] = 0;
			}
		} else {
		//specialarray a(5)
		//specialarray b(5)
		//specialarray c = a + b;
		//condition 3: r.size < this->size
		//condition 4: r.size > this->size
		//for either condition, delete existing array
		//and create new array and copy old array elements
		
			if (this->size != r.size){
			//specialarray a(5)
			//specialarray b(4)
			//specialarray c = a + b;
				//specialarray temp = *this;
				specialarray temp;
				temp = *this;
				delete [] this->array;
				this->size = r.size;
				this->array = new int[r.size];
				for (int i = 0; i < r.size; i++){
					this->array[i] = temp.array[i];
				}
				if (temp.size < r.size){
				//specialarray a(5)
				//specialarray b(6)
				//specialarray c = a + b;
					for (int i = temp.size; i < r.size; i++){
						this->array[i] = 0;
					}
				}
		 
			}
		}
		for(int i = 0; i < r.size; i++){
			this->array[i] = this->array[i] + r.array[i];    
		}
	}		
	return *this;
}

specialarray& specialarray::operator+=(const specialarray &r){
	*this = *this + r;	
	return *this;
}

specialarray& specialarray::operator-(const specialarray &r){
	//condition 1; r.size == 0

	//condition 2: r.size != 0
	if (r.size != 0){
		if (this->size == 0){
			//specialarray a
			//specialarray b(5)
			//specialarray c = a + b;
			//created new array for this object
			this->size = r.size;
			array = new int[r.size];
			for(int i = 0; i < r.size; i++){
				this->array[i] = 0;
			}
		} else {
		//specialarray a(5)
		//specialarray b(5)
		//specialarray c = a + b;
		//condition 3: r.size < this->size
		//condition 4: r.size > this->size
		//for either condition, delete existing array
		//and create new array and copy old array elements
		
			if (this->size != r.size){
			//specialarray a(5)
			//specialarray b(4)
			//specialarray c = a + b;
				//specialarray temp = *this;
				specialarray temp;
				temp = *this;
				delete [] this->array;
				this->size = r.size;
				this->array = new int[r.size];
				for (int i = 0; i < r.size; i++){
					this->array[i] = temp.array[i];
				}
				if (temp.size < r.size){
				//specialarray a(5)
				//specialarray b(6)
				//specialarray c = a + b;
					for (int i = temp.size; i < r.size; i++){
						this->array[i] = 0;
					}
				}
		 
			}
		}
		for(int i = 0; i < r.size; i++){
			this->array[i] = this->array[i] - r.array[i];    
		}
	}		
	return *this;
}

specialarray& specialarray::operator*(const specialarray &r){
	//condition 1; r.size == 0

	//condition 2: r.size != 0
	if (r.size != 0){
		if (this->size == 0){
			//specialarray a
			//specialarray b(5)
			//specialarray c = a + b;
			//created new array for this object
			this->size = r.size;
			array = new int[r.size];
			for(int i = 0; i < r.size; i++){
				this->array[i] = 0;
			}
		} else {
		//specialarray a(5)
		//specialarray b(5)
		//specialarray c = a + b;
		//condition 3: r.size < this->size
		//condition 4: r.size > this->size
		//for either condition, delete existing array
		//and create new array and copy old array elements
		
			if (this->size != r.size){
			//specialarray a(5)
			//specialarray b(4)
			//specialarray c = a + b;
				//specialarray temp = *this;
				specialarray temp;
				temp = *this;
				delete [] this->array;
				this->size = r.size;
				this->array = new int[r.size];
				for (int i = 0; i < r.size; i++){
					this->array[i] = temp.array[i];
				}
				if (temp.size < r.size){
				//specialarray a(5)
				//specialarray b(6)
				//specialarray c = a + b;
					for (int i = temp.size; i < r.size; i++){
						this->array[i] = 0;
					}
				}
		 
			}
		}
		for(int i = 0; i < r.size; i++){
			this->array[i] = this->array[i] * r.array[i];    
		}
	}		
	if (r.size == 0){
		for(int i = 0; i < this->size; i++){
			this->array[i] = 0;
		}
	}
	return *this;
}

specialarray& specialarray::operator/(const specialarray &r){
	//condition 1; r.size == 0

	//condition 2: r.size != 0
	if (r.size != 0){
		if (this->size == 0){
			//specialarray a
			//specialarray b(5)
			//specialarray c = a + b;
			//created new array for this object
			this->size = r.size;
			array = new int[r.size];
			for(int i = 0; i < r.size; i++){
				this->array[i] = 0;
			}
		} else {
		//specialarray a(5)
		//specialarray b(5)
		//specialarray c = a + b;
		//condition 3: r.size < this->size
		//condition 4: r.size > this->size
		//for either condition, delete existing array
		//and create new array and copy old array elements
		
			if (this->size != r.size){
			//specialarray a(5)
			//specialarray b(4)
			//specialarray c = a + b;
				//specialarray temp = *this;
				specialarray temp;
				temp = *this;
				delete [] this->array;
				this->size = r.size;
				this->array = new int[r.size];
				for (int i = 0; i < r.size; i++){
					this->array[i] = temp.array[i];
				}
				if (temp.size < r.size){
				//specialarray a(5)
				//specialarray b(6)
				//specialarray c = a + b;
					for (int i = temp.size; i < r.size; i++){
						this->array[i] = 0;
					}
				}
		 
			}
		}
		for(int i = 0; i < r.size; i++){
			this->array[i] = this->array[i] / r.array[i];    
		}
	}		
	if (r.size == 0){
		for(int i = 0; i < this->size; i++){
			this->array[i] = 0;
		}
	}
	return *this;
}

specialarray& specialarray::operator=(const specialarray &r){
	if(this != &r){
		if (r.size == 0){
			//condition 1: r.size = 0
			this->size = 0;	
			if (this->array != NULL){
				delete [] this->array;
			}
			this->array = NULL;
		} else {		
			if (this->array == NULL){
				//condition 2: this->size = 0
				//created new array for this object
				this->size = r.size;
				array = new int[r.size];
			} else {
			//condition 3: r.size < this->size
			//condition 4: r.size > this->size
			//for either condition, delete existing array
			//and create new array
				if (this->size != r.size){
					delete [] this->array;
					this->size = r.size;
					this->array = new int[r.size];
				}
					
			}
			for(int i = 0; i < r.size; i++){
				this->array[i] = r.array[i]; 
			}
		}		
	}
	return *this;
}

specialarray specialarray::addarrays(specialarray b){
	specialarray temp1;
	if (this->size != b.size){
		return temp1;
	} 
	specialarray temp(this->size);
	for(int i = 0; i < this->size; i++){
		temp.array[i] = this->array[i] + b.array[i];
	}
	return temp;
}

int specialarray::sumarrays(specialarray a, specialarray b){
	int sumofarrays;
	sumofarrays = a.sum() + b.sum();
	return sumofarrays;
}

int specialarray::subtractarrays(specialarray a, specialarray b){
	int sumofarrays;
	sumofarrays = a.sum() - b.sum();
	return sumofarrays;
}

int specialarray::multiplyarrays(specialarray a, specialarray b){
	int sumofarrays;
	sumofarrays = a.sum() * b.sum();
	return sumofarrays;
}

int specialarray::dividearrays(specialarray a, specialarray b){
	int sumofarrays;
	sumofarrays = a.sum() / b.sum();
	return sumofarrays;
}

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
	for(int i = 0; i < size; i++) {
		// This is dereference method for pointers only
			*(array + i) = (rand() % 50) * size;
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

specialarray::specialarray(const specialarray &r){
	this->size = r.size;
	this->array = new int[r.size];
	for(int i = 0; i < r.size; i++){
		this->array[i] = r.array[i]; 
	}
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
	for (int i = 0; i < size; i++){
		std::cout << *(array + i) << std::endl;
	}
}

void foo(int a){
	std::cout << a << std::endl;
}

void bar(int *a){
	std::cout << *a << std::endl;
	std::cout << a << std::endl;
	*a = 10;
}

void blah(int &a){
	std::cout << a << std::endl;
	std::cout << a << std::endl;
	a = 11;
}

int main(int argc, char **argv) {
	specialarray a2(6);	
	specialarray a(5);
	std::cout << "a array" << std::endl;
	a.printarray();
	std::cout << std::endl;
	int var = a[4];
	std::cout << var << std::endl;
	a[2] = 1000;	
	a.printarray();
/*
	int hi;
	std::cout << "new a" << std::endl;
	hi = a < a2;
	std::cout << hi << std::endl;

/*
	std::cout << std::endl;
	std::cout << "a2 array" << std::endl;
	a2.printarray();
	specialarray b = a.addarrays(a2);
	std::cout << "b array" << std::endl;
	b.printarray();
*/
/*	specialarray c(5);
	std::cout << " printing c before assignment "  << std::endl;
	c.printarray();
	std::cout << std::endl;
	std::cout << "a2 array" << std::endl;
	a2.printarray();
	std::cout << std::endl;
	c += a2;
	std::cout << " printing c after "  << std::endl;
	c.printarray();
	c = c;
	std::cout << " printing c1 after "  << std::endl;
	c.printarray();
	//c += a2; //c = c + a2
	//	specialarray x(10);
	//x = a;
*/
//	specialarray b = a;
//	std::cout << "b array" << std::endl;
//	b.printarray();
	
	return 0;
}
