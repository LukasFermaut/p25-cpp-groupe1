#include <iostream>
#include <cstdlib>

int fibo(int n){
    if (n<=1){
        return n;
    }
    else{
        return fibo(n-1)+fibo(n-2);
    }
}

int main(int argc, char *argv[]){
    std::cout<<fibo(std::atoi(argv[1]))<<std::endl;
    return 0;
}

#include <chrono>

int fibonacci_it(int n){
    if (n==0)
        return 0;
    if (n==1)
        return 1
    int n_1=0, n_2=1;
    int fib
    for (int i=2;i<=n;i++){

    }
}


// on voit que la complécité du fibo récursif est exponentielle, bien trop grande par rapport à l'autre