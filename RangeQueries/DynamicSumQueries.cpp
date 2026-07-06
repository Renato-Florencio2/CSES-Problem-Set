// https://cses.fi/problemset/task/1648

#include <bits/stdc++.h>
using namespace std;
#define int long long

int tamanho, casos;
vector<int> origin, bit;

int lowbit(int i){
    return i&-i;
}

void update(int i, int x){
    while(i <= tamanho){
        bit[i]+=x;
        i+=lowbit(i);
    }
}

int query(int i){
    int sum = 0;
    while(i){
        sum+=bit[i];
        i-=lowbit(i);
    }
    return sum;
}

int sum(int l, int r){
    return query(r) - query(l-1);
}

__int32_t main(){

    ios::sync_with_stdio(false); cin.tie(nullptr);
    string resp = "";

    cin>>tamanho>>casos;
    
    origin.resize(tamanho+1), bit.assign(tamanho+1, 0);
    for(int i = 1 ; i <= tamanho ; i++){
        cin>>origin[i];
        update(i, origin[i]);
    }

    for(int caso = 0 ; caso < casos ; caso++){
        int op; cin>>op;
        if(op == 1){
            int i, x; cin>>i>>x;
            update(i, x-origin[i]);
            origin[i]=x;;
        } else {
            int l, r; cin>>l>>r;
            resp+=to_string(sum(l, r))+'\n';
        }
    }

    cout<<resp;

    return 0;
}
