#include <bits/stdc++.h>
using namespace std;

//PRIME FACTORS TASK
int main()
{
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int>arr(n);
        for(int i=0;i<n;i++) cin>>arr[i];

        unordered_map<int,int>divisors;
        for(int i=0;i<n;i++){

            int j=2;
            // Divisors will always be smaller than sqrt(arr[i])
            while(j*j<=arr[i]){
                
                while(arr[i]%j==0){
                    divisors[j]++;
                    arr[i]/=j;
                }

                j++;
            }
            if(arr[i]>1) divisors[arr[i]]++;
            
        } 

        bool flag=true;

        for(auto x:divisors){
            if(x.second%n!=0){
                flag=false;
                break;
            }
        }

        if(flag==true) cout<<"YES";
        else cout<<"NO";

        cout<<endl;
    }
    return 0;
}