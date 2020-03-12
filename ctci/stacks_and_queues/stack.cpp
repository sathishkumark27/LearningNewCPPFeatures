#include<iostream>
#include<stdexcept>
using namespace std;

template<typename T>
class Stack
{
    private:
        T data;
        Stack<T>* next;
    public:
        Stack(){}
        Stack<T>* first = nullptr;
        int sz = 0;
        T top()
        {
            if (first == nullptr)  
            {   
                throw out_of_range{"Empty Stack Stack::top()"};                
            }

            return first->data;

        }

        void push(T data)
        {
            Stack<T>* node = new (Stack<T>);
            node->data = data;
            node->next = nullptr;
            if (first == nullptr)
            {
                first = node;
            }
            else
            {
               node->next = first;
               first = node;
            }
            sz++;          
        }

        void pop()
        {
            if (first == nullptr)
            {
                throw out_of_range{"Empty Stack Stack::pop()"};
                return;
            }

            Stack<T>* temp = first;                               

            first = first->next;
            delete temp;
            sz--; 
            return;            
        }

        bool IsEmpty()
        {
            return first == nullptr;  
        }
        
        int size()
        {
            return sz;
        }

};


// without inheritance also works need to understand why it need to be inherited as given i  CTCI 3.2 problem
template<typename T>
class minStack : public Stack<T> 
{
    private:
        Stack<T> s1;
        Stack<T> s2;
    public:
        minStack(){}

        T min()
        {
            if (s2.IsEmpty())
            {
                return INT32_MAX;
            }
            return s2.top();            
        }

        void push(T a)
        {
            if (a < min())
            {
                s2.push(a);
            }
            s1.push(a);
        }

        void pop()
        {
            if (s1.top()== min())
            {
                s2.pop();
            }
            s1.pop();
        }

        bool IsEmpty()
        {
            return s1.IsEmpty();
        }
        


};

template<typename T>
class SetofStacks
{
    private:
        Stack<T> s;
        SetofStacks<T>* nxtstack;
    
    public:
        SetofStacks(){}
        SetofStacks<T>* start = nullptr;
        int SetSz = 0;
        int MAX_STACK_SIZE = 3;
        int top()
        {
            if (start == nullptr || start->s.IsEmpty())
            {
                throw out_of_range{"setofstacks or stack is empty"};
            }
            return start->s.top();
        }
        bool IsEmpty()
        {
            return start == nullptr;
        }

        void push(T a)
        {
            if (start != nullptr)
            {
                if (start->s.IsEmpty() || start->s.size() < MAX_STACK_SIZE)
                {
                    start->s.push(a);
                }
                else 
                {
                    SetofStacks<T>* newset = new (SetofStacks);
                    newset->nxtstack = start;
                    start = newset;
                    start->s.push(a);
                    SetSz++;
                }
            }
            else
            {
                SetofStacks<T>* newset = new (SetofStacks);
                start = newset;
                start->s.push(a);
                SetSz++;
            }
            
            
        }

        void pop()
        {
            if (start == nullptr)
            {
                throw out_of_range{"setofstacks is empty"};
            }

            start->s.pop();
            if (start->s.IsEmpty())
            {
                SetofStacks<T>* tmp;
                tmp = start;
                start = start->nxtstack;
                delete tmp;
                SetSz--;
            }
        }

        int size()
        {
            return SetSz;
        }

        int stackSize()
        {
            if (start == nullptr)
            {
                throw out_of_range{"setofstacks is empty"};
            }
            return start->s.size();
        }

        void popAt(int at) // index of substack index starts from 1
        {
            if (start == nullptr)
            {
                throw out_of_range{"setofstacks is empty"};
            }
            if (at > size())
            {
                throw out_of_range{"Index is out of range. SetofStacks::popAt()"};
            }

            SetofStacks<T>* tmp = start;
            int count = 0;
            while (count < size()-at)
            {
                tmp = tmp->nxtstack;
                count++;
            }

            tmp->s.pop();
            tmp = tmp->next;
        }



};

