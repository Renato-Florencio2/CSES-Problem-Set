// https://cses.fi/problemset/task/1646/

#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long

__int32_t main(){

    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    int n, casos; cin>>n>>casos;

    vector<int> prefixos(n+1, 0);
    for(int i = 1 ; i <= n ; i++){
        int x; cin>>x;
        prefixos[i] += prefixos[i-1] + x;
    }

    for(int i = 0 ; i < casos ; i++){
        int n1, n2; cin>>n1>>n2;
        cout<<prefixos[n2] - prefixos[n1-1]<<endl;
    }

    return 0;
}
