#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<pair<int,int>>a(n),b(n),c(n);

        for(int i=0;i<n;i++) {
            cin>>a[i].first;
            a[i].second=i;
        }

        for(int i=0;i<n;i++) {
            cin>>b[i].first;
            b[i].second=i;
        }

        for(int i=0;i<n;i++) {
            cin>>c[i].first;
            c[i].second=i;
        }

        sort(a.begin(),a.end());
        sort(b.begin(),b.end());
        sort(c.begin(),c.end());

        int result=0;

        for(int i=n-3;i<n;i++){
            for(int j=n-3;j<n;j++){
                for(int k=n-3;k<n;k++){
                    if(a[i].second!=b[j].second && b[j].second!=c[k].second && c[k].second!=a[i].second){

                        result=max(result,a[i].first+b[j].first+c[k].first);

                    }
                }
            }
        }
        cout<<result<<endl;
    }
    return 0;
}