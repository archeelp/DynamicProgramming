#include<bits/stdc++.h>
using namespace std;

int dp[100][100];

int MCMRecursive(int arr[], int i, int j){
    if(i>=j)
        return 0;
    int ans = INT_MAX;
    for(int k=i; k < j; k++){
        int temp = MCMRecursive(arr,i,k)+MCMRecursive(arr,k+1,j)+arr[i-1]*arr[k]*arr[j];
        if(temp<ans)
            ans = temp;
    }
    return ans;
}

int MCMMemoized(int arr[], int i, int j){
    if(dp[i][j] == -1){
        if(i>=j)
            dp[i][j] = 0;
        else{
            int ans = INT_MAX;
            for(int k=i; k < j; k++){
                int temp = MCMMemoized(arr,i,k)+MCMMemoized(arr,k+1,j)+arr[i-1]*arr[k]*arr[j];
                if(temp<ans)
                    ans = temp;
            }
            dp[i][j] = ans;
        }
    }
    return dp[i][j];
}

int MCMTopDown(int arr[], int n){
    int dp[n+1][n+1];
    for(int i = 0; i <= n; i++)
        dp[i][i] = 0;
    for(int l=2; l<=n; l++){
        for(int i = 1; i<=n-l+1; i++){
            int j = i+l-1;
            dp[i][j] = INT_MAX;
            for(int k = i; k<j ; k++)
                dp[i][j] = min(dp[i][j],dp[i][k]+dp[k+1][j]+arr[i-1]*arr[k]*arr[j]);
        }
    }
    return dp[1][n];
}

int main(){
    memset(dp,-1,100*100*sizeof(dp[0][0]));
    int n;
    cin>>n;
    int arr[n+1];
    for(int i=0; i<n+1; i++){
        cin>>arr[i];
    }
    cout<<MCMRecursive(arr,1,n)<<endl;
    cout<<MCMMemoized(arr,1,n)<<endl;
    cout<<MCMTopDown(arr,n)<<endl;
}