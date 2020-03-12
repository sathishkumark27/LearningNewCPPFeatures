#include<iostream>
#include<vector>
using namespace std;

class X {
public:
    X(int);    // ‘‘ordinary constr uctor’’: create an object
    X();     // default constructor
    X(const X&);    // copy constr uctor
    X(X&&);     // move constructor
    X& operator=(const X&);    // copy assignment: clean up target and copy
    X& operator=(X&&);    // move assignment: clean up target and move
    ~X();    // destructor: clean up
};


class Y
{
    public:
        Y(); //defaut constructor
        Y(int); // parameter constructor
        Y(const Y&) = default; // I really do want the default copy constructor 
        Y(Y&&) = default; // and the default move constructor

};

struct Z
{
    vector<int> v;
    string s;
};

/*
Here, the compiler will synthesize memberwise default construction, copy, move, and destructor as
needed, and all with the correct semantics.
*/
void init_struct()
{
    Z z1; // default initialize z1.v and z1.s
    Z z2 = z1; //default copy construct copy z1.v and z1.s to z2 --  -- copy initialization
    Z z3;
    z3 = z2; // default copy assignment
}

class Shape
{
    public:
        Shape(const Shape&) = delete;
        Shape& operator=(const Shape &) = delete;
};

void copy(Shape& s1, Shape&  s2)
{
    //s1 = s2;  // error : Shape copy is deleted

}

/* To avoid implicit conversion such as vector v1 = 7 int-to-vector give "explicit" for constructor */
class Vector_explicit
{
    private:
        int sz;
        double* elem;
    public:
        explicit Vector_explicit(int s):sz{s}, elem{new double[s]}{}
        double& operator[](int i)
        {
            return elem[i];
        }
};

class Vector
{
    private:
        int sz = 0;
        double* elem = nullptr; //default member initialization     when called as v1()
    public:
        Vector(){}
        Vector(int s):sz{s}, elem{new double[s]}{}
        double& operator[](int i)
        {
            return elem[i];
        }
};
void init_Vector_explicit(int s)
{
    Vector_explicit v1(7);
    Vector_explicit v2 = 7;  // no implicit conversion from int to Vector == std vector libary way

}

void init_Vector(int s)
{
    Vector v1(s);
    Vector v2 = s;  // both are of vectors with elemets 7 but this not readable -- explicit conversion from int to vector
    Vector v3 = v1; // bad copy -- coying the representation of v1 to v3 ptr copy is bad 
    cout<<v1[2]<<endl;
    cout<<v2[2]<<endl;
    cout<<v3[2]<<endl;

}
int main()
{
    init_Vector(5); // here v2 = int allowed
    vector<double> v = 5; //in std vector library its not allowed
    vector<double> v(5);
    
}