#include<iostream>
#include<string>
using namespace std;

int main()
{
    string type;
    cin >> type;
    if (type == "circle")
    {
        int x;
        int y;
        int rad;
        cin>>x;
        cin>>y;
        cin>>rad;
        cout<<"Circle = "<<x<<y<<rad<<endl;
    }
    if (type == "point")
    {
        int x;
        int y;       
        cin>>x;
        cin>>y;
        cout<<"Point = "<<x<<y<<endl;
        
    }
}