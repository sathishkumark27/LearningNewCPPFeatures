#include<initializer_list>
using namespace std;

/********** CONCRETE TYPE CLASS ***************/
class Vector
{
    public:
        Vector(int s);
        Vector(initializer_list<double> list); // sec 4.2.3 init with list
        Vector(double d);
        ~Vector();
        double& operator[](int i);
    
        int size() const; // //The idea of const functions is not to allow them to modify the object on which they are called
    //Representation == data
    private:
        double *elem ;
        int sz;
};

/*********** ABSTRACT TYPE CLASS *******************/
//This class is a pure interface to specific containers defined later.
class Container
{
    //No representation 
    public:
        virtual double& operator[](int) = 0; //pure virtual fun, class derivide form Container MUST define this function
        virtual int size() const = 0;
        virtual ~Container() {}; // virtual function the derived class "may redefine this function"

};