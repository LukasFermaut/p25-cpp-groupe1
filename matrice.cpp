#include <iostream>

struct Buffer{
    int size;
    int compteur;
    double* tab;
    Buffer(int s): size(s){
        compteur=0;
        tab=new double[s];
    }
    ~Buffer(){
        delete[] tab;
    }
};

struct Matrix{
    int ligne;
    int colonne;
    Buffer* B;
    
    Matrix(int l, int c): ligne(l), colonne(c){
        int size=l*c;
        B=new Buffer(size);
        B->compteur +=1;
    }

    
    Matrix(int l, int c, Buffer* b): ligne(l), colonne(c), B(b){
        B->compteur +=1;
    }

    ~Matrix(){
        B->compteur += -1;
        if(B->compteur==0){
            delete B;
        }
    }
    void print(){
        for(int i=0;i<ligne;i++){
            for(int j=0;j<colonne;j++){
                std::cout<<B->tab[i*colonne+j]<<" ";
            }
            std::cout<<std::endl;
        }
    }
    void set(int i, int j, double v){
        B->tab[i*colonne+j]=v;
    }
    double get(int i, int j){
        return B->tab[i*colonne+j];
    }
    Matrix reshape(int m, int n){
        return Matrix(m,n,B);
    }

};

int main(){
    Matrix m(4,3);
    m.set(0,0,17.3);
    double d=m.get(0,0);
    m.print();
    Matrix h=m.reshape(2,6);
    h.print();
    h.set(0,0,21.3);
    h.print();
    return 0;
}