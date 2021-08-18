bool isPossible(vector<string>& v, int cx, int cy) {

    int n = v.size();
    
    for(int i = 0; i < n; i++) {
        if(v[cx][i] == 'Q') return false;
    }   
    for(int i = 0; i < n; i++) {
        if(v[i][cy] == 'Q') return false;
    }
    int i = cx, j = cy;
    
    while(i >= 0 && j >= 0) {
        if(v[i][j] == 'Q') return false;
        i--, j--;
    }
    
    i = cx, j = cy;
    while(i >= 0 && j < n) {
        if(v[i][j] == 'Q') return false;
        i--, j++;
    }
    
    return true;
}

void solve(int n, int currRow, vector<vector<string>>& ans, vector<string>& v) {

    if(currRow == n) {
        ans.push_back(v);
        return;
    }
    
    for(int i = 0; i < n; i++) {
        if(isPossible(v, currRow, i) == true) {
            v[currRow][i] = 'Q';
            solve(n, currRow + 1, ans, v);
            v[currRow][i] = '.';
        }
    }
}

vector<vector <string> > Solution::solveNQueens(int A) {
    int n = A;    
    vector<string> v;    
    for(int i = 0; i < n; i++) {
        string temp = "";
        for(int j = 0; j < n; j++) {
            temp += ".";
        }
        v.push_back(temp);
    } 
    
    vector<vector<string>> ans;
    solve(n, 0, ans, v);
    return ans;
}