#include <iostream>

class Buffer{
    friend class Matrix;
private:
    int size;
    double* tab;  //adresse du 1er element du tableau, a besoin de size
    int compteur;
public: 
    Buffer(int s,init=0): size(s),compteur(0){    // constructeur 
        tab=new double[s];
        reste(init)
    }
    void reset(int value){
        for (int i=0;i<size;i++)
        {
            tab[i]=value;   // quand on met une instruction on peut ne pas mettre d'accolade mais des qu'il y en a 2 c obligatoire
        }
    }
    void set(int i, int value){
        if (valid_index(i)){
            return tab[i];}  //sinon lancer exception
    }
    ing get_counter(){
        return counter;  //rajouter une fonction inrease counter, ou decremente buffer
    }
    ~Buffer(){
        delete[] tab;
    }
};

class Matrix{
    Buffer *B;
    int ligne;
    int colonne;

public:  
    Matrix(int l, int c): ligne(l), colonne(c){
        int size=l*c;
        B=new Buffer(size,init);
        B->compteur +=1;
    }
private:
    Matrix(int l, int c, Buffer* b): ligne(l), colonne(c), B(b){
        B->compteur +=1;
    }

    ~Matrix(){
        B->compteur += -1;
        if(B->compteur==0){
            delete B;
        }
    }
public:
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
        if (i*j != ligne*colonne){
            throw std::invalid_argument("Reshape incompatible")
        }
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