class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        vector<int> even, odd;

        for(int num:nums){
            if(num % 2 == 0){
                even.push_back(num);
            }
            else{
                odd.push_back(num);
            }
        }

        for(int odds:odd){
            even.push_back(odds);
        }
        return even;
    }
};