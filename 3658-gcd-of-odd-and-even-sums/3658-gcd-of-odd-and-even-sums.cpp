class Solution {
public:
    int gcdOfOddEvenSums(int n) {
        long long even = 0, odd = 0;
        for(int i=0; i<n; i++){
            even += 2*i;
            odd += 2*i + 1;
        }
        int res = __gcd(even, odd);
        return res;
    }
};