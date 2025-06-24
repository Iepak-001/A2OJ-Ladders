#include <bits/stdc++.h>
using namespace std;
// TRADITIONAL POSITIVE SUBARRAY SUM PROBLEM
int main()
{
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int>arr(n);
        vector<bool>isEven(n,true);
        for(int i=0;i<n;i++){
            cin>>arr[i];
            if(abs(arr[i])%2!=0) isEven[i]=false;
        }

        int right=0;

        int result=-1005;

        int currSum=0;

        while(right<n){
            currSum+=arr[right];
            result=max(result,currSum);            
            

            if(currSum<0 || (right<n-1 && isEven[right]^isEven[right+1]==0)) {
                currSum=0;
            }

            right++;
        }

        cout<<result<<endl;
    }
    return 0;
}