#include <iostream>
const int MAXLINE = 99;
char arr[MAXLINE][MAXLINE];
void arrinit() {
    for (int i = 0; i < MAXLINE; i++){
        for (int j = 0; j < MAXLINE; j++){
            arr[i][j] = ' ';
        }
    }
}

void prsp(int a) {
    for (int i = 0; i < a; i++) {
        std::cout << " ";
    }
}

void prst(int b) {
    for (int i = 0; i < b; i++) {
        std::cout << "*";
    } 
    std::cout << std::endl;
}

void prarr(int a) {
    for (int i = 0; i < a; i++) {
        for (int j = 0; j < a; j++) {
            std::cout << arr[i][j];
        } std::cout << std::endl;
    }
}

void prpat(int tl) {
    int numsp = tl / 2;
    int numst = 1;
    for (int i = 0; i < tl; i++) {
        prsp(numsp);
        prst(numst);
        for (int j = 0; j < numst; j++) {
            arr[numsp + j][i] = '*';
         }
        if (i >= tl / 2) {
            numst = numst - 2;
            numsp++;
        }
        else {
            numst = numst + 2;
            numsp--;      
        }
    }
}

int main()
{
    int lines;
    std::cout << "please pick an odd number between 3 and " << MAXLINE << ": ";
    std::cin >> lines;
    if (lines < 3 || lines > MAXLINE) {
        std::cout << "invalid";
        exit(0);
    } 
    if ( (lines % 2) == 0 ) {
        lines = lines + 1;
    }
    arrinit();
    prpat(lines);
    std::cout << "testing array\n";
    prarr(lines);
}
