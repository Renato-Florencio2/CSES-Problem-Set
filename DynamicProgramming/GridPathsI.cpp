// https://cses.fi/problemset/task/1638/

#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
const int MOD = (1e9)+7;

__int32_t main(){

    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    int tam ; cin>>tam;

    vector<string> matriz(tam);
    for(int l = 0 ; l < tam ; l++){
        cin>>matriz[l];
    }

    vector<vector<int>> dp(tam, vector<int>(tam, 0)); 
    if(matriz[0][0] != '*') dp[0][0] = 1;

    for(int l = 0 ; l < tam ; l++){
        for(int r = 0 ; r < tam ; r++){
            if(matriz[l][r] == '*' || !dp[l][r]) continue;

            if(l+1 < tam && matriz[l+1][r] != '*') dp[l+1][r] = (dp[l+1][r] + dp[l][r]) % MOD;
            if(r+1 < tam && matriz[l][r+1] != '*') dp[l][r+1] = (dp[l][r+1] + dp[l][r]) % MOD;

        }
    }
    
    cout<<dp[tam-1][tam-1]<<endl;

    return 0;
}
