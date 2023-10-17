/*
https://onlinejudge.org/index.php?option=onlinejudge&Itemid=8&page=show_problem&problem=4453
*/
#include<bits/stdc++.h>
using namespace std;

const int inf=2e9;

#define PB push_back

#define optimize() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

#define int long long

const int mx=1e5+1;
int mnt[mx*4];
int mxt[mx*4];
int r[mx];
typedef struct info{
    int pos;
    int type; ///3->query 1->left start, 2->right start,4->left end ,5 -> right end
    int id;
    info(int pos,int type,int id) : pos(pos) ,type(type) ,id(id){}
}info;

bool cmp(const info &p1,const info &p2)
{
    if(p1.pos<p2.pos)   return true;
    else if(p1.pos==p2.pos){
        if(p1.type<p2.type) return true;
        else if(p1.type==p2.type){
            return (p1.id<=p2.id);
        }else return false;
    }else return false;
}

void input(vector<info> &v,int n,int m)
{
    int a,b,pos;
    for(int i=1;i<=n;i++){
        cin>>a>>b;
        v.PB({a,1,i});
        v.PB({(a+b)/2,4,i});
        v.PB({(a+b+1)/2,2,i});
        v.PB({b,5,i});
        r[i]=b;
    }

    for(int i=1;i<=m;i++){
        cin>>pos;
        v.PB({pos,3,i});
    }
}

void update1(int v,int tl,int tr,int pos,int val)
{
    if(tl==tr)  mnt[v]=val;
    else {
        int tm=(tl+tr)/2;
        if(pos<=tm) update1(v*2,tl,tm,pos,val);
        else update1(v*2+1,tm+1,tr,pos,val);
        mnt[v]=min(mnt[v*2],mnt[v*2+1]);
    }
}

void update2(int v,int tl,int tr,int pos,int val)
{
    if(tl==tr)  mxt[v]=val;
    else {
        int tm=(tl+tr)/2;
        if(pos<=tm) update2(v*2,tl,tm,pos,val);
        else update2(v*2+1,tm+1,tr,pos,val);
        mxt[v]=max(mxt[v*2],mxt[v*2+1]);
    }
}

void solve(vector<int>&ans,vector<info>&v,int n,int m){
    for(auto &x: v){
        if(x.type==1) update1(1,1,n,x.id,x.pos);
        else if(x.type==4) update1(1,1,n,x.id,inf);
        else if(x.type==2) update2(1,1,n,x.id,r[x.id]);
        else if(x.type==5) update2(1,1,n,x.id,-inf);
        else{
            int req=0;
            int ret=mnt[1];
            if(ret!=inf)    req=max(req,(x.pos-ret));
            ret=mxt[1];
            if(ret!=(-inf))    req=max(req,(ret-x.pos));

            ans[x.id]=req;
        }
    }
}

signed main()
{
    optimize();

    int t,n,m;
    cin>>t;
    for(int tc=1;tc<=t;tc++){
        cin>>n>>m;
        vector<info>v;

        input(v,n,m);

        sort(v.begin(),v.end(),cmp);

        vector<int> ans(m+1);

        for(int i=0;i<=(n*4);i++)   mnt[i]=inf;
        for(int i=0;i<=(n*4);i++)   mxt[i]=-inf;

        solve(ans,v,n,m);

        cout<<"Case "<<tc<<":"<<endl;
        for(int i=1;i<=m;i++)   cout<<ans[i]<<endl;
        //cout<<endl;
    }

    return 0;
}

