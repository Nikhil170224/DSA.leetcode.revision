// class MyQueue {
// public:
//     stack<int>st;
//     MyQueue() {
        
//     }
    
//     void push(int x) {
//         st.push(x);
//     }

//     int frontEle = -1;
//     int findFrontEle(){
//           //Base case
//         if(st.size() == 1){
//             frontEle = st.top();
//             return frontEle;
//         }
//         //ek case khud solve kardo
//         int temp =st.top();
//         st.pop();
//         findFrontEle();
//         st.push(temp);
//         return frontEle;  
//     }

//     int popedEle = -1;
//     int pop() {
//         //Base case
//         if(st.size() == 2){
//             frontEle = st.top();
//         }
//         if(st.size() == 1){
//             popedEle = st.top();
//             st.pop();
//             return popedEle;
//         }
//         //ek case khud solve kardo
//         int temp =st.top();
//         st.pop();
//         pop();
//         st.push(temp);
//         return popedEle;
//     }
    
//     int peek() {
//         if(frontEle == -1){
//           return findFrontEle();
//         }
//         else{
//         return frontEle;
//         }
//     }
    
//     bool empty() {
//         return st.empty();
//     }
// };

class MyQueue {
public:
    stack<int>s1;
    stack<int>s2;
    MyQueue() {
        
    }
    
    void push(int x) {
       s1.push(x); 
    }
    
    int pop() {
        if(!s2.empty()){
            int topele = s2.top();
            s2.pop();
            return topele;
        }
        else{
            while(!s1.empty()){
                int topEle = s1.top();
                s2.push(topEle);
                s1.pop();
            }
            int top = s2.top();
            s2.pop();
            return top;
        }
    }
    
    int peek() {
       if(!s2.empty()){
        return s2.top();
       }
       else{
       while(!s1.empty()){
                int topEle = s1.top();
                s2.push(topEle);
                s1.pop();
            }
            int top = s2.top();
            return top;
       }
    }
    
    bool empty() {
        return (s1.size() + s2.size() == 0) ? true : false; 
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