#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin>>n;
    int count=0;

    for(int i=1;i<=n;i++){

        for(int j=1; j<=i; j++){

            int cSquared= i*i + j*j;
            int c=sqrt(cSquared);

            if(c*c == cSquared && c<=n) count++;
        }
    }
    cout<<count;
    return 0;
}