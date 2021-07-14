const int mod = 1e9 + 7;

int Solution::solve(int A) {
    int n = A+1;
    long long int ans = 0;
    
    
    for(int i = 1;i<31;i++){
        // Time period of the recurring pattern
        int T = (1 << i);
        // We calculate for each bit position, no. of times (d) one complete pattern have occured 
        // before the number by dividing it by T.
        int d = n / T;
        // remainder signifies an incomplete pattern for the particular bitPosition.
        int r = n % T;
     
        // first half of every pattern begins with continuous 0s (T/2 times) and then 1s (T/2)times 
        if(r<=T/2)  
            r=0;
        else 
            r = r-T/2;
        
        // ((d) complete patterns, each having (T/2) 1s)  +  (number of 1s in the incomplete pattern (if any))
        ans += d * (T/2) + r;
    }
    return ans%mod;
}