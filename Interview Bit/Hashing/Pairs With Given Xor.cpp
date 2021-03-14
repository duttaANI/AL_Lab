int Solution::solve(vector<int> &A, int B) {
    int result=0;
      vector<bool> hash(1000001,false);
      for(int i=0;i<A.size();i++){
          if(hash[B^A[i]]) result++;
           hash[A[i]]=true;
      }
      return result;
}
