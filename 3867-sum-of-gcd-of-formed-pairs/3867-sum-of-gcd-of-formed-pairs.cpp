class Solution {
public:
    long long gcdSum(vector<int>& nums) {
        int n = nums.size();

        int mx = 0;
        vector<int> preGCD(n);

        for(int i=0; i<n; i++){
            mx = max(mx, nums[i]);
            preGCD[i] = __gcd(mx, nums[i]);
        }

        sort(preGCD.begin(), preGCD.end());

        long long res = 0;
        int l = 0, r = n-1;
        while(l<r){
            res += __gcd(preGCD[l], preGCD[r]);
            l++, r--;
        }
        return res;
    }
};