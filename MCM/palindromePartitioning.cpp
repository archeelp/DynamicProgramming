#include<bits/stdc++.h>
using namespace std;

int dp[100][100];

bool isPalindrome(string s, int i, int j){
    int n = j-i+1;
    for(int k = 0; k < n/2; k++){
        if(s[i+k] != s[j-k])
            return false;
    }
    return true;
}

int recursive(string s, int i, int j){
    if(j-i+1 <= 1)
        return 0;
    if(isPalindrome(s,i,j))
        return 0;
    else{
        int temp = INT_MAX;
        for(int k=i; k<j; k++){
            temp = min(temp,recursive(s,i,k)+recursive(s,k+1,j)+1);
        }
        return temp;
    }
}

int memoized(string s, int i, int j){
    if(j-i+1 <= 1)
        return 0;
    if(isPalindrome(s,i,j))
        return 0;
    if(dp[i][j] != -1)
        return dp[i][j];
    else{
        int temp = INT_MAX;
        for(int k=i; k<j; k++){
            temp = min(temp,memoized(s,i,k)+memoized(s,k+1,j)+1);
        }
        dp[i][j] = temp;
        return temp;
    }
}

int topDown(string s){
    int n = s.length();
    int dp[n+1][n+1];
    bool P[n+1][n+1];
    memset(P,false,(n+1)*(n+1)*sizeof(P[0][0]));
    for(int i = 0; i <= n; i++){
        dp[i][i] = 0;
        P[i][i] = true;
    }
    for(int l=2; l<=n; l++)
        for(int i=1; i<=n-l+1; i++){
            int j = i+l-1;
            if(l == 2)  
                P[i][j] = (s[i-1] == s[j-1]);  
            else
                P[i][j] = (s[i-1] == s[j-1]) && P[i + 1][j - 1];
            if(P[i][j]){
                dp[i][j] = 0;
            }
            else{
                dp[i][j] = INT_MAX;
                for(int k=i; k<j; k++)
                    dp[i][j] = min(dp[i][j],1+dp[i][k]+dp[k+1][j]);
            }
        }
    return dp[1][n];
}

int main(){
    memset(dp,-1,100*100*sizeof(dp[0][0]));
    string s;
    cin>>s;
    // cout<<recursive(s,0,s.length()-1)<<endl;
    cout<<memoized(s,0,s.length()-1)<<endl;
    cout<<topDown(s)<<endl;
}