#include<iostream>
#include<iomanip>
using namespace std;

#define J 1
#define K 2
#define A 2
#define B 4
#define x_0 0.5		//行人初始概率
#define y_0 0.6		//车辆初始概率

void RK4(double(*f)(double t, double x, double y), double(*g)(double t, double x, double y), double initial[3], double resu[3], double h);


int main() {
	double f(double t, double x, double y);
	double g(double t, double x, double y);
	double initial[3], resu[3];
	double a, b, h;
	double step;
	int i;
	initial[0] = 0;			//t0
	initial[1] = x_0;		//x0
	initial[2] = y_0;		//y0
	//微分区间
	a = 0;
	b = 10;
	//子区间个数step
	step = 200;

	cout << setiosflags(ios::right) << setiosflags(ios::fixed) << setprecision(10);
	h = (b - a) / step;
	cout << initial[0] << setw(18) << initial[1] << setw(18) << initial[2] << endl;

	for (i = 0; i < step; i++) {
		RK4(f, g, initial, resu, h);
		cout << resu[0] << setw(20) << resu[1] << setw(20) << resu[2] << endl;
		initial[0] = resu[0];
		initial[1] = resu[1];
		initial[2] = resu[2];
	}

	return 0;
}

void RK4(double(*f)(double t, double x, double y),double(*g)(double t, double x, double y), double initial[3], double resu[3], double h) {
	double f1, f2, f3, f4, g1, g2, g3, g4, t0, x0, y0, x1, y1;
	t0 = initial[0]; x0 = initial[1]; y0 = initial[2];
	f1 = f(t0, x0, y0);											g1 = g(t0, x0, y0);
	f2 = f(t0 + h / 2, x0 + h * f1 / 2, y0 + h * g1 / 2);		g2 = g(t0 + h / 2, x0 + h * f1 / 2, y0 + h * g1 / 2);
	f3 = f(t0 + h / 2, x0 + h * f2 / 2, y0 + h * g2 / 2);		g3 = g(t0 + h / 2, x0 + h * f2 / 2, y0 + h * g2 / 2);
	f4 = f(t0 + h, x0 + h * f3, y0 + h * g3);					g4 = g(t0 + h, x0 + h * f3, y0 + h * g3);
	x1 = x0 + h * (f1 + 2 * f2 + 2 * f3 + f4) / 6;				y1 = y0 + h * (g1 + 2 * g2 + 2 * g3 + g4) / 6;
	resu[0] = t0 + h; resu[1] = x1; resu[2] = y1;
}

double f(double t, double x, double y) {
	double dx;
	dx = x * (1 - x)*(J - (J + A)*y);
	return (dx);
}
double g(double t, double x, double y) {
	double dy;
	dy = y * (1 - y)*(K - (K + B)*x);
	return (dy);
}