#include<iostream>
#include<unordered_map>
#include<algorithm>
#include<bitset>

using namespace std;

// With hash map time O(N)
bool IsUnique(string str)
{
    // Each char is of 1 byte == 256 distinct values if the inout str is having morethan 256 chars means atleast one chars repeated in the str
    if(str.length() > 256)
    {
        return false;
    }
    cout<<"str "<<str<<endl;
    unordered_map<char, int> umap;
    char ch = {'0'};

    for (int i = 0; i != str.length(); ++i) //O(N)
    {
        ch = str[i];
        if (umap.find(ch) == umap.end()) // O(1) accessing hash
        {
            umap[ch] = i;
        }
        else
        {
            return false;
        }        
    }
    return true;
}
// With out hash 2 pointer method O(N + NlogN) == O(NlogN)
bool IsUnique2(string& str)
{
    if(str.length() > 256)
    {
        return false;
    }
    int i = {0};
    int j = {1};
    sort(str.begin(), str.end()); //O(NlogN)
    
    for (auto len = 0; len!=str.length(); ++len) //O(N)
    {
        if (str[i] == str[j])
        {
            return false;
        }
        i+=1;
        j+=1;
    }
    return true;
}

// O(N) and O(1) space
bool IsUnique3 (string str)
{
    if(str.length() > 256)
    {
        return false;
    }
    bool arr[256] = {0}; 
    for (auto i=0; i!=str.length(); i++) // O(N)
    {
        if (arr[int(str[i])] != 0)
        {
            return false;
        }
        arr[int(str[i])] = 1;
    }
    return true;
}
//here we assume that input takes small letter alphabets 'a' to 'z. then only we can use int (32 bits) for each alphabet
// O(N) time complexity. we can reduce space by a factor of 8 as we are using 1-bit  where as we used one bool(i byte) for each char
bool IsUnique4(string str)
{
    if(str.length() > 26)
    {
        return false;
    }
    int bitmap = {0};
    for (auto i = 0; i != str.length(); ++i)
    {
        int val = int(str[i]) - int('a');
        int pos = 1 << val;
        //bitset<32> bit = {bitmap};
        //cout<<"bitmap = "<<bit<<endl;
        if (bitmap & pos)
        {
            return false;
        }
        bitmap |= 1 << val;
    }

    return true;
}

int main()
{
    cout<<"Enter input"<<endl;
    string input;
    cin>>input;
    if (input.empty())
    {
        cout<<"empty input"<<endl;
    }
    bool res1 = IsUnique(input);
    bool res2 = IsUnique2(input);
    bool res3 = IsUnique3(input);
    bool res4 = IsUnique4(input);
    cout<<"Result_1 = "<<res1<<endl;
    cout<<"Result_2 = "<<res2<<endl;
    cout<<"Result_3 = "<<res3<<endl;
    cout<<"Result_4 = "<<res4<<endl;
}