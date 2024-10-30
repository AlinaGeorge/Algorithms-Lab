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
int CCollect(int C[5][6]){
	int F[5][6]={0};
	F[0][0]=C[0][0];
	for(int i=1;i<5;i++){
		F[i][0]=F[i-1][0]+C[i][0];
	}
	for(int j=1;j<6;j++){
		F[0][j]=F[1][j-1]+C[0][j];
	}
	for(int i=1;i<5;i++){
		for(int j=1;j<6;j++){
			F[i][j]=Max(F[i][j-1],F[i-1][j])+C[i][j];
		}
	}
	display(F,5,6);
	return F[4][5];
}

int main(){
	//int C[5][6];
	/*cout<<"Enter the matrix with coin value:"<<endl;
	for(int i=0;i<5;i++){
		for(int j=0;j<6;j++){
			cin>>C[i][j];
		}
	}*/
	int C[5][6]={{0,0,0,0,1,0},
	{0,1,0,1,0,0},
	{0,0,0,1,0,1},
	{0,0,1,0,0,1},
	{1,0,0,0,1,0}};
	CCollect(C);
	int CC=CCollect(C);
	cout<<"The maximum number of collected coin "<<CC<<endl;
	return 0;
}	
	
	
