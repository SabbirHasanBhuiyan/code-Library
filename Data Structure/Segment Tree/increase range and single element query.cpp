//Bismillah

#include<bits/stdc++.h>
using namespace std;

#define endl '\n'

#define optimize() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define int long long

const int mx=2e5+1;
int ar[mx],t[mx*4];

void build(int v,int tl,int tr)
{
    if(tl==tr)  t[v]=ar[tl];
    else {
        int tm=(tl+tr)/2;
        build(v*2,tl,tm);
        build(v*2+1,tm+1,tr);
        t[v]=0;
    }
}

void update(int v,int tl,int tr,int l,int r,int add)
{
    if(r<tl || l>tr)    return;
    if(tl>=l && tr<=r){
        t[v]+=add;
    }else{
        int tm=(tl+tr)/2;
        update(v*2,tl,tm,l,r,add);
        update(v*2+1,tm+1,tr,l,r,add);
    }
}

int query(int v,int tl,int tr,int idx)
{
    if(tl==tr)  return t[v];
    else{
        int tm=(tl+tr)/2;
        if(idx<=tm){
            return t[v]+query(v*2,tl,tm,idx);
        }else return t[v]+query(v*2+1,tm+1,tr,idx);
    }
}

signed main()
{
    optimize();

    int n,q,type,l,r,add,idx;
    cin>>n>>q;
    for(int i=1;i<=n;i++)   cin>>ar[i];

    build(1,1,n);

    while(q--){
        cin>>type;
        if(type==1){
            cin>>l>>r>>add;
            update(1,1,n,l,r,add);
        }else{
            cin>>idx;
            cout<<query(1,1,n,idx)<<endl;
        }
    }

    return 0;
}

