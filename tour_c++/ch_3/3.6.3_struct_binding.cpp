#include<iostream>
using namespace std;
struct Entry
{
    string s;
    int i;
};

Entry read_entry(istream& is)
{
    // Entry en;
    string s;
    int i;
    // is>>en.s>>en.i;
    // return en;
    is>>s>>i;
    return {s,i};
}

int main()
{
    auto e = read_entry(cin); 
    auto[unpack_s,unpack_i] = read_entry(cin);

    cout<<"Entry.s = "<<e.s<<" Entry.i = "<<e.i<<endl;
    cout<<"unpack_s = "<<unpack_s<<" unpack_i = "<<unpack_i<<endl;
}

  
// struct Point 
// { 
//     int x; 
//     int y; 
// }; 
  
// // Driver code 
// int main( ) 
// { 
//     Point p = { 1,2 }; 
      
//     // Structure binding 
//     auto[ x_coord, y_coord ] = p; 
      
//     cout << "X Coordinate : " << x_coord << endl; 
//     cout << "Y Coordinate : " << y_coord << endl; 
      
//     return 0; 
// } 
