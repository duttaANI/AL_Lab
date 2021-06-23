#include<bits/stdc++.h>
int min(int x, int y) {
    return x<y?x:y;
}

bool isCommonPrefix(vector<string>& strs, int len) {
    string str1 = strs[0].substr(0, len );
    for(int i=1; i<strs.size(); ++i) {
        if(strs[i].find(str1)!=0) 
            return false;
    }
    return true;
}


string Solution::longestCommonPrefix(vector<string> &strs) {
    if (strs.size() == 0)
        return "";
    int minLen = 2147483647;
    for (int i=0; i<strs.size(); ++i) {
        minLen = min(minLen, strs[i].length());
    }
    int low = 1;
    int high = minLen;
    while (low <= high) {
        int middle = (low + high) / 2;
        if (isCommonPrefix(strs, middle))
            low = middle + 1;
        else
            high = middle - 1;
    }
    return strs[0].substr(0, (low + high) / 2);
}
