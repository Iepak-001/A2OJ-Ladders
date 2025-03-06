#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin>>n;

    int MAX=10000007;
    vector<int>freq(MAX+1,0);
    int maxVal=0;
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        freq[x]++;
        maxVal=max(maxVal,x);
    }
    MAX=maxVal;

    vector<int>pref(MAX+1,0);

    vector<int>isPrime(MAX+1,1);
    isPrime[0]=0;
    isPrime[1]=0;
    
    // For prime no calcn we are travelling all elements
    // Use this traversal for our benifit

    for(int i=2;i<=MAX;i++){

        if(isPrime[i]==true){
        for(int j=i; j<=MAX;j+=i){

            isPrime[j]=false;
            pref[i]+=freq[j];
        }
        isPrime[i]=true;
        }
    }
    
    for(int i=1;i<=MAX;i++){
        pref[i]+=pref[i-1];
    }

    int m;
    cin>>m;

    while (m--) {
        int x, y;
        cin >> x >> y;

        if (x > maxVal) {
            cout << "0\n";  // If range is outside the max value, answer is 0
            continue;
        }

        x = min(x, maxVal);
        y = min(y, maxVal);

        cout << pref[y] - (x > 0 ? pref[x - 1] : 0) << "\n";
    }

    return 0;
}