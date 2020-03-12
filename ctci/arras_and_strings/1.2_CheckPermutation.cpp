#include<iostream>
#include<unordered_map>
#include<string>
#include<algorithm>
using namespace std;

//O(A + B + A) lets say len A nad len B are N ==> O(3N) = O(N)
bool IsPermutation(string A, string B)
{
    if (A.length() != B.length())
    {
        return false;
    }
    unordered_map<char, int> counterA;
    for (auto a : A)
    {
        counterA[a]+=1;
    }

    for (auto b : B)
    {
        counterA[b]-=1;
    }

    for (auto [key, val]: counterA)
    {
        if (val != 0)
        {
            return false;
        }

    }
    return true;

}

/*
Solution #2: Sort the strings. If tw0 strings are permutations of each other they have same chars but in different positions,
 therefore sorting them makes the strings equal
 sort A and sort B == O(NlogN)
 comprae strings O(N)
 total = O(NlogN)
 */
bool IsPermutation2(string& A, string& B)
{
    sort(A.begin(), A.end()); // inplace sort
    sort(B.begin(), B.end());
    if (A.compare(B) == 0)
    {
        return true;
    }
    return false;
}

int main()
{
    cout<<"Enter input1 ans input2"<<endl;
    string input1, input2;
    cin>>input1;
    cin>>input2;
    if (input1.empty() || input2.empty())
    {
        cout<<"empty input"<<endl;
    }
    bool res1 = IsPermutation(input1, input2);
    bool res2 = IsPermutation2(input1, input2);
    cout<<"Result_1 = "<<res1<<endl;
    cout<<"Result_2 = "<<res2<<endl;
}