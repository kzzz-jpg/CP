#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,m,s;
    cin>>n>>m>>s;
    bitset<200001> bs;
    int t,sum=0;
    bs[0]=1;
    for(int i=0;i<n;i++){
        cin>>t;
        sum+=t;
        bs|=bs<<t;
    }
    s-=m-sum;
    for(int i=s;i<200000;i++){
        if(bs[i]){
            cout<<i<<endl;
            break;
        }
    }
    return 0;
}