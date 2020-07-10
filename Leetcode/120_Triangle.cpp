// Bottom up Dp link : https://leetcode.com/problems/triangle/discuss/38730/DP-Solution-for-Triangle
class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        vector<int> dp_min = triangle[triangle.size()-1];
        for (int layer = n-2; layer >= 0; layer--){ // For each layer
            for (int i = 0; i <= layer; i++) // Check its every 'node'
            {
                // Find the lesser of its two children, and sum the current value in the triangle with it.
                dp_min[i] = min(dp_min[i], dp_min[i+1]) + triangle[layer][i]; 
            }
        }
        return dp_min[0];
    }
};


// My failed approach DFS idea
class Solution {
public:
    
    void dfs(vector<vector<int>>& triangle, int &minSum, int& curSum, int child, int & level){
        cout << level << "\n";
        if(level<triangle.size() && child<=triangle[level].size()-1 && child>=0){
            
            curSum+=triangle[level][child];
            cout << level << " " << curSum << "\n";
            ++level;
            int ch =child;
            dfs(triangle,minSum,curSum,child+1,level);
            dfs(triangle,minSum,curSum,child-1,level);
            curSum-=triangle[level][ch];
            --level;
        }else if(level ==triangle.size()){
            
            if(curSum<minSum){
                minSum = curSum;
            }
            cout<< minSum << "\n";
            return ;
        }else{
            return ;
        }
    }
    
    int minimumTotal(vector<vector<int>>& triangle) {
        int minSum = INT_MAX;
        int curSum=0;
        int level=0;
        int child=0;
        dfs(triangle,minSum,curSum,child,level);
        return minSum;
    }
};