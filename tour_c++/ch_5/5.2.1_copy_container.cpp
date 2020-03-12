#include<iostream>
using namespace std;

class Vector
{
    public:
        Vector(int s) : sz{s}, elem{new double[s]}
        {
            for (auto i =0; i!=s; i++)
            {
                elem[i] = i;
            }
            cout<<"parameterized constructor called"<<endl;
        }
        Vector(initializer_list<double> list): sz{static_cast<int>(list.size())},elem{new double[static_cast<int>(list.size())]}
        {
            copy(list.begin(), list.end(), elem);
            cout<<"initializer list called"<<endl;
        }       
        ~Vector()
        {
            delete[] elem; 
        }
        double& operator[](int i)
        {
            return elem[i];
        }
        Vector(Vector&); //copy construct
        Vector& operator=(Vector&); //copy assignment
        Vector(Vector&&); //move constructor
        Vector& operator=(Vector&&); //Move assignment
    
        int size() const
        {
            return sz;
        }

    private:
        double *elem ;
        int sz;
};

Vector::Vector(Vector& src): sz{src.sz}, elem{new double[src.sz]} // here elem is null because it is in init state
{
    for (auto i=0; i!=sz; ++i)
    {
        elem[i] = src.elem[i];
    }
    cout<<"copy constructor called"<<endl;
}

Vector& Vector::operator=(Vector& src)
{   
    cout<<"sz = "<<sz<<endl;
    cout<<"elem[2] = "<<elem[2]<<endl; // here elem is not null it points to 20 which is v4 object
    sz = src.sz;
    double *p = new double[sz];    
    for (auto i=0; i!=sz; ++i)
    {
        p[i] = src.elem[i];
    }
    delete elem;
    elem = p;
    cout<<"assignment operator called"<<endl;
    return *this; // return current object
}
/* when ever return is called from a function instead of copy a move constructor is used*/
Vector::Vector(Vector&& v)
{
    cout<<"move constructor called"<<endl;
    sz = v.sz;
    elem = v.elem;
    v.sz = 0;
    v.elem = nullptr;
}

Vector& Vector::operator=(Vector&& v)
{
    cout<<"move assignment called"<<endl;
    sz = v.sz;
    delete[] elem;
    elem = v.elem;
    v.sz = 0;
    v.elem = nullptr;
    return *this;
}

Vector noconstruct_test()
{
    Vector v1 = {1,2,3,4,5};
    Vector v2 = {6,7,8,9,10};
    Vector v3(5);
    for (auto i=0; i!=v1.size(); ++i)
    {
        v3[i] = v1[i] + v2[i];
    }
    /*
        -- If we do not define move construct all the data is copied to location where the caller of this function i.e main has access ( generally to registers).
        -- lets say size of vector is 10^8 then copy is expensive operation.
        -- As we defined the move operation when we return from here the move constructor is invoked to move the rvalue reference to the caller.
        -- it is rvalue reference
    */
    return v3;  // move called (unable test)

}

int main()
{
    cout<<"V1"<<endl;
    Vector v1 = {1,2,3,4,5};

    cout<<"V2"<<endl;    
    // here v2(v1) is lvalue reference so expensive copy constructor is called
    Vector v2(v1); //copy constructor called    -- here v2 not pointing to any thing i.e v2.elem = nullptr -- least efficient

    cout<<"V3"<<endl;
    Vector v3 = v1; //copy constructor called -- here v3 not pointing to any thing i.e v3.elem = nullptr -- least efficient

    cout<<"V4"<<endl;
    Vector v4(5);
    v4[2] = 20;
    v4 = v1; //assignment operator called -- if assignment operator not defined v1 and v4 points to same -- here v4.elem is not nullptr
    v4[2] = 200;

    cout<<"V5"<<endl;    
    Vector v5(noconstruct_test()); // dont call any constructor  -- most efficient

    cout<<"V6"<<endl;
    Vector tmp = {41, 42, 43, 44, 45};
    //calls move constructor 
    /* https://www.youtube.com/watch?v=IOkgBrXCtfo */   
    Vector v6(std::move(tmp)); // tmp.elem = nullptr (tmp cannot be used further) move uses move constructor -- as efficient as v5

    cout<<"V7"<<endl;
    Vector tmp1 = {51, 52, 53, 54, 55};
    Vector v7(5);
    v7 = std::move(tmp1);
       

    cout<<endl;
    cout<<endl;
    cout<<endl;

    for(auto i=0; i!=5; ++i)
    {
        cout<<"v1["<<i<<"] = "<<v1[i]<<endl;
        cout<<"v2["<<i<<"] = "<<v2[i]<<endl;
        cout<<"v3["<<i<<"] = "<<v3[i]<<endl;
        cout<<"v4["<<i<<"] = "<<v4[i]<<endl;
        cout<<"v5["<<i<<"] = "<<v5[i]<<endl;
        cout<<"v6["<<i<<"] = "<<v6[i]<<endl;
        cout<<endl;
    }
    
    

}