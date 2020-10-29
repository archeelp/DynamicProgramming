#include<bits/stdc++.h>
using namespace std;

int dp[100][100];

int lcsRecursive(string a, string b, int m, int n){
    if(m&&n){
        if(a[m-1] == b[n-1])
            return 1+lcsRecursive(a,b,m-1,n-1);
        return max(lcsRecursive(a,b,m-1,n),lcsRecursive(a,b,m,n-1));
    }
    return 0;
}

int lcsMemoized(string a, string b, int m, int n){
    if(!dp[m][n]){
        if(m&&n){
            if(a[m-1] == b[n-1])
                dp[m][n] = 1+lcsRecursive(a,b,m-1,n-1);
            else
                dp[m][n] = max(lcsRecursive(a,b,m-1,n),lcsRecursive(a,b,m,n-1));
        }
        else
            dp[m][n] = 0;
    }
    return dp[m][n];
}

int lcsDynamic(string a, string b){
    int m=a.length(),n=b.length();
    int dp[m+1][n+1];
    for(int i = 0; i<=m; i++)
        for(int j = 0; j<=n; j++){
            if(i&&j){
                if(a[i-1] == b[j-1])
                    dp[i][j] = 1 + dp[i-1][j-1];
                else
                    dp[i][j] = max(dp[i][j-1],dp[i-1][j]);
            }
            else
                dp[i][j] = 0;
        }
    return dp[m][n];
}

int longestCommonSubString(string a, string b){
    int m=a.length(),n=b.length();
    int dp[m+1][n+1], max_length = INT_MIN+1;
    for(int i = 0; i<=m; i++)
        for(int j = 0; j<=n; j++){
            if(i&&j){
                if(a[i-1] == b[j-1])
                    dp[i][j] = 1 + dp[i-1][j-1];
                else
                    dp[i][j] = 0;
            }
            else
                dp[i][j] = 0;
            if(dp[i][j]>max_length){
                max_length = dp[i][j];
            }
        }
    return max_length;
}

string printLCS(string a, string b){
    int m=a.length(),n=b.length();
    string ans = "";
    int dp[m+1][n+1];
    for(int i = 0; i<=m; i++)
        for(int j = 0; j<=n; j++){
            if(i&&j){
                if(a[i-1] == b[j-1])
                    dp[i][j] = 1 + dp[i-1][j-1];
                else
                    dp[i][j] = max(dp[i][j-1],dp[i-1][j]);
            }
            else
                dp[i][j] = 0;
        }
    int i = m, j = n;
    while(i&&j){
        if(a[i-1] == b[j-1]){
            ans = a[i-1] + ans;
            i--;
            j--;
        }
        else{
            if(dp[i][j-1]>=dp[i-1][j]){
                j--;
            }
            else
                i--;
        }
    }
    return ans;
}

int scs(string a, string b){
    int m=a.length(),n=b.length();
    int dp[m+1][n+1];
    for(int i = 0; i<=m; i++)
        for(int j = 0; j<=n; j++){
            if(i&&j){
                if(a[i-1] == b[j-1])
                    dp[i][j] = 1 + dp[i-1][j-1];
                else
                    dp[i][j] = max(dp[i][j-1],dp[i-1][j]);
            }
            else
                dp[i][j] = 0;
        }
    return m+n-dp[m][n];
}

string printSCS(string a, string b){
    int m=a.length(),n=b.length();
    string ans = "";
    int dp[m+1][n+1];
    for(int i = 0; i<=m; i++)
        for(int j = 0; j<=n; j++){
            if(i&&j){
                if(a[i-1] == b[j-1])
                    dp[i][j] = 1 + dp[i-1][j-1];
                else
                    dp[i][j] = max(dp[i][j-1],dp[i-1][j]);
            }
            else
                dp[i][j] = 0;
        }
    int i = m, j = n;
    while(i&&j){
        if(a[i-1] == b[j-1]){
            ans = a[i-1] + ans;
            i--;
            j--;
        }
        else{
            if(dp[i][j-1]>dp[i-1][j]){
                ans = b[j-1] + ans;
                j--;
            }
            else{
                ans = a[i-1] + ans;
                i--;
            }
        }
    }
    while(i){
        ans = a[i] + ans;
        i--;
    }
    while(j){
        ans = b[j] + ans;
        j--;
    }
    return ans;
}

void minNumberOfInsertionAndDeletionToConvert(string a, string b){
    int res = lcsDynamic(a,b);
    cout<<"Deletion "<<a.length()-res<<endl;
    cout<<"Insertion "<<b.length()-res<<endl;
    return;
}

int LPS(string a){ //LONGEST PALLINDROMIC SUBSEQUENCE
    int m=a.length();
    int dp[m+1][m+1];
    for(int i = 0; i<=m; i++)
        for(int j = 0; j<=m; j++){
            int c = m-j;
            if(i&&j){
                if(a[i-1] == a[c-1])
                    dp[i][j] = 1 + dp[i-1][j-1];
                else
                    dp[i][j] = max(dp[i][j-1],dp[i-1][j]);
            }
            else
                dp[i][j] = 0;
        }
    return dp[m][m];
}

int minimumNumberOfDeletionToMakePallindrome(string a){
    int res = LPS(a);
    return a.length()-res;
}

int minimumNumberOfInsertionToMakePallindrome(string a){
    int res = LPS(a);
    return a.length()-res;
}

int LRS(string a){ //LONGEST REPEATING SUBSEQUENCE
    int m=a.length();
    int dp[m+1][m+1];
    for(int i = 0; i<=m; i++)
        for(int j = 0; j<=m; j++){
            if(i&&j){
                if(a[i-1] == a[j-1] && i != j)
                    dp[i][j] = 1 + dp[i-1][j-1];
                else
                    dp[i][j] = max(dp[i][j-1],dp[i-1][j]);
            }
            else
                dp[i][j] = 0;
        }
    return dp[m][m];
}

bool isSubsequenceOf(string a, string b){
    int res = lcsDynamic(a,b);
    return a.length() == res;
}

int main(){
    string a, b;
    cin>>a>>b;
    cout<<lcsRecursive(a,b,a.length(),b.length())<<endl;
    cout<<lcsMemoized(a,b,a.length(),b.length())<<endl;
    cout<<lcsDynamic(a,b)<<endl;
    cout<<longestCommonSubString(a,b)<<endl;
    cout<<scs(a,b)<<endl;
    cout<<printLCS(a,b)<<endl;
    cout<<printSCS(a,b)<<endl;
    minNumberOfInsertionAndDeletionToConvert(a,b);
    cout<<LPS(a)<<endl;
    cout<<minimumNumberOfDeletionToMakePallindrome(a);
    cout<<minimumNumberOfInsertionToMakePallindrome(a);
    cout<<LRS(a)<<endl;
}