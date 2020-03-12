#include "3.2_vector.h"
#include"3.2_derived_class.h"
#include <cmath>
#include<stdexcept>
#include<list>
#include<initializer_list>
using namespace std;

/****************************** CONCRETE CLASS DEFINITIOS ************************************************************/

//Vector::Vector(int s): elem{new double[sz]}, sz{s} {};


/*an array of sz doubles’’ but we only said that in a comment. Such a statement of what is assumed
to be true for a class is called a class invariant, or simply an invariant. It is the job of a constructor to establish the invariant for its class (so that the member functions can rely on it) and for the mem-
ber functions to make sure that the invariant holds when they exit.
*/
Vector::Vector(int s)
{
    if (s <= 0)
    {
        throw length_error{"Vector Constructor: Invalid Size"};
    }
    sz = s;
    elem = new double[sz]; //resource allocation
    /* The technique of acquiring resources in a
        constructor and releasing them in a destructor, known as Resource Acquisition Is Initialization
    */

    for (auto i=0; i!=s; i++) //initialization  ==> Resource Aquasition Is Initialization 
    {
        elem[i] = 0;
    }

}
//sec 4.2.3 init container with list
Vector::Vector(initializer_list<double> list) : elem{new double[static_cast<int>(list.size())]}, sz{static_cast<int>(list.size())}
{
    copy(list.begin(), list.end(), elem);
}

Vector::~Vector()
{
    delete[] elem;
}
double& Vector::operator[](int i)
{
    if (i < 0 || i >= sz)
    {
        throw out_of_range{"Vector::operator[]"}; // Sec 3.5.1
    }
    return elem[i];
}

// The idea of const functions is not to allow them to modify the object on which they are called
int Vector::size() const
{
    return sz;
}

/*
when the variable goes out of scope it will be destructed
void fct(int n)
{
    Vector v(n);
    // ... use v ...
    {
    Vector v2(2∗n);
    // ... use v and v2 ...
    } // v2 is destroyed here
    // ... use v ..
} // v is destroyed here

*/


/****************************** ABSTRACT CLASS DEFINITIOS ************************************************************/

// only definition, declarations are in 3.2_derived_class.h
Vector_container::Vector_container(int i) : v(i){}

Vector_container::Vector_container(initializer_list<double> lst) : v(lst) {}

/* The destructor ( ̃Vector_container()) overrides the base class destructor ( ̃Container()).
Note that the member destructor ( ̃Vector()) is implicitly invoked by its class’s destructor ( ̃Vector_container()).
*/
Vector_container::~Vector_container(){}

double& Vector_container::operator[](int i)  // overriding the base class operator method
{
    return v[i];
}

int Vector_container::size() const
{
    return v.size();
}

#if 0
//delaration and defining vector container using Container base class
class Vector_container : public Container
{
    private:
        /* we have to implement a container that implements the functions required by its interface. 
        For that, we could use the concrete class Vector */
        Vector v;
    public:
        Vector_container(int i) : v(i) {}
        Vector_container(initializer_list<double> lst) : v(lst) {}
        /* The destructor ( ̃Vector_container()) overrides the base class destructor ( ̃Container()).
        Note that the member destructor ( ̃Vector()) is implicitly invoked by its class’s destructor ( ̃Vector_container()).
        */
        ~Vector_container(){}

        double& operator[](int i) override  // overriding the base class operator method
        {
            return v[i];
        }

        int size() const override
        {
            return v.size();
        }

};


//defining list container using Container base class
class List_container : public Container
{
    private:
        list<double> ld;
    public:
        List_container(int i):ld(i){};
        List_container() // default constructor
        {
            //empty list
        }
        List_container(std::initializer_list<double> il)        
        {
            ld = il;
        }
        ~List_container()
        {

        }
        double& operator[](int i) override;
        int size() const override
        {
            return ld.size();
        }       

};
double& List_container::operator[](int i)
{
    for (auto& x : ld)
    {
        if (i == 0)
        {
            return x;
        }
        --i;
    }
    throw out_of_range{"List_container:opertor[];Out of range access"};
}
#endif

List_container::List_container(int s):ld(s){}
List_container::List_container(){}
List_container::List_container(std::initializer_list<double> il)        
{
    ld = il;
}
List_container::~List_container()
{

}

int List_container::size() const
{
    return ld.size();
} 

double& List_container::operator[](int i)
{
    for (auto& x : ld)
    {
        if (i == 0)
        {
            return x;
        }
        --i;
    }
    throw out_of_range{"List_container:opertor[];Out of range access"};
}