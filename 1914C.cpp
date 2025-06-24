#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin>>t;
    while(t--){
        int n,k;
        cin>>n>>k;
        vector<int>a(n),b(n),maxTillNowInB(n),prefSumA(a);
        

        for(int i=0;i<n;i++){
            cin>>a[i];
        }

        for(int i=0;i<n;i++){
            cin>>b[i];
        }

        prefSumA[0]=a[0];
        for(int i=1;i<n;i++){
            prefSumA[i]=prefSumA[i-1]+a[i];

        }


        int maxi=-1;
        for(int i=0;i<n;i++){
            maxi=max(maxi,b[i]);
            maxTillNowInB[i]=maxi;

        }


        int result=a[0];
        for(int i=0;i<k && i<n;i++){
            result=max(result,prefSumA[i]+ (k-i-1)*maxTillNowInB[i]);

        }

        cout<<result<<endl;
       


    }
    return 0;
}