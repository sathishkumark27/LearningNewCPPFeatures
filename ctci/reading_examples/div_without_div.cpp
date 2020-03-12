#include<iostream>
using namespace std;
/*
A and B MUST BE INTS

and A >= B

*/

int main()
{
    cout<<"Enter A and B"<<endl;
    int A={0};
    int B={0};
    cin>>A;
    cin>>B;
    int sum = B;
    int count = 0;
    while (sum <= A)
    {
        sum+=B;
        count+=1;
    }

    cout<<"div = "<<count<<endl;
}