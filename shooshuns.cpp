#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, k;
    cin >> n >> k;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    // Agar k aur first element same hai then never ans

    // ek element udne par dusra element aa rha
    //  matlab ki relative distance bw position same hai
    //  mtlb single loop me ho jaana chahiye

    // K ke baad se saara element same hona chahiye
    

    // element ko arr[k] se replace krke last me bhej de rha

    for(int i=k-1; i<n-1; i++){
        if(arr[i]!=arr[i+1]){
            cout<<-1;
            return 0;
        }
    }

    for(int i=k-1;i>=0; i--){
        if(arr[i]!=arr[i-1]){
            cout<<i;
            return 0;
        }
    }

    cout<<0;
}