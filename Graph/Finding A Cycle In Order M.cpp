//Finding A cycle In Order(M)
//We will run a series of DFS in the graph. Initially all vertices are colored white (0). From each unvisited (white) vertex, start the DFS, mark it gray (1) while entering and mark
//it black (2) on exit. If DFS moves to a gray vertex, then we have found a cycle (if the graph is undirected, the edge to parent is not considered). The cycle itself can be
//reconstructed using parent array.

//This code is for undirected graph; for directed graph par in dfs(u,par) must be avoided.
//Need to call find_cycle(n): n is the total number of nodes.
//Bismillah

#include<bits/stdc++.h>
using namespace std;

#define int long long 
typedef long long ll;

#define PB push_back
#define F first
#define S second
#define endl '\n'
#define all(a) (a).begin(),(a).end()
#define sz(x) (int)x.size()


#define optimize() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

const int N=1e5+1;
vector<int>adj[N];
vector<char>color;
vector<int>parent;
int cycle_start,cycle_end;
 
bool dfs(int u,int par)
{
    color[u]=1;
    for(auto &v: adj[u]){
        if(color[v]==0){
            parent[v]=u;
            if(dfs(v,u))  return true;
        }else if(color[v]==1 and v!=par){
            cycle_end=u;
            cycle_start=v;
            return true;
        }
    }
    color[u]=2;
    return false;
}
void find_cycle(int n){
    color.assign(n+1,0);
    parent.assign(n+1,-1);
    cycle_start=-1;
    for(int u=1;u<=n;u++){
        if(color[u]==0 and dfs(u,-1)){
            break;
        } 
    }
    if(cycle_start==-1){
        cout<<"IMPOSSIBLE"<<endl;
    }else{
        vector<int>cycle;
        cycle.PB(cycle_start);
        for(int v=cycle_end;v!=cycle_start;v=parent[v]){
            cycle.PB(v);
        }
        cycle.PB(cycle_start);
        reverse(cycle.begin(),cycle.end());
        cout<<cycle.size()<<endl;
        for(auto &v: cycle) cout<<v<<" ";
        cout<<endl;
    }
}
signed main()
{
    optimize();
    
    int n,m,u,v;
    cin>>n>>m;
    for(int i=1;i<=m;i++){
        cin>>u>>v;
        adj[u].PB(v);
        adj[v].PB(u);
    }
 
    find_cycle(n);
 
    return 0;
}

