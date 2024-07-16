//union find algorithm
#include<bits/stdc++.h>
using namespace std;
int findparent(int node,vector<int>& parent){
    if(node!=parent[node]) parent[node]=findparent(parent[node],parent);
   
    return parent[node];
}
void union_set(int a, int b,vector<int>& parent, vector<int>& size){
    a=findparent(a,parent);
    b=findparent(b,parent);
    if(a!=b){
        if(size[b]>size[a]) swap(a,b);
        parent[b]=a;
        size[a]+=size[b];
    }
}
int main(){
    int n,m;cin>>n>>m;
    vector<int> parent(n+1);
    vector<int> size(n+1,1);
    for(int i=0;i<n+1;i++) parent[i]=i;
    for(int i=0;i<m;i++){
        int a,b;
        cin>>a>>b;
        union_set(a,b,parent,size);
    }
    for(int i=1;i<n+1;i++) findparent(i,parent);
    set<int> st;
    // for(auto ele:parent) cout<<ele<<' ';
    // cout<<endl;
    for(int i=1;i<n+1;i++){
        st.insert(parent[i]);
    }
    cout<<st.size()-1<<endl;
    auto x=*st.begin();
    st.erase(st.begin());
    for(auto ele:st){
        cout<<x<<' '<<ele<<endl;
        x=ele;
    }
    
}