#include<iostream>
#include <vector>
using namespace std;

int main()
{
    vector<int> l;
    for (int i=1; i<=3; i++) l.push_back(i);

    for (int i=0; i<l.size(); i++)
    {
        cout<<" i = "<<i<<endl;
        if (l[i] == 1)
        {
            l.erase(l.begin()+i);
        }
    }
    //cout<<" l = "<<l<<endl;
}