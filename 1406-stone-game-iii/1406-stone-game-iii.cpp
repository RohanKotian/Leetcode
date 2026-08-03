class Solution {
public:

    string stoneGameIII(vector<int>& stoneValue) {
        int n = stoneValue.size();

        int curr = 0, prev1 = 0, prev2 = 0, prev3 = 0;

        for(int i=n-1; i>=0; i--){
            curr = stoneValue[i] - prev1;        
            if(i+1 < n) 
                curr = max(curr, stoneValue[i] + stoneValue[i+1] - prev2);
            if(i+2 < n) 
                curr = max(curr, stoneValue[i] + stoneValue[i+1] + stoneValue[i+2] - prev3);

            prev3 = prev2;
            prev2 = prev1;
            prev1 = curr;
        }

        if(prev1 == 0) return "Tie";
        else if(prev1 > 0) return "Alice";
        return "Bob";
    }
};