// https://cses.fi/problemset/task/1750

#include <bits/stdc++.h>
using namespace std;
#define endl '\n'

vector<int> original;
vector<vector<int>> bl;

int query(int de, int quant){
    int resp = de;
    for(int i = 0 ; i < 31 ; i++){
        if(quant & (1 << i)){
            resp = bl[resp][i];
        }
    }

    return resp;
}

__int32_t main(){

    ios::sync_with_stdio(false); cin.tie(nullptr);
    
    int tam, consul; cin>>tam>>consul;

    bl.assign(tam+1, vector<int>(31));
    original.resize(tam+1);

    for(int i = 1 ; i <= tam ; i++){
        cin>>original[i];
        bl[i][0] = original[i];
    }

    for(int w = 1 ; w < 31 ; w++){
        for(int i = 1 ; i <= tam ; i++){
            bl[i][w] = bl[ bl[i][w-1] ][w-1];
        }
    }

    for(int i = 0 ; i < consul ; i++){        
        int de, quant; cin>>de>>quant;
        cout<<query(de, quant)<<endl;
    }

    return 0;
}
