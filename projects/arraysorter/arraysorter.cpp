#include <iostream>
int testarr[8] = { 9,2,17,18,16,3,4,11 };
int testarr1[12] = { 6,22,1,-8,6,12,-4,13,34,-100,61,7 };
int testarr2[10] = { 9,4,7,14,16,9,4,11,8,-22 };
void swapasc(int *c, int a, int b) {
    if (c[b] < c[a]) {
        int t = c[b];
        c[b] = c[a];
        c[a] = t;
    }
}
void swapdesc(int* c, int a, int b) {
    if (c[b] > c[a]) {
        int t = c[b];
        c[b] = c[a];
        c[a] = t;
    }
}

void acsendsort(int *a, int size){
    for (int i = 0; i <= size - 1; i++) {
        for (int j = 0; j <= size - 2; j++) {
          swapasc(a,j,j + 1);
        }
    }
}
void descendsort(int* a, int size) {
    for (int k = 0; k <= size - 1; k++) {
        for (int l = 0; l <= size - 2; l++) {
            swapdesc(a, l, l + 1);
        }
    }
}

void prarr(int *a, int size) {
    for (int i = 0; i < size; i++) {
        std::cout << a[i] << " ";
    }
    std::cout << std::endl;
}
int main(){
    prarr(testarr2, 8);
    descendsort(testarr2, 8);
    prarr(testarr2, 8);
}
