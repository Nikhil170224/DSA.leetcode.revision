class Solution {
public:
    void prevSmallerEle(vector<int>&v,vector<int>&ans){
    int size = v.size();
    stack<int>st;
    st.push(-1);
    for(int i = 0; i< v.size(); ++i){
        while(st.top() != -1 && v[i]<= v[st.top()]){
            st.pop();
        }
        ans[i]= st.top();
        st.push(i);
    }
}
void nextSmallerEle(vector<int>&v,vector<int>&ans){
    int size = v.size();
    stack<int>st;
    st.push(-1);
    for(int i = size-1; i>= 0; --i){
        while(st.top() != -1 && v[i]<= v[st.top()]){
            st.pop();
        }
        ans[i]= st.top();
        st.push(i);
    }
}
    int largestRectangleArea(vector<int>& heights) {
        int size = heights.size();
        vector<int>prev(size);
        vector<int>next(size);
        prevSmallerEle(heights,prev);
        nextSmallerEle(heights,next);
        int maxArea = INT_MIN;
        for(int i = 0; i< size; i++){
            int lenght = heights[i];
            if(next[i] == -1){
                next[i]=size;
            }
            int width = next[i]-prev[i]-1;
            int area = lenght * width;
            maxArea = max(maxArea,area);
        }
        return maxArea;
    }
};