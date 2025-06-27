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

        //Now do the processing
        vector<int>positionOfNearestLeftDifferentElement(n);
        positionOfNearestLeftDifferentElement[0]=-1;

        for(int i=1;i<n;i++){
            if(arr[i]==arr[i-1]) positionOfNearestLeftDifferentElement[i]=positionOfNearestLeftDifferentElement[i-1];
            else positionOfNearestLeftDifferentElement[i]=i-1;
        }

        int q;
        cin>>q;
        while(q--){
            int l,r;
            cin>>l>>r;

            //Make starting index as 0
            l--,r--;

            int rightPos=r;
            int leftPos=positionOfNearestLeftDifferentElement[r];

            if(leftPos<l){
                cout<<("-1 -1");
            }
            else{
                
                // To make starting index 1

                cout<<leftPos+1<<" "<<rightPos+1;
            }
            cout<<endl;
        }
    }
    return 0;
}