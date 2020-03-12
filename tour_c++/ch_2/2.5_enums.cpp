#include<iostream>
using namespace std;

/*

The class after the enum specifies that an enumeration is strongly typed(a programming language that enforces strict restrictions on intermixing of values with differing data types) and that its enumerators
are scoped. Being separate types, enum class es help prevent accidental misuses of constants. In
particular, we cannot mix Traffic_light and Color values:
Color x = red; // error : which red?
Color y = Traffic_light::red; // error : that red is not a Color
Color z = Color::red; // OK 

Similarly, we cannot implicitly mix Color and integer values:
int i = Color::red; // error : Color ::red is not an int
Color c = 2; // initialization error: 2 is not a Color
*/
enum class Color
{
    red,
    blue,
    green
};
enum class traffic_light
{
    red,
    gellow,
    green
};
