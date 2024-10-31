#include<bits/stdc++.h>
using namespace std;
const int N=1000010;
int n,a[N],f[N],MaxDep;
bool GotIt;
vector<int> aans;
int CheckVal(){
	int ret=0;
	for(int i=1;i<=n;i++)
		if(abs(a[i]-a[i+1])!=1)ret++;
	return ret;
}
void dfs(int step,int pre){
	int Val=CheckVal();
	if(step+Val>MaxDep)return;
	if(step>MaxDep)return;
	if(GotIt)return;
	if(Val==0){
		GotIt=1;
		printf("%d\n",step);
		for(auto x:aans) cout<<x<<' ';
		cout<<'\n';
		return;
	}
	for(int i=2;i<=n;i++)
		if(i!=pre){
			reverse(a+1,a+i+1);
			aans.push_back(i);
			dfs(step+1,i);
			aans.pop_back();
			reverse(a+1,a+i+1);
		}
}
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]),f[i]=a[i];
	sort(f+1,f+n+1);
	for(int i=1;i<=n;i++)
		a[i]=lower_bound(f+1,f+n+1,a[i])-f;//离散化 
	a[n+1]=n+1;
	for(MaxDep=0;MaxDep<=(n<<1)-2;MaxDep++){
		GotIt=0;
		dfs(0,0);
		if(GotIt)break;
	}
	return 0;
}
