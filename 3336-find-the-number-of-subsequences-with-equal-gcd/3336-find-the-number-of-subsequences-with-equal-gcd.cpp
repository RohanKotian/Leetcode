class Solution {
public:
    const int MOD = 1e9 + 7;

    int subsequencePairCount(vector<int>& nums) {
        int n = nums.size();
        int max_val = *max_element(nums.begin(), nums.end());

        vector<vector<int>> prev(max_val+1, vector<int>(max_val+1, -1));
        vector<vector<int>> curr(max_val+1, vector<int>(max_val+1, -1));        

        for(int gcd1=0; gcd1<=max_val; gcd1++){
            for(int gcd2=0; gcd2<=max_val; gcd2++){
                bool valid = (gcd1!=0 && gcd2!=0);
                bool equal = (gcd1==gcd2);
                prev[gcd1][gcd2] = (valid && equal);
                
            }
        }

        for(int i=n-1; i>=0; i--){
            for(int gcd1=max_val; gcd1>=0; gcd1--){
                for(int gcd2=max_val; gcd2>=0; gcd2--){

                    int skip = prev[gcd1][gcd2];
                    
                    int seq1 = prev[__gcd(gcd1, nums[i])][gcd2];
                    
                    int seq2 = prev[gcd1][__gcd(gcd2, nums[i])];

                    curr[gcd1][gcd2] = (0LL + skip + seq1 + seq2) % MOD;
                }                
            }
            prev = curr;
        }

        return prev[0][0];
    }
};