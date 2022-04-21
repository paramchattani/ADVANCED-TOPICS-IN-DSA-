#include<bits/stdc++.h>
using namespace std  ;  
int  a[100005] ; int  seg[4*100005] ;
int solveQuery(int l ,int  r ,int  low ,int high , int  index )
{
	if(high< l ||  r< low)
		return  0;
	if(l<=low && r>=high)
	return seg[index] ; 

int  mid = ( low+high ) /2; 
	return solveQuery(l,r,low,mid,2*index + 1 ) + solveQuery(l,r,mid+1,high,2*index +2 );   
}

void  pointUpdate(int  up , int  toAdd , int  low ,int high  , int  index )
{
	if(low==high)
	{
		seg[index] = seg[index] +toAdd ;
		a[up]=a[up]+toAdd;
	}
else
{
int  mid=(low+high)/2 ;  
if(up<=mid && up>=low)
{
pointUpdate(up,toAdd,low,mid,2*index+1);
}
else
{
pointUpdate(up,toAdd,mid+1,high,2*index +2)  ; 
}
seg[index]=seg[2*index+1] + seg[2*index +2];
}

}

void  buildTree(int  index,  int low  ,int  high)
{
	if(low==high)
	{
		seg[index]= a[low] ;  
		return ;  
	}
	int  mid = ( low + high )  /2 ;
	buildTree(2*index + 1 ,low  ,mid) ;   
	buildTree(2*index + 2 , mid+1 , high ) ;  
	seg[index]=seg[2*index + 1 ] + seg[2*index + 2]  ;  

} 
int  main()
{
	freopen("inputf.in", "r", stdin);
   
	freopen("outputf.out", "w", stdout);
	int  n ;  
	cin>> n ; 
	for(int  i = 0 ;i< n;i++)
	{
		cin>>a[i] ;  
	}
	buildTree(0,0,n-1); 

int l ; int  r;    
cin>> l>> r;    

	int  p =solveQuery(l , r , 0  , n-1 , 0 ) ; 

cout<< p  ; 

int indexToUpdate  ;  
cin>>indexToUpdate;
int  byWhat ;  
cin>> byWhat  ; 
pointUpdate(indexToUpdate ,  byWhat, 0 , n-1 ,  0) ;
int  q=solveQuery(l , r , 0 ,n-1,0);  
cout<<q;
}