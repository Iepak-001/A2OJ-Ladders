#include <bits/stdc++.h>
using namespace std;

//This is a Observation centric Question
// Same as that of one given in Online assesment

int main() {
    int t;
    cin>>t;
    while(t--){
        unordered_set<char>st;
        unordered_map<char,int>mp;
        int n;
        string s;
        cin>>n;
        cin>>s;
        
        int sz=s.size();
        for(int i=0;i<sz;i++){
            mp[s[i]]++;
            st.insert(s[i]);
        }
        int ans=0;
        ans+=st.size();
        
        mp[s[sz-1]]--;
        if(mp[s[sz-1]]==0) st.erase(s[sz-1]);
        
        for(int i=sz-2;i>=0;i--){
            ans+=st.size();
            mp[s[i]]--;
            if(mp[s[i]]==0) st.erase(s[i]);
        }
        cout<<ans<<endl;
    }
}
