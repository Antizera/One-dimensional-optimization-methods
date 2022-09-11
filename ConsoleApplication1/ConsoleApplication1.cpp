#include<iostream>
#include <iomanip>
#include<cmath>

#include<iomanip>

using namespace std;
double eps = 0.001;
double f(double x) {
	return (pow(x-0.5,2));
}
void solved(double a, double b, double Xavg, double k);
void hulf_sub(double a, double b, double Xavg, double k)
{
	double  Lk = abs(b - a);
	double Xavg_res = f(Xavg);
	double y = a + Lk / 4;
	double z = b - Lk / 4;
	double y_result = f(y);
	double z_result = f(z);
	cout << "a=" << y << " x=" << Xavg << " b=" << z << " F(y)=" << y_result <<" F(x)="<<Xavg_res << " F(z)=" << z_result << endl;
	if (y_result < Xavg_res) {
		b = Xavg_res;
		Xavg = y;
		solved(a, b, Xavg, k);
	}
	else if (y_result > Xavg_res) {
		if (z_result < Xavg_res) {
			a = Xavg;
			Xavg = z;
			solved(a, b, Xavg, k);
		}
		else if(z_result>Xavg_res || z_result==Xavg_res)
		{
			a = y;
			b = z;
			solved(a, b, Xavg, k);
		}
	}
}

void solved(double a, double b, double Xavg, double k) {
	double Lkk = abs(b - a);
	if (Lkk < eps || Lkk == eps) {
		double avg = (a + b) / 2;
		cout <<"X= "<< avg<<endl;
		double res = f(avg);
		cout <<"f= "<< res<<endl;
	}
	else hulf_sub(a, b, Xavg, k + 1);
}
void solved2(double a, double b, double y, double z, double k);
void golden(double a, double b, double y, double z, double k) {
	double y_res = f(y);
	double z_res = f(z);
	cout << endl;
	cout << "Y= " << y << " Z= " << z << " F(y)= " << y_res << " F(z)= " << z_res << endl;
	if (y_res <= z_res) {
		b = z;
		z = y;
		y = a + b - y;
	}
	else if (y_res > z_res) {
		a = y;
		y = z;
		z = a + b - z;
	}
	
	solved2(a, b, y, z, k);
}
void solved2(double a, double b, double y, double z, double k) {
	double delta = abs(a - b);
	if (delta <= eps) {
		double x = (a + b) / 2;
		cout << "X= " << x<<endl;
		cout << "F= " <<round(f(x)*100)/100;
	}
	else golden(a, b, y, z, k + 1);
}




int main()

 {
	 double k = 0;
	 double a = -1, b = 1,y=a+(3-sqrt(5))/2*(b-a),z=a+b-y;
	 hulf_sub(a, b, (a + b) / 2, k);
	 golden(a, b, y, z, k);
	return 0;

 }