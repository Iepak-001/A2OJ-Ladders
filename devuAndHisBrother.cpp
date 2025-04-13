#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll cost(int x, const vector<int>& a, const vector<int>& b) {
    ll total = 0;
    for (int val : a)
        if (val < x)
            total += x - val;

    for (int val : b)
        if (val > x)
            total += val - x;

    return total;
}

int main(){
    int n,m;
    cin>>n>>m;

    vector<int>a(n),b(m);
    for(int i=0;i<n;i++) cin>>a[i];
    for(int j=0;j<m;j++) cin>>b[j];

    sort(a.begin(),a.end());
    sort(b.begin(),b.end());

    int i=0, j=0;

    vector<int>merged;

    while(i<n && j<m){
        if(a[i]<=b[j]){
            merged.push_back(a[i]);
            i++;
        }
        else{
            merged.push_back(b[j]);
            j++;
        }
    }

    while(j<m) {
        merged.push_back(b[j]);
        j++;
    }

    while(i<n){
        merged.push_back(a[i]);
        i++;
    }

    // terneary search lagao
    
    // On Index 

    int lo=0;
    int hi=m+n-1;

    while(hi-lo>3){
        int mid1=lo+(hi-lo)/3;

        int mid2= hi-(hi-lo)/3;

        ll cost1=cost(merged[mid1],a,b);
        ll cost2=cost(merged[mid2],a,b);

        if (cost1 < cost2)
            hi = mid2;
        else
            lo = mid1;
    }

    ll answer = LLONG_MAX;
    for (int x = lo; x <=hi; ++x) {
        answer = min(answer, cost(merged[x], a, b));
    }

    cout << answer << endl;
    return 0;

}