#include<iostream>
using namespace std;


/*The definition of count_x() assumes that the char∗ is a C-style string, that is, that the pointer
points to a zero-terminated array of char . The characters in a string literal are immutable, so to han-
dle count_x("Hello!") , I declared count_x() a const char∗ argument.

In older code, 0 or NULL is typically used instead of nullptr . Howev er, using nullptr eliminates
potential confusion between integers (such as 0 or NULL ) and pointers (such as nullptr ).

*/

int count_x(const char* p, char x)
{
    if (p == nullptr)
    {
        return 0;
    }

    int count={0};

    while (*p)
    {
        cout<<p<<endl;
        cout<<*p<<endl;
        if (*p == x)
        {
            ++count;
        }
        ++p;
        //cout<<*p<<endl;
    }

    return count;
}



int main()
{
    /*
    To define a C-style string, simply declare a char array and initialize it with a string literal:	
        char myString[]{ "string" };
    Although “string” only has 6 letters, C++ automatically adds a null terminator to the end of the string for us 
    (we don’t need to include it ourselves). Consequently, myString is actually an array of length 7!
    */
    const char* c = {"Hello!"};
    char c1[]{ "string" }; // string is array of chars by default it is immutable
    int count = {0};
    count = count_x(c1, 'l');
    cout<<"count = "<<count<<endl;
}