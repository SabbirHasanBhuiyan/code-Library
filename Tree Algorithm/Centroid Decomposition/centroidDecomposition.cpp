 //Bismillah
 
#include<bits/stdc++.h>
using namespace std;

#define int long long 
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pii;
 
#define PB push_back
#define F first
#define S second
#define endl '\n'
#define all(a) (a).begin(),(a).end()
#define sz(x) (int)x.size()
#define mx_int_prime 999999937
 
const double PI = acos(-1);
const double eps = 1e-9;
const int inf = 2000000000;
const ll infLL = 9000000000000000000;
#define MOD 1000000007
  
#define optimize() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define file() freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);


const int mx=1e5+1;
set<int>adj[mx];
int par[mx];
int subSz[mx];
//------Decompose part-----//

int dfs1(int node ,int p)
{
    subSz[node]=1;

    for(auto &v: adj[node]){
        if(v!=p){
            subSz[node]+=dfs1(v,node);
        }
    }
    return subSz[node];
}

int dfs2(int node,int p,int n)
{
    for(auto &v: adj[node]){
        if(v!=p && subSz[v]>n/2){
            return dfs2(v,node,n);
        }
    }
    return node;
}

void decompose(int node,int p){
    int subTreeSz=dfs1(node,p);
    int centroid=dfs2(node,p,subTreeSz);

    cout<<"tree is rooted at "<<node<<" "<<"with size "<<subTreeSz<<" and has centroid "<<centroid<<endl;

    par[centroid]=p;
    
    for(auto &v: adj[centroid]){
        adj[v].erase(centroid);
        decompose(v,centroid);
    }
}

signed main()
{
    optimize();
    #ifndef ONLINE_JUDGE
    file();
    #endif

    int n,u,v;
    cin>>n;
    for(int i=1;i<n;i++){
        cin>>u>>v;
        adj[u].insert(v);
        adj[v].insert(u);
    }


    decompose(1,-1);


    return 0;
}

/*
sample input
15
2 1
2 3
2 4
2 5
5 6
5 8
6 7
8 9
9 10
9 13
10 11
10 12
13 14
13 15
*/
