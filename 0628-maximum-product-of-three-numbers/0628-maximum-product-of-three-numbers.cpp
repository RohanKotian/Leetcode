class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        int max1 = -1001;
        int min2 = 1001, max2 = -1001;
        int min3 = 1001, max3 = -1001;
        
        for(int num:nums){
            if(max1 < num){
                max3 = max2;
                max2 = max1;
                max1 = num;
            }
            else if(max2 < num){
                max3 = max2;
                max2 = num;
            }
            else if(max3 < num){
                max3 = num;
            }
            if(min2 > num){
                min3 = min2;
                min2 = num;
            }
            else if(min3 > num){
                min3 = num;
            }
        }
        int a = max1 * min2 * min3;
        int b = max1 * max2 * max3;

        return max(a, b);
    }
};