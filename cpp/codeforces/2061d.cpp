#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,x;
void print(multiset<int> &a){
    for(auto c:a) cout<<c<<' ';
    cout<<'\n';
}
void solve(){
    cin>>n>>m;
    multiset<int> a,b;
    for(int i=1;i<=n;i++) {
        cin>>x;
        a.insert(x);
    }
    for(int i=1;i<=m;i++){
        cin>>x;
        b.insert(x);
    }
    while(b.size()){
        print(a);
        print(b);
        if(a.size()==0){
            cout<<"no\n";
            return;
        }
        cerr<<*a.find(*b.begin())<<'\n';
        if(a.find(*b.begin())!=a.end()){
            a.erase(a.find(*b.begin()));
            b.erase(b.begin());
            continue;
        }
        if(a.size()<=1||*next(a.begin())-*a.begin()>1){
            cout<<"no\n";
            return;
        }
        a.insert(*a.begin()+*next(a.begin()));
        a.erase(a.begin());
        a.erase(a.begin());
    }
    if(a.size()) cout<<"no\n";
    else cout<<"yes\n";
}
signed main(){
    int t=1;
    cin>>t;
    while(t--) solve();
}

/*

1 1 1 1 1 1 2 2 2 2 2 2 3 3 3 3 5 10 
1 2 5 5 6 7 9 10 
1 1 1 1 1 2 2 2 2 2 2 3 3 3 3 5 10 
2 5 5 6 7 9 10 
1 1 1 1 1 2 2 2 2 2 3 3 3 3 5 10 
5 5 6 7 9 10 
1 1 1 1 1 2 2 2 2 2 3 3 3 3 10 
5 6 7 9 10 
1 1 1 2 2 2 2 2 2 3 3 3 3 10 
5 6 7 9 10 
1 2 2 2 2 2 2 2 3 3 3 3 10 
5 6 7 9 10 
2 2 2 2 2 2 3 3 3 3 3 10 
5 6 7 9 10 
2 2 2 2 3 3 3 3 3 4 10 
5 6 7 9 10 
2 2 3 3 3 3 3 4 4 10 
5 6 7 9 10 
3 3 3 3 3 4 4 4 10 
5 6 7 9 10 
3 3 3 4 4 4 6 10 
5 6 7 9 10 
3 4 4 4 6 6 10 
5 6 7 9 10 
4 4 6 6 7 10 
5 6 7 9 10 
6 6 7 8 10 
5 6 7 9 10 
7 8 10 12 
5 6 7 9 10 
10 12 15 
5 6 7 9 10 
no


*/