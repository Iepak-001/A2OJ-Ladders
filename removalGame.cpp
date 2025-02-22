#include <bits/stdc++.h>
using namespace std;

long long dp[5005][5005];
long long f(int i, int j, vector<int>&arr){
    if(i==j) return arr[i];
    if(i>j) return 0;
    if(dp[i][j]!=-1) return dp[i][j];
    return dp[i][j]=max(arr[i]-f(i+1,j,arr), arr[j]-f(i,j-1,arr));
}
int main() {
  int n;
  cin >> n;
  vector<int> x(n);
  long long sum = 0;
  for (int&v : x) {
    cin >> v;
    sum += v;
  }
  memset(dp, -1, sizeof(dp));
  long long sum2=f(0,n-1,x);
  cout<<(sum+sum2)/2;
}