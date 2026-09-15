class Solution {
public:
    int longestCycle(vector<int>& edges) {
        int n = edges.size();
        int res = -1;

        vector<int> time(n, 0);
        vector<int> pathID(n, 0);

        for(int i=0; i<n; i++){
            if(pathID[i] != 0 || edges[i] == -1) continue;

            int curr = i;
            int currTime = 0;
            int id = i+1;

            while(!time[curr]){
                if(pathID[curr] != 0) break;
                currTime++;

                pathID[curr] = id;
                time[curr] = currTime;

                curr = edges[curr];
                if(curr == -1) break;

                if(pathID[curr] == id){
                    res = max(res, currTime - time[curr] + 1);
                    break;
                }
            }

        }
        return res;
    }
};