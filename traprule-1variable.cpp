#include <iostream>
using namespace std;
double f(double x){
	return 1/(x+1);
}
int main(){
	double a,b,h;
	int n;
	cout<<"enter the number of subinterval"<<endl;
	cin>>n;
	cout<<"enter the value of endpoint of interval";
	cin>>a>>b;
	h=(b-a)/n;
	double y[n+1];
double 	x_0=a;
	y[0]=1/f(x_0);
/*	cout<<x[0]<<endl;
	for(int i=1;i<=n;i++){
		x[i]=x[i-1]+h;
		cout<<x[i]<<" ";
	}
	cout<<endl;
	cout<<"values of function at subdivision"<<endl;
	for(int i=0;i<=n;i++){
		y[i]=1/(x[i]+1);
		cout<<y[i]<<" ";
	}
	cout<<endl;
	double end_sum=y[0]+y[n];
	cout<<end_sum<<endl;
	double int_sum=0;
	for(int i=1;i<n;i++){
		int_sum+=y[i];
		cout<<int_sum<<endl;
	}
	double integral=(h/2)*(end_sum+2*int_sum);
	cout<<"value of double integral is "<<" "<<integral<<endl;*/
	double int_sum=0;
	double x_1;
	for(int i=1;i<=n;i++){
		x_1=x_0+h;
		cout<<x_1<<endl;
		y[i]=f(x_1);
		cout<<y[i]<<endl;
		x_0=x_1;
		if(i>=1 && i<n){
		int_sum+=y[i]	;
		}
		
	}
	cout<<int_sum<<endl;
	double end_sum=y[0]+y[n];
	cout<<end_sum<<endl;
	double integral=(h/2)*(end_sum+2*int_sum);
	cout<<"value of double integral is "<<" "<<integral<<endl;
	
}
