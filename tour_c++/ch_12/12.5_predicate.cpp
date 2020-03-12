#include<iostream>
#include<map>
#include<algorithm>
#include<list>
using namespace std;

// void findall_if(map<string, int>& m)
// {
//     auto p = find_if(m.begin(), m.end(), [](const auto& r){r.second > 3});
// }

int main()
{
    map<string, int> m = {{"a", 1}, {"b", 2}, {"c", 3}, {"d", 4}, {"e", 5}};
    auto p = find_if(m.begin(), m.end(), [](const auto& r){return r.second > 3;});
    cout<<p->first<<endl;
    cout<<p->second<<endl;
}