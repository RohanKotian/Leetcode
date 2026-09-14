class Solution {
public:
    bool isRectangleOverlap(vector<int>& rec1, vector<int>& rec2) {
        int a = rec1[0], b = rec1[1], c = rec1[2], d = rec1[3];
        int l = rec2[0], m = rec2[1], n = rec2[2], o = rec2[3];        

        if(a >= n || c <= l || b >= o || d <= m) return false;

        return true;
    }
};