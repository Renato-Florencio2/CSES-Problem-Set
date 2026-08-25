// https://cses.fi/problemset/task/1637/

#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
const int MAX = INT_MAX;

__int32_t main(){

    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    int x; cin>>x;

    vector<int> dp(x+1, MAX); dp[x] = 0;

    for(int i = x ; i >= 0 ; i--){
        if(dp[i] == INT_MAX) continue;
        
        int atP = i;
        while(atP){
            int at = atP % 10;

            if(i - at >= 0){
                dp[i - at] = min(dp[i - at], dp[i]+1);
            }

            atP /= 10;
        }
    }

    cout<<dp[0]<<endl;

    return 0;
}
