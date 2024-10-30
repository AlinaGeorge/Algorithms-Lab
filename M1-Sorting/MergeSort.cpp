#include<iostream>
#include<cstring>
#include<limits>
using namespace std;

void Merge(int A[],int LB,int mid,int UB){
	int n1=mid-LB+1;
	int n2=UB-mid;	
	int L[n1+1];
	int R[n2+1];
	memcpy(L,&A[LB],n1*sizeof(int));
    memcpy(R,&A[mid+1],n2*sizeof(int));
    L[n1]=R[n2]=numeric_limits<int>::max();
    int i=0;
    int j=0;
    int k=LB;
    for (k=LB;k<=UB;k++){
    	if (L[i]<R[j]){
    		A[k]=L[i];
    		i=i+1;
		}
		else{
			A[k]=R[j];
			j=j+1;
		}
	}

}

void Merge_Sort(int A[],int LB,int UB){
	if (LB<UB){
		int M=(LB+UB)/2;
		Merge_Sort(A,LB,M);
		Merge_Sort(A,M+1,UB);
		Merge(A,LB,M,UB);
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
	cout<<"Merge Sorted Array:";
	Merge_Sort(A,0,len);
	for(int i=0;i<len;i++){
				cout<<A[i]<<" ";
			}
			cout<<endl;
}
