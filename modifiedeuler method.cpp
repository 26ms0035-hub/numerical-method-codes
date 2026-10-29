// modified euler method
#include <iostream>
#include<cmath>
#include<iomanip>
using namespace std;
int main(){
	int n,p;
	double h;
	cout<<"enter the step size"<<endl;
	cin>>h;
	cout<<"enter the size of array x/number of predictor step"<<endl;
	cin>>n;
	cout<<"enter the size of array y "<<endl;
	cin>>n;
	cout<<"enter the number of corrector step" <<endl;
	cin>>p;
	double x[n];
	double y[n];
	x[0]=0;
	y[0]=1;
	for(int i=1;i<n;i++){
		x[i]=x[i-1]+h;
		double y_c=y[i-1]+(h)*(x[i-1]+y[i-1]);// predictor 
		for (int j=1;j<p;j++){
			double y_c=y[i-1]+(h/2)*((x[i-1]+y[i-1])+(x[i]+y_c));//corrector
		}
		y[i]=y_c;
	}
	for (int i=0;i<n;i++){
		cout<<fixed<<setprecision(8)<<y[i]<<'\n'<<endl;
	}
}
// using the function
#include<iostream>
#include<cmath>
#include<iomanip>
using namespace std;
double f(double x,double y){
	return x+y;
}
int main(){
	int n,p;
	cout<<"enter the number of predictor step";
	cin>>n;
	cout<<"enter the number of corrector step";
	cin>>p;
	double a,b;
	cout<<"enter the initial value and final value "<<endl;
	cin>>a>>b;
	double h=(b-a)/n;
	double x_0=a;
	double y_0=1;
	double y_p;
	for(int i=1;i<=n;i++){
		double x=x_0+h;
		y_p=y_0+h*f(x_0,y_0);
		
		for(int j=2;j<=p;j++){
			y_p=y_0+(h/2)*(f(x_0,y_0)+f(x,y_p));
		}
		y_0=y_p;
		cout<<y_p<<endl;
		x_0=x;
		cout<<x<<endl;
		
	}
	cout<<fixed<<setprecision(8)<<y_p<<" ";
	
	
}
