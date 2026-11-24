class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        int area = 0, maxArea = 0;
        int pse = -1, nse = n;
        stack<int> st;
        for(int i=0; i<n; i++){
            while(!st.empty() && heights[st.top()]>heights[i]){
                int element = st.top();
                st.pop();
                pse = st.empty() ? -1: st.top();
                nse = i;
                area = heights[element] * (nse - pse - 1);
                maxArea = max(maxArea, area);
            }
            st.push(i);
        }
        while(!st.empty()){
            int element = st.top();
            st.pop();
            pse = st.empty() ? -1: st.top();
            nse = n;
            area = heights[element] * (nse - pse - 1);
            maxArea = max(maxArea, area);
        }
        return maxArea;
    }
};