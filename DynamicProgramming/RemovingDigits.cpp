// https://cses.fi/problemset/task/1637/

#include <bits/stdc++.h>
using namespace std;
#define endl '\n'

__int32_t main(){

    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    int num; cin>>num;

    int resp = 0;
    while(num > 0){
        resp++;
        int sub = 0, numAt = num;
        for(int i = 6 ; i >= 0 ; i--){
            int pot = pow(10, i);
            int elev = numAt / pot;

            sub = max(sub, elev);
            numAt -= elev*pot;
        }
        num = num-sub;
    }

    cout<<resp<<endl;

    return 0;
}
