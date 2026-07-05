class Solution {
public:
    const int MOD = 1e9 + 7;

    int getIntfromChar(char ch){
        return (ch=='S') ? 0 : ch - '0';
    }

    vector<int> pathsWithMaxScore(vector<string>& board) {
        int n = board.size();

        vector<pair<int, int>> prev(n, {0, 0});       
        vector<pair<int, int>> curr(n, {0, 0});   

        prev[0] = {0, 1};

        for(int i=0; i<n; i++){
            curr.assign(n, {0, 0});
            
            if(i==0) curr[0] = {0, 1};

            for(int j=0; j<n; j++){
                if((i==0 && j==0) || board[i][j]=='X') continue;

                int upScore = 0, upCount = 0;
                int lfScore = 0, lfCount = 0;
                int diScore = 0, diCount = 0;

                int val = getIntfromChar(board[i][j]);

                if(i>0){
                    const auto &[tempScore, tempCount] = prev[j];
                    upCount = tempCount;
                    if(upCount > 0){
                        upScore = tempScore + val;
                    }
                }
                if(j>0){
                    const auto &[tempScore, tempCount] = curr[j-1];            
                    lfCount = tempCount;
                    if(lfCount > 0){
                        lfScore = tempScore + val;
                    }
                }
                if(i>0 && j>0){
                    const auto &[tempScore, tempCount] = prev[j-1];
                    diCount = tempCount;
                    if(diCount > 0){
                        diScore = tempScore + val;
                    }
                }

                int bestScore = max({upScore, lfScore, diScore});
                int bestCount = 0;

                if(bestScore==upScore) bestCount = (bestCount + upCount) % MOD;
                if(bestScore==lfScore) bestCount = (bestCount + lfCount) % MOD;
                if(bestScore==diScore) bestCount = (bestCount + diCount) % MOD;

                curr[j] = {bestScore, bestCount};
            }
            swap(prev, curr);
        }

        pair<int, int> ans = prev[n-1];
        if(ans.second == 0){
            return {0, 0};
        }
        return {ans.first, ans.second};
    }
};