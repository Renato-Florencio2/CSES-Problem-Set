// https://cses.fi/problemset/task/1164

#include <bits/stdc++.h>
using namespace std;
#define int long long

int idP = 0;
int defineId(){
    idP++;
    return idP;
}

struct alo{
    int pri;
    int tipo;
    int id;

    bool operator<(const alo &other) const {
        if(pri != other.pri) return pri < other.pri;
        else if(tipo != other.tipo) return tipo < other.tipo;
        return id < other.id;
    }
};

map<int, int> resp;
vector<alo> sweep;
map<int, int> usando;

__int32_t main(){

    ios::sync_with_stdio(false); cin.tie(nullptr);

    int casos; cin>>casos;
    for(int i = 0 ; i < casos ; i++){
        int ini, fim; cin>>ini>>fim;
        int idAt = defineId();
        sweep.push_back({ini, 1, idAt});
        sweep.push_back({fim, 2, idAt});
    }

    sort(sweep.begin(), sweep.end());

    int quartoM = 0;
    queue<int> quartosD;

    int maior = 0, at = 0;
    for(auto i:sweep){
        if(i.tipo == 1){
            if(!quartosD.empty()){
                usando[i.id] = quartosD.front();
                resp[i.id] = quartosD.front();
                quartosD.pop();
            } else {
                quartoM++;
                usando[i.id] = quartoM;
                resp[i.id] = quartoM;
            }

            at++;
        } else {
            quartosD.push(usando[i.id]);

            at--;
        }

        maior = max(maior, at);
    }

    cout<<maior<<'\n';
    for(auto i:resp) cout<<i.second<<' ';
    cout<<'\n';

    return 0;
}
