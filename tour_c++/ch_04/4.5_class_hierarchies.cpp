#include<iostream>
#include<vector>
#include<memory>
using namespace std;

struct Point
{
    double x;
    double y;
};


/****** BASE CLASS ***********/
class Shape
{
    public:
        virtual Point centre() const = 0;
        virtual void move(Point p) = 0;
        virtual void draw() const = 0;
        virtual void rotate(int angle) = 0;
        virtual ~Shape(){};
};

/***** level-1 derived class *********/
class Circle : public Shape
{
    private:
        Point x; //center
        int r; //radius
    public:
        //Circle():x{0},r{0}{}  // its always good practice to have default constructor especially for base class
        Circle(Point p, int i):x{p}, r{i}{}

        Point centre() const override
        {
            return x;
        }
        void draw() const override; // declared
        void move(Point to) override
        {
            x = to;
        }
        void rotate(int angle) override;        
};

void Circle::draw() const
{
    //draw algo goes here
}
void Circle::rotate(int angle)
{
    //circle rotate algo goes here
}


/******** level-2 derived class ****************/
/*
https://stackoverflow.com/questions/28312552/inherited-class-and-parents-constructor
https://stackoverflow.com/questions/32018607/c-inheritance-child-class-instance-uses-both-child-and-parent-constructors/32019065#32019065
Every time you derive a class from a base class, before entering in the subclass constructor, 
the compiler automatically calls the base class constructor for you if it has no arguments. 
*/
class Smiley: public Circle
{
    private:
        vector<Shape*> eyes; //usually 2 eyes
        Shape* mouth;
        //vector<unique_ptr<Shape>> eyes;  // if we use thse unique_ptrs destructor is not needed once the unique_ptr goes out of score it will be deleted by compiler
        //unique_ptr<Shape> mouth;
    public:
        Smiley(Point p, int r):Circle(p, r) // tries to call the base class constrcter with parameters p,r
        {            
            
            mouth = nullptr;
        }
        /*
            Smiley(Point p, int r)  // tries to call the base class default constructor to work with this base class should have default constructor
            {
                Circle(p,r);
                mouth = nullptr;
            }
        */
        ~Smiley()
        {
            delete mouth;
            for (auto p : eyes)
            {
                delete p;
            }
        }
        void move(Point to) override;
        void draw() const override;
        void rotate(int angle) override;
        void add_eyes(Shape *s)
        {
            eyes.push_back(s);            
        }
        void set_mouth(Shape *s)
        {
            mouth = s;
        }
};

class Eyes : public Shape
{

};

void Smiley::draw() const
{
    Circle::draw();
    for (auto p : eyes)
    {
        p->draw(); // eyes is another shape derived from Shape     
    }
    mouth->draw();
}


/*
Naturally, above interface is an abstract class: as far as representation is concerned, nothing (except
the location of the pointer to the vtbl) is common for every Shape. Given this definition, we can
write general functions manipulating vectors of pointers to shapes:
*/
void rotate_all(vector<Shape*>& shapes, int angle)
{
    for(auto shape : shapes)
    {
        shape->rotate(angle);
    }

}
