#include<bits/stdc++.h>
#define int long long
using namespace std;
random_device rd;
mt19937 rg(rd()+11415461);
int n,a[1000500];
bool flag=1;
int nw,ot1,ot2;
bitset<10000500> vs;
int p[1000500];
int cnt=0;
/*
void era(){
        vs[0]=vs[1]=1;
        for(int i=2;i<=n;i++){
                if(!vs[i]){
                        p[++cnt]=i;
                        for(int j=i*i;j<=n;j+=i) vs[j]=1;
                }
        }
        cerr<<cnt<<'\n';
}
*/
int ncnt;
signed main(){
        ios::sync_with_stdio(0);
        cin.tie(0),cout.tie(0);
        cin>>n;
        ncnt=n;
        for(int i=1;i<=n;i++){
                cin>>a[i];
                if(a[i]==1) ncnt--;
                else p[++cnt]=a[i];
                if(i==1) nw=a[i];
                else{
                        nw=__gcd(nw,a[i]);
                        if(nw!=1) flag=0;
                }
        }
        cerr<<cnt<<'\n';
        for(int i=1;i<=cnt;i++) cerr<<p[i]<<" \n"[i==cnt];
        if(nw!=1) return cout<<"not coprime\n",0;
        if(cnt>78500) flag=0;
        for(int i=1;i<=cnt;i++){
                if(!flag) break;
                for(int j=2;j<=sqrt(p[i]);j++){
                        if(p[i]%j==0){
                                if(vs[j]) flag=0;
                                if(vs[p[i]/j]) flag=0;
                                vs[j]=1;
                                vs[p[i]/j]=1;
                        }
                }
        }
        if(flag) cout<<"pairwise coprime\n";
        else return cout<<"setwise coprime\n",0;
}
