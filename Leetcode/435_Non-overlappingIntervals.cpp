class Solution {
public:
    
    static bool cmp( vector<int> &a, vector<int> &b ){
        return a[0]<b[0];
    }
    
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end(),cmp);
        
        int ans  = 0, pre=0;
        int n = intervals.size();
        for( int i=1;i<n;++i ){
            if( intervals[pre][1] > intervals[i][0] ){
                ++ ans;
                if(  intervals[pre][1] > intervals[i][1]   ){
                    pre = i;
                }
            }
            else{
                pre = i;
            }
        }
        
        return ans;
    }
};