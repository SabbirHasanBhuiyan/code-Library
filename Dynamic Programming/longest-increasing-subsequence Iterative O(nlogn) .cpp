class Solution {
    static const int mx=2503;
    int n,ar[mx],dp[mx];
    int solve(){
        for(int i=0;i<n;i++){
            int j=upper_bound(dp,dp+n+1,ar[i])-dp;
            if(dp[j-1]<ar[i])   dp[j]=ar[i];
        
        }
        int ans=1;
        for(int i=1;i<=n;i++){   
            if(dp[i]!=1e9) ans=i;
            else break;
        }
        return ans;
    }
public:
    int lengthOfLIS(vector<int>& nums) {
        n=nums.size();
        for(int i=0;i<n;i++)    ar[i]=nums[i];
        for(int i=1;i<=n;i++)   dp[i]=1e9;
        dp[0]=-1e9;
        
        return solve();
    }
};
