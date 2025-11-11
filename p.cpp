#include <iostream>

void push(int* tab[],int size, int nb, int a){
    if(nb<size)
    {*(tab+nb)=a
        n=n+1
    }
    return 0;
}

void print(int* tab,int size,int nb){
    std::cout<< '[';
    for(int i=0, i<size, i++){
        std::cout<< tab[i];
        if(i<nb-1) std::cout<<',';
    }
    std::cout<< ']' <<std::endl;
}

int pop(tab,size,nb){
    
}

int main(){
    int size=5;
    int tab[size];
    int nb = 0;
    push(tab,size,nb, -17);
    push(tab,size,nb,90);
    print(tab,size, nb);
    int e=pop (tab,size,nb);
}