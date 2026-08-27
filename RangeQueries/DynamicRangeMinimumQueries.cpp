// https://cses.fi/problemset/task/1649

#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
const int MAX = LLONG_MAX;

int n, casos;
vector<int> st, orig;

void build(int no, int l, int r){
    if(l == r) st[no] = orig[l];
    else{
        int mid = (l+r)/2;
        
        build(no*2, l, mid);
        build(no*2+1, mid+1, r);
    
        st[no] = min(st[no*2], st[no*2+1]);
    }
}

void update(int no, int l, int r, int pos, int val){
    if(l == r) st[no] = val;
    else{
        int mid = (l+r)/2;

        if(mid >= pos) update(no*2, l, mid, pos, val);
        else update(no*2+1, mid+1, r, pos, val);

        st[no] = min(st[no*2], st[no*2+1]);
    }
}

int query(int no, int l, int r, int ql, int qr){
    if(l > qr || r < ql) return MAX;

    if(l >= ql && r <= qr) return st[no];

    int mid = (l+r)/2;
    return min(query(no*2, l, mid, ql, qr), query(no*2+1, mid+1, r, ql, qr));
}

__int32_t main(){

    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    cin>>n>>casos;

    st.resize(4*n); orig.resize(n+1);

    for(int i = 1 ; i <= n ; i++) cin>>orig[i];

    build(1, 1, n);
    for(int i = 0 ; i < casos ; i++){
        int esc, n1, n2; cin>>esc>>n1>>n2;
        if(esc == 1) update(1, 1, n, n1, n2);
        else cout<<query(1, 1, n, n1, n2)<<endl;
    }

    return 0;
}
