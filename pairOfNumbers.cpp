#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;

    vector<int> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    int logN = floor(log2(n)) + 1;
    vector<vector<int>> gcdTable(logN, vector<int>(n, 0));
    vector<vector<int>> minTable(logN, vector<int>(n, 0));
    // length=log(n)
    // index =n 
    for (int j = 0; j < n; j++) gcdTable[0][j] = arr[j];

    for (int j = 0; j < n; j++)  minTable[0][j] = arr[j];
        

    // gcdTable ==(length, index)
    for (int i = 1; (1 << i) <= n; i++) // length 1 ke liye pahle saara => length 2 => then length 4
    { 
        for (int j = 0; j + (1 << i) <= n; j++)
        {
            // Combine results of two intervals of length 2^(i-1)
            gcdTable[i][j] = __gcd(gcdTable[i - 1][j],
                                   gcdTable[i - 1][j + (1 << (i - 1))]);

            minTable[i][j] = min(minTable[i - 1][j], 
                                    minTable[i - 1][j + (1 << (i - 1))]);
        }
    }
    int maxLen=0;
    int maxLen2=1;
    set<int>indices;
    // Now apply binary search for earch length
    for(int i=0;i<n;i++){

        // each index search kro ki righ me kitna ja skta hai
        // aur left me kitna
        // .. index i hamesa included rhega

        // LEFT SIDE Search =>>

        int minVal=arr[i];
        int left=i;
        int lo=0, hi=i,best=i;

        while(lo<=hi){
            int mid=lo+(hi-lo)/2;

            int k = floor(log2(i - mid + 1));

            // minVal=min(minTable[k][mid],minTable[k][i-(1<<k)+1]);
            int gcdVal=0;
            gcdVal=__gcd(gcdTable[k][mid],gcdTable[k][i-(1<<k)+1]);


            if(gcdVal==minVal){
                best=mid;
                hi=mid-1;
            }
            else{
                lo=mid+1;
            }
            // if(i==3) cout<<mid<<" "<<gcdVal<<" "<<minVal<<""<<endl;
        }
        if(best<left) left=best;
        int length=i-best+1;
        
        // Now for right side

        lo=i, hi=n-1,best=i;

        while(lo<=hi){
            int mid=lo+(hi-lo)/2;

            int k = floor(log2(mid-i + 1));

            // minVal=min(minTable[k][i],minTable[k][mid-(1<<k)+1]);
            int gcdVal=0;
            gcdVal=__gcd(gcdTable[k][i],gcdTable[k][mid-(1<<k)+1]);

            if(gcdVal==minVal){
                best=mid;
                lo=mid+1;
            }
            else{
                hi=mid-1;
            }
            // if(i==3) cout<<mid<<" "<<gcdVal<<" "<<minVal<<""<<endl;
        }
       
        int length2=best-i;
        if(length2 + length >maxLen){
            maxLen=length + length2;
            indices.clear();
            indices.insert(left+1);
        }
        else if(length + length2==maxLen){
            indices.insert(left+1);
        }
        cout<<i<<" "<<left<<" "<<maxLen<<endl;
    }
    cout<<indices.size()<<" "<<maxLen-1<<"\n";
    for(auto el: indices) cout<<el<<" ";

    return 0;
}