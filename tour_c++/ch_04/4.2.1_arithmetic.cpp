// Do not compile -- PRACTICE
#include<iostream>
using namespace std;
class complex
{
    double im, re;
    public:
        complex(double r, double im)
        {
            re = r;
            im = im;
        }

        complex(double r)
        {
            re = r;
            im = 0;
        }

        complex()
        {
            re = 0;
            im = 0;
        }
        //The idea of const functions is not to allow them to modify the object on which they are called
        double real() const {return re;}
        void real(double r) {re = r;}
        double im() const {return im;}
        void im(double i) {im = i;}

        complex& operator+=(complex z)
        {
            re+= z.re;
            im+= z.im;
            return *this;
        }

        complex& operator-=(complex z)
        {
            re-= z.re;
            im-= z.im;
            return *this;
        }

        complex& operator*= (complex);
        complex& operator*= (complex);
};