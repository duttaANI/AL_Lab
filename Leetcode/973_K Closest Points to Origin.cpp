#define ar array
class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int K) {
        vector< vector<int> > ans;
        vector<ar<int,3> > a;
        for(auto i : points){
            a.push_back({ (i[0])*(i[0]) + (i[1])*(i[1])  ,i[0],i[1]});
        }
        sort(a.begin(),a.end());
        
        for(int i=0; i<K; ++i){
            ans.push_back({a[i][1],a[i][2]});
        }
        return ans;
    }
};