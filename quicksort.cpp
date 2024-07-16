#include<iostream>
using namespace std;

void Swap(int A[],int i,int j){
	int t=A[j];
	A[j]=A[i];
	A[i]=t;
}
int partition(int A[],int lb,int len){
	int j=lb-1;
	int pivot=A[len-1];
	int i=lb;
	while(i<len){
		if(A[i]<pivot){
			j=j+1;
			Swap(A,i,j);
		}
		i=i+1;
	}
	Swap(A,j+1,len-1);
	return j+1;
}
	
void quicksort(int A[],int lb,int len){
	if(lb<len){
		int p=partition(A,lb,len);
		quicksort(A,lb,p);
		quicksort(A,p+1,len);
	}
}
	
int main(){
	int len;
	cout<<"Enter the length of the array:";
	cin>>len;
	int Arr[len];
	cout<<"Enter the elements:"<<endl;
	for(int i=0;i<len;i++){
		cin>>Arr[i];
	}
	quicksort(Arr,0,len);
	cout<<"Quick Sorted Array:";
	for(int j=0;j<len;j++){
		cout<<Arr[j]<<" ";
	}
	cout<<endl;
	return 0;
}

