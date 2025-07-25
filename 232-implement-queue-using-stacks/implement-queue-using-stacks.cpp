class MyQueue {
public:
    stack<int>st;
    MyQueue() {
        
    }
    
    void push(int x) {
        st.push(x);
    }

    int frontEle = -1;
    int findFrontEle(){
          //Base case
        if(st.size() == 1){
            frontEle = st.top();
            return frontEle;
        }
        //ek case khud solve kardo
        int temp =st.top();
        st.pop();
        findFrontEle();
        st.push(temp);
        return frontEle;  
    }

    int popedEle = -1;
    int pop() {
        //Base case
        if(st.size() == 2){
            frontEle = st.top();
        }
        if(st.size() == 1){
            popedEle = st.top();
            st.pop();
            return popedEle;
        }
        //ek case khud solve kardo
        int temp =st.top();
        st.pop();
        pop();
        st.push(temp);
        return popedEle;
    }
    
    int peek() {
        if(frontEle == -1){
          return findFrontEle();
        }
        else{
        return frontEle;
        }
    }
    
    bool empty() {
        return st.empty();
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