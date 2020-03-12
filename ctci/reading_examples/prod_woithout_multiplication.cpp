#include<iostream>
using namespace std;
/*
A and B MUST BE INTS
A*B == A+A+A+.. B times
*/
int main()
{
    cout<<"Enter A and B"<<endl;
    int A={0};
    int B={0};
    cin>>A;
    cin>>B;
    int sum = 0;
    for (auto i=0; i!=B; ++i)
    {
        sum+=A;
    }
    cout<<"Product = "<<sum<<endl;

}