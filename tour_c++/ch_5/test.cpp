#include<iostream>
using namespace std;

class Vector {
    private:        
        double* elem;
        int sz;
    public:
        Vector(int s) : sz{s}, elem{new double[s]}
        {
            for (auto i =0; i!=s; i++)
            {
                elem[i] = i;
            }
        }
        Vector() { delete[] elem; }   // destructor: release resources
        Vector(const Vector& a);        // copy constructor
        Vector& operator=(const Vector& a);        // copy assignment
        double& operator[](int i)
        {
            return elem[i];
        }
        const double& operator[](int i) const;
        int size() const;
};

void bad_copy(Vector v1)
{
    Vector v2 = v1;
    v1[0] = 2;
    v2[1] = 3;
    for(auto i=0; i!=5; ++i)
    {
        cout<<"v1["<<i<<"] = "<<v1[i]<<endl;
        cout<<"v2["<<i<<"] = "<<v2[i]<<endl;
    }
}

int main()
{
    Vector v1(5);
    bad_copy(v1);
}
