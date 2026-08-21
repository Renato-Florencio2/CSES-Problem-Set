// https://cses.fi/problemset/task/1687

#include <bits/stdc++.h>
using namespace std;
#define endl '\n'

int tam, quant;
vector<vector<int>> bl;

int query(int de, int para){
    int ret = de;
    for(int i = 0 ; i < 31 ; i++){
        if(para & (1 << i)){
            ret = bl[ret][i];
        }
    }
    return ret;
}

__int32_t main(){
    
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    string resp = "";

    cin>>tam>>quant;

    bl.assign(tam+1, vector<int>(31));

    bl[0][0] = 0; bl[1][0] = 0;
    for(int i = 2 ; i <= tam ; i++){
        cin>>bl[i][0];
    }

    for(int x = 0 ; x <= tam ; x++){
        for(int w = 1 ; w <= 30 ; w++){
            bl[x][w] = bl[ bl[x][w-1] ][w-1];
        }
    }

    for(int i = 0 ; i < quant ; i++){
        int ini, vezes; cin>>ini>>vezes;
        int x = query(ini, vezes);
        if(!x) resp += "-1\n";
        else resp += to_string(x) + endl;
    }

    cout<<resp;

    return 0;
}
