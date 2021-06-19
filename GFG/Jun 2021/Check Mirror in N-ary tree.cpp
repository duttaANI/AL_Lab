class Solution {
  public:
    int checkMirrorTree(int n, int e, int A[], int B[]) {
        vector<stack<int>> s(n + 1);
        vector<queue<int>> q(n + 1);
        for(int i = 0; i < 2 * e; i+=2)
        {
            s[A[i]].push(A[i + 1]);
            q[B[i]].push(B[i + 1]);
        }
        // now take out the vectors and queues
        // for each of the nodes and compare them
        // one by one
        for(int i = 1; i <= n; i++)
        {
            while(!s[i].empty() && !q[i].empty())
            {
                int a = s[i].top();
                int b = q[i].front();
                if(a != b)
                return false;
                s[i].pop();
                q[i].pop();
            }
        }
        return true;
    }
};