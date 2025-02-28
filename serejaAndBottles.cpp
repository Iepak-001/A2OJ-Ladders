#include <bits/stdc++.h>
using namespace std;
#define pp pair<int,int>
int main()
{
    int n;
    cin>>n;

    vector<pp>bottles(n+1);

    for(int i=1;i<=n;i++){
        cin>>bottles[i].first;
        cin>>bottles[i].second;
    }
    
    int count=0;
    for(int  i=1;i<=n;i++){
        
        for(int j=1;j<=n; j++){
            if(i==j) continue;
            if(bottles[j].second==bottles[i].first){
                count++;
                break;
            }
        }
    }
    cout<<n-count;
    
    return 0;
}