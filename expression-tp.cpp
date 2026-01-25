/*

implement a hierarchy of classes for arithmetic expression manipulations:
    - the classes holds, evaluates and prints arithmetic expressions
    - print in infix, prefix or postfix notation

Additional work:
   - note that the postfix notation is also called Reverse Polish notation (RPN)
   - it is a mathematical notation in which operators follow their operands
   - this notation does not need any parentheses i.e. this notation is non ambigu
   - => you can read (easily) RPN expressions using a stacks
  implement a code to read RPN expression and store them with your class objects
  RPN arithmetic expression are passed as main command-line arguments

./main 87 12 - + 75 -
*/
#include <iostream>
Class Op{//je vois pas quoi mettre dedans
    };
Class Constant: public Op{
    double value;
    Constant(double v):value v{}
    void print(){
        std::cout<<value<<std::endl;
    }
    void eval(){
        return value;
    }
};
Class Plus: public Op{
    Constant Expression& droite;
    Constant Expression& gauche;
    public:
    Plus(Constant d, Constant g):droite(d),gauche(g){}
    double eval{
        return droite.eval()+gauche.eval()
    }
    void print{
        gauche.print();
        droite.print();
        std::cout<<'+'<<std::endl;
    }
};
Class UnaryMinus:public Op{
    Constant Expression& nb;
    public:
    UnaryMinus( Constant n):nb(n){}
    double eval{
        return -nb.eval();
    }
    void print{
        nb.print();
        std::cout<<'-'<<std::endl;
    }
}
Class Divide:public Op{
    Constant Expression& numerateur;
    Constant Expression& dénominateur;
    public:
    Plus(Constant n, Constant d):numerateur(n),denominateur(d){}
    double eval{
        if (denominateur.eval()==0){
            throw std::runtime_error("Division par zero !");
        }
        return numerateur.eval()/denominateur.eval()
    }
    void print{
        numérateur.print();
        dénominateur.print();
        std::cout<<'/'<<std::endl;
    }
}

int main()
{
    try
    {
        // Constant c1(12), c2(-87), c3(23); // try it (-87 is not an unsigned int)
        Constant c1(12), c2(87), c3(75);

        c1.print(); // affiche 12
        std::cout << std::endl;
        std::cout << "eval " << c1.eval() << std::endl; // affiche 12

        UnaryMinus u1(c1);
        u1.print(); // affiche 12 -
        std::cout << std::endl;
        std::cout << "eval " << u1.eval() << std::endl; // affiche -12

        Plus p1(c2, u1);
        p1.print(); // affiche 87 12 -+
        std::cout << std::endl;
        std::cout << "eval " << p1.eval() << std::endl; // affiche 75

        Minus m1(p1, c3);
        m1.print(); // 87 12 -+75 -
        std::cout << std::endl;
        std::cout << "eval " << m1.eval() << std::endl; // affiche 0

        Divide d1(p1, m1);
        std::cout << std::endl;
        std::cout << d1.eval() << std::endl; // throws an instance of 'std::runtime_error'

        std::vector<???> expr;
        expr.push_back(???c1);
        expr.push_back(???u1);
        // parcourez le vecteur
    }
    catch (std::runtime_error &e)
    {
        // affiche zero divide error
        std::cout << e.what() << std::endl;
    }
    return 0;
}
