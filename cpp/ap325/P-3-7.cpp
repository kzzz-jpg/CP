#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MI 1<<30
signed main(){
    int n,K;
    cin>>n>>K;
    vector<int> a(n);
    for(int i=0;i<n;i++) cin>>a[i];
    int l=0,r=0;
    int maxk=a[0],tot=1;
    int now=a[0];
    while(1){
        while(((now>K)||r==n)&&(r>l)){
            now-=a[l];
            l++;
            if(maxk<now&&now<=K) {
                maxk=now;
                tot=1;
            }
            else if(maxk==now) tot++;
        }
        r++;
        now+=a[r];
        if(maxk<now&&now<=K) {
            maxk=now;
            tot=1;
        }
        else if(maxk==now) tot++;
        if(l==n) break;
    }
    cout<<maxk<<endl<<tot<<endl;
    return 0;
}