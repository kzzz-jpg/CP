#include<bits/stdc++.h>
using namespace std;
struct lk{
        int l,r,sz,v;
        lk(int L=0,int R=0,int Sz=0,int V=0):l(L),r(R),sz(Sz),v(V){}
} ln[500500];
int n,k;
string s;
int cnt=1;
signed main(){
        cin>>n>>k;
        cin>>s;
        for(int l=0,r=0;r<s.size();r++){
                if(s[r]!=s[l]) ln[cnt++]=lk(cnt-1,cnt+1,r-l,s[l]-'0');
                if(r==s.size()-1) ln[cnt++]=lk(cnt-1,0,r-l+1,s[l]-'0');
        }
        int ctz=0;
        for(int nw=1;nw;nw=ln[nw].r){

                if(ln[nw].v==1) ctz++;
                if(ctz==k-1){
                        ln[ln[nw].l].r=ln[ln[nw].r].r;
                        ln[ln[ln[nw].r].r].l=ln[nw].l;
                        ln[ln[ln[nw].r].r].r=nw;
                }
        }
}
