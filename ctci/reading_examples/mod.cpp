#include<iostream>
using namespace std;

/* A%B */

int main()
{
    cout<<"Enter A and B"<<endl;
    int A={0};
    int B={0};
    cin>>A;
    cin>>B;

    int div = A/B;
    int mod = A - (B * div);
    cout<<"Mod = "<<mod<<endl;

}