class Solution {
public:
    vector<int> remainingMethods(int n, int k, vector<vector<int>>& invocations) {
        vector<bool> sus(n, false);
        vector<int> inDeg(n, 0);

        vector<vector<int>> adj(n);
        for(auto& it:invocations){
            int u = it[0];
            int v = it[1];

            adj[u].push_back(v);
            inDeg[v]++;
        }

        queue<int> q;
        q.push(k);
        sus[k] = true;

        while(!q.empty()){
            int node = q.front();
            q.pop();

            for(int& nei:adj[node]){
                inDeg[nei]--;
                if(!sus[nei]){
                    sus[nei] = true;
                    q.push(nei);
                }
            }
        }

        vector<int> res;
        bool cannotRemove = false;
        for(int i=0; i<n; i++){
            if(sus[i] && inDeg[i]>0){
                cannotRemove = true;
                break;
            }
            if(!sus[i]){
                res.push_back(i);
            }
        }

        if(cannotRemove){
            vector<int> arr(n);
            for(int i=0; i<n; i++){
                arr[i] = i;                
            }
            return arr;
        }

        return res;
    }
};