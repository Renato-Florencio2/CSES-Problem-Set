// https://cses.fi/problemset/task/1750

#include <bits/stdc++.h>
using namespace std;
#define endl '\n'

vector<vector<int>> bl;
int Log = 0, k = 1e9;
void defineLog(){
    while((1 << Log) <= k) Log++;
}

int consulta(int ini, int quant){
    int resp = ini;
    for(int j = 0 ; j < Log ; j++){
        if(quant & (1 << j)){
            resp = bl[resp][j];
        }
    }
    return resp;
}

__int32_t main(){

    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    int planetas, consultas; cin>>planetas>>consultas;

    defineLog();
    bl.assign(planetas+1, vector<int>(Log));

    for(int i = 1 ; i <= planetas ; i++){
        int n; cin>>n;
        bl[i][0] = n;
    }

    for(int y = 1 ; y < Log ; y++){
        for(int x = 1 ; x <= planetas ; x++){
            bl[x][y] = bl[bl[x][y-1]][y-1];
        }
    }

    for(int i = 0 ; i < consultas ; i++){
        int n1, n2; cin>>n1>>n2;
        cout<<consulta(n1, n2)<<endl;
    }

    return 0;
}
