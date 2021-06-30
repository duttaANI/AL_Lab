int Solution::repeatedNumber(const vector<int> &A) {
    int n=A.size();
    if(n==1) 
        return -1;
    //The basic approach used is of finding cycle in an array
    int slow=A[0];
    int fast=A[0];
    //We have taken 2 variables slow will move 1 step ahead and access element at slow position
    //while fast will move 2 steps ahead and access element at A[fast] position
    int count=0;
    //Count is used to prevent the infinite loop
    do{
        slow=A[slow];
        fast=A[A[fast]];
        count++;
    }while(slow!=fast && count<n);
    //If I have traversed n times then I know there is no duplicate
    if(count==n) 
        return -1;
    //Else I will find the number by finding the starting point of the cycle
    fast=A[0];
    while(slow!=fast){
        slow=A[slow];
        fast=A[fast];
    }
    return slow;
    
    // my O(n) space
    // int n = A.size();
    // vector<int> freq(n,0);
    // for(int i=0;i<n;++i){
    //     freq[A[i]]++;
    //     if(freq[A[i]]>1){
    //         return A[i];
    //     }
    // }
    // return -1;
}
