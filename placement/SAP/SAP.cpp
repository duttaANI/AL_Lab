#include <bits/stdc++.h>

using namespace std;

vector<int> maxSlidingWindow(vector<int>& nums, int k) {
    int n = nums.size();
    vector<int> windowMax;
    deque<int> dq;
    for (int i = 0; i < n; i++) {
        while (!dq.empty() && dq.front() < i - k + 1) // If an element in the deque and it is out of i-(k-1), we discard them. We just need to poll from the head, as we are using a deque and elements are ordered as the sequence in the array
            dq.pop_front();
        while (!dq.empty() && nums[dq.front()] > 0 ) // Now only those elements within [i-(k-1),i] are in the deque. We then discard elements smaller than a[i] from the tail. This is because if a[x] <a[i] and x<i, then a[x] has no chance to be the "max" in [i-(k-1),i], or any other subsequent window: a[i] would always be a better candidate.
            dq.pop_back();  
        dq.push_back(i);
        if (i >= k - 1) windowMax.push_back(nums[dq.front()]);
    }
    return windowMax;
}

int main(){
    vector< int> a = { -11,2,9,-2,-9,18,8 };
    vector<int> ans;
    ans = maxSlidingWindow(a,3);

    for( int i=0;i<ans.size();++i ){
        cout << ans[i] << " ";
    }

    return 0;
}