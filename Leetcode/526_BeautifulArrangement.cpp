/* levels of tree repsent "pos" and "i" represents branches */
class Solution {
public:
    int count = 0;
    
    void calculate (int N, int pos, vector<bool>& vis) {
        
        if (pos>N) {
            ++count;
            return ;
        }
        
        for (int i=1 ;i<=N ; ++i) {
            if( !vis[i] && (pos%i==0 || i%pos==0)  ) // if "i" is not present in beautiful arrangement and can fit in position "pos"
            {
                vis[i] = true;
                calculate(N, pos+1, vis);
                vis[i] = false;
            } 
           
        }
    }
    
    int countArrangement(int N) {
        vector <bool> vis (N+1,false);
        calculate (N , 1, vis);
        return count;
    }
};