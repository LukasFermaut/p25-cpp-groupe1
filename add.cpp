#include <cstdlib>
#include <iostream>

int main(int argc, char *argv[]){
    if (argc<2) {
        std::cout << "not enough arguments" << std::endl;
    }
    int s=0;
    for (int i = 0; i < argc; i++){
        s+=std::atoi(argv[i]);
    }
    std::cout << "Résultat " << s << std::endl;

    return 0;
}