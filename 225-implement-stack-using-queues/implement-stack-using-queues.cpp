class MyStack {
public:
    queue<int>q;
    MyStack() {
        
    }
    
    void push(int x) {
        q.push(x);
    }
    
    int pop() {
        int size = q.size();
        int ele;
        for(int i = 0; i< size; i++){
            ele = q.front();
            q.pop();
            if(i != size-1){
            q.push(ele);
            }
        }
        return ele ;
    }
    int top() {
         int size = q.size();
         int topele;
        for(int i = 0; i< size; i++){
            topele = q.front();
            q.pop();
            q.push(topele);
        }
        return topele;
    }
    
    bool empty() {
        return (q.empty());
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */