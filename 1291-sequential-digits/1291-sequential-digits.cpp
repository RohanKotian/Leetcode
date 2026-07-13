class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {

        int temp_low = low;
        int temp_high = high;

        int len1 = 0, len2 = 0;
        
        while(temp_low){
            temp_low /= 10;
            len1++;
        }
        while(temp_high){
            temp_high /= 10;
            len2++;
        }        

        vector<int> res;
        bool flag = true;

        for(int len = len1; len <= len2 && flag; len++){
            for(int s=1; s<=9; s++){
                if(s + len - 1 > 9) break;

                int num = 0, d = s;
                for(int i=0; i<len; i++){
                    num *= 10;
                    num += d;
                    d++;
                }
                if(num>high){
                    flag = false;
                    break;
                } 
                if(num>=low) res.push_back(num);
            }
        }        

        return res;
    }
};