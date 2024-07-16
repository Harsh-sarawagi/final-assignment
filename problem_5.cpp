// dijkshtra's algorithm inspired from BFS
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INF=LLONG_MAX;
int main(){
    int n,m;
    cin>>n>>m;
    vector<vector<pair<ll,ll>>> adj(n+1);
    vector<ll> dist(n+1,INF);
    set<pair<ll,ll>> s;
    for(int i=0;i<m;i++){
        ll a,b,c;
        cin>>a>>b>>c;
        adj[a].push_back({b,c});
        // adj[b].push_back({a,c});
    }
    dist[1]=0;
    s.insert({0,1});
    while(!s.empty()){
        auto x=*(s.begin());
        s.erase(x);
        ll u=x.second;
        for(auto &it: adj[u]){
            ll v=it.first;
            ll weight=it.second;
            if(dist[v]>dist[u]+weight){
                s.erase({dist[v],v});
                dist[v]=dist[u]+weight;
                s.insert({dist[v],v});
            }
        }
    }
    for(int i=1;i<n+1;i++){

        cout<<dist[i]<<' ';
    }

}
