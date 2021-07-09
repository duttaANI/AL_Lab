string Solution::addBinary(string A, string B) {
    if( A.size() < B.size() ){ // A is bigger
        return addBinary(B,A);
    }
    
    reverse(A.begin(),A.end());
    reverse(B.begin(),B.end());
    
    int carry = 0;
    int n = B.size()-1;
    int i=0;
    while( i<=n   ){
        
        int sum = ( int(A[i]-'0') + int(B[i]-'0') + carry ) ;
        if( sum==0 ){
            A[i] = '0';
            carry = 0;
        }
        else if ( sum==1 ){
            A[i] = '1';
            carry =0;
        }
        else if (sum==2){
            A[i] = '0';
            carry = 1;
        }
        else if ( sum==3 ){
            A[i] = '1';
            carry = 1;
        }
        ++i;
    }
    
    while( carry && i<A.size() ){
        int sum = ( int(A[i]-'0') + carry ) ;
        if( sum==0 ){
            A[i] = '0';
            carry = 0;
        }
        else if ( sum==1 ){
            A[i] = '1';
            carry =0;
        }
        else if (sum==2){
            A[i] = '0';
            carry = 1;
        }
        else if ( sum==3 ){
            A[i] = '1';
            carry = 1;
        }
        ++i;
    }
    
    if(carry){
        A.push_back('1');
    }
    
    reverse(A.begin(),A.end());
    
    return A;
}