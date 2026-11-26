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
        bool neg = false;
        long long m = n;
        if(n < 0){
            neg = true;
            m = abs(m);
        }
        double res = findPower(x, m);
        if(neg){
            res = 1/res;
        }
        return res;
    }
};