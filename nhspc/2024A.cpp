#include<bits/stdc++.h>
using namespace std;
int l[1000500];
int ans[1000500];
int pt2[1000500];
int n,m;
struct day{
    int s,v,id;
    bool operator<(day o)const{
        if(s-v<=0) return 0;
        if(o.s-o.v<=0) return 1;
        return 1/double(s+v)+1/double(s-v)<1/double(o.s+o.v)+1/double(o.s-o.v);
    }
} s[1000500];
bool comp2(int a,int b){
    return l[a]>l[b];
}
int cnt=0;
void solve2(){
    vector<int> l(n);
    vector<int> s(m),v(m),A(m),tmp(m);
    double nw,mn=9999999;
    for(int i=0;i<n;i++) cin>>l[i];
    for(int i=0;i<m;i++) cin>>s[i];
    for(int i=0;i<m;i++){
        cin>>v[i],tmp[i]=i;
        if(s[i]-v[i]<=0) cnt++;
    }
    if(n>m-cnt){
        cout<<-1<<'\n';
        return;
    }
    do{
        nw=0;
        for(int i=0;i<n;i++){
            nw+=l[i]/double(s[tmp[i]]+v[tmp[i]]);
            nw+=l[i]/double(s[tmp[i]]-v[tmp[i]]);
        }
        if(nw<mn) mn=nw,A=tmp;
    }while(next_permutation(tmp.begin(),tmp.end()));
    for(int i=0;i<n;i++) cout<<A[i]+1<<' ';
}

signed main(){
    cin>>n>>m;
    //if(n<=10&&m<=10){
    //    solve2();
    //    return 0;
    //}
    for(int i=1;i<=n;i++) cin>>l[i],pt2[i]=i;
    for(int i=1;i<=m;i++){
        cin>>s[i].s;
        s[i].id=i;
    }
    int t;
    for(int i=1;i<=m;i++){
        cin>>s[i].v;
        if(s[i].s-s[i].v<=0)cnt++;
    }
    if(n>m-cnt){
        cout<<-1<<'\n';
        return 0;
    }
    sort(s+1,s+1+m);
    sort(pt2+1,pt2+1+n,comp2);
    for(int i=1;i<=n;i++){
        ans[pt2[i]]=s[i].id;
    }
    for(int i=1;i<=n;i++){
        cout<<ans[i]<<' ';
    }
}