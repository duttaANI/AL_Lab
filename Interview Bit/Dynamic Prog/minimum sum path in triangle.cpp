int Solution::minimumTotal(vector<vector<int> > &triangle) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details

    
        int n = triangle.size();
        vector<int> dp_min = triangle[triangle.size()-1];
        for (int layer = n-2; layer >= 0; layer--){ // For each layer
            for (int i = 0; i <= layer; i++) // Check its every 'node'
            {
                // Find the lesser of its two children, and sum the current value in the triangle with it.
                dp_min[i] = min(dp_min[i], dp_min[i+1]) + triangle[layer][i]; 
            }
        }
        return dp_min[0];
}
