#include<iostream>
using namespace std;

template<typename T, int N>
struct Buffer
{
    using value_type = T;
    constexpr int size(){return N;};
    T* data = new T[N];
};

    
int main()
{
    /*  A template value argument must be a constant expression. 
        The alias (value_type) and the constexpr function are provided to allow users (read-only) access to
        the template arguments.
        Vector(int s); --> in prev example code, it run time argument for vector constructor
    */

    Buffer<char, 5> buf;
    cout<<"Buffer Size = "<<buf.size()<<endl;
    Buffer<char, 15> buf2; // template argument allows us to define diff sizes of buffer
}