class Solution {
public:
    long long sumAndMultiply(int n) {
        long long num = 0;
        long long sum = 0;
        long long place = 1;

        while(n){
            int d = n%10;            
            n /= 10;

            if(d==0) continue;
            num += d*place;
            sum += d;
            place *= 10;
        }
        num = num * sum;
        return num;
    }
};