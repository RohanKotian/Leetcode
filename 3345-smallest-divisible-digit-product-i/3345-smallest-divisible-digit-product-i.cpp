class Solution {
public:
    int smallestNumber(int n, int t) {
        if(n%10 == 0) return n;

        int num = n;
        int d;
        for(int i=0; i<10; i++){
            num = n + i;
            d = num % 10;
            if(num >= 10) d *= (num / 10);

            if(d % t == 0) return num;
        }
        return n;
    }
};