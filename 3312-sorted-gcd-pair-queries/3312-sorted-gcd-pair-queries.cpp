class Solution {
public:
    typedef long long ll;
    vector<int> gcdValues(vector<int>& nums, vector<long long>& queries) {
        int maxVal = 1;
        
        for(int num:nums){
            maxVal = max(maxVal, num);
        }

        vector<int> freq(maxVal+1, 0);
        
        for(int num:nums){
            freq[num]++;
        }

        vector<ll> pairDiv(maxVal+1);
        for(int d=1; d<=maxVal; d++){
            int count = 0;
            for(int mul=d; mul<=maxVal; mul += d){
                count += freq[mul];
            }
            pairDiv[d] = 1LL * count * (count-1)/2;
        }

        vector<ll> exactGCD(maxVal+1);
        for(int d=maxVal; d>=1; d--){
            exactGCD[d] = pairDiv[d];
            for(int mul=d+d; mul<=maxVal; mul += d){
                exactGCD[d] -= exactGCD[mul];
            }
        }

        vector<ll> preSum(maxVal+1);
        preSum[0] = 0;
        for(int i=1; i<=maxVal; i++){
            preSum[i] = preSum[i-1] + exactGCD[i];
        }

        vector<int> res;
        for(ll q:queries){
            int g = upper_bound(preSum.begin(), preSum.end(), q) - preSum.begin();
            res.push_back(g);
        }

        return res;
    }
};