// https://cses.fi/problemset/task/1636

#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
const int MOD = (1e9)+7;

__int32_t main(){

    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    int quant, valor; cin>>quant>>valor;

    vector<int> moedas(quant);
    for(int i = 0 ; i < quant ; i++) cin>>moedas[i];

    vector<int> dp(valor+1, 0); dp[0] = 1;
    for(auto m : moedas){
        for(int i = m ; i <= valor ; i++){
            dp[i] = (dp[i] + dp[i-m]) % MOD;
        }
    }

    cout<<dp[valor]<<endl;

    return 0;
}

