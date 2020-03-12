#include<iostream>
#include<string>
using namespace std;

// COMEBACK WITH POINT KNOWLEDGE

void action()
{
    while(true)
    {
        cout<<"Enter actions n, s, e, or w \n"<<endl;
        string act;
        cin >> act;
        
        Point position = {0,0};
        for (char ch : act)
        {
            switch (ch)
            {
            case 'n':
                ++position.y;
                break;
            case 's':
                --position.y;
                break;
            case 'e':
                ++position.x;
                break;
            case 'w':
                --position.x;
                break;        
            default:
                cout<<"default"<<endl;
                break;
            }
        }
        cout<<"position = "<<position<<endl;
    }
    
}

int main()
{
    action();
}