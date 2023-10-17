//Bismillah
/*
https://cses.fi/problemset/task/1135/
*/

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
#define optimize() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl '\n'

const int mx=2e5+1,LOG=18;
vector<int>adj[mx];
int up[mx][LOG];
int depth[mx];
bool vis[mx];

void dfs(int u)
{
    vis[u]=1;
    for(int j=1;j<LOG;j++){
        up[u][j]=up[up[u][j-1]][j-1];
    }

    for(auto &v: adj[u]){
        if(!vis[v]){
            depth[v]=depth[u]+1;
            up[v][0]=u;
            dfs(v);
        }
    }
}

int get_lca(int a,int b){   //O(log(n))
    if(depth[a]<depth[b])   swap(a,b);
    int k=depth[a]-depth[b];
    for(int j=LOG-1;j>=0;j--){
        if(k&(1<<j)){
            a=up[a][j];
        }
    }
    if(a==b)    return a;
    else{
        for(int j=LOG-1;j>=0;j--){
            if(up[a][j]!=up[b][j]){
                a=up[a][j];
                b=up[b][j];
            }
        }
        return up[a][0];
    }
}
int main()
{
    optimize();

    int n,m,v,u,q;
    cin>>n>>q;
    for(int i=1;i<n;i++){
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    up[1][0]=1;
    depth[1]=0;
    dfs(1);

    while(q--){
        cin>>u>>v;
        int lca=get_lca(u,v);
        cout<<depth[u]+depth[v]-2*depth[lca]<<endl;
    }

    return 0;
}

