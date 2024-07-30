#include<iostream>
using namespace std;

void heapsort(int Arr[],int n){
	for(int i=n/2;i>0;i--){
		Heapify(i,n,A);
	}
	for(i=0;i<n;i++){
		Swap(0,n-1,Arr);
		Heapify((n-i)/2,n-i,A);
	}
}
void Heapify(){
	int i=(n-2)/2;    //index of last leaf node
	if (Arr[i]<Arr[2*i+1]){
		Swap(i,2*i+1,Arr);
	}
	else if(Arr[i]<Arr[2*i+2]){
		Swap(i,2*i+2,Arr);
	}
	
	
	
}

void Swap(int i,int j,int Arr[]){
	int temp=Arr[i];
	Arr[i]=Arr[j];
	Arr[j]=temp;
}

int main(){
	
	int Arr[7]={5,2,9,4,7,3,1};
	
	
