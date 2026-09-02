class Solution {
public:
    using VB    = vector<bool>;
    using VVB   = vector<VB>;
    using VVVB  = vector<VVB>;
    using VVVVB = vector<VVVB>;

    vector<pair<int, int>> dirs = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};

    struct State{
        int row;
        int col;
        int energyLeft;
        int collectedMask;
    };
    
    int minMoves(vector<string>& classroom, int energy) {
        int n = classroom.size();
        int m = classroom[0].size();

        int maxEnergy = energy;

        int litterBit[20][20];
        int litterCount = 0;
        int startR = 0;
        int startC = 0;

        for(int r=0; r<n; r++){
            for(int c=0; c<m; c++){
                litterBit[r][c] = -1;

                if(classroom[r][c]=='S'){
                    startR = r;
                    startC = c;
                }

                else if(classroom[r][c]=='L'){
                    litterBit[r][c] = litterCount;
                    litterCount++;
                }
            }
        }

        if(litterCount==0)
            return 0;

        int allCollected = (1<<litterCount) - 1;

        VVVVB visited(n, VVVB(m, VVB(maxEnergy+1, VB(allCollected+1, false))));

        queue<State> que;
        que.push({startR, startC, energy, 0});

        visited[startR][startC][energy][0] = true;

        int moves = 0;
        while(!que.empty()){
            int currSize = que.size();

            while(currSize--){
                State curr = que.front();
                que.pop();

                if(curr.collectedMask == allCollected)
                    return moves;

                if(curr.energyLeft == 0)
                    continue;

                for(auto& [dir1, dir2]:dirs){
                    int nextR = curr.row + dir1;
                    int nextC = curr.col + dir2;

                    if(nextR < 0 || nextR >= n || nextC < 0 || nextC >= m)
                        continue;

                    char cell = classroom[nextR][nextC];
                    if(cell=='X')
                        continue;

                    int nextEnergy = curr.energyLeft - 1;
                    int nextMask = curr.collectedMask;

                    if(cell=='R'){
                        nextEnergy = maxEnergy;
                    }
                    else if(cell=='L')
                        nextMask |= (1<<litterBit[nextR][nextC]);

                    if(!visited[nextR][nextC][nextEnergy][nextMask]){
                        visited[nextR][nextC][nextEnergy][nextMask] = true;
                        que.push({nextR, nextC, nextEnergy, nextMask});
                    }                    
                }
            }
            moves++;
        }
        return -1;        
    }
};