class Solution {
public:
    int digitSum(int num){
        int sum = 0;
        while(num){
            sum += num % 10;
            num /= 10;
        }
        return sum;
    }
    int minSwaps(vector<int>& nums) {
        int n = nums.size();
        vector<tuple<int, int, int>> mp;

        for(int i=0; i<n; i++){
            int sum = digitSum(nums[i]);
            mp.push_back({sum, nums[i], i});
        }

        sort(mp.begin(), mp.end());

        vector<bool> vis(n, 0);
        int swapCount = 0;

        for(int i=0; i<n; i++){
            if(vis[i]) continue;

            int curr = i;
            while(!vis[curr]){
                vis[curr] = true;
                curr = get<2>(mp[curr]);
                swapCount++;
            }
            swapCount--;
        }

        return swapCount;
    }
};