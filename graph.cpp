#include <iostream>
#include <vector>
#include <stdexcept>
#include <algorithm>


struct Edge{
    double poids;
    int* begin;
    int* end;
    Edge(int* b,int* e, double p):begin(b),end(e),poids(p){}

    void print(){
        std::cout<<begin<<" "<<poids<<" "<<end<<std::endl;
    }
    ~Edge(){};
};

struct Vertex{
    int id;
    std::vector<Edge*> n;
    Vertex(int i):id(i){}
    void print(){
        for(int i=0;i<n.size();i++){
            n[i]->print();
        }
    }
    ~Vertex(){};

};

struct Graph{
    std::vector<Vertex*> v;
    void addEdge(int b,int e,double p){
        while(v.size()<=std::max(b,e)){
            addvertex(v.size());
        }
        v[b]->n.push_back(new Edge(&b,&e,p));

    }
    void addvertex(int i){
        v.push_back(new Vertex(i));
    }
    void print(){
        for(int j=0;j<v.size();j++){
            v[j]->print();
        }
    }
    void depthsearch(){
        
    }
};

int main(){
    Graph g;

    g.addEdge(2,5,17.9);
    g.addEdge(5,3,23.9);
    g.addEdge(4,0,699.9);
    g.print();

    return 0;
}