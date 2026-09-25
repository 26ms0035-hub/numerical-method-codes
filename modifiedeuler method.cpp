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
