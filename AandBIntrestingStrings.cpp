#include <bits/stdc++.h>
using namespace std;
using ll=long long;
int main()
{
    vector<int>val(26);
    for(int i=0;i<26;i++) cin>>val[i];

    string s;
    cin>>s;
    int n=s.size();

    vector<ll>prefixSum(n+1);
    prefixSum[0]=0;
    for(int i=0;i<n;i++){
        prefixSum[i+1]=prefixSum[i]+val[s[i]-'a'];
    }

    vector<unordered_map<ll,ll>>freq(26);

    ll ans=0;

    for(int i=0;i<n;i++){
        int charIndex=s[i]-'a';

        ans+=freq[charIndex][prefixSum[i]];
        
        freq[charIndex][prefixSum[i+1]]++;
    }

    cout<<ans;

    return 0;
}