//Two Pointer Approach
class Solution {
public:
    int maxArea(vector<int>& height) {
        int l=0,r=height.size()-1,ans=0,ar=0;
        while(l<r){
            ar = min(height[l],height[r])*(r-l);
            ans = max({ans,ar});
            if( height[l]<height[r] ){
                ++l;
            }
            else{
                --r;
            }
        }
        return ans;
    }
};


// link: https://leetcode.com/problems/container-with-most-water/solution/
#include <iostream>
#include <bits/stdc++.h> 
#include <cstdlib>
#include <queue>
using namespace std; 


class Solution {
public:
    int maxArea(vector<int>& height) {
        int i =0;       int  j=height.size()-1;  
        int maxA = 0,curArea,minH,shift_i,shift_j;

        while(j>i)
        {
            minH = (height[i]<height[j])?height[i]:height[j];
            curArea = (j-i)*minH;
            if(curArea>maxA)
                maxA = curArea;
            
            shift_i = (height[i]>=height[i+1])?false:true;
            shift_j = (height[j]>=height[j-1])?false:true;

            if( height[i]<height[j] )
            	++i;
            else if(height[j]<height[i])
            	--j;
            else
            {
            	if(shift_i)
            		++i;
            	else if(shift_j)
            		--j;
            	else
            		++i;
            }
          	
        }

        return maxA;
    }
};

void trimLeftTrailingSpaces(string &input) {
    input.erase(input.begin(), find_if(input.begin(), input.end(), [](int ch) {
        return !isspace(ch);
    }));
}

void trimRightTrailingSpaces(string &input) {
    input.erase(find_if(input.rbegin(), input.rend(), [](int ch) {
        return !isspace(ch);
    }).base(), input.end());
}

vector<int> stringToIntegerVector(string input) {
    vector<int> output;
    trimLeftTrailingSpaces(input);
    trimRightTrailingSpaces(input);
    input = input.substr(1, input.length() - 2);
    stringstream ss;
    ss.str(input);
    string item;
    char delim = ',';
    while (getline(ss, item, delim)) {
        output.push_back(stoi(item));
    }
    return output;
}

int main() {
    string line;
    while (getline(cin, line)) {
        vector<int> height = stringToIntegerVector(line);
        
        int ret = Solution().maxArea(height);

        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}
