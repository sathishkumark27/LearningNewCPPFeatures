#include<iostream>
using namespace std;

// ranged based for loop since c++11

/*
The first range- for -statement can be read as ‘‘for every element of v , from the first to the last, place
a copy in x and print it.’’
*/
void print()
{
    int src[10] = {1,2,3,4,5,6,7,8,9,10};
    for (auto i : src)
    {
        cout<<"src = "<<i<<endl;
    }
    //int src1[] = {1,2,3,4,5,6,7};
    for (auto x : {1,2,3,4,5,6,7})
    {
        cout<<"src1 = "<<x<<endl;
    }

}
/*
If we didn’t want to copy the values from v into the variable x , but rather just have x refer to an
element

In a declaration, the unary suffix & means ‘‘reference to.’’ A reference is similar to a pointer,
except that you don’t need to use a prefix ∗ to access the value referred to by the reference. Also, a
reference cannot be made to refer to a different object after its initialization.
References are particularly useful for specifying function arguments. For example:
void sort(vector<double>& v); // sor t v (v is a vector of doubles)
By using a reference, we ensure that for a call sor t(my_vec) , we do not copy my_vec and that it
really is my_vec that is sorted and not a copy of it.
When we don’t want to modify an argument but still don’t want the cost of copying, we use a
const reference (§1.6). For example:
double sum(const vector<double>&)
*/
void print2()
{
    int src[10] = {1,2,3,4,5,6,7,8,9,10};
    for (auto& x: src)
    {
        cout<<"print2 = "<<x<<endl;
    }
}
int main()
{
    print();
    print2();
}