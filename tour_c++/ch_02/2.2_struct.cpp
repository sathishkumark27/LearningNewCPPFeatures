#include <iostream>
using namespace std;

struct Vector
{
    int sz;  // size of int 4 + 4 byte padding
    double* elem; // size of pointer to a double i.e is 8 bytes 64bit system
};

void vector_init(Vector& v, int s)
{
    v.sz = s;
    v.elem = new double[s];

}

double read_and_sum(int s)
{
    cout<<" Enter "<<s<<"elements"<<endl;
    Vector v;
    vector_init(v, s);
    for (auto i = 0; i!=s; ++i)
    {
        cin>>v.elem[i];
    }

    double sum = {0};
    for (auto i =0; i!=s; ++i)
    {
        sum+=v.elem[i];
    }

    return sum;  

}

int main()
{
    Vector v;
    vector_init(v, 4);
    cout<<"size of vector = "<<sizeof(v)<<endl; //size of struct is always 16
    cout<<"size of vector elem = "<<sizeof(v.elem)<<endl; // size of elem (pointer) is always 8
    cout<<"vector sz = "<<v.sz<<endl;
    double sum = {0};
    sum = read_and_sum(5);
    cout<<"Sum = "<<sum<<endl;
}