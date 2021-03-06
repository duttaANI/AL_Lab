// https://leetcode.com/problems/maximal-rectangle/discuss/122456/Easiest-solution-build-on-top-of-leetcode84
class Solution {
public:
    
    
    int leetcode84(const vector<int> &heights)
    {
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
        int n = heights.size();
        if (!n)
            return 0;
        int ans = 0;
        bool sorted = is_sorted(heights.begin(), heights.end());
        if (sorted)
        {
            int area = 0;
            for (int i = 0; i < n; i++)
            {
                area = max(area, heights[i] * (n - i));
            }
            return area;
        }
        for (int i = 0; i < n; i++)
        {
            int left = i - 1, right = i + 1;
            bool gl = true, gr = true;
            while (left >= 0 || right <= n - 1)
            {
                if (gl && left >= 0 && heights[left] >= heights[i])
                    left--;
                else
                    gl = false;
                if (gr && right < n && heights[right] >= heights[i])
                    right++;
                else
                    gr = false;
                if (!(gl || gr))
                    break;
            }
            ans = max(ans, abs(right - left - 1) * heights[i]);
        }
        return ans;
    }
    
    
    int maximalRectangle(vector<vector<char>>& mat) {
        int n = mat.size();
        if(n==0) return 0;
        int m = mat[0].size();
        int ans=0;
        vector<int> height(m,0);
        for(int i=0;i<n;++i){
            for(int j=0;j<m;++j){
                if( mat[i][j]=='0' ){
                    height[j]=0;
                }
                else{
                    height[j]++;
                }
                // cout << height[i] << " ";
            }
            // cout << endl;
            int ar = leetcode84(height);
            // cout << ar << endl;
            ans = max(ans,ar);
        }
        return ans;
    }
};