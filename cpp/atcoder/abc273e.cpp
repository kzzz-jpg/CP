#include<bits/stdc++.h>
using namespace std;
int q;
struct pt{
        int fa,num;
} a[500500];
map<int,pt> mp;
int cnt=1,nw=0;
map<int,int> trie[500500];
signed main(){
        ios_base::sync_with_stdio(0);
        cin>>q;
        string op;
        int x;
        a[0].num=-1;
        while(q--){
                cin>>op;
                if(op=="ADD"){
                        cin>>x;
                        if(!trie[nw][x]){
                                trie[nw][x]=cnt;
                                a[cnt]={nw,x};
                                nw=cnt++;
                        }else{
                                nw=trie[nw][x];
                        }
                }else if(op=="DELETE"){
                        nw=a[nw].fa;
                }else if(op=="SAVE"){
                        cin>>x;
                        mp[x]=a[nw];
                }else{
                        cin>>x;
                        nw=trie[mp[x].fa][mp[x].num];
                }
                cout<<a[nw].num<<' ';
        }
}
