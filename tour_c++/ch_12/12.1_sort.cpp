#include<iostream>
#include<vector>
#include<list>
#include<algorithm>
#include<string>
#include<initializer_list>
using namespace std;

struct Entry
{
    string name;
    int num;
    Entry(string x, int y):name{x}, num{y}{}
    Entry():num{0}, name{"zzz"s}{}

    /*
    inside class, with only one parameter which is right operand
    outside of class, with two parameters, left and right operands.
    */

    bool operator<(const Entry& rhs) // left operand is current object
    {
        return name < rhs.name;
    }

    bool operator==(const Entry& rhs) // left operand is current object
    {
        return name == rhs.name;
    }

    void dig();


};


class EntryClass
{
    string name;
    int num;
    public:
        EntryClass(string x, int y):name{x}, num{y}{}
        EntryClass():num{0}, name{"zzz"s}{}

        /*
        inside class, with only one parameter which is right operand
        outside of class, with two parameters, left and right operands.
        inside class definitin == LHS is the instance of the class and RHS is the function parameter
        */

        bool operator<(const EntryClass& rhs) // left operand is current object
        {
            return name < rhs.name;
        }

        bool operator==(const EntryClass& rhs) // left operand is current object
        {
            return name == rhs.name;
        }

        friend ostream& operator<<(ostream& out, const EntryClass& rhs); //fried because to get access to private members in struct no need to define friend because all are public members

        void dig();
        

};

void EntryClass::dig()
{
    cout<<"EntryClass Dig"<<endl;
}

ostream& operator<<(ostream& out, const EntryClass& rhs)
{
    out << "name = "<<rhs.name<<" num = "<<rhs.num;
    return out;
}

/*https://stackoverflow.com/questions/23508546/override-binary-operator-on-struct*/
ostream& operator<<(ostream &out, const Entry &c)
{
    out << "name = "<<c.name<<" num = "<<c.num;
    return out;
}

void f(vector<Entry>& ve, list<Entry>& lst)
{
    sort(ve.begin(), ve.end());
    unique_copy(ve.begin(), ve.end(), lst.begin());
}
void f2(vector<Entry>& ve, list<Entry>& lst)
{
    sort(ve.begin(), ve.end());
    unique_copy(ve.begin(), ve.end(), back_inserter(lst));
}


int main()
{
    Entry e1("abc", 1);
    Entry e2("bcd", 2);
    Entry e3("skl", 3);
    Entry e4("wekf", 4);
    Entry e5("owefm", 5);
    EntryClass ec1("EntryClass", 45);
    cout<<ec1<<endl;

    // bool res  = e1<e2;
    // cout<<res<<endl;

    //cout << e1;

    vector<Entry> ve = {e1, e2, e3, e4, e5};
    list<Entry> lst(5); // asks for Entry() constructor
    list<Entry> lst2;

    f(ve, lst);
    f2(ve, lst2);
    cout<<" LST 1"<<endl;
    for (auto x : lst)
    {
        cout<<x<<endl;
    }
    cout<<" LST 2"<<endl;
    for (auto x : lst2)
    {
        cout<<x<<endl;
    }
    
}
