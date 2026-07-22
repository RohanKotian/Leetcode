void buildSegmentTree(int i, int l, int r, int* segmentTree, int arr[]){
    if(l==r){
        segmentTree[i] = arr[l];
        return;
    }
    
    int mid = l + (r-l)/2;
    buildSegmentTree(2*i+1, l, mid, segmentTree, arr);
    buildSegmentTree(2*i+2, mid+1, r, segmentTree, arr);
    segmentTree[i] = max(segmentTree[2*i+1], segmentTree[2*i+2]);
}

int* constructST(int arr[], int n){
    int* segmentTree = new int[4 * n];
    buildSegmentTree(0, 0, n-1, segmentTree, arr);
    return segmentTree;
}

int querySegmentTree(int start, int end, int i, int l, int r, int segmentTree[]){
    if(r < start || l > end){
        return INT_MIN;
    }
    if(start<=l && r<=end){
        return segmentTree[i];
    }

    int mid = l + (r-l)/2;
    return max(querySegmentTree(start, end, 2*i+1, l, mid, segmentTree),
               querySegmentTree(start, end, 2*i+2, mid+1, r, segmentTree));
}

int RMQ(int st[], int n, int a, int b){
    return querySegmentTree(a, b, 0, 0, n-1, st);
}

class Solution {
public:    
    vector<int> maxActiveSectionsAfterTrade(string s, vector<vector<int>>& queries) {
        int n = s.length();        

        int onesCount = 0;
        vector<int> blockStart;
        vector<int> blockEnd;

        int i = 0;
        while(i<n){
            if(s[i]=='0'){
                int start = i;
                while(i<n && s[i]=='0'){
                    i++;
                }
                blockStart.push_back(start);
                blockEnd.push_back(i-1);
            }
            else{
                onesCount++;
                i++;
            }
        }

        int m = blockStart.size();

        if(m<2){
            return vector<int>(queries.size(), onesCount);
        }

        vector<int> blockSize(m);
        for(int i=0; i<m; i++){
            blockSize[i] = blockEnd[i] - blockStart[i] + 1;
        }

        int N = m-1;
        vector<int> pairSum(N);
        for(int i=0; i<N; i++){
            pairSum[i] = blockSize[i] + blockSize[i+1];
        }

        // .data() to convert vector to array
        int* st = constructST(pairSum.data(), N);  

        vector<int> result;
        for(auto& q:queries){   //O(q * logn)
            int l = q[0];
            int r = q[1];

            // First and Last Blocks in the range
            int low  = lower_bound(blockEnd.begin(), blockEnd.end(), l) - blockEnd.begin();
            int high = upper_bound(blockStart.begin(), blockStart.end(), r) - blockStart.begin() - 1;

            int maxPairSum = 0;
            if(low < high){ // We need atleast 2 blocks
                int firstLen = blockEnd[low] - max(blockStart[low], l) + 1;
                int lastLen  = min(blockEnd[high], r) - blockStart[high] + 1;

                if(high - low == 1){    //Exactly 2 blocks
                    maxPairSum = firstLen + lastLen;
                }
                else{
                    int pair1 = firstLen + blockSize[low+1];
                    int pair2 = lastLen  + blockSize[high-1];
                    int RMQMaxPairSum = RMQ(st, N, low+1, high-2);
                    maxPairSum = max({pair1, pair2, RMQMaxPairSum});
                }
            }
            result.push_back(maxPairSum + onesCount);
        }
        return result;
    }
};