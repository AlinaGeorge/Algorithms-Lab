#include<iostream>
using namespace std;

void LinearSearch(int A[],int len,int key){
	int count=0;		
	for(int i=0;i<len;i++){
		if(A[i]==key){
			count++;
			cout<<"Element "<<key<<" found at index"<<i<<endl;
		}
	}
	if(count==0){
		cout<<"Element not found"<<endl;	
	}
}

int main(){
	int len,key;
	cout<<"Enter the length of array:";
	cin>>len;
	int A[len];
	cout<<"Enter the elements one by one:"<<endl;
	for(int i=0;i<len;i++){
		cin>>A[i];
	}
	cout<<"Enter the key to search:";
	cin>>key;
	LinearSearch(A,len,key);
	return 0;
}
