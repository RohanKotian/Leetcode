class Solution {
public:
    bool checkValidString(string s) {
        int n = s.size();
        vector<bool>prev (n+1, false);
        vector<bool>curr (n+1, false);

        prev[0] = true;

        for(int i=n-1; i>=0; i--){
            for(int bal=0; bal<n; bal++){

                bool ans = false;
                if(s[i] == '('){
                    ans = prev[bal + 1];
                }
                else if(s[i] == ')'){
                    if(bal > 0){
                        ans = prev[bal - 1];                        
                    }
                }
                else{
                    ans = prev[bal];                        
                    
                    if(bal <= n){
                        ans = ans || prev[bal + 1];                        
                    }

                    if(bal > 0){
                        ans = ans || prev[bal - 1];
                    }
                }

                curr[bal] = ans;
            }
            prev = curr;
        }

        return prev[0];
    }
};