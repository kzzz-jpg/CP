#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MI 1<<30
int maxh=0,tot=0;
struct tre{
    int c=0,h=0;
    int l=0,r=0;
    bool alive=false;
};
void chk(int i);
void func(int n);
vector<tre> trec(1e5);
void chk(int i){
    if((trec[i].c+trec[i].h<=trec[trec[i].r].c||trec[i].c-trec[i].h>=trec[trec[i].l].c)&&trec[i].alive){
        func(i);
    }
    return;
}
void func(int n){
    tot++;
    maxh=max(trec[n].h,maxh);
    trec[trec[n].l].r=trec[n].r;
    trec[trec[n].r].l=trec[n].l;
    trec[n].alive=false;
    chk(trec[n].r);
    chk(trec[n].l);
    return;
}
signed main(){
    int N,L;
    cin>>N>>L;
    trec[0].h=MI;
    trec[N+1].h=MI;
    trec[N+1].c=L;//maybe L
    for(int i=1;i<=N;i++){
        cin>>trec[i].c;
        trec[i].l=i-1;
        trec[i].r=i+1;
        trec[i].alive=true;
    }
    for(int i=1;i<=N;i++){
        cin>>trec[i].h;
    }
    for(int i=1;i<=N;i++){
        chk(i);
    }
    cout<<tot<<endl<<maxh<<endl;
    return 0;
}