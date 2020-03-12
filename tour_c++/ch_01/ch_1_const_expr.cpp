#include <iostream>
using namespace std;

/*
const : meaning roughly ‘‘I promise not to change this value.’’ This is used primarily to
specify interfaces so that data can be passed to functions using pointers and references with-
out fear of it being modified. The compiler enforces the promise made by const . The value
of a const can be calculated at run time.

constexpr :
meaning roughly ‘‘to be evaluated at compile time.’’ This is used primarily to
specify constants, to allow placement of data in read-only memory (where it is unlikely to
be corrupted), and for performance. The value of a constexpr must be calculated by the
compiler.

for constexpr -- c++11 -- only one statement(1.e return) in constexpr function because of this we use recursion for example fib with constexpr
              -- c++14 --  multiple c++ statements allowed but all the args should br constexprs
              -- c++17 -- extend for templates etc
              -- c++20 -- constexpr function will be allowed with non consat args

*/
constexpr double square(double x)
{
    return x*x;    
}

constexpr double power(double x, int times)
{
    double res = 1;
    int i = 0;
    while (i < times)
    {
        res*=x;
        ++i;
    } 
    return res;
}

int main()
{
    const int var = 12;
    // var should be constant
    constexpr double res1 = square(var);
    constexpr double res2 = square(12);
    cout<<"Square1 = "<<res1<<endl;
    cout<<"Square2 = "<<res2<<endl;
    /* C++20 : A constexpr function can be used for non-constant arguments, but when that is done the result is not
    a constant expression. We allow a constexpr function to be called with non-constant-expression
    arguments in contexts that do not require constant expressions. That way, we don’t hav e to define
    essentially the same function twice: once for constant expressions and once for variables.
    To be constexpr , a function must be rather simple and cannot have side effects and can only use
    information passed to it as arguments. In particular, it cannot modify non-local variables, but it can
    have loops and use its own local variables*/
    const int val = 12;
    const int times = 2;
    constexpr double res3 = power(val, times);
    //constexpr double res3 = square(val);
    cout<<"Square3 = "<<res3<<endl;
}