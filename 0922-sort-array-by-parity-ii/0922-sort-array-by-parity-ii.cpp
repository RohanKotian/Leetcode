class Solution {
public:
    vector<int> sortArrayByParityII(vector<int>& nums) {
        vector<int> even, odd;

        for(int num:nums){
            if(num % 2 == 0){
                even.push_back(num);
            }
            else{
                odd.push_back(num);
            }
        }

        vector<int> res;
        for(int i=0; i<even.size(); i++){
            res.push_back(even[i]);
            res.push_back(odd[i]);
        }
        return res;
    }
};