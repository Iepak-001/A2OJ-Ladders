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

        int left=0;
        int right=n-1;

        //Two possibilities
        // If both arr[left] and right doesnt match
        // Then remove any of the element

        int element1=-1,element2=-1;

        while(left<right){
            if(arr[left]!=arr[right]){
                element1=arr[left];
                element2=arr[right];
                break;
            }
            left++;
            right--;
        }

        if(element1==-1){
            cout<<"YES"<<endl;
            continue;
        }

        // First try remove element1
        bool flag=false;
        left=0;
        right=n-1;

        while(left<right){
            if(arr[left]!=arr[right]){
                if(arr[left]==element1) left++;
                else if(arr[right]==element1) right--;
                else break;
            }
            else{
                left++;
                right--;
            }
        }

        if(left>=right) flag=true;

        //Now try remove element2

        left=0;
        right=n-1;

        while(left<right){
            if(arr[left]!=arr[right]){
                if(arr[left]==element2) left++;
                else if(arr[right]==element2) right--;
                else break;
            }
            else{
                left++;
                right--;
            }
        }
        if(left>=right) flag=true;

        if(flag==true) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;

    }
    return 0;
}