#include<bits/stdc++.h>
using namespace std;
int n;
signed main(){
    cin>>n;
    if(n>=90) cout<<"expert"<<'\n';
    else if(n>=70) cout<<90-n<<'\n';
    else if(n>=40) cout<<70-n<<'\n';
    else cout<<40-n<<'\n';
}