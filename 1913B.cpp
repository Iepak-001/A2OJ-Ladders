#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin>>t;
    while(t--){
        string s;
        cin>>s;

        int sz=s.size();

        unordered_map<char,int>mp;
        mp['0']=0;
        mp['1']=0;
        for(int i=0;i<sz;i++){
            mp[s[i]]++;
        }

        int ans=0;

        for(int i=0;i<sz;i++){
            if(s[i]=='0'){
                if(mp['1']==0){
                    ans=sz-i;
                    break;
                }
                mp['1']--;
            }
            else{
                if(mp['0']==0){
                    ans=sz-i;
                    break;
                }
                mp['0']--;
            }
        }
        cout<<ans<<endl;

    }
    return 0;
}