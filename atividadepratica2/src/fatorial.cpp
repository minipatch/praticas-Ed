#include "fatorial.h"

int Factorial_recursive(int n){
    if(n <= 0)
        return 1;
    else
        return n * Factorial_recursive(n-1);
}

int Factorial_iterative(int n){
    int f = 1;
    while(n > 0){
        f = f * n;
        n = n - 1;
    }
    return f;
}