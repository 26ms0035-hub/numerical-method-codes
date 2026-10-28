# include <iostream>
using namespace std;
int main(){
int n;
cout<<"enter the number of unknown// number of equation"<<endl;
cin>>n;
float a[n+1];
float b[n+1];
float c[n+1];
float d[n+1];
float alpha[n+1];
float beta[n+1];
float x[n+1];
cout<<"enter the element at principal diagonal"<<endl;
for(int i=1;i<=n;i++){
	cin>>b[i];
}
cout<<" enter the element at superdiagonal"<<endl;
for(int i=1;i<=n-1;i++){
	cin>>c[i];
}
cout<<"enter the element at subdiagonal"<<endl;
for(int i=2;i<=n;i++){
	cin>>a[i];
}
cout<<"enter the element on right side"<<endl;
for(int i=1;i<=n;i++){
	cin>>d[i];
}
alpha[1]=b[1];
for(int i=2;i<=n;i++){
	alpha[i]=b[i]-((c[i-1]*a[i])/alpha[i-1]);
}
for(int i=1;i<=n;i++){
	cout<<alpha[i]<<" ";
}
beta[1]=d[1]/b[1];
for(int i=2;i<=n;i++){
	beta[i]=(d[i]-(a[i]*beta[i-1]))/alpha[i];
}
for(int i=1;i<=n;i++){
	cout<<beta[i]<<" ";
}

x[n]=beta[n];
x[0]=0;
for(int i=n-1;i>=1;i--){
	x[i]=beta[i]-((c[i]*x[i+1])/alpha[i]);	
}
cout<<"the solution of system of equation is "<<endl;
for(int i=1;i<=n;i++){
	cout<<x[i]<<" ";
}

}
