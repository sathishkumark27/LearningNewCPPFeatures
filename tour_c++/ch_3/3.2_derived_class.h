//#include"3.2_vector.h"
#include<list>
using namespace std;

class Vector_container : public Container
{
    private:
        Vector v;
    public:
        Vector_container(int);
        Vector_container(initializer_list<double>);
        ~Vector_container();
        double& operator[](int i) override;
        int size() const override;
};

class List_container : public Container
{
    private:
        list<double> ld;
    public:
        List_container(int);
        List_container();
        List_container(std::initializer_list<double>);
        ~List_container();
        double& operator[](int i) override;
        int size() const override;
};