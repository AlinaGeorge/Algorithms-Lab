#include<iostream>
using namespace std;

void Swap(int A[],int i,int j){
	int t=A[j];
	A[j]=A[i];
	A[i]=t;
}
void SelectionSort(int A[],int len){
	for(int i=0;i<len-1;i++){
		int min=i;
		for(int j=i+1;j<len;j++){
			if(A[j]<A[min]){
				min=j;
			}
		}
		if(min!=i){
			Swap(A,i,min);
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
	cout<<"Selection Sorted Array:";
	SelectionSort(A,len);
	for(int i=0;i<len;i++){
				cout<<A[i]<<" ";
			}
			cout<<endl;
}






















