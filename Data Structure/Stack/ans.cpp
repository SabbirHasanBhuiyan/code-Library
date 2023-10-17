//Bismillah

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

#define vi vector<int>
#define PB push_back

int solve(vector<int>v,int n)
{
    vector<int> Left(n+1,0);
    vector<int> Right(n+1,0);

    stack<int>ss;
    ss.push(0);
    for(int i=1;i<=n;i++){
        int idx=ss.top();
        while(v[idx]>=v[i]) {ss.pop();idx=ss.top();}
        Left[i]=(i-idx);
        if(v[idx]<v[i]) ss.push(i);
    }

    while(!ss.empty())  ss.pop();
    ss.push(0);
    reverse(v.begin(),v.end());
    for(int i=1;i<=n;i++){
        int idx=ss.top();
        while(v[idx]>=v[i]) {ss.pop();idx=ss.top();}
        Right[i]=(i-idx);
        if(v[idx]<v[i]) ss.push(i);
    }
    reverse(Right.begin()+1,Right.begin()+n+1);

    int ans=0,ret;
    for(int i=1;i<=n;i++){
        ans=max(ans,v[i]*(Left[i]+Right[i]-1));
    }
    return ans;
}
int main()
{

    int n,m;
    cin>>n>>m;

    int ar[n+1][m+2];
    for(int j=1;j<=m;j++)   ar[0][j]=0;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++)   cin>>ar[i][j];
    }

    int ans=0;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(ar[i][j]==0){
                ar[i][j]=1+ar[i-1][j];
            }else ar[i][j]=0;
        }

        vi v;
        v.PB(-1);
        for(int j=1;j<=m;j++){
            v.PB(ar[i][j]);
        }
        v.PB(-1);
        ans=max(ans,solve(v,m));
    }


    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++)   cout<<ar[i][j]<< " ";
        cout<<endl;
    }

    cout<<ans<<endl;


    return 0;
}

