#include <bits/stdc++.h>
using namespace std;
#define int long long
const int MAX = LLONG_MAX;

int vertices, arestas;

struct Edge{
    int in;
    int weight;

    bool operator>(const Edge &other) const {
        return weight > other.weight;
    }
};

struct EdgeMod{
    int in;
    int weight;
    int bigger;

    bool operator>(const EdgeMod &other) const {
        return weight > other.weight;
    }
};

vector<vector<Edge>> grafo;
vector<vector<int>> menoresCaminhos; 

void djikstra(){

    priority_queue<Edge, vector<Edge>, greater<Edge>> fp;

    fp.push({1, 0});

    while(!fp.empty()){
        Edge at = fp.top(); fp.pop();

        if(at.weight >= menoresCaminhos[0][at.in]) continue;
        else menoresCaminhos[0][at.in] = at.weight;

        for(auto i:grafo[at.in]){
            int soma = at.weight + i.weight;
            if(soma < menoresCaminhos[0][i.in]){
                fp.push({i.in, soma});
            }
        }
    }
}

void djikstraMod(){

    priority_queue<EdgeMod, vector<EdgeMod>, greater<EdgeMod>> fp;
    
    fp.push({1, 0, 0});

    while(!fp.empty()){
        EdgeMod at = fp.top(); fp.pop();

        if(at.weight >= menoresCaminhos[1][at.in]) continue;
        else menoresCaminhos[1][at.in] = at.weight;
        
        for(auto i:grafo[at.in]){
            int somaCupomAntes = at.weight + i.weight;
            int somaCupomAgora = menoresCaminhos[0][at.in] + i.weight/2;
            int soma = min(somaCupomAntes, somaCupomAgora);

            if(soma < menoresCaminhos[1][i.in]){
                fp.push({i.in, soma, max(at.bigger, i.weight)});
            }
        }
    }
}

__int32_t main(){

    ios::sync_with_stdio(false); cin.tie(nullptr);

    cin>>vertices>>arestas;

    grafo.assign(vertices+1, vector<Edge>());
    menoresCaminhos.assign(2, vector<int>(vertices+1, MAX));
    for(int i = 0 ; i < arestas ; i++){
        int n1, n2, peso; cin>>n1>>n2>>peso;
        grafo[n1].push_back({n2, peso});
    }

    djikstra();
    djikstraMod();

    cout<<menoresCaminhos[1][vertices]<<endl;

    return 0;
}
