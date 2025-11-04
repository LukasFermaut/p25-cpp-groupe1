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