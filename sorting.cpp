//headerfile//////////////
#include <bits/stdc++.h>
//define///////////////////
#define S(x) scanf("%d",&x)
#define P(x) printf("%d\n",x)
#define szo(x) ((int)sizeof(x))
#define szs(x) ((int)(x).size())
#define S2(x,y) scanf("%d%d",&x,&y)
#define loop(i,a,b) for(int i = a; i < b; i++)
#define revloop(i,a,n) for (int i=n-1;i>=a;i--)
#define pi 3.14159265358979323846264338327950288419716939937510582097494459230781640
//////typedef//////////
typedef long long int ll;
typedef unsigned long long int ull;
const ll mod=1000000007;
const int INF = 1000000000;
using namespace std;
//////functions////////
ull pow2(ull s) {if(s!=0 && (s & (s-1)))return 0;else return 1;}
ull powany(ll a,ll b) {ull res=1;a%=mod;for(;b;b>>=1){if(b&1)res=res*a%mod;a=a*a%mod;}return res;}
ull prime(ull n) {if (n<=1)return 0;if(n<=3)return 1;if(n%2==0||n%3==0)return 0;for(ull i=5;i*i<=n;i+=6)if(n%(i)==0||n%(i+2)==0)return 0;return 1;}
//head//////////////////
int ar[10000];
void bubble_sorting(int ar[],int n)
{
	for(int i=n-1;i>=0;i--)
	{int maxi=ar[i];int k=i;
		for(int j=0;j<=i;j++)
		{
            if (maxi<ar[j])
            {
            	k=j;
            	maxi=ar[j];
            }
		}
		int temp=ar[k];
		ar[k]=ar[i];
		ar[i]=temp;
	}
}
void shell_sort(int ar[],int n){
	int k = n/2 ;
	for( ;k >= 1 ;k /= 2){
		for(int i = k; i < n ;i++){
			int j = i - k ;
			int maxi = ar[i] ;
			for( ;j >= 0 && ar[j] > maxi ;j -= k){
				ar[j + k] = ar[j] ;
			}
			ar[j + k] = maxi ;
		}
	}
	for(int i = 0 ;i < n ;i++){
        cout << ar[i] << " " ;
	}
}
void insertion_sorting(int ar[],int n)
{
	for(int i=1;i<n;i++)
	{
		int k=ar[i];int j=i-1;
		for(;j>=0 && ar[j]>k;j--)
		{
           ar[j+1]=ar[j];
		}
		ar[j+1]=k;
	}
}
void selection_sorting(int ar[],int n)
{
	for(int i=0;i<n;i++)
	{
		int mini=ar[i];int k=i;
        for(int j=i;j<n;j++)
        {
        	if (ar[j]<mini)
        	{
        		k=j;
        		mini=ar[j];
        	}
        }
        int temp=ar[k];
        ar[k]=ar[i];
        ar[i]=temp;
	}
}
int partition(int ar[],int l,int u)
{
	int i=l;
	int v=ar[i];
	int j=u+1;
	do
	{
		do
		{
			i++;
		}while(ar[i]<v && i<=u);
		do
		{
			j--;
		}while(ar[j]>v);
		if (i<j)
		{
			int temp=ar[i];
			ar[i]=ar[j];
			ar[j]=temp;
		}
	}while(i<j);
      ar[l]=ar[j];
      ar[j]=v;
      return(j);

}
void quick_sorting(int ar[],int l,int u)
{
	if (l<u)
	{
	  int j=partition(ar,l,u);
      quick_sorting(ar,l,j-1);
      quick_sorting(ar,j+1,u);
	}
}
void merge(int ar[],int l,int m,int u)
{
	int c[100000];
	int k=0;
	int i=l;
	int j=m+1;
	while(i<=m && j<=u)
	{
        if (ar[i]<ar[j])
        {
        	c[k]=ar[i];
        	k++;
        	i++;
        }
        else
        {
        	c[k]=ar[j];
        	k++;
        	j++;
        }
	}
	while(i<=m)
	{
		c[k]=ar[i];
		k++;
		i++;
	}
	while(j<=u)
	{
		c[k]=ar[j];
		k++;
		j++;
	}
	for(i=l,j=0;i<=u;i++,j++)
	{
		ar[i]=c[j];
	}
}
int merge_sorting(int ar[],int l,int u)
{
   if (l<u)
   {
   	int k=(l+u)/2;
   	 merge_sorting(ar,l,k);
   	 merge_sorting(ar,k+1,u);
   	 merge(ar,l,k,u);
   }
}
//	RADIX SORT STARTS......................
void count_sort(int ar[],int n,int k) {
    int o[n+1];
    int c[10]={0};

    for(int i=0;i<n;i++) {
        c[(ar[i]/k)%10]++;
    }
    for(int i=1;i<10;i++) {
        c[i]+=c[i-1];
    }
    for(int i=n-1;i>=0;i--) {
        o[c[(ar[i]/k)%10]-1]=ar[i];
        c[(ar[i]/k)%10]--;
    }
    for(int i=0;i<n;i++)
        ar[i]=o[i];
}

void radix_sort(int ar[],int n) {
    int max=0;
    for(int i=0;i<n;i++) {
        if(ar[i]>max)
            max=ar[i];
    }
    	for (int i= 1; max/i > 0; i*= 10)
		count_sort(ar, n, i);

}

//	RADIX SORT ENDS....................

int main(){
	ios_base::sync_with_stdio(0);
int n;cin>>n;
for (int i = 0; i < n; ++i)
{
	int a;
	cin>>a;
	ar[i]=a;
}
//insertion_sorting(ar,n);
//bubble_sorting(ar,n);
//selection_sorting(ar,n);
//quick_sorting(ar,0,n-1);
//merge_sorting(ar,0,n-1);
//radix_sort(ar,n);
for (int i = 0; i < n; ++i)
{
	cout<<ar[i]<<" ";
}
return 0;
}
