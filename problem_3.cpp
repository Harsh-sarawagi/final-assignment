#include<bits/stdc++.h>
using namespace std;
const long long mod=1e9+7;
vector<vector<long long>> multiply(vector<vector<long long>>& a,vector<vector<long long>>& b, int n) {
    vector<vector<long long>> c(n,vector<long long>(n, 0));
    for (int i=0;i<n;++i) {
        for (int j=0;j<n;++j) {
            for (int k=0;k<n;++k) {
                c[i][j]=(c[i][j]+a[i][k]*b[k][j])%mod;
            }
        }
    }
    return c;
}
vector<vector<long long>> exponential(vector<vector<long long>>& matrix, long long k,int n){
    vector<vector<long long>> result(n,vector<long long>(n,0));
    vector<vector<long long>> ans(n,vector<long long>(n,0));
    for (int i = 0; i < n; ++i) {
        result[i][i] = 1;
    }
    while(k>0){
        if(k%2){
            result=multiply(result, matrix,n);
        }
        matrix=multiply(matrix,matrix,n);
        k/=2;
        // matrix=result;
    }
    return result;
}

int main(){
    int n;
    long long k;
    // long long mod=1000000007;
    cin>>n>>k;
    // long long ans=0;
    vector<vector<long long>> matrix(n,vector<long long> (n,0));
    for(int i=0;i<n;i++){
        for( int j=0;j<n;j++){
            cin>>matrix[i][j];
        }
    }
    vector<vector<long long>> ans_matrix=exponential(matrix,k,n);
    long long ans= 0;
    for (int i=0;i<n;++i) {
        for(int j=0;j<n;j++){
            // cout<<ans_matrix[i][j]<<' ';
            ans=(ans+ans_matrix[i][j])%mod;
        }
        cout<<endl;
    }

    cout<<ans<<endl;

    
    
}