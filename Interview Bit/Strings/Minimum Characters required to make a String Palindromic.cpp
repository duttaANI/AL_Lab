int isPalin(int mid, string& s)
{
    int low = mid - 1, high = mid + 1, result = -1, N = s.size();
    while(low > -1 && high < N && s[low] == s[high])
    {
        low = low - 1;
        high = high + 1;
    }
    if(low == -1)
        result = max(result, high);
    
    low = mid, high = mid+1;
    while(low > -1 && high < N && s[low] == s[high])
    {
        low = low - 1;
        high = high + 1;
    }
    
    if(low == -1)
        result = max(high, result);
        
    return result;
}
int Solution::solve(string A)
{
    int low = 0, high = A.size()-1, insertionsRequired = A.size() + 1, N = A.size();
    while(low <= high)
    {
        int mid = low + (high - low)/2,
        index = isPalin(mid, A);
        if(index == -1)
        {
            high = mid - 1;
        }
        else
        {
            insertionsRequired = min(insertionsRequired, N-index);
            low = mid + 1;
        }
    }
    
    return insertionsRequired;
}