#include <iostream>
#include <stdexcept>
class Stack{
private:
    int size;
    int nb;
    int* tab;
public:
    Stack (int s): nb(0){
        if (s<=0){
            throw std::runtime_error("Stack bad size");
        }
        size=s;
        tab=new int[size];} 
    bool is_full(){
        return nb>=size;
    }
    bool is_empty(){
        return nb==0;
    }
    void push(int v){
        if(is_full()){ 
            throw std::overflow_error("Pile pleine");
        }
        if(not is_full()){
            tab[nb]=v;
            nb+=1;
        }
    }
    Stack(const Stack& s){
        size=s.size;
        nb=s.nb;
        tab=new int[size];
        for (int i=0;i<nb;i++){
            tab[i]=s.tab[i];
        }
    }
    Stack& operator=(const Stack& s) {
        if (this != &s) {
            delete[] tab;
            size = s.size;
            nb = s.nb;
            tab = new int[size];
            for (int i = 0; i<nb; i++){
                tab[i] = s.tab[i];
            }
        }
        return *this;
    }
    int pop(){
    if (is_empty())
        throw std::overflow_error("pile vide");
    nb=nb-1;
    return tab[nb - 1];
    }
    int top(){
    if (is_empty())
        throw std::underflow_error("pile vide");
    return tab[nb - 1];
    }
    void print(){
   std::cout<< '[';
    for(int i=0; i<nb; i++){
        std::cout<< tab[i];
        if(i<nb-1){ std::cout<<',';}
    }
    std::cout<< '[' <<std::endl;
    }
~Stack(){
    delete [] tab;
}
};


