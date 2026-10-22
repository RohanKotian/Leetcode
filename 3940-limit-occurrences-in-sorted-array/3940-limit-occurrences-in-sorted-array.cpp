class Solution {
public:
    vector<int> limitOccurrences(vector<int>& nums, int k) {
        int freq[101] = {0};

        for(int num:nums){
            freq[num]++;
        }

        vector<int> res;
        for(int i=1; i<=100; i++){
            for(int j=0; j<min(freq[i], k); j++){
                res.push_back(i);
            }
        }
        return res;
    }
};