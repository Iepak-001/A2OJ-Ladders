#include <bits/stdc++.h>
using namespace std;

int main()
{
    vector<int>arr(3);
    for(int i=0;i<3;i++) cin>>arr[i];
    int count=0;

    for(int i=0;i<3;i++){
        if(arr[i]%3==0 && arr[i]!=0){
            count+=arr[i]/3 -1;
            arr[i]=3;
        }
        else{
            count+=arr[i]/3;
            arr[i]=arr[i]%3;
        }
    }
    int m1=0;
    int mini=*min_element(arr.begin(),arr.end());
    m1+=mini;

    for(int i=0;i<3;i++){
        m1+=(arr[i]-mini)/3;
    }

    int m2=0;
    for(int i=0;i<3;i++){
        m2+=arr[i]/3;
    }

    count+=max(m1,m2);

    cout<<count;
    
    return 0;
}