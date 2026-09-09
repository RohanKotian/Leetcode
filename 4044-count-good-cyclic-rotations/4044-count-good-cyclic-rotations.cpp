class Solution {
public:
    int countGoodRotations(vector<int>& nums) {
        int n = nums.size();
        int m = n/2;

        long long sum = 0;

        for(int i=0; i<m; i++){
            sum += nums[i];
        }

        vector<long long> preSum;
        preSum.push_back(sum);

        int j = 0;
        for(int i=m; i<2*n-1; i++){
            sum -= nums[j%n];
            sum += nums[i%n];
            j++;
            preSum.push_back(sum);
        }

        int count = 0;
        for(int i=0; i<preSum.size()-m; i++){
            if(preSum[i] > preSum[i+m])
                count++;
        }

        return count;
    }
};