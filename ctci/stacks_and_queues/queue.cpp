#include<iostream>
#include<stdexcept>
using namespace std;

template<typename T>
class Queue
{
    private:
        T data;
        Queue<T>* next;
    public:
        Queue(){}
        ~Queue(){}
        Queue<T>* start = {nullptr};
        Queue<T>* curr = {nullptr};
        int sz = 0;
        T first()
        {
            if (start == nullptr)
            {
                throw out_of_range{"Empty Queue: Queue::first()"};                
            }

            return start->data;
        }

        void push(T dat)
        {
            Queue<T>* node = new (Queue<T>);
            node->data = dat;
            node->next = nullptr;
            if (start == nullptr)
            {
                start = curr = node;
            }
            else
            {                
                curr->next = node;
                curr = node;
            }
            sz++;
            return;
        }
        void pop()
        {
            if (start == nullptr)
            {
                throw out_of_range{"Empty Queue : Queue::pop()"};
                return;
            }

            Queue<T>* tmp = start;            
            start = start->next;
            delete tmp;
            sz--;
            return;
        }

        bool IsEmpty()
        {
            return start == nullptr;
        }

        int size()
        {
            return sz;
        }

};


int main()
{
    Queue<int> q;

    cout<<"q is empty= "<<q.IsEmpty()<<endl;

    cout<<"q size = "<<q.size()<<endl;
    q.push(1);
    q.push(2);
    q.push(3);
    cout<<"q size = "<<q.size()<<endl;
    q.push(4);
    q.push(5);
    q.push(6);
    cout<<"q size = "<<q.size()<<endl;

    cout<<"q.first() = "<<q.first()<<endl;
    q.pop();
    cout<<"q.first() = "<<q.first()<<endl;
    q.pop();
    cout<<"q.first() = "<<q.first()<<endl;
    q.pop();    
    cout<<"q.first() = "<<q.first()<<endl;
    q.pop();
    cout<<"q.first() = "<<q.first()<<endl;
    q.pop();
    cout<<"q.first() = "<<q.first()<<endl;
    q.pop();            

    cout<<"q is empty= "<<q.IsEmpty()<<endl;

    q.pop();

}