void test_setofstacks()
{
    SetofStacks<int> st;
    cout<<" is set of stacks empty = "<<st.IsEmpty()<<endl;
    //st.pop();

    st.push(1);
    cout<<" current Stack size = "<<st.stackSize()<<endl;
    cout<<"Set size = "<<st.size()<<endl;

    st.push(2);
    cout<<" current Stack size = "<<st.stackSize()<<endl;
    cout<<"Set size = "<<st.size()<<endl;

    st.push(3);
    cout<<" current Stack size = "<<st.stackSize()<<endl;
    cout<<"Set size = "<<st.size()<<endl;

    st.push(4);
    cout<<" current Stack size = "<<st.stackSize()<<endl;
    cout<<"Set size = "<<st.size()<<endl;

    st.push(5);
    cout<<" current Stack size = "<<st.stackSize()<<endl;
    cout<<"Set size = "<<st.size()<<endl;

    st.push(6);
    cout<<" current Stack size = "<<st.stackSize()<<endl;
    cout<<"Set size = "<<st.size()<<endl;

    st.push(7);
    cout<<" current Stack size = "<<st.stackSize()<<endl;
    cout<<"Set size = "<<st.size()<<endl;

    st.push(8);
    cout<<" current Stack size = "<<st.stackSize()<<endl;
    cout<<"Set size = "<<st.size()<<endl;

    st.push(9);
    cout<<" current Stack size = "<<st.stackSize()<<endl;
    cout<<"Set size = "<<st.size()<<endl;

    st.popAt(2);


    //POP

    cout<<" top  = "<<st.top()<<endl;
    st.pop();
    cout<<" current Stack size = "<<st.stackSize()<<endl;
    cout<<"Set size = "<<st.size()<<endl;    

    cout<<" top  = "<<st.top()<<endl;
    st.pop();
    cout<<" current Stack size = "<<st.stackSize()<<endl;
    cout<<"Set size = "<<st.size()<<endl; 

    cout<<" top  = "<<st.top()<<endl;
    st.pop();
    cout<<" current Stack size = "<<st.stackSize()<<endl;
    cout<<"Set size = "<<st.size()<<endl; 

    cout<<" top  = "<<st.top()<<endl;
    st.pop();
    cout<<" current Stack size = "<<st.stackSize()<<endl;
    cout<<"Set size = "<<st.size()<<endl; 

    cout<<" top  = "<<st.top()<<endl;
    st.pop();
    cout<<" current Stack size = "<<st.stackSize()<<endl;
    cout<<"Set size = "<<st.size()<<endl; 

    cout<<" top  = "<<st.top()<<endl;
    st.pop();
    cout<<" current Stack size = "<<st.stackSize()<<endl;
    cout<<"Set size = "<<st.size()<<endl; 

    cout<<" top  = "<<st.top()<<endl;
    st.pop();
    cout<<" current Stack size = "<<st.stackSize()<<endl;
    cout<<"Set size = "<<st.size()<<endl; 

    cout<<" top  = "<<st.top()<<endl;
    st.pop();
    cout<<" current Stack size = "<<st.stackSize()<<endl;
    cout<<"Set size = "<<st.size()<<endl; 

    cout<<" top  = "<<st.top()<<endl;
    st.pop();
    cout<<" current Stack size = "<<st.stackSize()<<endl;
    cout<<"Set size = "<<st.size()<<endl; 

    cout<<" top  = "<<st.top()<<endl;
    st.pop();
    cout<<" current Stack size = "<<st.stackSize()<<endl;
    cout<<"Set size = "<<st.size()<<endl;                                                 

}
void test_minstack()
{
    minStack<int> ms;
    cout<<" is min stack empty = "<<ms.IsEmpty()<<endl;

    ms.push(3);
    cout<<"min val = "<<ms.min()<<endl;
    ms.push(1);
    ms.push(5);
    ms.push(-10);

    cout<<"min val = "<<ms.min()<<endl;
    ms.pop();

    cout<<"min val = "<<ms.min()<<endl;
    ms.pop();

    cout<<"min val = "<<ms.min()<<endl;
    ms.pop();

    cout<<"min val = "<<ms.min()<<endl;
    ms.pop();    


}


void test_stack()
{
    Stack<int> s1, s2;
    // s1.push(1);
    // cout<<"s1.top = "<<s1.top()<<endl;
    // s1.pop();
    // cout<<"s1.top = "<<s1.top()<<endl;

cout<<"s1.size = "<<s1.size()<<endl;
    s1.push(1);
    s1.push(2);
    s1.push(3);
    cout<<"s1.size = "<<s1.size()<<endl;
    s1.push(4);
    s1.push(5);
    cout<<"s1.size = "<<s1.size()<<endl;

    cout<<"s1.top = "<<s1.top()<<endl;
    s1.pop();
    cout<<"s1.top = "<<s1.top()<<endl;
    s1.pop();
    cout<<"s1.top = "<<s1.top()<<endl;
    s1.pop();
    cout<<"s1.top = "<<s1.top()<<endl;
    s1.pop();
    cout<<"s1.top = "<<s1.top()<<endl;
    s1.pop();

    cout<<"s1 is empty = "<<s1.IsEmpty()<<endl;
    cout<<"s2 is empty = "<<s2.IsEmpty()<<endl;
    
}

int main()
{
    //test_stack();
    //test_minstack();
    test_setofstacks();
}

