#include<iostream>
using namespace std;
/*
The following method checks if a number is prime by checking for divisibility on numbers less than it. It only
needs to go up to the square root of n because if n is divisible by a number greater than its square root then
it's divisible by something smaller than it.
For example, while 33 is divisible by 11 (which is greater than the square root of 33), the "counterpart"to 11
is 3 (3 * 11 = 33). 33 will have already been eliminated as a prime number by 3.
1*100 = 100
2*50 = 100
4*25 = 100
5*20 = 100
10*10 = 100 divides equally
20*5 = 100
25*4 = 100
50*2 = 100
100*1=100

*/

bool prime (int num)
{
    for (int i=2; i*i <= num; i++)
    {
        if (num%i == 0)
        {
            return false;
        }
    }
    return true;
}

int main()
{
    int input = 1;
    bool res = false;
    cout<<"Enter number \n"<<endl;
    cin >> input;
    res = prime(input);
    cout<<res<<endl;
}