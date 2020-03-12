#include "3.2_vector.h"
#include"3.2_derived_class.h"
#include <iostream>
#include <cmath>
using namespace std;
void test();
double sqrt_sum(Vector& v)
{
    double sum = {0};
    for (auto i = 0; i!=v.size(); ++i)
    {
        sum+=sqrt(v[i]);

    }
    return sum;
}

/**** Using ABSTRACT class ***/
/* 
function "use" doesnot know about which type of container (Vector_container or List_container) we are using.
with out changing (without compiling) "use", we can change Vector_container and List_container
*/
void use(Container& c)
{
    const int sz = c.size();
    for (auto i=0; i!=sz; ++i)
    {
        cout<<"Container["<<i<<"] = "<<c[i]<<endl;
    }
}

void g(int s)
{
    Vector_container vc(s);
    for (auto i=0; i!=s; i++)
    {
        vc[i] = i;
    }
    Vector_container vc2 = {20,30,40,50};
    use(vc);
    use(vc2);
}
void h(int s)
{
    List_container lc(s);
    for (auto i=0; i!=s; i++)
    {
        lc[i] = i;
    }
    List_container lc2 = {20,30,40,50};
    use(lc);
    use(lc2);
}

int main()
{
    Vector v(5);
    for (auto i=0; i!=v.size(); ++i)
    {
        v[i] = i*i;
    }
    Vector v1= {10,11,12,13};
    cout<<"v1 = "<<v1[2]<<endl;    
    double sum = {0};
    sum = sqrt_sum(v);
    cout<<"sqrt_sum = "<<sum<<endl;
 
    test();

    cout<<"Vector Container"<<endl;
    g(10);

    cout<<"List Container"<<endl;
    h(10);
       
}

   //cout<<"Exception ="<<v[v.size()+1]<<endl;
    // try 
    // {
    //     v[v.size()] = 7;
    // }
    // catch(out_of_range& err) // specific exception
    // {
    //     cerr<<err.what()<<endl;
    // } 
    // try
    // {
    //     Vector v(-2);
    // }
    // catch(const std::exception& e) // general exception
    // {
    //     std::cerr << e.what() << '\n';
    // }

void test()
{
    try
    {
        Vector v(-5);
    }
    catch(const std::out_of_range& e)
    {
        std::cerr << e.what() << '\n';
        // handle out of range case
    }
    catch(const std::length_error& e)
    {
        std::cerr << e.what() << '\n';
        std::cerr << "test failed : Length Error " << '\n';
        //handle length case
    }
    catch(const bad_alloc& e)
    {
        std::cerr << e.what() << '\n';
        std::terminate();
    }
    // catch(const std::exception& e) // general exception
    // {
    //     std::cerr << e.what() << '\n';
    // }
    
}