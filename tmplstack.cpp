#include <iostream>
#include <stdexcept>
#include "tmplstack.h"

int main()
{

    try
    {
        // the type Stack is defined inside the namespace my_library
        my_library::Stack<int, 20> st1;
        st1.push(1);
        st1.push(2);
        std::cout << st1 << std::endl;
        std::cout << "type the number of element you want to add to your stack (then return) then each element followed by return: ";
        std::cin >> st1;
        std::cout << "you created the stack " << st1 << std::endl;

        // user is given access directly to the Stack type
        using my_library::Stack;
        // we do not need to precise my_library::
        Stack<char, 0> st2; // pas besoin de préciser
        st2.push('a');
        st2.push('b');
        std::cout << st2 << std::endl;
    }
    catch (std::length_error &e)
    {
        std::cout << e.what() << std::endl;
    }
    return 0;
}