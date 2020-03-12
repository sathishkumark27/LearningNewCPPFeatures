#include<iostream>
#include<vector>
#include<utility>
#include<unordered_map>
using namespace std;


int main()
{
    vector<pair<int, int>> index; 
    auto idx = make_pair(10, 20.2);
    unordered_map<int, int> umap;
    for (auto i=0; i<5; i++)
    {
        //cout<<"at "<< umap.at(1)<<endl; -- throus out of range error
        cout<<"[] "<< umap[1]<<endl;
        
        umap[i]++;

    }

    for (auto i : umap)
    {
        cout<<"at "<< umap.at(1)<<endl;
        cout<<i.first << " and "<<i.second<<endl;
    }
}