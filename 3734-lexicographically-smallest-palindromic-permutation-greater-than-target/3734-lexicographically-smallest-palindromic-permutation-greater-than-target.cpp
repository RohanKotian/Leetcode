class Solution {
public:
    int n, m;
    string res = "";
    char middle;

    bool checkPallindrome(string half, string& t){
        string left = half;

        if(n%2){            
            half += middle;
        }

        reverse(left.begin(), left.end());
        half += left;

        return half > t;
    }

    bool solve(int i, string& half, string& target, 
    vector<int>& freq, bool greater, string& t){
        if(i==m){
            if(greater || checkPallindrome(half, t)){
                res = half;
                return true;
            }
            return false;
        }

        for(char ch='a'; ch<='z'; ch++){
            int x = ch - 'a';

            if(freq[x]==0)
                continue;

            if(!greater && ch < target[i])
                continue;

            bool isGreater = greater || ch > target[i];

            half += ch;
            freq[x]--;
            
            if(solve(i+1, half, target, freq, isGreater, t))
                return true;

            half.pop_back();
            freq[x]++;

        }
        return false;
    }
    string lexPalindromicPermutation(string s, string target) {
        n = s.size();

        vector<int> freq(26, 0);

        for(char c:s){
            freq[c - 'a']++;            
        }

        int oddCount = 0;
        vector<int> hfreq(26);
        
        m = n / 2;

        for(int i=0; i<26; i++){
            hfreq[i] = freq[i]/2;

            if(freq[i] % 2){
                middle = i + 'a';
                oddCount++;
            }
        }

        if(oddCount > 1)
            return "";

        string htarget = target.substr(0, m);
        string half = "";

        if(!solve(0, half, htarget, hfreq, false, target))
            return "";   

        string ans = res;

        if(n%2){
            ans += middle;
        }

        reverse(res.begin(), res.end());
        ans += res;

        return ans;        
    }
};