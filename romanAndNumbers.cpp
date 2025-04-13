#include <bits/stdc++.h>
using namespace std;
int m;
int flipMSBAndAhead(int n) {
    int msb_pos = 31 - __builtin_clz(n); // Find MSB position
    int mask = (1 << (msb_pos + 1)) - 1; // Create mask with all 1s up to MSB
    return n ^ mask; // Flip MSB and all bits ahead
}
// no of digits==18 [ Bitmask can be used]
// 4s time limit

// steps
// 1st. Generate all permutations
// Then test by dividing

//Modulo opration ka proety use kro
int f(int n, int bitmask){
    cout<<bitmask<<" ";
    // 1bit == not selected
    // 0 bit== already selected
    if(bitmask==0) return 0;

    int rem=flipMSBAndAhead(bitmask)%m;
    int ans=0;

    for(int i=1;(1<<i)<n; i++){

        if((bitmask>>i) & 1 !=0){
            int rem2=f(n,bitmask^(1<<i))%m;
            if((rem2+rem)%m==0) ans+=1;
        }
       
    }

    return ans;
    
}
int main()
{
    int n;
    cin>>n>>m;


    cout<< f(n,n);
    return 0;
}