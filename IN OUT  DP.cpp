#include<bits/stdc++.h>
using namespace std; 

vector<int> adj[100001];
int  no_of_nodes[100001];
int  visited[100001];
int  subtree[100001];
int  in[100001];
int out[100001];
int  total;
int dfs(int x,int y);
void  dfs2(int  x,int  y);
void inDP(int  x,int  y);
int main(){
	// for getting input from input.txt
    freopen("inputf.in", "r", stdin);
    // for writing output to output.txt
    freopen("outputf.out", "w", stdout);
int  n;
cin>>n; 
for(int i=0;i<n-1;i++)
{
	int  a,b;
	
	cin>>a>>b;
	
	a--;b--;

	//adj[a].psuh_back(b);
	//adj[b].psuh_back(a);
adj[a].push_back(b);
adj[b].push_back(a);

}

total=dfs(0 ,-1);
dfs2(0,-1);

cout<<"total nodes :"<<total<<endl;

//int  total=dfs1(0,-1);
for(int i=0;i<n;i++)
{
	cout<<"distance  for all the in nodes  from "<<i+1<<":"<<in[i]<<endl;
}
cout<<endl;
for(int i=0;i<n;i++)
{

	cout<<"distance  for all the out nodes  from "<<i+1<<":"<<out[i]<<endl;
}
}

void  dfs2(int  start ,int  parent)
{
	if(parent==-1)
	{
		out[start]=0;
	}
	for(int  i=0;i<adj[start].size();i++)
	{
		if(adj[start][i]^parent)
		{
		out[adj[start][i]]=out[start]+in[start]-(in[adj[start][i]]+subtree[adj[start][i]])+total-subtree[adj[start][i]];
		dfs2(adj[start][i],start);
	}
	}
}

int  dfs(int  start,int  parent)
{ 
	
	//cout<<start+1<<" ";
	int  x=1;
for(int  i=0;i<adj[start].size();i++)
{
if(adj[start][i]^parent)
{
	x=x+dfs(adj[start][i],start);
	in[start]+=in[adj[start][i]]+subtree[adj[start][i]];

}
}
subtree[start]=x;
if(x==1)
in[start]=0;
return x;
}
