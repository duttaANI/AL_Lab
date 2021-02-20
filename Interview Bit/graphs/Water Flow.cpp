#define ar array

int red[1001][1001], blue[1001][1001];
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};

bool check(int x, int y, int n, int m){
    if(x >= 0 && x < n && y >= 0 && y < m){
        return true;
    }
    return false;
}

int Solution::solve(vector<vector<int> > &A) {
    int n = A.size(), m = A[0].size();
    int ans = 0;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            blue[i][j] = 0;
            red[i][j] = 0;
        }
    }
    queue<ar<int,2>> q;
    // All the co-ordinates which touches blue lake on left edge
    for(int i = 1; i < n; i++){
        q.push({i,0});
        blue[i][0] = 1;
    }
    // All the co-ordinates which touches blue lake on top edge
    for(int i = 0; i < m; i++){
        q.push({0,i});
        blue[0][i] = 1;
    }
    


    while(!q.empty()){
        ar<int,2> idx = q.front();
        q.pop();
        for(int i = 0; i < 4; i++){
            int x = idx[0] + dx[i], y = idx[1] + dy[i];
            if(check(x, y, n, m) && blue[x][y] == 0 && A[x][y] >= A[idx[0]][idx[1]]){
                  q.push({x,y});
                  blue[x][y] = 1;
            }
        }
    }
    // All the co-ordinates which touches red lake on right edge
    for(int i = 0; i < n; i++){
        q.push({i,m-1});
        red[i][m-1] = 1;
    }
    // All the co-ordinates which touches red lake on bottom edge
    for(int i = m-2; i >= 0; i--){
        q.push({n-1,i});
        red[n-1][i] = 1;
    }

    while(!q.empty()){
        ar<int,2> idx = q.front();
        if(red[idx[0]][idx[1]] == 1 && blue[idx[0]][idx[1]] == 1){
            ans += 1;
        }
        q.pop();
        for(int i = 0; i < 4; i++){
            int x = idx[0] + dx[i], y = idx[1] + dy[i];
            if(check(x, y, n, m) && red[x][y] == 0 && A[x][y] >= A[idx[0]][idx[1]]){
                  q.push({x,y});
                  red[x][y] = 1;
            }
        }
    }
    return ans;
}

