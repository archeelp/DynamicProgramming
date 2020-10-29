#include<bits/stdc++.h>
using namespace std;

int dp[100][100];

int recursive(int n, int f){
    if(f==0 || f==1 || n==1)
        return f;
    int ans = INT_MAX;
    for(int i=1; i<=f; i++){
        ans = min(ans,max(recursive(n-1,i-1),recursive(n,f-i)));
    }
    return ans+1;
}

int memoized(int n, int f){
    if(dp[n][f] == -1){
        if(f==0 || f==1 || n==1)
            dp[n][f] = f;
        else{
            int ans = INT_MAX;
            for(int i=1; i<=f; i++){
                ans = min(ans,max(memoized(n-1,i-1),memoized(n,f-i)));
            }
            dp[n][f] = ans+1;
        }
    }
    return dp[n][f];
}

int topDown(int n, int f){
    int dp[n+1][f+1];
    for(int i = 1; i<=n; i++){
        dp[i][0] = 0;
        dp[i][1] = 1;
    }
    for(int i = 1; i<=f; i++){
        dp[1][i] = i;
        dp[1][i] = i;
    }
    for(int i = 2; i<=n; i++)
        for(int j = 2; j<=f; j++){
            dp[i][j] = INT_MAX;
            for(int k = 1; k<=j; k++){
                dp[i][j] = min(dp[i][j],1+max(dp[i-1][k-1],dp[i][j-k]));
            }
        }
    return dp[n][f];
}

int main(){
    memset(dp,-1,100*100*sizeof(dp[0][0]));
    int n,f;
    cin>>n>>f;
    cout<<recursive(n,f)<<endl;
    cout<<memoized(n,f)<<endl;
    cout<<topDown(n,f)<<endl;
}