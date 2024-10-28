#include<iostream>
using namespace std;

int Min(int a,int b,int c){
	if(a<b and a<c){
		 return a;
	}
	else if (b<a and b<c){
		return b;
	}
	//if (c<a and c<b){
	else{
		return c;
	}
	//return 0;
}
void display(int Arr[4][3],int n,int m){
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			cout<<Arr[i][j]<<" ";
		}
		cout<<endl;
	}
	cout<<endl;
}
int CCollect(int C[4][3]){
	int F[4][3]={0};
	F[0][0]=C[0][0];
	for(int i=1;i<4;i++){
		F[i][0]=F[i-1][0]+C[i][0];
	}
	for(int j=1;j<3;j++){
		F[0][j]=F[0][j-1]+C[0][j];
	}
	for(int i=1;i<4;i++){
		for(int j=1;j<3;j++){
			F[i][j]=Min(F[i][j-1],F[i-1][j],F[i-1][j-1])+C[i][j];
		}
	}
	display(F,4,3);
	return F[3][2];
}

int main(){
	//int C[5][6];
	/*cout<<"Enter the matrix with coin value:"<<endl;
	for(int i=0;i<5;i++){
		for(int j=0;j<6;j++){
			cin>>C[i][j];
		}
	}*/
	int C[4][3]={{3,2,8},
	{1,9,7},
	{0,5,2},
	{6,4,3}};
	//CCollect(C);
	int CC=CCollect(C);
	cout<<"The maximum number of collected coin "<<CC<<endl;
	return 0;
}	
	
	
