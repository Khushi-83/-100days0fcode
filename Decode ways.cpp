class Solution {
public:
    int numDecodings(string s) {
        int n = s.size();
        vector<int> dp(n+1, 0);
        dp[1]=1;
        dp[0] = 1;
        if(s[0]=='0' || (s[n-1]=='0' && s[n-2]-'0'>2))return 0;
        for (int i = 2; i < n+1; i++) {
            if(s[i-1]=='0' && (s[i-2]=='1' || s[i-2]=='2')){
                dp[i]=dp[i-2];
            }
            else if(s[i-1]=='0' &&(s[i-2]!='2'||s[i-3]!='1')){
                return 0;
            }
            else if ((s[i - 2]-'0') * 10 + (s[i - 1]-'0')>26 || s[i-1]=='0'|| s[i-2]=='0') {
                dp[i] = dp[i - 1];
            }else {
                dp[i] = dp[i - 1] + dp[i-2];
                // prev=dp[i-1];

            }
        }
        return dp[n];
    }
};
