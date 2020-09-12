#include<bits/stdc++.h> 
#include <vector>
using namespace std;

// i --> index of current element
// prev --> index of previous element included in sum
vector<int> maxSumSubseq(vector<int> & A, int i, int n, int prev, vector<int>  ans){
	// base case: all elements are processed
	if (i == n) {
		return ans;
	}

	// recur by excluding current element
	vector<int> ans1 = maxSumSubseq(A, i + 1, n, prev, ans );

	// include current element only if it is not adjacent
	// to previous element considered
	vector<int> ans2;
	if (prev + 1 != i) {
		ans.push_back(A[i]);
		ans2 = maxSumSubseq(A, i + 1, n, i, ans );
	}

	// return the list with maximum sum

	long incl = accumulate(ans1.begin(),ans1.end(),0);
	long excl = accumulate(ans2.begin(),ans2.end(),0);

	if(incl > excl){
		return ans1;
	}
	return ans2;
}

int main(){
	vector<int> A = { 1, 2, 9, 4, 5, 0, 4, 11, 6 };
	vector<int> ans ;
	ans = maxSumSubseq(A, 0, A.size(), INT_MIN, ans);

	for (int i = 0; i < ans.size(); ++i)
	{
		cout << ans[i] << " ";
	}
}
