#include<iostream>
using namespace std;

int binSearch(int A[],int lb,int ub,int key){
	int mid=(lb+ub)/2;
	int index=-1;
	if (A[mid]>key){
		binSearch(A,0,mid-1,key);
	}
	else if (A[mid]<key){
		binSearch(A,mid+1,ub,key);
	}
	else if(A[mid]==key){
		index=mid;
		cout<<"Element found at "<<index<<endl;
	}
	return index;
}
int main(){
	int len,key;
	cout<<"Enter the length of array:";
	cin>>len;
	int A[len];
	cout<<"Enter the elements of a sorted array to search:";
	for(int i=0;i<len;i++){
		cin>>A[i];
	}
	cout<<"Enter the element to search:";
	cin>>key;
	int result=binSearch(A,0,len,key);
	if(result==-1){
		cout<<"Element not found!"<<endl;
	}
	else{
		binSearch(A,0,len-1,key);
	}
}
	
