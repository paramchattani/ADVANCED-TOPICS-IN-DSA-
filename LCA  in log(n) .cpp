#include<bits/stdc++.h>
using namespace std;
vector<int> adj[100001];
int  u[100001][20];
int  level[100001];
int  visited[100001];
void  binarylift(int a,int  b);
	void dfs(int  x,int  y);
	int  makelargejumps(int  first ,int  second);
	int  findlca(int  first,int  second);
	int  findancestor(int  a ,int  b) ; 

int main()
{
    // for getting input from input.txt
    freopen("inputf.in", "r", stdin);
    // for writing output to output.txt
    freopen("outputf.out", "w", stdout);

int  n;
cin>> n; 
for(int i=0;i<n-1;i++)
{

int  a,b;
cin>>a>>b;


a--;
b--;
//cout<<a<<b;
adj[a].push_back(b);
adj[b].push_back(a);
}
cout<<endl;
int  x,y;
cin>>x>>y;
x--;
y--;
//cout<<x<<y<<"scd";
dfs(0,0);

binarylift(0,-1);

//cout<<first<<second;
cout<<"lca is "<<findlca(x,y)+1;
}

int  findlca(int first,int  second)
{
	if(level[first]<level[second])
	{
		//cout<<level[first]<<level[second];
		int  temp=first; 
		first=second;
		second =temp;

	}
	//cout<<level[first]<<level[second];
	int  ancestor=level[first]-level[second];
	//cout<<"ancestor"<<ancestor;
	int  node=findancestor(first ,ancestor);
	//now node and  secodn are at same level ; 
	//cout<<endl<<node<<second<<endl;
	int  lca =makelargejumps(node  ,second );
	return lca ; 
}
int findancestor(int  source ,int ancestor)
{
	if(source==-1 || ancestor==0 )
		return source; 
int  i=19;
	for(;i>=1;i--)
	{
		if(ancestor>=(i<<1))
			break;
	}
	if(i==0)
		return findancestor(u[source][i],ancestor-1);
	else
return findancestor(u[source][i],ancestor-(i<<1));
}

void dfs(int start ,int  l)
{
	if(visited[start]==1)
		return;
	visited[start]=1;
	level[start]=l;
	for(int i=0;i<adj[start].size();i++)
	{
		if(visited[adj[start][i]]==0)
		{
			dfs(adj[start][i],l+1);
		}
	}


}

void binarylift(int  src ,int  parent)
{

	u[src][0]=parent;
	for(int  i=1;i<20;i++)
	{
		if(u[src][i-1]!=-1)
		u[src][i]=u[u[src][i-1]][i-1];
	else
		u[src][i]=-1;
	}
	//for(int  child: adj[])
for(int i=0;i<adj[src].size();i++)
{
	if(adj[src][i]!=parent)
	{
		binarylift(adj[src][i],src); 
	}
}

}
int makelargejumps(int  first ,int  second)
{
//cout<<first<<second;
if(first==second)
	return first ;
int  i=19;
for(;i>=1;i--)
{

	if(u[first][i]!=u[second][i])
		break;
		
}
//cout<<i;
return makelargejumps(u[first][i],u[second][i]);
}