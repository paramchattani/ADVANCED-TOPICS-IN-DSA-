#include<bits/stdc++.h>
using namespace std ;

int  a[100000];

int segmentTree[2*100000+1];

int main(){

int  dividebinary(int l ,int  r ,int  x);
int  find_max_in_given_range(int  a,int  b,int c,int d,int e );
  // for getting input from input.txt
    freopen("inputf.in", "r", stdin);
    // for writing output to output.txt
    freopen("outputf.out", "w", stdout);

int  n ; 
cin>> n ; 
for(int i=0;i<n;i++)
{
	cin>>a[i];
}


int  x=dividebinary(0,n-1,0);

for(int i=0;i<=2*n;i++)
{
	cout<<segmentTree[i]<<" ";
}

int  l,r;
cin>>l>>r ; 

//cout<<l<<r;
cout<<endl;
cout<<"max is "<<find_max_in_given_range(0,n-1,l,r,0);

}
//0 to 9 
int dividebinary(int left,int  right,int  index)
{
if(left==right)
{
	return segmentTree[index]=a[left];
}

if(left<right)
{
int  mid=(left+right)/2;//(0+9)/2 = = 4 [0 , 4] && [mid+1,right] 

return segmentTree[index]=max(dividebinary(left,mid,2*index+1),
dividebinary(mid+1,right,2*index+2));
//all things  are stored  in segmentTree; 
}

return -1 ; 
}

int  find_max_in_given_range(int startleft,int  startright,int  query_left,int  query_right,int index)
{
	//cout<<startleft<<" "<<startright<<endl;
	if(startleft<=startright)
	{
		int  mid=(startright+startleft)/2;

		if(startright<query_left) 
		{
	//		cout<<"coditom 1 apssed";
		return INT_MIN;
	}

	if(startleft>=query_left && startright<=query_right)
		{
	//	cout<<"conditom 2 passed";
		//	cout<<segmentTree[index]<<" ";
			return segmentTree[index];
		}

//0<2 && 5>2
		if((startleft<=query_left && startright>=query_left) || (startleft<=query_right && startright>=query_right))
			{
			//cout<<"condition 3 passed ";
			return max(find_max_in_given_range(startleft,mid,query_left,query_right,index*2+1),find_max_in_given_range(mid+1,startright,query_left,query_right,index*2+2));
			}
	}

	return -1;
}