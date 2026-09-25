#include <iostream>
using namespace std;
 int main(){
 	int m,n;
 	double top=0,bottom=0,right=0,left=0;
 	double R_sum=0;
 	cout<<" enter the number of subinterval on x-axis and y-axis"<<endl;
 	cin>>m>>n;
 	double a,b,c,d;
 	cout<<" enter the starting point and endpoint of interval on x-axis"<<endl;
 	cin>>a>>b;
 	cout<<" enter the starting point and endpoint of interval on y-axis"<<endl;
 	cin>>c>>d;
 	double h=(b-a)/n;
 	double k=(d-c)/m;
 	double x[n+1];
 	double y[m+1];
 	double f[n+1][m+1];
 	for (int i=0;i<=n;i++){
 		x[i]=a+i*h;
	 }
	 for (int i=0;i<=n;i++){
 		cout<<x[i]<<" ";}
 	for (int i=0;i<=m;i++){
 		y[i]=c+i*k;}
 	for (int i=0;i<=m;i++){
 		cout<<y[i]<<" ";}
 	for (int i=0;i<=n;i++){
 		for(int j=0;j<=m;j++){
 			f[i][j]=1.0/(x[i]+y[j])
		 ;}
	 }
	 double corner_sum=(f[0][1]+f[0][m]+f[n][0]+f[n][m]);
	 for (int i=1;i<m;i++){
	 	 top+=f[0][i];
	 	 bottom+=f[n][i];
	 }
	 for(int i=1;i<n;i++){
	 	 left+=f[i][0];
	 	 right+=f[i][m];
	 }
	 for (int i=1;i<n;i++){
	 	for (int j=1;j<m;j++){
	 		R_sum+=f[i][j];
		 }
	 }
	 double final_integral=(h*k)/4(corner_sum+2*(top+bottom+right+left)+4*R_sum)
}
 		
 		
 	
