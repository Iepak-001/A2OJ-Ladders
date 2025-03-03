#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin>>n;
    set<int>st;
    int prefix=0;

    for(int i=1;i<=n && prefix<=n;i++){
        prefix+=i;
        st.insert(prefix);
    }

    for(auto x:st){
        int rem=n-x;
        if(st.find(rem)!=st.end()){
            cout<<"YES";
            return 0;

        }
    }
    cout<<"NO";

    return 0;
}