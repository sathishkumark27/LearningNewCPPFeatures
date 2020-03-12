#include<iostream>
#include<string>
using namespace std;

// void print()
// {
//     // what we do for no arguments: nothing

// }

/*
The typename... indicates that Tail is a sequence of types. The Tail... indicates that tail is a sequence
of values of the types in Tail. A parameter declared with a ... is called a parameter pack. Here, tail
is a (function argument) parameter pack where the elements are of the types found in the (template
argument) parameter pack Tail. So, print() can take any number of arguments of any types.

*/
template<typename T, typename... Tail> // arbitrary no.of(typename... == exactly 3 dots) args of arbitrary types
void print(T head, Tail... tail)
{
    cout<<head<<" ";
    /*
    A call of print() separates the arguments into a head (the first) and a tail (the rest). The head is
    printed and then print() is called for the tail. Eventually, of course, tail will become empty, so we
    need the no-argument version of print() to deal with that. If we don’t want to allow the zero-argu-
    ment case, we can eliminate that print() using a compile-time if:
    I used a compile-time if (§6.4.3), rather than a plain run-time if to avoid a final, never called, call
    print() from being generated.

    */
    if constexpr (sizeof...(tail) > 0) // if you remove this empty args print call check add the empty print which we have commented above
    {
        print(tail...);
    }
    
}

int main()
{
    print("cstring(char*)", 1,2.2,'x',"string"s,'\n');
}
