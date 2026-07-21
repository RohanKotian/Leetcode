class Solution {
public:    
    int maxActiveSectionsAfterTrade(string s) {
        int n = s.length();

        int ones = 0;
        int prevZeros = 0;
        int nextZeros = 0;

        int bestGain = 0;

        int i = 0;
        while(i<n && s[i]=='0'){
            prevZeros++;
            i++;
        }
        while(i<n){
            while(i<n && s[i]=='1'){
                i++;
                ones++;
            }

            while(i<n && s[i]=='0'){
                nextZeros++;
                i++;
            }

            if(prevZeros>0 && nextZeros>0){
                bestGain = max(bestGain, prevZeros + nextZeros);
            }
            
            prevZeros = nextZeros;
            nextZeros = 0;
        }

        return ones + bestGain;
    }
};