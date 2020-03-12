#include<iostream>
#include<string>
#include<vector>
using namespace std;
/*
One particularly useful kind of template is the function object (sometimes called a functor), which
is used to define objects that can be called like functions. For example:

The function called operator() implements the ‘‘function call,’’ ‘‘call,’’ or ‘‘application’’ operator ().
*/

template<typename T>
class Less_than
{
    const T val;
    public:
        Less_than(const T& v):val{v}{};
        bool operator()(const T& x) const {return x < val;}

};

// A predicate is something that we can invoke to return true or false. 
template<typename seq, typename predicate>
int counter(seq lst, predicate p)
{
    int  count = 0;
    for (auto x: lst)
    {
        if (p(x))
        {
            count++;
        }
    }
    return count;
}



int main()
{
    Less_than lti(5);
    cout<<"Compare = "<<lti(10)<<endl;
    cout<<"Compare = "<<lti(1)<<endl;
    Less_than lts("abc"s);  // lts(s) will compare s to "Backus" using < (s<"abc")
    cout<<"compare string = "<<lts("aba"s)<<endl;
    vector<int> vi = {3,4,5,6,7};
    int x = counter(vi, lti);
    cout<<"number of values less than "<< 5 << " are = "<<x<<endl;
    int temp = 5;

    /****************** LAMBDA EXPRESSIONS******************/
    //In predicate example, we defined Less_than separately from its use. That can be inconvenient.
    //int ct = counter(vi, [](int a){return a<temp;}); // an enclosing-function local variable cannot be referenced in a lambda body unless it is in the capture list
    int ct = counter(vi, [&](int a){return a<temp;}); //to use a local var in lambda body it should be in capture list
    cout<<"LAMBDA : number of values less than "<< 5 << " are = "<<ct<<endl;
}