//https://www.spoj.com/problems/GSS3/
//https://codeforces.com/contest/2117/problem/H big one... needs integaration of ofline query
//if empty substring is allowed then answer will max(0,query())
#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
const int inf=1e9;
#define file() freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);

#define optimize() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
typedef struct nodeData{
    int ans;
    int sm;
    int mxpre;
    int mxsuf;
}nodeData;
nodeData make_data(int val)
{
    nodeData ret;
    ret.ans=ret.sm=ret.mxpre=ret.mxsuf=val;
    return ret;
}
const int mx=50001;
int a[mx];
nodeData t[mx*4];
nodeData combine(nodeData l,nodeData r){
    if(l.ans==-inf) return r;
    else if(r.ans==-inf)    return l;
    nodeData res;
    res.ans=max({l.ans,r.ans,l.mxsuf+r.mxpre});
    res.mxpre=max({l.mxpre,l.sm+r.mxpre});
    res.mxsuf=max({r.mxsuf,r.sm+l.mxsuf});
    res.sm=l.sm+r.sm;
    return res;
}
void build(int i,int tl,int tr)
{
    if(tl==tr)  t[i]=make_data(a[tl]);
    else{
        int tm=(tl+tr)/2;
        build(i*2,tl,tm);
        build(i*2+1,tm+1,tr);
        t[i]=combine(t[i*2],t[i*2+1]);
    }
}
nodeData query(int i,int tl,int tr,int l,int r)
{
    if(l>tr || r<tl){
        return make_data(-inf);
    }
    if(tl>=l && tr<=r)  return t[i];

    int tm=(tl+tr)/2;
    nodeData ret1=query(i*2,tl,tm,l,r);
    nodeData ret2=query(i*2+1,tm+1,tr,l,r);
    return combine(ret1,ret2);
}
void update(int v,int tl,int tr,int pos,int new_val)
{
    if(tl==tr){
        a[pos]=new_val;
        t[v]=make_data(new_val);
        return;
    }else{
        int tm=(tl+tr)/2;
        if(pos<=tm){
            update(v*2,tl,tm,pos,new_val);
        }else update(v*2+1,tm+1,tr,pos,new_val);
        t[v]=combine(t[v*2],t[v*2+1]);
    }
}
int main()
{
    optimize();
    #ifndef ONLINE_JUDGE
    file();
    #endif

    int n,m,type,x,y;
    cin>>n;
    for(int i=1;i<=n;i++)   cin>>a[i];

    build(1,1,n);

    cin>>m;
    while(m--){
        cin>>type>>x>>y;
        if(type==0){
            update(1,1,n,x,y);
        }else{
            nodeData res=query(1,1,n,x,y);
            cout<<res.ans<<endl;
        }
    }

    return 0;
}

