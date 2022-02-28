#include <iostream>
#include <stdio.h>
#include <time.h>
using namespace std;

class card {
public:
	int suite;
	int number;
};
// Suite: 0 = hearts, 1 = diamonds, 2 = clubs, and 3 = spades
// Numbers: 1 = Ace, 2 - 10 = 2 - 10, 11 = jack, 12 = queen, 13 = king
// Value (most value to least): Spades, clubs, diamonds, hearts
class deck {
public:
	static const int size = 52;
	card Newdeck[size];
	deck() { deckinit(); }
	~deck(){}
	void deckinit();
	void Cardshuffle();
	void printdeck();
	int morevaluablecard(card firstcard, card secondcard);
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
		
		if (Newdeck[i].number == 1) {
			std::cout << "Ace of ";
		} else if (Newdeck[i].number == 11) {
			std::cout << "Jack of ";
	    } else if (Newdeck[i].number == 12) {
			std::cout << "Queen of ";
	    } else if (Newdeck[i].number == 13) {
			std::cout << "King of ";
	    } else  {	
	    	std::cout << Newdeck[i].number << " of ";
	    }
		
		if (Newdeck[i].suite == 0){
			std::cout << "Diamonds" << std::endl;
		}
		else if (Newdeck[i].suite == 1) {
			std::cout << "Clubs" << std::endl;
		}
		else if (Newdeck[i].suite == 2) {
			std::cout << "Hearts" << std::endl;
		}
		else if (Newdeck[i].suite == 3) {
			std::cout << "Spades" << std::endl;
		}

	}
}

// return value: 0 = first card is more valuable, 1 = second card is more valuable, -1 = error
int deck::morevaluablecard(card firstcard, card secondcard) {
	if(firstcard.suite == secondcard.suite){
		return -1;
	}
	if(firstcard.number > 13 || secondcard.number > 13) {
		return -1;
	}
	if(firstcard.number < 1 || secondcard.number < 1) {
		return -1;
	}
	if(firstcard.suite > 3 || secondcard.suite > 3) {
		return -1;
	}
	if(firstcard.suite < 0 || secondcard.suite  < 0) {
		return -1;
	}

	if(firstcard.number == 1 && secondcard.number != 1){
		return 0;
	} else if (secondcard.number == 1 && firstcard.number != 1) {

		return 1;

	} else if (firstcard.suite + firstcard.number > secondcard.suite + secondcard.number) {
		
		return 0;
	}

	return 1;
	
}

int main(int argc, char **argv) {

	deck a;
	a.printdeck();
	a.Cardshuffle();
	std::cout << std::endl;
	a.printdeck();
	std::cout << std::endl;

	card first;
	card second;

	first.number = 11;
	first.suite = 2;
	second.number = 19;
	second.suite = -1;
	
	std::cout << a.morevaluablecard(first, second);

	return 0;

}
