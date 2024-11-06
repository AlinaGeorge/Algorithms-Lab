#include<iostream>
#include<limits>
using namespace std;
int min(int p,int q){
	if(p<q){
		return p;
	}
	else{
		return q;
	}
}
void display(int Arr[],int n){
    for(int i=0;i<n;i++){
        cout<<Arr[i]<<" ";
    }
    cout<<endl;
}
int coinchange(int D[],int amount,int m){
	int F[amount+1];
	F[0]=0;
	for(int i=1;i<=amount;i++){
		int temp=numeric_limits<int>::max()-1;
		int j=0;
		while(j<m and i>=D[j]){
			temp=min(F[i-D[j]],temp);
			j++;
		}
		F[i]=temp+1;
	}
	cout<<"Function Array:";
	display(F,amount);
	int bal=amount;
	int cc=F[amount];
	int B[cc];
	int ind=0;
	while(bal>0){
		for(int j=0;j<m;j++){
			if(bal>=D[j] && F[bal]==F[bal-D[j]]+1){
				B[ind++]=D[j];
				bal-=D[j];
			}
		}	
	}
	cout<<"Path:";
	display(B,cc);
	return F[amount];
}
int main(){
	int den;
	cout<<"Enter the number of denominations:";
	cin>>den;
	int D[den];
	cout<<"Enter the denominations:";
	for(int i=0;i<den;i++){
		cin>>D[i];
	}
	int sum;
	cout<<"Enter the sum:";
	cin>>sum;
	int coins=coinchange(D,sum,den);
	cout<<"Number of coins:"<<coins<<endl;
	return 0;
} 
