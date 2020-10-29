#include<bits/stdc++.h>
using namespace std;

bool subSetSum(int arr[], int n, int sum){
    bool dp[n+1][sum+1];
    for(int i=0;i<=n;i++){
        dp[i][0] = true;
    }
    for(int i=1;i<=sum;i++){
        dp[0][i] = false;
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=sum;j++){
            if(j>=arr[i-1])
                dp[i][j] = dp[i-1][j] || dp[i-1][j-arr[i-1]];
            else
                dp[i][j] = dp[i-1][j];
        }
    }
    return dp[n][sum];
}

bool equalSumPartition(int arr[],int n){
    int s=0;
    s = accumulate(arr,arr+n,s);
    if(s%2 != 0)
        return false;
    else return subSetSum(arr,n,s/2);
}

int subsetWithGivenSum(int arr [], int n, int sum){
    int dp[n+1][sum+1];
    for(int i=0;i<=n;i++){
        dp[i][0] = 1;
    }
    for(int i=1;i<=sum;i++){
        dp[0][i] = 0;
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=sum;j++){
            if(j>=arr[i-1])
                dp[i][j] = dp[i-1][j] + dp[i-1][j-arr[i-1]];
            else
                dp[i][j] = dp[i-1][j];
        }
    }
    return dp[n][sum];
}

int minSubsetSumDifference(int arr[],int n){
    int sum=0;
    sum = accumulate(arr,arr+n,sum);
    bool dp[n+1][sum+1];
    for(int i=0;i<=n;i++){
        dp[i][0] = 1;
    }
    for(int i=1;i<=sum;i++){
        dp[0][i] = 0;
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=sum;j++){
            if(j>=arr[i-1])
                dp[i][j] = dp[i-1][j] || dp[i-1][j-arr[i-1]];
            else
                dp[i][j] = dp[i-1][j];
        }
    }
    for(int i=sum/2;i>=0;i--){
        if(dp[n][i])
            return sum-2*i;
    }
}

int subsetWithGivenDifference(int arr[], int n, int d){
    int sum=0;
    sum = accumulate(arr,arr+n,sum);
    return subsetWithGivenSum(arr,n,(sum+d)/2);
}

int main(){
    int n,sum;
    cin>>n;
    int arr[n];
    for(int i=0; i<n; i++) {
        cin>>arr[i];
    }
    cin>>sum;
    cout<<subSetSum(arr,n,sum)<<endl;
    cout<<equalSumPartition(arr,n)<<endl;
    cout<<subsetWithGivenSum(arr,n,sum)<<endl;
    cout<<minSubsetSumDifference(arr,n)<<endl;
    cout<<subsetWithGivenDifference(arr,n,sum)<<endl;
}