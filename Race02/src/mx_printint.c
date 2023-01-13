#include "header.h"
void mx_printint(int n) {
    int counter = 0;
    int num[30];
    if (n < 0) {
        mx_printchar('-');
        n = -n;
    }
    if (n == 0)
        mx_printchar('0');
    while (n != 0) {
        num[counter] = n % 10;
        n /= 10;
        counter++;
    }
    while (counter > 0) {
        counter--;
        mx_printchar(num[counter] + 48);
    }
}


