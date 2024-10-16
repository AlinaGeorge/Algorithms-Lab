#include<iostream>
#include<limits>
using namespace std;

int Min(int a,int b){
	if(a<b){
		 return a;
	}
	else{
		return b;
	}
}
void display(int Arr[],int n){
	for(int i=0;i<n;i++){
		cout<<Arr[i]<<" ";
	}
	cout<<endl;
}

int CoinChange(int n,int D[],int m){
	int F[n+1];
	F[0]=0;
	for(int i=1;i<=n;i++){
		int temp=numeric_limits<int>::max();
		int j=0;
		while(j<=m and i>=D[j]){
			temp=Min(F[i-D[j]],temp);
			j++;
		}
		F[i]=temp+1;
	}
	display(F,n);
	return F[n];
}
int main(){
	cout<<"Enter the Coin value for which change is generated:";
	int n;
	cin>>n;
	cout<<"Enter the number of denominations:";
	int m;
	cin>>m;
	int D[m];
	cout<<"Enter the denominations:"<<endl;
	for(int i=0;i<m;i++){
		cin>>D[i];
	}
	CoinChange(n,D,m);
	return 0;
}
	
	
	
