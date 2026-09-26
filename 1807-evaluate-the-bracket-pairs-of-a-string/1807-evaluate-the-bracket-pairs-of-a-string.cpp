class Solution {
public:
    string evaluate(string s, vector<vector<string>>& know) {
        int n = s.size();

        unordered_map<string, string> mp;
        for(auto& k:know){
            mp[k[0]] = k[1];
        }

        string res = "";

        int i=0, j=0;
        while(i<n){
            while(j < n && s[j] != '('){
                j++;
            }

            if(i != j){
                res += s.substr(i, j-i);
            }

            j++;
            i = j;
            while(j < n && s[j] != ')'){
                j++;
            }
            if(j>=n) break;

            string word = s.substr(i, j-i);
            auto it = mp.find(word);
            if(it != mp.end()){
                res += it->second;
            }
            else{
                res += '?';
            }

            j++;
            i = j;
        }

        return res;
    }
};