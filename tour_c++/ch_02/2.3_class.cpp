#include<iostream>
using namespace std;

/*
Having the data specified separately from the operations on it has advantages, such as the ability to
use the data in arbitrary ways. However, a tighter connection between the representation and the
operations is needed for a user-defined type to have all the properties expected of a ‘‘real type.’’ In
particular, we often want to keep the representation inaccessible to users so as to ease use, guaran-
tee consistent use of the data, and allow us to later improve the representation. To do that we have
to distinguish between the interface to a type (to be used by all) and its implementation (which has
access to the otherwise inaccessible data). The language mechanism for that is called a class. A
class has a set of members, which can be data, function, or type members. The interface is defined
by the public members of a class, and private members are accessible only through that interface.
*/

/*
A member ‘‘function’’ with the same name as its class is called a constructor, that is, a function
used to construct objects of a class. So, the constructor, Vector() , replaces vector_init() from §2.2.
Unlike an ordinary function, a constructor is guaranteed to be used to initialize objects of its class.
Thus, defining a constructor eliminates the problem of uninitialized variables for a class
*/
class Vector
{
    public:
        // The constructor initializes the Vector members using a member initializer list
        Vector(int s) : sz{s}, elem{new double[s]}{};
        /* Access to elements is provided by a subscript function, called operator[] . It returns a reference
           to the appropriate element (a double& allowing both reading and writing). */
        double& operator[](int i)
        {
            return elem[i];
        } 
        int size()
        {
            return sz;
        }
    private:
        int sz;
        double *elem;

};

/*
Obviously, error handling is completely missing, but we’ll return to that in §3.5. Similarly, we
did not provide a mechanism to ‘‘give back’’ the array of double s acquired by new ; §4.2.2 shows
how to use a destructor to elegantly do that.

There is no fundamental difference between a struct and a class ; a struct is simply a class with
members public by default. For example, you can define constructors and other member functions
for a struct .

*/
double read_and_sum(int s)
{
    cout<<" Enter "<<s<<"elements"<<endl;
    Vector v(s);
    for (auto i = 0; i!=v.size(); ++i)
    {
        cin >> v[i];
    }
    double sum = 0;
    for (auto i = 0; i!=v.size(); ++i)
    {
        sum+=v[i];
    }

    return sum;
}

int main()
{
    double sum =0;
    sum = read_and_sum(5);
    cout<<"sum = "<<sum<<endl;
}