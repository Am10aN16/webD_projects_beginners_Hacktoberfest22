#include<iostream>
#include<climits>
using namespace std;

class StackUsingArray{
    int *data;
    int nextIndex;
    int capacity;

    public:
    StackUsingArray()
    {
        data=new int[4];
        nextIndex=0;
        capacity=4;
    }
    int size()
    {
        return nextIndex;
    }

    bool isEmpty()
    {
        return nextIndex==0;
    }
    void push(int element)
    {
        if(nextIndex==capacity)
        {
            int *newdata= new int[capacity*2];
            for (int  i = 0; i < capacity; i++)
            {
                newdata[i]=data[i];
            }
            capacity*=2;
            delete []data;
            data=newdata;
            
        }
        data[nextIndex]=element;
        nextIndex++;
    }
    int pop()
    {
        if(isEmpty())
        {
            cout<<"stack is empty"<<endl;
            return INT_MIN;
        }
        nextIndex--;
        return data[nextIndex];
    }
    int top()
    {
         if(isEmpty())
        {
            cout<<"stack is empty"<<endl;
            return INT_MIN;
        }
        return data[nextIndex-1];
    }

};

int main()
{
    StackUsingArray s;
    s.push(10);
    s.push(20);
    s.push(30);
    s.push(40);
    s.push(50);

    cout<<s.pop()<<endl;
    cout<<s.isEmpty()<<endl;
    cout<<s.top()<<endl;

    cout<<s.size()<<endl;

}