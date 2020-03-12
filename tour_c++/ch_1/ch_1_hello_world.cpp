#include<iostream>
using namespace std;

double square(double x)
{
    return x*x;
}

int main()
{
    double x = 1.235;
    cout<<"Square of "<<x<<" is "<<square(x)<<endl;
}

constexpr double x = 1.2356;
