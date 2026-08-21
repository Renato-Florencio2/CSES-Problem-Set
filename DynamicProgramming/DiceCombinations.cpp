// https://cses.fi/problemset/task/1633

#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'

__int32_t main(){

    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    int objetivo; cin>>objetivo;

    int dp[objetivo+1](0); dp[0] = 1;

    for(int i = 0 ; i <= objetivo ; i++){
        for(int d = 1 ; d <= 6 ; d++){
            if(i+d <= objetivo){
                dp[i+d] = (dp[i+d] + dp[i]) % long((1e9)+7);
            }
        }
    }

    cout<<dp[objetivo]<<endl;

    return 0;
}

