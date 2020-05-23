// lexical order
#include <iostream>
#include <bits/stdc++.h> 
#include <cstdlib>
#include <queue>
#include <string>
using namespace std;

class Solution {
public:
    
    int fact(int n)
    {
        int f=1;
        for (int i = 1; i <= n; ++i)
        {
            f=f*i;
        }
        return f;
    }
    
    void reverse(vector<int>& nums,int largestI,int n)
    {
        int temp1;
        int i,j;
        for ( j=0, i = largestI + 1; i < n - j -1 ; ++i,++j)
        {

            temp1 = nums[n  - j -1 ];
            nums[n - j - 1] = nums[i];
            nums[i] = temp1;
        }
    }
    
    void swap(vector<int>& nums, int pos1, int pos2)
    {
        int temp;
        temp = nums[pos1];
        nums[pos1] = nums[pos2];
        nums[pos2] = temp;
    }
    
    int drawI(int n, vector<int>& nums)
    {
        int largestI = -1;
        for (int i = 0; i < n - 1 ; ++i)
        {
            if(nums[i]<nums[i+1])
            {
                largestI = i;
            }
        }

        return largestI;
    }

    void drawJ(int n ,vector<int>& nums,vector<vector<int>>& ans)
    {

        ans.push_back(nums);


        int largestJ = -1;
        int largestI = drawI(n,nums);

        if(largestI == -1)
            return ;

        for (int j = 0; j < n; ++j)
        {
            if( nums[largestI] < nums[j])
            {
                largestJ = j;
            }
        }

        swap(nums,largestI,largestJ);

        //reverse from largestI + 1 to end

        reverse(nums,largestI,n);

    }
    
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        int n = nums.size();
        sort(nums.begin(), nums.end());
        for (int i = 0; i < fact(n); ++i)
        {
            drawJ(n,nums,ans);
        }
        return ans;
    }
};
