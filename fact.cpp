#include <iostream>
#include <cstdlib>

int main(int argc, char *argv[]){
    int s=1;
    if(std::atoi(argv[1])==0){
        std::cout << "1" << std::endl;
        return 0;
    }
    
    for (int i=1;i <= std::atoi(argv[1]);i++){
        s=s*i;
    }
        std::cout << s << std::endl;

    return 0;
}