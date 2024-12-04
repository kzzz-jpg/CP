#include<bits/stdc++.h>
using namespace std;
int a[100500],pos[100500];
bool comp(int x,int b){
        return a[x]<a[b];
}
signed main(){
        int n;
        cin>>n;
        for(int i=1;i<=n;i++) cin>>a[i],pos[i]=i;
        sort(pos+1,pos+1+n,comp);
        for(int i=1;i<=n;i++) cout<<pos[i]<<' ';
}
