//Q.double integral by simpson 3/8 rule
#include <iostream>
using namespace std;
int main(){
	int n,m;
	double a,b,c,d;
	cout<<" enter the number of subdivision on x axis"<<endl;
	cin>>n;
	cout<<"enter the number of subdivision on y axis "<<endl;
	cin>>m;
	if (n%3!=0 || m%3!=0){
		cout<<"integral is not possible";
		return 0;
	}
	cout<<"enter the starting and endpoint on x axis"<<endl;
	cin>>a>>b;
	cout<<"enter the starting and endpoint on y axis"<<endl;
	cin>>c>>d;
	double h=(b-a)/n;
	double k=(d-c)/m;
	double x[n+1];
	double y[m+1];
	double f[n+1][m+1];
	double sum=0;
	for (int i=0;i<=n;i++){
		x[i]=a+h*i;
	}
	for (int i=0;i<=m;i++){
		y[i]=c+k*i;
	}
	for (int i=0;i<=n;i++){
		int w1;
		if(i==0 || i==n){
			w1=1;
		}
		else if(i%3!=0){
			w1=3;
		}
		else{w1=2;
		}
		for(int j=0;j<=m;j++){
			int w2;
			if(j==0 || j==m){w2=1;
			}
			else if (j%3!=0){w2=3;
			}
			else{w2=2;
			}
			int weight=w1*w2;
			sum+=weight*(x[i]*x[i]+y[j]*y[j]);
		}
		
	}
	double integral=(9*h*k/64)*(sum);
	cout<<integral;
}
