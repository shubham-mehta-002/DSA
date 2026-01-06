#include<bits/stdc++.h>
using namespace std;

class MyQueue {
    stack<int>s1;
    stack<int>s2;
public:
    MyQueue() {
        
    }
    
    void push(int x) {
        s1.push(x);
    }
    
    int pop() {
        int val = -1;
        if(!s2.empty()){
            val = s2.top();
        }else{
            while(!s1.empty()){
                s2.push(s1.top());
                s1.pop();
            }
            val = s2.top();
        }
        s2.pop();
        return val;
    }
    
    int peek() {
        int val = -1;
        if(!s2.empty()){
            val = s2.top();
        }else{
            while(!s1.empty()){
                s2.push(s1.top());
                s1.pop();
            }
            val = s2.top();
        }
        return val;
    }
    
    bool empty() {
        return s1.empty() && s2.empty();   
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */