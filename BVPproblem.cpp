#include<iostream>
#include<cmath>
#include<vector>
#include<iomanip>
using namespace std;
double P(double x){
	return 0.0;
}
double Q(double x){
	return 0.0;
}
double R(double x ){
	return -2;
}
int main(){
	int n;
	cout<<"enter the number of subinterval";
	cin>>n;
	double x_right=1;
	double  x_left=0;
	double  y_bottom=0;
	double y_top=0;
	double h=(x_left-x_right)/n;
	int m=n-1;
	vector<double>A(m);
	vector<double>B(m);
	vector<double>C(m);
	vector<double>D(m);
	
	for (int j=0;j<m;j++){
	// interior grid index
		int i=j+1;
		double x=x_left+i*h;
		double Pi=P(x);
		double Qi=Q(x);
		double Ri=R(x);
		//finite difference coefficient 
		A[j]=1-((h*Pi)/2.0);
		B[j]=(-2.0)+h*h*Qi;
		C[j]=1.0+(h*Pi)/2;
		D[j]=h*h*Ri;}
		
		// applying boundary condition
		// left boundary condition 
		D[0]=D[0]-A[0]*y_bottom;
		// right boundary condition
		D[m-1]=D[m-1]-C[m-1]*y_top;
		A[0]=0.0;
		C[m-1]=0.0;
		// applying thomas algorithm
		for(int j=1;j<m;j++){
		double factor=A[j]/B[j-1];
		B[j]=B[j]-factor*C[j-1];
		D[j]=D[j]-factor*D[j-1];	
		}
		//back substitution
		vector<double>y(n+1);
		y[0]=y_bottom;
		y[n]=y_top;
		y[n-1]=D[m-1]/B[m-1];
		for(int j=m-2;j>=0;j--){
			int i=j+1;
			y[i]=(D[j]-C[j]*y[i+1])/B[j];
		}
	//	cout<<"\n-------\n"<<endl;
		cout<<setw(10)<<"x"<<setw(15)<<"y(x)"<<endl;
	//	cout<<"------\n"<<endl;
		for(int i=0;i<=n;i++){
			double x=x_left+i*h;
			cout<<setw(10)<<fixed<<setprecision(4)<<x<<setw(15)<<fixed<<setprecision(6)<<y[i]<<endl;
		}
		return 0;
	
	
}

