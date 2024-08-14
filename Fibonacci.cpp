#include<iostream>
using namespace std;

int Fib(int n){
	if(n<=1){
		return 0;
	}
	if(n==2){
		return 1;
	}
	if(n>2){
		return Fib(n-1)+Fib(n-2);
	}
	return 0;
}
int main(){
	int n;
 	cout<<"Enter the index of term to be printed:";
 	cin>>n;
 	cout<<"'n'th term is:"<<Fib(n)<<endl;
 	return 0;
 }