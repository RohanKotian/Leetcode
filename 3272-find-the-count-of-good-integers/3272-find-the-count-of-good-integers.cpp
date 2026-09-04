class Solution {
public:    
    long long countGoodIntegers(int n, int k) {
        int d = (n+1)/2;
        int start = pow(10, d-1);
        int end = pow(10, d) - 1;

        vector<long long> factorial(11, 1);
        for(int i=1; i<11; i++){
            factorial[i] = factorial[i-1] * i;
        }

        unordered_set<string> st;
        for(int num=start; num<=end; num++){
            string left = to_string(num);
            string full = "";

            if(n%2==0){
                string right = left;
                reverse(right.begin(), right.end());
                full = left + right;
            }
            else{
                string right = left.substr(0, d-1);
                reverse(right.begin(), right.end());
                full = left + right;
            }

            long long number = stoll(full);
            if(number%k!=0)
                continue;
            
            sort(full.begin(), full.end());
            st.insert(full);
        }

        long long res = 0;
        for(const string& s:st){
            vector<int> count(10, 0);
            for(const char& ch:s){
                count[ch - '0']++;
            }

            int totalDigs = s.length();
            int zeroCount = count[0];
            int nonZeroDigs = totalDigs - zeroCount;

            long long perm = (nonZeroDigs * factorial[totalDigs-1]);

            for(int i=0; i<10; i++){
                perm /= factorial[count[i]];
            }

            res += perm;
        }
        return res;
    }
};