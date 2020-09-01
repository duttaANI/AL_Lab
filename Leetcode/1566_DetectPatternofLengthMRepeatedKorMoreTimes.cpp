class Solution {
public:
    bool containsPattern(vector<int>& arr, int m, int k) {
    int cnt =0;
        int n = arr.size();
        for(int i=0; i< n-m ;++i){
            if(arr[i]!=arr[i+m])
                cnt = 0;
            cnt += (arr[i]==arr[i+m]);
            // cout << cnt << " ";
            if(cnt == (k-1)*m)
                return true;
        }
        return false;
    }
};

// Below solution is for non consecutive hence doesnt work
class Solution {
public:
    bool containsPattern(vector<int>& arr, int m, int k) {
        // patterns possible i < arr.size() - m*k
        int n = arr.size();
        vector<int> pat ;
       
        if(0 > n - m*k) return false;
        for(int i = 0; i <= n - m*k ; ++i){
            // get pattern
            int l = 0;
            for(int j = i; l < m; ++j,++l){
            	pat.push_back(arr[j]);
            }

            // for(int j = 0; j < m; ++j){
            // 	cout << pat[j] << " ";
            // }
            // cout << "\n";
            // count pattern
            int flag = 1,cnt = 0;
            for(int j = i ; j<n  ; ){
            	flag = 1;
            	for (int x = 0; x < m  ; ++x,++j){
                    // cout << j << " ";
            		if(pat[x]!=arr[j]){
                        flag = 0;
                        ++j;
                        break ;
                    }	
            	}
            	if(flag) ++cnt;
                // cout << "j\n";
            }
            if(cnt >= k) return true;
            pat.clear();
        }
        return false;
    }
};