#include<iostream>
using namespace std;

void Swap(int A[],int i,int j){
	int t=A[j];
	A[j]=A[i];
	A[i]=t;
}
void InsertionSort(int A[],int len){
	for(int i=1;i<len;i++){
		int j=i;
		while(j>0 and A[j]<A[j-1]){
			Swap(A,j,j-1);
			j--;
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
	cout<<"Insertion Sorted Array:";
	InsertionSort(A,len);
	for(int i=0;i<len;i++){
				cout<<A[i]<<" ";
			}
			cout<<endl;
}
