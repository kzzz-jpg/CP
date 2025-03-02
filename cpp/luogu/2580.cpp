#include<bits/stdc++.h>
using namespace std;
struct trie{
    int tr[1000500][26],cnt=1;
    bool vs[1000500];
    void insert(string &s){
        int nw=0;
        for(int i=0;i<s.size();i++){
            if(tr[nw][s[i]-'a']) nw=tr[nw][s[i]-'a'];
            else tr[nw][s[i]-'a']=cnt++,nw=tr[nw][s[i]-'a'];
        }
        vs[nw]=1;
    }
    bool query(string &s){
        int nw=0;
        for(int i=0;i<s.size();i++){
            if(tr[nw][s[i]-'a']) nw=tr[nw][s[i]-'a'];
            else return 0;
        }
        return vs[nw];
    }
} mp,vs;
string s;
int n,m;
signed main(){
    cin>>n;
    for(int i=1;i<=n;i++) cin>>s,mp.insert(s);
    cin>>m;
    while(m--){
        cin>>s;
        if(mp.query(s)){
            if(vs.query(s)){
                cout<<"REPEAT\n";
            }else{
                cout<<"OK\n";
                vs.insert(s);
            }
        }else{
            cout<<"WRONG\n";
        }
    }
}