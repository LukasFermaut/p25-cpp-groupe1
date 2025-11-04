#include <iostream>

void swap(int* a,int* b){
    int t=*a;
    *a=*b;
    *b=t;
}

int main(){
    int j = 12;
    int i= 17;

    swap(&i,&j);
    std::cout << std::boolalpha <<((i==12) and (j==17) == true)<< std::endl;
    return 0;
}