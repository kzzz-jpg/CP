#include <bits/stdc++.h>
using namespace std;
int n;
vector<string> ptr(1002);
bool visited[1002][1002];
vector<vector<int>> road;
int dx[]={-1,1,0,0};
int dy[]={0,0,-1,1};
bool dfs(int x,int y,int endx,int endy){
    if(x<0 or x>=n or y<0 or y>=n or ptr[x][y]=='#' or visited[x][y])
        return false;
    visited[x][y]=true;
    road.push_back({x,y});
    if(x==endx and y==endy)
        return true;
    for(int i=0;i<4;i++){
        int nx=x+dx[i],ny=y+dy[i];
        if(dfs(nx,ny,endx,endy))
            return true;
    }
    road.pop_back();
    return false;
}
int main(){
    int homex,homey,endx,endy;
    cin>>n;
    for(int i=0;i<n;i++)
        cin>>ptr[i];
    cin>>homex>>homey;
    int t;
    cin>>t;
    for(int i=0;i<t;i++){
    int maxx;
    cin>>endx>>endy>>maxx;;
    memset(visited,false,sizeof(visited));
    road.clear();
    dfs(homex,homey,endx,endy);
    int totalroad=road.size()-1;
    if(totalroad<=maxx){
        cout<<"I like to move it move it\n";
        int stop=min(totalroad, max(0,maxx-totalroad));
        cout<<road[totalroad-stop][0]<<" "<<road[totalroad-stop][1];
    }
    else{
         cout<<"Too tired\n";
         cout<<road[maxx][0]<<" "<<road[maxx][1];
    }
    if(i!=t-1){
        cout<<endl;
    }
    }

}