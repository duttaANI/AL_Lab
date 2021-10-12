class Solution {
public:
    int n ;
    vector<vector<int> > res;
    void recursion(vector<int> num, int i ) {
        if (i == n-1) {
            res.push_back(num);
            return;
        }
        for (int k = i; k < n; k++) {
            if (i != k && num[i] == num[k]) continue;
            swap(num[i], num[k]);
            recursion(num, i+1);
        }
    }
    vector<vector<int> > permuteUnique(vector<int> &num) {
        sort(num.begin(), num.end());
    
        n= num.size();
        recursion(num, 0);
        return res;
    }
};