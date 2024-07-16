#include<bits/stdc++.h>
using namespace std;
const int mod=1e9+7;
// int count(int x,vector<int>& dp,set<int>& s){
//     if(x<0) return 0;
//     if(x==0) return 1;
//     if(dp[x]!=-1) return dp[x];
//     dp[x]=0;
//     for(auto ele:s){
//         dp[x]+=count(x-ele,dp,s);
//     }
//     return dp[x];
// }
int main(){
    int n,x; cin>>n>>x;
    vector<int> vec(n);
    vector<vector<int>> dp(n+1,vector<int> (x+1,0));
    for(int i=0;i<n;i++){
        cin>>vec[i];
    }
    dp[0][0]=1;
    for(int j=1;j<=n;j++){
        for(int i=0;i<=x;i++){
            if(i-vec[j-1]>=0){
                dp[j][i]=(dp[j][i]+dp[j][i-vec[j-1]])%mod;
            }
            dp[j][i]=(dp[j][i]+dp[j-1][i])%mod;
        }
    }
    cout<<dp[n][x]%(1000000007)<<endl;
    // cout<<count(x,dp,s);

}