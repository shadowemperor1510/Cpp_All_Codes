#include<iostream>
#include<climits>
using namespace std;
class stack{
    int *data;
    int nextindex;
    int totsize;

    public:
    stack(int size){
        data= new int(size);
        nextindex=0;
        totsize=size;
    }

    int size(){
        return totsize;
    }

    bool empty(){
        return nextindex==0;
    }

    void push(int element){
        if(nextindex==totsize){
            cout<<"Stack is full"<<endl;
            return;
        }
        data[nextindex]=element;
        nextindex++;
    }

    int pop(){
        if(nextindex<0){
            cout<<"Stack is empty"<<endl;
            return INT16_MIN;
        }
        nextindex--;
        return data[nextindex];
    }

    int top(){
        if(nextindex<0){
            cout<<"Stack is empty"<<endl;
            return INT16_MIN;
        }
        return data[nextindex-1];
    }
};

int main(){
    stack s1(5);
    s1.push(5);
    s1.push(10);
    s1.push(15);
    cout<<s1.top()<<endl;
    s1.pop();
    cout<<s1.empty()<<endl;
    cout<<s1.size()<<endl;
    return 0;
}