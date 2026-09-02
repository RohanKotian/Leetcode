class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        int n = nums1.size();
        int oddCount = 0, evenCount = 0;

        int smallestOdd = 1e9;
        int smallestEven = 1e9;

        for(int i=0; i<n; i++){
            if(nums1[i]%2==0){
                oddCount++;
                smallestEven = min(smallestEven, nums1[i]);
            }
            else{
                evenCount++;
                smallestOdd = min(smallestOdd, nums1[i]);
            }
        }

        if(evenCount==n || oddCount==n || smallestOdd < smallestEven)
            return true;        
        
        return false;
    }
};