#include<iostream>
#include<vector>
using namespace std;

/*
default vec doesnot guarantee ranger checking
*/
template<class T>
void range_check(T& v)
{
    int i = v[v.size()];
    cout<<"i = "<<i<<endl;
}
/*
we can overload the operator [] with at() to throw exception for ou_of_range access.
This is similar to strings [] doesnot guarantee range checking but .at() does */
template<typename T>
class Vec : public std::vector<T>
{
    public:
        /*
        using Base::Base(constructor)
        use the constructors from vector (under the name Vec)
        https://stackoverflow.com/questions/20790932/what-is-the-logic-behind-the-using-keyword-in-c
        */
        using vector<T>::vector;
        T& operator[](int i)
        {
            return vector<T>::at(i); //range checking
        }
        const T& operator[](int i) const
        {
            return vector<T>::at(i);
        }
};

int main()
{
    vector<int> v1 = {1,2,3,4,5}; // standard vec doesnot guarantee range checking
    range_check(v1);
    try
    {
        range_check(v1);
    }
    catch(const std::exception& e)
    {
        cout<<"for V1"<<endl;
        std::cerr << e.what() << '\n';
    }
    Vec<int> v2 = {1,2,3,4,5}; // Vec guarantees range checking
    try
    {
        range_check(v2);
    }
    catch(const std::exception& e)
    {
        cout<<"for V2"<<endl;
        std::cerr << e.what() << '\n';
    }
    
}