#include "fibonacci.h"


int Fibonacci_recursive(int n){
    if (n < 3)
        return 1;
    else
        return Fibonacci_recursive(n-1) + Fibonacci_recursive(n-2);
}

int Fibonacci_iterative(int n){
    int f1 = 1 , f2 = 1;
    int fn, i;

    if (n < 3)
        return 1;
    
    for(i = 3; i <= n; i++){
        fn = f2 + f1;
        f2 = f1;
        f1 = fn;
    }
    return fn;
}
