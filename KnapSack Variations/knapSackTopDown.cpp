#include <bits/stdc++.h> 
using namespace std;

struct item {
    int weight;
    int value;
};

int knapSack(item items[],int capacity,int n){
    int dp[n+1][capacity+1];
    for(int i=0;i<=n;i++){
        dp[i][0] = 0;
    }
    for(int i=0;i<=capacity;i++){
        dp[0][i] = 0;
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=capacity;j++){
            if(j>=items[i-1].weight)
                dp[i][j] = max(dp[i-1][j],items[i-1].value+dp[i-1][j-items[i-1].weight]);
            else
                dp[i][j] = dp[i-1][j];
        }
    }
    return dp[n][capacity];
}

int main(){
    int n;
    cout<<"Enter the number of items ";
    cin>>n;
    item items[n];
    for(int i = 0; i<n; i++) {
        cin>>items[i].weight;
        cin>>items[i].value;
    }
    cout<<"Enter capacity ";
    int capacity;
    cin>>capacity;
    cout<<knapSack(items,capacity,n)<<endl;
    return 0;
}
