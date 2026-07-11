class DisJointSet{
    public:
    vector<int> parent, size;

    DisJointSet(int n){
        size.assign(n, 1);
        parent.resize(n);
        for(int i=0; i<n; i++){
            parent[i] = i;
        }
    }

    int findUpar(int node){
        if(parent[node] != node){
            parent[node] = findUpar(parent[node]);
        }
        return parent[node];
    }

    void unionBySize(int u, int v){
        int up = findUpar(u);
        int vp = findUpar(v);

        if(up==vp) return;
        
        if(size[up] > size[vp]){
            size[up] += size[vp];
            parent[vp] = up;
        }
        else{
            size[vp] += size[up];
            parent[up] = vp;
        }
    }
};
class Solution {
public:
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        DisJointSet ds(n);

        for(auto& edge:edges){
            ds.unionBySize(edge[0], edge[1]);            
        }

        vector<int> edge_count(n, 0);
        for(auto& edge:edges){
            int root = ds.findUpar(edge[0]);
            edge_count[root]++;
        }

        int res = 0;
        for(int i=0; i<n; i++){
            if(ds.findUpar(i) == i){
                int s = ds.size[i];
                if(edge_count[i] == (s*(s-1)/2)){
                    res++;
                }
            }
        }

        return res;

        
    }
};