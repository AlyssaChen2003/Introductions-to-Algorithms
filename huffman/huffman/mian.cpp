#include<iostream>
#include<list>
#include<iomanip>
using namespace std;
int main(){
	int n;
	cin>>n;
	int *a=new int[n];
	list <int> l;
	for(int i=0;i<n;i++){
		cin>>a[i];
		l.push_front(a[i]);
	}
	double s=0;
	for(int i=0;i<n;i++){
		s+=a[i];
	}
	double sum=0;
	while(l.size()!=1){
		l.sort();
		int x=l.front();
		l.pop_front();
		int y=l.front();
		l.pop_front();
		int temp=x+y;
		sum+=temp;
		l.push_front(temp);
		l.sort();
	}
	cout<<fixed<<setprecision(2);
	cout<<sum/s;


}

