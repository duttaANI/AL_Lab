// Using Expand function

class Solution {
public:
int largestRectangleArea(const vector<int> &heights)
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
};


// My simple solution (1340ms)
class Solution {
public:
    
    int maxAr(vector<int> heights, int H,int n){
        int area;
        
        int maxlen=0,curlen=0;
        for(int i=0; i<n; ++i){
            if( heights[i]>=H ){
                ++curlen;
            }else{
                if(curlen>maxlen){
                    maxlen = curlen;
                }
                curlen = 0;
            }
        }
        if(curlen>maxlen){
            maxlen = curlen;
        }
        area = maxlen*H;
        return area;
    }
    
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        set <int, greater <int> > copyHeights;
        for(int i=0; i<n; ++i)
            copyHeights.insert(heights[i]);
        
        int ans=0,cur;
        set <int, greater <int> > :: iterator itr; 
        for( itr = copyHeights.begin(); itr != copyHeights.end(); ++itr ){
            cur = maxAr(heights,*itr,n);
            if(cur>ans)
                ans = cur;
        }
        return ans;
    }
};