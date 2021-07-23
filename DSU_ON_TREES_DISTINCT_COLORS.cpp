#include<bits/stdc++.h>
using namespace std ;
const int mx=2e5;
vector<int> adj[mx];
int color[mx];
set<int> s[mx];
int result[mx];
int main()
{
	void  dfs(int  a,int b);
  // for getting input from input.txt
//freopen("inputf.in", "r", stdin);
    // for writing output to output.txt
  //freopen("outputf.out", "w", stdout);

int  n;
cin>> n ;
for(int i=0;i<n;i++)
	cin>>color[i];

for(int i=0;i<n-1;i++)
{
int  a,b ; 
cin>> a>> b ; 
a--;
b--;
adj[a].push_back(b);
adj[b].push_back(a);
}

dfs(0,-1);

for(int i=0;i<n;i++)
{
cout<<result[i]<<' ';
}

}


void  dfs(int src ,int p)
{

//set<int> t; 
s[src].insert(color[src]);
for(int i=0;i<adj[src].size();i++)
{

if(adj[src][i]^p)
{

	dfs(adj[src][i],src);

	if(s[src].size()<s[adj[src][i]].size())
		swap(s[src],s[adj[src][i]]);
	s[src].insert(s[adj[src][i]].begin(),s[adj[src][i]].end());
}

result[src]=s[src].size();

}


}
