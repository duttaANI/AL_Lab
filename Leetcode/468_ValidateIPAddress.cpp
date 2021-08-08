class Solution {
    
    //Note: [0-9] can also be replaced with \\d
    bool check4(string& ip) {
        regex pattern("(([0-9]|[1-9][0-9]|1[0-9][0-9]|2[0-4][0-9]|25[0-5]).){4}");
        return regex_match(ip + '.', pattern);
    }
    
    bool check6(string& ip) {
        regex pattern("([0-9a-fA-F]{1,4}:){8}");
        return regex_match(ip + ':', pattern);
    }
    
    public:
    string validIPAddress(string IP) {
        if(check4(IP)) return "IPv4";
        if(check6(IP)) return "IPv6";
        return "Neither";
    }
};