class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), [&](const auto& a, const auto& b){
            if(a[0]==b[0]){
                return a[1] > b[1];
            }
            return a[0] < b[0];
        });

        int maxEnd = -1;
        int count = 0;

        for(auto& interval:intervals){
            if(maxEnd < interval[1]){
                count++;
                maxEnd = interval[1];
            }
        }
        return count;
    }
};