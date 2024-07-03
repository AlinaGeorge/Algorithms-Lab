#include<iostream>
using namespace std;

class Array{
	public:
	int LB,UB,A[100];
	Array(int ub){
		LB=0;
		UB=ub;
		int el;
		cout<<"Enter the elements one by one:"<<endl;
		for(int i=LB;i<UB;i++){
			cin>>el;
			A[i]=el;
		}
	}
	void display(){
		for(int i=LB;i<UB;i++){
			cout<<A[i]<<" ";
		}
		cout<<endl;
	}
	void LinearSearch(int key){
		int i=LB,count=0;		
		for(int i=LB;i<UB;i++){
			if(A[i]==key){
				count++;
				cout<<"Element "<<key<<" found at "<<i<<endl;
			}
		}
		if(count==0){
			cout<<"Element not found"<<endl;
			
		}

	}
};
int main(){
	int len,key;
	cout<<"Enter the length of array:"<<endl;
	cin>>len;
	Array arr(len);
	cout<<"Provided Array:";
	arr.display();
	cout<<"Enter the key to search:";
	cin>>key;
	arr.LinearSearch(key);
	return 0;
}
