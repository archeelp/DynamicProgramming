#include <bits/stdc++.h> 
using namespace std;

struct item {
    int weight;
    int value;
};

int dp[100][100];

int knapSack(item items[],int capacity,int n){
    if(dp[n][capacity]==-1){
        if(n&&capacity){
            if(capacity>=items[n-1].weight){
                dp[n][capacity] = max(items[n-1].value+knapSack(items,capacity-items[n-1].weight,n-1),knapSack(items,capacity,n-1));
            }
            else dp[n][capacity] = knapSack(items,capacity,n-1);
        }
        else dp[n][capacity] = 0;
    }
    return dp[n][capacity];
}

int main(){
    int n;
    memset(dp,-1,sizeof(dp[0][0])*100*100);
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
