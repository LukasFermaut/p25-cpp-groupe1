#pragma once
#include <iostream>
#include <stdexcept>

// the type int is not a good type for indice of for-loop
// inc++ you must use the type std::size_t
// a std::size_t object:
//   - is positive
//   - it can store the maximum size of an array or object

// we enclose the stack definition in a namespace named my_library (for example)
namespace my_library
{
    template <class T, std::size_t SIZE>
    class Stack
    {
        // write
        template <class U, std::size_t S>
        friend std::ostream &operator<<(std::ostream &os,
                                        const Stack<U, S> &st);
        // read
        template <class U, std::size_t S>
        friend std::istream &operator>>(std::istream &os,
                                        Stack<U, S> &st);

        std::size_t size = SIZE;
        std::size_t nb = 0;
        T tab[SIZE];

    public:
        Stack() : size(SIZE), nb(0)
        {
            if (size <= 0)
                throw std::length_error("Stack size must be non null");
        }

        void push(T val); // we defined this method outside the class

        bool is_empty() const
        {
            return nb == 0;
        }

        bool is_full() const
        {
            return nb == size;
        }

        T top() const
        {
            if (is_empty())
                throw std::length_error("Stack is empty");
            return tab[nb - 1];
        }

        T pop()
        {
            if (is_empty())
                std::length_error("Nothing to pop");
            nb = nb - 1;
            return tab[nb];
        }
    };
    // definition of the method push:it must be inline
    template <class T, std::size_t S>
    inline void Stack<T, S>::push(T val)
    {
        if (is_full())
            throw std::length_error("Stack is full");
        tab[nb] = val;
        nb = nb + 1;
    }

    template <class T, std::size_t S>
    inline std::ostream &operator<<(std::ostream &os, const Stack<T, S> &st)
    {
        // st.print();
        os << "[ ";
        for (std::size_t i = 0; i < st.nb; i++)
        {
            os << st.tab[i] << " ";
        }
        os << "[" << std::endl;
        return os;
    }
} // no need of a ; after a namespace definition

// note that we can re-open a namespace
// inside the same file or in another file
namespace my_library
{
    // this the method to read an object (here of type Stack)
    // i want to enter the number of objects to add to the stack (then <enter>)
    // then each elements (each followed by <enter>)
    template <class U, std::size_t V>
    inline std::istream &operator>>(std::istream &is, Stack<U, V> &st)
    {
        // we read the number of values to push
        std::size_t n;
        is >> n;
        // if the number is correct nb + n <= size
        // we read and push n values
        if (n + st.nb > st.size)
            throw std::length_error("cannot read that much element (... find a better message !!)");
        else
            for (std::size_t i = 0; i < n; ++i)
            {
                int value;
                is >> value;
                st.push(value);
            }
        return is;
    }
}
