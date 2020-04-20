// link : https://www.youtube.com/watch?v=LPFhl65R7ww
// Do bin search on the sorted arr having smaller length i.e X
#include <iostream>
#include <bits/stdc++.h> 
#include <cstdlib>
#include <queue>
using namespace std; 

class Solution {
public:

	int BinSearch(vector<int>& X, vector<int>& Y, int* start, int* end, int* partitionX, int* partitionY, int* found, int tot_len)
	{
		int int_MAX = 2147483647;
		int int_MIN = -2147483648;

		int maxLeftX = ((*partitionX)==0 )? int_MIN : X[*partitionX-1];
		int minRightX = ((*partitionX)== X.size() )? int_MAX : X[*partitionX];

		int maxLeftY = ((*partitionY)==0 )? int_MIN : Y[*partitionY-1];
		int minRightY = ((*partitionY)== Y.size() )? int_MAX : Y[*partitionY];

		if      ( (maxLeftX<=minRightY) && (maxLeftY<=minRightX) )
		{
			*found = 1;
            //cout << "if " << *start << " "<<*end<<" "<<*partitionX<<" "<<*partitionY<<"\n";
            //cout << maxLeftX<<" "<<minRightX<<" "<<maxLeftY<<" "<<minRightY<<"\n";

			return 0;
		}
		else if ( (maxLeftX>minRightY) )  // move towards left in X
		{
			*end = *partitionX - 1;
			*partitionX = ((*start)+(*end))/2;
			*partitionY = (tot_len+1)/2 - *partitionX;
            //cout << "e " << *start << " "<<*partitionX<<" "<<*partitionY<<"\n";
            //cout << maxLeftX<<" "<<minRightX<<" "<<maxLeftY<<" "<<minRightY<<"\n";

			return 1;
		}
		else // move towards right in X i.e (Y[partitionY-1]>X[partitionX])
		{
			*start = *partitionX + 1;
           
			*partitionX = (*start+*end)/2;
			*partitionY = (tot_len+1)/2 - *partitionX;
            //cout << " " << *end << " "<<*partitionX<<" "<<*partitionY<<"\n";
            //cout << maxLeftX<<" "<<minRightX<<" "<<maxLeftY<<" "<<minRightY<<"\n";
			return 2;
		}

	}

    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
    	int int_MAX = 2147483647;
		int int_MIN = -2147483648;
		int maxLeftX , maxLeftY , minRightY , minRightX;
        
        if(nums1.size()>nums2.size())
        {
        	return findMedianSortedArrays(nums2, nums1);
        }

        int len1 = nums1.size();    int len2 = nums2.size();    int tot_len = len1+len2;
        

        int start = 0;              int end = nums1.size();     int partitionX = (start+end)/2;   int partitionY = (tot_len+1)/2 - partitionX;
        int found = 0;    
        int val;

        while(found!=1 && start<=end)
    	{   
    		val = BinSearch(nums1, nums2, &start, &end, &partitionX, &partitionY, &found, tot_len);
            
            //cout << val;
    	}
        
        maxLeftX = ((partitionX)==0 )? int_MIN : nums1[partitionX-1];
			minRightX = ((partitionX)== nums1.size() )? int_MAX : nums1[partitionX];

			maxLeftY = ((partitionY)==0 )? int_MIN : nums2[partitionY-1];
			minRightY = ((partitionY)== nums2.size() )? int_MAX : nums2[partitionY];

        if( tot_len%2 == 0 ) 
        {
        	return (double)(max(maxLeftX,maxLeftY)+min(minRightX,minRightY))/2.0;
        }
        else
        {
        	return (double)max(maxLeftX,maxLeftY);
        }
        
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
        vector<int> nums1 = stringToIntegerVector(line);
        getline(cin, line);
        vector<int> nums2 = stringToIntegerVector(line);
        
        double ret = Solution().findMedianSortedArrays(nums1, nums2);

        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}

/*
SAMPLE I/o
aniruddha@aniruddha-G3-3579:~/MIT/competitions/leetcode$ ./a.out
[1,3,6,7,90]    
[2,4,5]
4.500000*/


