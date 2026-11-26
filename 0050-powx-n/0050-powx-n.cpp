class Solution {
public:
    double findPower(double a, long long base){
        if(base == 0){
            return 1.0;
        }

        double half = findPower(a, base/2);
        double result = (half * half);

        if(base % 2 == 1){
            result = (result * a);
        }

        return result;
    }
    double myPow(double x, int n) {
        long long m = n;
        if(n < 0){
            m = abs(m);
        }
        double res = findPower(x, m);
        if(n < 0){
            res = 1.0 / res;
        }
        return res;
    }
};