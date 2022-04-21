#include<bits/stdc++.h>
using namespace std;
int a[1000005] ;  int seg[4*1000005]; 

int solvequery(int  l ,int r , int low  ,int high,int  index ) 
{
if(l<=low  && r >= high)//
{
	return seg[index];
}

if(r<low || high<l)
return INT_MIN;


	int mid=(low+high)/2; 
	int  x =solvequery(l,r,low,mid,2*index+1);
	int y  =solvequery(l,r,mid+1,high,2*index+2) ;  
	return max(x,y);

}   

void buildmaxsegtree(int  index ,int  low  ,int high)
{
	if(low==high)
	{
		seg[index]=a[low]; 
		return;  
	}
	int  mid =(low + high) /2 ;  
	buildmaxsegtree(2*index + 1,low,mid);
	buildmaxsegtree(2*index + 2 , mid+1 , high) ;   
	//backtrack
	seg[index]=max(seg[2*index + 1],seg[2*index + 2])  ; 
}
int main()
{
	freopen("inputf.in","r",stdin); //can need to change file . this one for taking input
freopen("outputf.out","w",stdout);
int n ;  
cin>>n ;    
for(int i = 0 ;i< n;i++)
{
	cin>>a[i] ; 
}

buildmaxsegtree(0,0,n-1);

int  l,r;  
cin>> l>> r   ; 

//find  maximum int the range  l to  r   ;   
//now  three case arise  
// the  range  overlaps  partially or fully ;   // we go down  in both the directions  
// the  range do not overlap at all //we  return  
// the  range is  superset of the  seg set  // we  do not  go more down as  it  has  already the  maximum    ;   
int  p =  solvequery(l,r,0,n-1,0);
cout<<p;

  
}