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
void display(int Arr[8][7],int n,int m){
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			cout<<Arr[i][j]<<" ";
		}
		cout<<endl;
	}
	cout<<endl;
}


int LCS(char S1[],char S2[]){
	int C[8][7];
	for(int i=0;i<8;i++){
		for(int j=0;j<7;j++){
			if(i==0 or j==0){
				C[i][j]=0;
			}
			if(i>0 and j>0 and S1[i]==S2[j]){
				C[i][j]=C[i-1][j-1]+1;
			}
			else if(i>0 and j>0 and S1[i]!=S2[j]){
				C[i][j]=Max(C[i][j-1],C[i-1][j]);
			}
		}
	}
	
	display(C,8,7);
	return C[7][6];	
}

int main(){
	//int C[5][6];
	/*cout<<"Enter the length  with coin value:"<<endl;
	for(int i=0;i<5;i++){
		for(int j=0;j<6;j++){
			cin>>C[i][j];
		}
	}*/
	char S1[8]={' ','A','B','C','B','D','A','B'};
	char S2[7]={' ','B','D','C','A','B','A'};
	
	cout<<"The maximum number of subsequence "<<endl;
	LCS(S1,S2);
	return 0;
}	
	
	
