#include <iostream>
#include <stdio.h>
#include <time.h>
using namespace std;

class card {
public:
	int suite;
	int number;
};
// Suite: 0 = diamonds, 1 = clubs, 2 = hearts, and 3 = spades
// Numbers: 1 = Ace, 2 - 10 = 2 - 10, 11 = jack, 12 = queen, 13 = king
class deck {
public:
	int size = 52;
	card Newdeck[52];

	deck() { deckinit(); }
	~deck(){}
	void deckinit();
	void Cardshuffle();
	void printdeck();
};

void deck::Cardshuffle() {
	int n;
	card temp;
	srand(time(NULL));
	for(int i = size-1; i > 0; i--){
		n = rand() % i;
		temp.suite = Newdeck[i].suite;
		temp.number = Newdeck[i].number;
		Newdeck[i].suite = Newdeck[n].suite;
		Newdeck[i].number = Newdeck[n].number;
		Newdeck[n].suite = temp.suite;
		Newdeck[n].number = temp.number;

	}
}

void deck::deckinit() {
	int s = 0;
	for(int i = 0; i < size; i++){
		if(i > 0 & i % 13 == 0){
			s++;
		}
		Newdeck[i].suite = s;
		Newdeck[i].number = (i % 13) + 1;
	}
}

void deck::printdeck() {
	for (int i = 0; i < size; i++){

		std::cout << Newdeck[i].suite << ",";
		std::cout << " " << Newdeck[i].number << std::endl;

	}
}



int main(int argc, char **argv) {

	deck a;
	a.printdeck();
	a.Cardshuffle();
	std::cout << std::endl;
	a.printdeck();

	return 0;

}
