class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        sort(points.begin(), points.end());
        int shots = 0, n = points.size();
        int i = n - 1;
        while (i >= 0) {
           shots++;
           int shot = points[i][0];
           while (i >= 1 && points[i - 1][1] >= shot) i--;
           i--;
        }
        return shots;
    }
};