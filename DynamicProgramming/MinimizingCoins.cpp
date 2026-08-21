// https://cses.fi/problemset/task/1634/

#include <bits/stdc++.h>
using namespace std;
#define endl '\n'

__int32_t main(){

    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    priority_queue<int> fp;
    
    int quant, obj; cin>>quant>>obj;

    for(int i = 0 ; i < quant ; i++){
        int x; cin>>x;
        fp.push(x);
    }

    vector<int> dp(obj+1, INT_MAX); dp[0] = 0;
    while(!fp.empty()){
        int at = fp.top(); fp.pop();

        for(int i = at ; i <= obj ; i++){
            if(dp[i - at] != INT_MAX){
                dp[i] = min(dp[i], dp[i-at]+1);
            }
        }
    }

    if(dp[obj] == INT_MAX) cout<<"-1\n";
    else cout<<dp[obj]<<endl;

    return 0;
}

