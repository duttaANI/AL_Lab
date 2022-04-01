string Solution::minWindow(string s, string t) {
    if(s.length() < t.length())
            return "";
        unordered_map<char, int> hash;
        for(char c : t)
            hash[c]++;
        int right = 0, left = 0, count = hash.size();
        string res = "";
        while(right < s.length())
        {
            // add right to window
            if(hash.find(s[right]) != hash.end())
            {
                hash[s[right]]--;
                if(hash[s[right]] == 0)
                    count--;
            }
            while(count == 0)
            {
                if(res == "" || res.length() > right-left+1)
                {
                    res = s.substr(left, right-left+1);
                }
                if(hash.find(s[left]) != hash.end())
                {
                    hash[s[left]]++;
                    if(hash[s[left]] == 1)
                        count++;
                }
                left++;
            }
            right++;
        }
        return res;
}
