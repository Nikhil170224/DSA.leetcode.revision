class Solution {
public:
    bool isValid(string s) {
        stack<char>st;
        for(int i = 0; i<s.size(); i++){
            char ch = s[i];
            if(ch == '(' || ch == '{' || ch == '['){
                st.push(ch);
            }
            else{
                //closing brackets
                if(!st.empty()){
                    char topCh = st.top();
                    if(ch == ')' && topCh == '('){
                        st.pop();
                    }
                    else if(ch == '}' && topCh == '{'){
                        st.pop();
                    }
                    else if(ch == ']' && topCh == '['){
                        st.pop();
                    }
                    else{
                        return false;
                    }
                }
                else{
                    //empty
                    return false;
                }
            }
        }
        if(st.empty()){
            return true;
        }
        else{
            return false;
        }
    }
};