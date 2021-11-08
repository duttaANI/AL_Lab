int CntcontSubs(int a[],int n)
{
    int prod = 1;
 
    // Creating vectors to store
    // the remainders and the
    // subsequences
    vector<pair<int,int> > vect;
 
    vect.push_back(make_pair(0, 2));
 
    vector<int> two, zero;
 
    // Iterating through the array
    for (int i = 0; i < n; i++) {
 
        // Finding the remainder when the
        // element is divided by 4
        a[i] = a[i] % 4;
 
        // Bringing all the elements in
        // the range [0, 3]
        if (a[i] < 0)
            a[i] = a[i] + 4;
 
        // If the remainder is 2, store
        // the index of the
        if (a[i] == 2)
            two.push_back(i + 1);
 
        // If the remainder is 2, store
        // the index of the
        if (a[i] == 0)
            zero.push_back(i + 1);
 
        if (a[i] == 0 || a[i] == 2)
            vect.push_back(make_pair(i + 1, a[i]));
    }
    vect.push_back(make_pair(n + 1, 2));
 
    // Finding the total number of subsequences
    int total = (n * (n + 1)) / 2;
 
    // If there are no numbers which
    // yield the remainder 2
    if (two.empty())
        return total;
    else {
        int sum = 0;
 
        int pos1 = -1, pos2 = -1, pos3 = -1;
 
        int sz = vect.size();
 
        // Iterating through the vector
        for (int i = 1; i + 1 < sz; i++) {
 
            // If the element is 2, find the nearest
            // 2 or 0 and find the number of
            // elements between them
            if (vect[i].second == 2) {
                sum += (vect[i].first
                        - vect[i - 1].first)
                           * (vect[i + 1].first
                              - vect[i].first)
                       - 1;
            }
        }
 
        // Returning the count
        return total - sum - two.size();
    }
}