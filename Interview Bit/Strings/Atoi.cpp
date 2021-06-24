int Solution::atoi(const string str) {
    int sign = 1, base = 0, i = 0;
    while (str[i] == ' ') { i++; }
    if (str[i] == '-' || str[i] == '+') {
        sign = (str[i++] == '-') ? -1 : 1; 
    }
    while (str[i] >= '0' && str[i] <= '9') {
        if (base >  INT_MAX / 10 || (base == INT_MAX / 10 && str[i] - '0' > 7)) {
            if (sign == 1) return INT_MAX;
            else return INT_MIN;
        }
        base  = 10 * base + (str[i++] - '0');
    }
    return base * sign;
}

// My solution doesnt work
// int Solution::atoi(const string A) {
//     int n = A.size();
//     int res = 0;
//     int flg = 0;
//     int is_neg = 0;
//     int followed_by_space = 0; // 1 for neg , 2 for pos
//     // for loop to check if + or - is followed by space
//     for(int i=0;i+1<n;++i){
//         if( A[i]=='+' && A[i+1]==' '){
//             followed_by_space = 2;
//             break;
//         }
//         if( A[i]=='-' && A[i+1]==' '){
//             followed_by_space = 1;
//             break;
//         }
//     }

//     if( followed_by_space>0) return 0;

//     for (int i = 0; A[i] != '\0'; ++i){
//         if( ('0'<=A[i] && A[i]<='9') && flg!=2 ){
//             flg = 1; // start
//             if( i>0 && A[i-1]=='-'){
//                 is_neg = 1;
//             }
//             res = res * 10 + A[i] - '0';
//             // cout << res << endl;
//         }
//         else if(flg==1){
//             flg = 2; // if started then end
//         }
        
//     }
        
//     if(is_neg) return -1*res;
//     return res;
// }
