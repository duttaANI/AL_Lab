// link : https://leetcode.com/problems/number-of-ways-where-square-of-number-is-equal-to-product-of-two-numbers/discuss/831467/C%2B%2BJava-Two-Sum-O(n-*-m)
class Solution {
public:
    
    int getTriplet( long i, vector<int>& n ){
        unordered_map <int,int> m;
        int cnt = 0;
        for( auto v : n ){
            if( i % v == 0 ){
                cnt += m[i/v];
            }
            ++m[v];
        }
        return cnt;
    }
    
    int totalCnt( vector<int>& a, vector<int>& b ){
        sort(a.begin(),a.end());
        int cnt = 0;
        int mul = 1;
        for( int i=0; i< a.size(); ++i ){
            if( i+1 < a.size() && a[i]==a[i+1]){
                ++mul;
            
                continue;
            }
            cnt += mul*getTriplet((long)a[i]*a[i],b);
            mul =1;
        }
        return cnt;
    }
    
    int numTriplets(vector<int>& nums1, vector<int>& nums2) {
        return totalCnt(nums1,nums2) + totalCnt(nums2,nums1);
    }
};