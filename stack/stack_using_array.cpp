#include<iostream>
#include<climits>
using namespace std;

class StackUsingArray{
    int *data;
    int nextIndex;
    int capacity;

    public:
    StackUsingArray(int totalSize)
    {
        data=new int[totalSize];
        nextIndex=0;
        capacity=totalSize;
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
        {cout<<"stack is full"<<endl;
        return ;}
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
    StackUsingArray s(4);
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