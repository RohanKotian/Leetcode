class Solution {
public:
    string majorityFrequencyGroup(string s) {
        int freq[26] = {0};

        for(char c:s){
            freq[c - 'a']++;
        }

        int maxLen = 0;
        int maxFreq = 0;
        int unique[101] = {0};
        for(int i=0; i<26; i++){
            if(freq[i]){
                unique[freq[i]]++;
                if(maxLen < unique[freq[i]] || maxLen == unique[freq[i]] && freq[i] > maxFreq){
                    maxLen = unique[freq[i]];
                    maxFreq = freq[i];
                }
            }
        }

        string res = "";
        for(int i=0; i<26; i++){
            if(freq[i] == maxFreq){
                res += i + 'a';
            }
        }

        return res;
    }
};