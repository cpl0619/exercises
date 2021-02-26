#include <iostream>
char arr[99][99];
void initarr() {
    for (int i = 0; i < 99; i++) {
        for (int j = 0; j < 99; j++) {
            arr[i][j] = ' ';
        }
    }
}

void prarr(int l, int w) {
    for (int i = 0; i < l; i++) {
        for (int j = 0; j < w; j++) {
            std::cout << arr[i][j];
        }
        std::cout << std::endl;
    } 
}

void prsp(int totalspace){
    for (int i = 0; i < totalspace; i++) {
        std::cout << " ";
    }
}

void prpat(int l, int w) {
    if (l > 99 || w > 99 || l <= 0 || w <= 0) {
        return;
    }
    for (int i = 0; i < l; i++) {
        if (i == l - 1 || i == 0 || i == l / 2) {
            for (int j = 0; j < w; j++) {
                arr[i][j] = '*';
                std::cout << '*';
            }
        }
        else {
            arr[i][0] = '*';          
            arr[i][w / 2] = '*';
            arr[i][w - 1] = '*';
            std::cout << '*';
            prsp(w / 2 - 1);
            std::cout << '*';
            prsp(w / 2 - 1);
            std::cout << '*';
        } 
        std::cout << std::endl;
    }
}
int main()
{
    int w;
    int l;
    //initarr();
    std::cout << "enter length: ";
    std::cin >> l;
    std::cout << "enter width: ";
    std::cin >> w;
    if (w > 99 || l > 99 || w <= 0 || l <= 0) {
        std::cout << "invalid";
    }
    prpat(l, w); 
    std::cout << "testing array" << std::endl;
    prarr(l, w);
}
