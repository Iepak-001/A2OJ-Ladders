#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int>arr(n);
        for(int i=0;i<n;i++) cin>>arr[i];

        int ans=0;

        bool flag=true;
        for(int i=n-2;i>=0;i--){
            while(arr[i]>=arr[i+1]){
                arr[i]/=2;
                ans++;
                if(arr[i+1]==0){
                    flag=false;
                    break;
                }
            }
        }
        if(flag==false) cout<<-1;
        else cout<<ans;
        cout<<endl;
    }
    
    return 0;
}