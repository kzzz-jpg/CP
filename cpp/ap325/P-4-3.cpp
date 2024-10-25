#include<bits/stdc++.h>
using namespace std;
void ChungAlwaysAC(){
    long long n;
    cin>>n;
    priority_queue<long long> a;
    for(int i=0;i<n;i++){
        int t;
        cin>>t;
        a.push(t);
    }
    long long total=0;
    for(int i=1;i<=n;i++){
        total+=a.top()*i;
        a.pop();
    }
    cout<<total<<endl;
}
int main(){
    ChungAlwaysAC();
    return 0;
}