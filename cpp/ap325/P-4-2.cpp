#include<bits/stdc++.h>
using namespace std;
void ChungAlwaysAC(){
    int n;
    cin>>n;
    priority_queue<int> a;
    priority_queue<int> b;
    for(int i=0;i<n;i++){
        int t;
        cin>>t;
        a.push(t);
    }
    for(int i=0;i<n;i++){
        int t;
        cin>>t;
        b.push(t);
    }
    int total=0;
    while(!a.empty()){
        if(b.top()>a.top()){
            a.pop();
            b.pop();
            total++;
        }else{
            a.pop();
        }
    }
    cout<<total<<endl;
}
int main(){
    ChungAlwaysAC();
    return 0;
}