#include <bits/stdc++.h>
using namespace std;

int dp[25][25][25]; // i, j, current length
int maxLength = 0;

int f(string &s1, string &s2, int i, int j, int currLen) {
    if (i == s1.size() || j == s2.size()) return currLen;

    if (dp[i][j][currLen] != -1) return dp[i][j][currLen];

    int newLen = currLen;
    if (s1[i] == s2[j]) {
        newLen = f(s1, s2, i + 1, j + 1, currLen + 1);
        maxLength = max(maxLength, newLen);
    }

    // Reset currLen to 0 for next branches
    f(s1, s2, i + 1, j, 0);
    f(s1, s2, i, j + 1, 0);

    return dp[i][j][currLen] = newLen;
}
int main()
{
    int t;
    cin>>t;
    while(t--){
        string s1,s2;
        cin>>s1>>s2;
        memset(dp,-1,sizeof(dp));
        int lcsLength=f(s1,s2,0,0,0);

        cout<<s1.size()+s2.size()-(2*maxLength)<<endl;
    }
    return 0;
}