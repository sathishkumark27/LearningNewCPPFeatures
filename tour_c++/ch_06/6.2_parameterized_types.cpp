#include<iostream>
#include<stdexcept>
#include<list>
using namespace std;

/*
The template<typename T> prefix makes T a parameter of the declaration it prefixes. It is C++’s version 
of the mathematical ‘‘for all T’’ or more precisely ‘‘for all types T.’’ 
*/

template<typename T> 
class Vector
{
    private:
        int sz;
        T* elem;
    public:
        explicit Vector(int s);
        Vector(initializer_list<T> lst):sz{static_cast<int>(lst.size())}, elem{new T[sz]}
        {
            copy(lst.begin(), lst.end(), elem);
        }
        ~Vector(){delete[] elem;}
        // .. copy and move operations
        T& operator[](int i){ return elem[i];} // for non-const vectors
        const T& operator[](int i) const; // for const vectors
        int size() const {return sz;}
        T* begin();
        T* end();
};

template<typename T>
Vector<T>::Vector(int s)
{
    if (s <0)
    {
        throw out_of_range{"negative init size"};
    }
    sz = s;
    elem = new T[sz];
}

template<typename T>
const T& Vector<T>::operator[](int i) const
{
    if (i < 0)
    {
        throw out_of_range{"negative value"};
    }   
    return elem[i];
}

void write(const Vector<string>& vs)
{
    for (auto i=0; i!=vs.size(); ++i)
    {
        cout<<"vs["<<i<<"] = "<<vs[i]<<endl;
    }
}

/* To support the range-for loop for our Vector, we must define suitable begin() and end() functions */
template<typename T>
T* Vector<T>::begin()
{
    return sz ? &elem[0] : nullptr;
}

template<typename T>
T* Vector<T>::end()
{
    return sz ? &elem[0] + sz : nullptr;
}

void write1(Vector<string>& v)
{
    for (auto& s : v)
    {
        cout<<s<<endl;
    }
}

int main()
{    
    Vector<char> vc={'a','b', 'c', 'd', 'e'};
    //Vector<double> vd= 5; // conversion error
    Vector<double> vd{1,2,3,4,5};
    Vector<string> vs = {"abc", "def", "ghi", "jkl", "mno"};
    Vector<list<int>> vli = {{1,2,3}, {4,5,6}, {7,8,9}, {10,11,12}, {13,14,15}};
    write(vs);
    write1(vs);
}
