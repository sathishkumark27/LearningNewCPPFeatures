#include<iostream>
#include<vector>
#include<list>
#include<complex>

using namespace std;

/*
https://stackoverflow.com/questions/2354210/can-a-class-member-function-template-be-virtual

Templates are all about the compiler generating code at compile-time. 
Virtual functions are all about the run-time system figuring out which function to call at run-time.
Once the run-time system figured out it would need to call a templatized virtual function, 
compilation is all done and the compiler cannot generate the appropriate instance anymore. 
Therefore you cannot have virtual member function templates. 
*/
template<typename Sequence, typename Value>
Value sum(const Sequence& lst, Value v)
{
    
    for (auto i : lst)
    {
        v+=i;
    }
    cout<<&v<<endl;
    return v;
}

template<typename T>
void explicit_template(T v)
{
    cout<<"v = "<<v<<endl;
}

template<typename T>
void explicit_template2(T x, T y)
{
    cout<<"sum = "<<x+y<<endl;
}

void user(vector<int>& vi, list<double>& ld, vector<complex<double>>& vc)
{
    int x = sum(vi, 0); // at compile time copy of sum with vector<int> input and int v is genrated -- type is deduced from arguments
    cout<<"x = "<<x<<endl;

    double y = sum(ld, 0.0); // at compile time copy of sum with list<double> input and double v is genrated
    cout<<"y = "<<y<<endl;

    complex z = sum(vc, complex{0.0,0.0});
    cout<<"z = "<<z<<endl;

}

int main()
{
    vector<int> vi = {1,2,3,4,5};
    list<double> ld = {1.0, 2.0, 3.0, 4.0, 5.0};
    vector<complex<double>> vc = {{1.0,2.0}, {3.0,4.0}, {5.0,6.0}};
    user(vi, ld, vc);

    explicit_template(20); // type deduced from 20 as int
    //if I want ro promote the type to double explicitly
    explicit_template("abc"); // treated as char*
    explicit_template<std::string>("abc"); // treated as string explicitly telling
    int x = 10;
    double y = 20.0;
    //explicit_template2(x, y); deduced type gives error -- no instance of function template "explicit_template2" matches the argument list -- argument types are: (int, double)
    explicit_template2<int>(x, y); // explict 
}