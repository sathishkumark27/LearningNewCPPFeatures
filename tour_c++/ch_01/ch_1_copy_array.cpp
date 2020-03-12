#include <iostream>
using namespace std;

/*
We use auto where we don’t hav e a specific reason to mention the type explicitly. ‘‘Specific
reasons’’ include:
    • The definition is in a large scope where we want to make the type clearly visible to readers
    of our code.
    • We want to be explicit about a variable’s range or precision (e.g., double rather than float ).

*/
/*
C++ offers a variety of notations for
expressing initialization, such as the = used above, and a universal form based on curly-brace-
delimited initializer lists: The = form is traditional and dates back to C, but if in doubt, use the general {} -list form. If nothing
else, it saves you from conversions that lose information:
int i1 = 7.8; // i1 becomes 7 (surprise?)
int i2 {7.8}; // error : floating-point to integer conversion

With auto , we tend to use the = because there is no potentially troublesome type conversion
involved, but if you prefer to use {} initialization consistently, you can do that instead.
*/

void copy_fct()
{
    int src[10]{1,2,3,4,5,6,7,8,9,10};
    int j{0}; // curly brack init
    int dst[10] = {}; // we can use = or we can ignore for {} init
    // ‘‘set i to zero; while i is not 10 , copy the i th element and increment i’’
    for (auto i=0; i!=10; i++)
    {
        dst[i] = src[i];
        cout<<"dst["<<i<<"] = "<<dst[i]<<endl;
    }

}

int main()
{
    copy_fct();
}