class Solution {
public:
    string smallestPalindrome(string s) {
        int n = s.length();
        int mp[26] = {0};

        for(int i=0; i<n/2; i++){
            mp[s[i] - 'a']++;
        }

        string left = "";        

        for(int i=0; i<26; i++){
            while(mp[i]--){
                left += (char)(i + 'a');
            }
        }

        string right = left;
        reverse(right.begin(), right.end());
        
        if(n%2==1){
            left += s[n/2];            
        }

        left += right;

        return left;
    }
};