// Refer Aryan Mittal's video
class Solution {
public:
    typedef long long ll;
    ll CountLessThanEqualToX(vector<int>& coins, ll mid){
        int m = coins.size();
        int allOnes = (1<<m) - 1;   //m No. of bits, all 1s

        ll count = 0;   //count of values <= mid;

        // Generate all the subsets (eg. ab, ac, bc, abc, etc.)
        for(int mask=1; mask<=allOnes; mask++){
            ll setBitsLCM = 1;
            for(int j=0; j<m; j++){
                if(mask & (1<<j)){  //Select coin according to current mask
                    setBitsLCM = lcm(setBitsLCM, coins[j]); //LCM to find common multiples
                }
            }

            // Take odd(eg. A, B, C, AUBUC, AUBUCUDUE)
            if(__builtin_popcount(mask) & 1){   //Odd elements selected
                count += mid / setBitsLCM;
            }
            // Leave even(eg. AUB, BUC, AUC, AUBUCUD)
            else{                               //Even elements selected
                count -= mid / setBitsLCM;
            }
        }
        return count;
    }
    ll findKthSmallest(vector<int>& coins, int k) {
        ll l = 1;
        ll r = 25 * 2 * 1e9 + 25;  //Derived from AP of constraints,can use anything bigger

        ll ans = 0;

        while(l<=r){
            ll mid = l + (r-l)/2;
            ll cnt = CountLessThanEqualToX(coins, mid);
            if(cnt < k){
                l = mid + 1;
            }
            else{
                ans = mid;
                r = mid - 1;
            }
        }
        return ans;
    }
};