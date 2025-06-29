#include <bits/stdc++.h>
using namespace std;

const long long MOD = 998244353;

// Iterative factorial with modulo
long long fact(long long n){
    long long res = 1;
    for(long long i = 2; i <= n; i++){
        res = (res * i) % MOD;
    }
    return res;
}

int main()
{
    int t;
    cin>>t;
    while(t--){
        string s;
        cin>>s;

        int n=s.size();

        //Divide the string in blocks of equivalent characters

        //No of blocks == k (==no of elements that will be present after deletion)

        // only one element will remain in block

        // no of ways of selecting that element == sizeof block

        // min no of element deleted== totalElements(n) - selectedElements(k)

        // Now find permutation of selecting one element from each block

        // After all element is selected [ (n-k) elements ] 

        // multiply it with permutation for selection of order in which they can be deleted (n-k)!

        int blockSize=1;
        vector<int>blocks;
        for(int i=1;i<n;i++){
            if(s[i]==s[i-1]) blockSize++;
            else{
                 blocks.push_back(blockSize);
                 blockSize=1;
            }
        }
        if(blockSize>=1) blocks.push_back(blockSize);

        int k=blocks.size();

        long long distinctSequences=1;
        for(int i=0;i<k;i++){
            distinctSequences*=(long long) blocks[i];
            distinctSequences%=MOD;
        }

        distinctSequences*=fact(n-k);
        distinctSequences%=MOD;

        cout<<n-k<<" "<<distinctSequences<<endl;

    }
    return 0;
}