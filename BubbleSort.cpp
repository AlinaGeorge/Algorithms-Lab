#include<iostream>
using namespace std;

void Swap(int A[],int i,int j){
	int t=A[j];
	A[j]=A[i];
	A[i]=t;
}
void BubSort(int A[],int UB){
	for(int i=0;i<UB;i++){
		for(int j=0;j<UB-1-i;j++){
			if(A[j]>A[j+1]){
				Swap(A,j,j+1);
			}
		}
	}
}
int main(){
	int len;
	cout<<"Enter the length of array:";
	cin>>len;
	int A[len];
	cout<<"Enter the elements one by one:"<<endl;
	for(int i=0;i<len;i++){
		cin>>A[i];
	}		
	cout<<"Bubble Sorted Array:";
	BubSort(A,len);
	for(int i=0;i<len;i++){
				cout<<A[i]<<" ";
			}
			cout<<endl;
}
