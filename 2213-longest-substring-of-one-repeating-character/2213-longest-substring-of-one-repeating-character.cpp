class Solution {
public:
    struct Node{
        int maxLen = 0;
        int pre = 0;
        int suf = 0;
        char leftChar = 0;
        char rightChar = 0;
    };

    int n;
    vector<Node> segmentTree;
        
    void buildSegmentTree(int i, int l, int r, string& s){
        if(l==r){
            segmentTree[i] = {1, 1, 1, s[l], s[l]};
            return;
        }
        int mid = l + (r-l)/2;
        buildSegmentTree(2*i+1, l, mid, s);
        buildSegmentTree(2*i+2, mid+1, r, s);

        segmentTree[i] = merge(segmentTree[2*i+1], segmentTree[2*i+2], mid-l+1, r-mid);
    }

    void update(int i, int l, int r, int pos, char ch){
        if(l==r){
            segmentTree[i] = {1, 1, 1, ch, ch};
            return;
        }

        int mid = l + (r-l)/2;
        if(pos<=mid){
            update(2*i+1, l, mid, pos, ch);
        }
        else{
            update(2*i+2, mid+1, r, pos, ch);
        }
        segmentTree[i] = merge(segmentTree[2*i+1], segmentTree[2*i+2], mid-l+1, r-mid);
    }

    Node merge(const Node& L, const Node& R, int leftLen, int rightLen){
        Node res;

        res.leftChar = L.leftChar;
        res.rightChar = R.rightChar;

        res.pre = L.pre;
        if(L.pre == leftLen && L.rightChar == R.leftChar){
            res.pre += R.pre;
        }

        res.suf = R.suf;
        if(R.suf == rightLen && L.rightChar == R.leftChar){
            res.suf += L.suf;
        }

        res.maxLen = max(L.maxLen, R.maxLen);
        if(L.rightChar == R.leftChar){
            res.maxLen = max(res.maxLen, L.suf + R.pre);
        }

        return res;
    }

    vector<int> longestRepeating(string s, string queryCharacters, vector<int>& queryIndices) {

        int n = s.length();
        segmentTree.assign(4*n, Node());

        buildSegmentTree(0, 0, n-1, s);

        int k = queryIndices.size();

        vector<int> res(k);
        for(int i=0; i<k; i++){
            int pos = queryIndices[i];
            char ch = queryCharacters[i];

            update(0, 0, n-1, pos, ch);

            res[i] = segmentTree[0].maxLen;
        }

        return res;
    }
};