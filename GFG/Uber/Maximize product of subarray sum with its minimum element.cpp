// C++ program to implement 
// the above approach 
#include<bits/stdc++.h>
using namespace std;

// Function to find the
// maximum product possible
// void maxValue(int a[], int n)
// {
	
// 	// Stores prefix sum
// 	int presum[n];

// 	presum[0] = a[0];

// 	// Find the prefix sum array
// 	for(int i = 1; i < n; i++)
// 	{
// 		presum[i] = presum[i - 1] + a[i];
// 	}

// 	// l[] and r[] stores index of
// 	// nearest smaller elements on
// 	// left and right respectively
// 	int l[n], r[n];

// 	stack<int> st;

// 	// Find all left index
// 	for(int i = 1; i < n; i++) 
// 	{
		
// 		// Until stack is non-empty
// 		// & top element is greater
// 		// than the current element
// 		while (!st.empty() && 
// 			a[st.top()] >= a[i])
// 			st.pop();

// 		// If stack is empty
// 		if (!st.empty())
// 			l[i] = st.top() + 1;
// 		else
// 			l[i] = 0;

// 		// Push the current index i
// 		st.push(i);
// 	}

// 	// Reset stack
// 	while(!st.empty())
// 	st.pop();

// 	// Find all right index
// 	for(int i = n - 1; i >= 0; i--) 
// 	{
		
// 		// Until stack is non-empty
// 		// & top element is greater
// 		// than the current element
// 		while (!st.empty() && 
// 			a[st.top()] >= a[i])
// 			st.pop();

// 			if (!st.empty())
// 				r[i] = st.top() - 1;
// 			else
// 				r[i] = n - 1;

// 		// Push the current index i
// 		st.push(i);
// 	}

// 	// Stores the maximum product
// 	int maxProduct = 0;

// 	int tempProduct;

// 	// Iterate over the range [0, n)
// 	for(int i = 0; i < n; i++) 
// 	{
		
// 		// Calculate the product
// 		tempProduct = a[i] * (presum[r[i]] - 
// 					(l[i] == 0 ? 0 : 
// 					presum[l[i] - 1]));

// 		// Update the maximum product
// 		maxProduct = max(maxProduct,
// 						tempProduct);
// 	}

// 	// Return the maximum product
// 	cout << maxProduct;
// }

// long long greatestValueDays(vector<int> r) {
//     int n = r.size();
//     vector<long long> presum(n);
//     presum[0] = r[0];
    
//     for(int i = 1; i < n ; i++){
//         presum[i] = presum[i-1] + r[i];
//     }
    
//     vector< int> left(n), right(n);
//     stack<int> st;
    
//     for(int i = 1; i < n; i++){
//         while(!st.empty() && r[st.top()] >= r[i]) st.pop();
//         if(!st.empty()) left[i] = st.top() + 1;
//         else left[i] = 0;
//         st.push(i);
//     }
    
//      while(!st.empty()) st.pop();
     
//      for(int i = n-1; i >= 0; i--){
//          while(!st.empty() && r[st.top()] >= r[i] ) st.pop();
//          if(!st.empty()) right[i] = st.top() -1;
//          else right[i] = n-1;
//          st.push(i);
//      }
     
//      long long maxProd = 0, tempProd = 0;
//      for(int i = 0; i < n; i++){
//          tempProd = r[i] * (presum[right[i]] - (left[i] == 0 ? 0 : presum[left[i]-1]));
//          maxProd = max(maxProd, tempProd);
//      }
//      return maxProd;
// }

long long greatestValueDays(vector<int> r) {
    int n = r.size();
    vector<long long int> presum(n), left(n), right(n);
    presum[0] = r[0];
    
    for(int i = 1; i < n ; i++){
        presum[i] = presum[i-1] + r[i];
    }
    
    stack<int> st;
    
    for(int i = 1; i < n; i++){
        while(!st.empty() && r[st.top()] >= r[i]) st.pop();
        if(!st.empty()) left[i] = st.top() + 1;
        else left[i] = 0;
        st.push(i);
    }
    
     while(!st.empty()) st.pop();
     
     for(int i = n-1; i >= 0; i--){
         while(!st.empty() && r[st.top()] >= r[i] ) st.pop();
         if(!st.empty()) right[i] = st.top() -1;
         else right[i] = n-1;
         st.push(i);
     }
     for(int i = 0; i < n; i++) cout << presum[i] << " ";
     
     long long maxProd = 0, tempProd = 0 ;
     for(int i = 0; i < n; i++){
         tempProd = r[i] * (presum[right[i]] - ((left[i] == 0) ? 0 : presum[left[i]-1]));
         // cout << tempProd << endl;
         maxProd = max(maxProd, tempProd);
     }
     return maxProd;
}

// Driver Code
int main()
{
	
	// Given array
	// int n = 6;
	// int arr[] = { 3, 1, 6, 4, 5, 2 };
	vector<int> arr = {3, 1, 6, 4, 5, 2, 8,8,8,5,6,7};
	int n = arr.size();
	// Function call
	cout << "ans " << greatestValueDays(arr);
}

// This code is contributed by grand_master
