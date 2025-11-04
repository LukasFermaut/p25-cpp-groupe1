#include <iostream>
#include <cstdlib>

int main(int argc, char *argv[]){
    int s=1;
    if(std::atoi(argv[1])==0){
        std::cout << "0" << std::endl;
    }
    else{
        for (int i=1;i <= std::atoi(argv[1]);i++){
        s=s*i;
    }
        std::cout << s << std::endl;
    }
    return 0;
}