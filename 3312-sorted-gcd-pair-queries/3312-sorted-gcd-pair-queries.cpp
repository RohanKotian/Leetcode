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

        vector<ll> exactGCD(maxVal+1);

        for(int d=maxVal; d>=1; d--){
            int count = 0;
            for(int mul=d; mul<=maxVal; mul += d){
                count += freq[mul];
            }
            exactGCD[d] = 1LL * count * (count-1)/2;
            
            for(int mul=d+d; mul<=maxVal; mul += d){
                exactGCD[d] -= exactGCD[mul];
            }
        }

        for(int i=1; i<=maxVal; i++){
            exactGCD[i] += exactGCD[i-1];
        }

        vector<int> res(queries.size());
        for(int i=0; i<queries.size(); i++){
            int g = upper_bound(exactGCD.begin(), exactGCD.end(), queries[i]) - exactGCD.begin();
            res[i] = g;
        }

        return res;
    }
};