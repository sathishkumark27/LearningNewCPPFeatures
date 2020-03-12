#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

bool has_c(const string& str, const char& c)
{
    return str.end() != find(str.begin(), str.end(), c);
}

vector<string::iterator> find_all(string& str, const char& c)
{
    vector<string::iterator> res;
    for (auto p = str.begin(); p!= str.end(); ++p)
    {
        if (*p == c)
        {
            res.push_back(p);
        }
    }

    return res;
}

int main()
{
    bool res  = has_c("ashdcahcklmk"s, 'h');
    cout<<"res = "<<res<<endl;
    string m ={"asosfhdjclsznmdcldvmmv"};
    vector<string::iterator> fall = find_all(m, 's');
    for (auto p : fall)
    {
        if (*p != 's')
        {
            cerr<<"Error"<<endl;
        }
        
    }
}
