// https://cses.fi/problemset/task/1158/

#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long

__int32_t main(){

    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    int quant, maximo; cin>>quant>>maximo;

    vector<int> preco(quant), paginas(quant);
    for(int i = 0 ; i < quant ; i++) cin>>preco[i];
    for(int i = 0 ; i < quant ; i++) cin>>paginas[i];

    vector<int> dp(maximo+1, 0);
    for(int i = 0 ; i < quant ; i++){
        for(int t = 0 ; t <= maximo ; t++){
            if(t+preco[i] <= maximo){
                dp[t] = max(dp[t], paginas[i]+dp[t+preco[i]]);
            }
        }
    }

    cout<<dp[0]<<endl;

    return 0;
}
