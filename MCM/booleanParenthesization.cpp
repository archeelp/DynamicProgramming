#include<bits/stdc++.h>
using namespace std;

int dp[100][100][2];

bool toBool(char a){
    if(a == 'T')
        return true;
    return false;
}

int recursive(string s, int i, int j, bool equalTo){
    if(i==j){
        return toBool(s[i-1]) == equalTo;
    }
    else{
        int ans = 0;
        for(int k=i+1; k<j; k+=2){
            int lt = recursive(s,i,k-1,true);
            int rt = recursive(s,k+1,j,true);
            int lf = recursive(s,i,k-1,false);
            int rf = recursive(s,k+1,j,false);
            switch(s[k-1]){
                case '&':{
                    if(equalTo){
                        ans += lt*rt;
                    }
                    else ans += lf*rf + lt*rf +lf*rt;
                    break;
                }
                case '|':{
                    if(equalTo){
                        ans += lt*rt + lt*rf + lf*rf;
                    }
                    else ans += lf*rf;
                    break;
                }  
                case '^':{
                    if(equalTo){
                        ans += lt*rf + lf*rt;
                    }
                    else ans += lf*rf + lt*rt;
                    break;
                }
            }
        }
        return ans;
    }
}

int memoized(string s, int i, int j, bool equalTo){
    if(dp[i][j][equalTo] == -1){
        if(i==j){
            dp[i][j][equalTo] = toBool(s[i-1]) == equalTo;
        }
        else{
            int ans = 0;
            for(int k=i+1; k<j; k+=2){
                int lt = memoized(s,i,k-1,true);
                int rt = memoized(s,k+1,j,true);
                int lf = memoized(s,i,k-1,false);
                int rf = memoized(s,k+1,j,false);
                switch(s[k-1]){
                    case '&':{
                        if(equalTo){
                            ans += lt*rt;
                        }
                        else ans += lf*rf + lt*rf +lf*rt;
                        break;
                    }
                    case '|':{
                        if(equalTo){
                            ans += lt*rt + lt*rf + lf*rf;
                        }
                        else ans += lf*rf;
                        break;
                    }  
                    case '^':{
                        if(equalTo){
                            ans += lt*rf + lf*rt;
                        }
                        else ans += lf*rf + lt*rt;
                        break;
                    }
                }
            }
            dp[i][j][equalTo] = ans;
        }
    }
    return dp[i][j][equalTo];
}

int topDown(string s){
    int n = 1+s.length()/2;
    int F[n][n],T[n][n];
    for(int i = 1; i < s.length()+1; i+=2) {
        T[i/2][i/2] = s[i-1] == 'T' ? 1 : 0;
        F[i/2][i/2] = s[i-1] == 'F' ? 1 : 0;
    }
    for(int l=3; l<s.length()+1; l+=2){
        for(int i=0; i<s.length()-l+1; i+=2){
            int j = i+l-1;
            T[i/2][j/2] = 0;
            F[i/2][j/2] = 0;
            for(int k=i+1; k<j; k+=2){
                int ik = T[i/2][k/2] + F[i/2][k/2];
                int kj = T[k/2+1][j/2] + F[k/2+1][j/2];
                switch(s[k]){
                    case '&':{
                        T[i/2][j/2] += T[i/2][k/2]*T[k/2+1][j/2];
                        F[i/2][j/2] += ik*kj - T[i/2][k/2]*T[k/2+1][j/2];
                        break;
                    }
                    case '|':{
                        T[i/2][j/2] += ik*kj-F[i/2][k/2]*F[k/2+1][j/2];
                        F[i/2][j/2] += F[i/2][k/2]*F[k/2+1][j/2];
                        break;
                    }
                    case '^':{
                        T[i/2][j/2] += ik*kj - (T[i/2][k/2]*T[k/2+1][j/2] + F[i/2][k/2]*F[k/2+1][j/2]);
                        F[i/2][j/2] += T[i/2][k/2]*T[k/2+1][j/2] + F[i/2][k/2]*F[k/2+1][j/2];
                        break;
                    }
                }
            }
        }
    }
    return T[0][n-1];
}

int main(){
    memset(dp,-1,100*100*2*sizeof(dp[0][0][0]));
    string s;
    cin>>s;
    cout<<recursive(s,1,s.length(),true)<<endl;
    cout<<memoized(s,1,s.length(),true)<<endl;
    cout<<topDown(s)<<endl;
}