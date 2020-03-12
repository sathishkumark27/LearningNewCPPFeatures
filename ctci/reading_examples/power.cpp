#include<iostream>
using namespace std;

/*
A and B MUST BE INTS

A^B
*/
int power(int A, int B)
{
    if (B < 0)
    {
        return -1;
    }
    else if (B == 0)
    {
        return 1;
    }

    return A * power(A, B-1);

}

int main()
{
    cout<<"Enter A and B"<<endl;
    int A={0};
    int B={0};
    cin>>A;
    cin>>B;
    int pow={0};
    pow = power(A, B);
    cout<<"Power = "<<pow<<endl;
}