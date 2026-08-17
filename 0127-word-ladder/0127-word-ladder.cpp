class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        int n = beginWord.size();

        unordered_set<string> st(wordList.begin(), wordList.end());
        st.erase(beginWord);

        if(st.find(endWord) == st.end()) return 0;
        
        queue<pair<string, int>> q;
        q.push({beginWord, 1});

        while(!q.empty()){
            auto [word, steps] = q.front();
            q.pop();

            if(word == endWord){
                return steps;
            }

            for(int i=0; i<n; i++){
                char og = word[i];
                for(char c='a'; c<='z'; c++){
                    word[i] = c;
                    if(st.find(word) != st.end()){
                        q.push({word, steps+1});
                        st.erase(word);
                    }
                }
                word[i] = og;
            }
        }
        return 0;
    }
};