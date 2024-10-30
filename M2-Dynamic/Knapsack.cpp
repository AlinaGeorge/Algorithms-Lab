#include<iostream>
using namespace std;

int Max(int a,int b){
	if(a>b){
		 return a;
	}
	else{
		return b;
	}
}
void display(int Arr[5][6],int n,int m){
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			cout<<Arr[i][j]<<" ";
		}
		cout<<endl;
	}
	cout<<endl;
}


int Knapsack(int W[],int V[]){
	int F[5][6];
	for(int i=0;i<5;i++){
		for(int j=0;j<6;j++){
			if(i==0 or j==0){
				F[i][j]=0;
			}
		}
	}
	for(int i=1;i<5;i++){
		for(int j=1;j<6;j++){
			if(j-W[i]>=0){
				F[i][j]=Max(F[i-1][j],V[i]+F[i-1][j-W[i]]);
			}
			else if(j-W[i]<0){
				F[i][j]=F[i-1][j];
			}
		}
	}
	
	display(F,5,6);
	return F[4][5];	
}

int main(){
	
	int cap=5;
	int W[5]={0,2,1,3,2};
	int V[5]={0,12,10,20,15};
	
	cout<<"The maximum number of subsequence "<<endl;
	Knapsack(W,V);
	return 0;
}	
	
	
