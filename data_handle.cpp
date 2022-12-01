#include<iostream>
#include<math.h>
#include<vector>

using namespace std;

class Datas {
private:
	double t;
	double v_0;
	double f;
	double L_average;
	double v_average;
	vector<double> Ls;
	double s;
	double U_A;
	double U_B;
	double U_L;
	double U_v;
	double h;

public:
	void init();
	double get_v_0();
	void set_f(double new_f);
	double get_f();
	void set_L_average(double new_L_average);
	double get_L_average();
	double get_v_average();
	void set_Ls();
	vector<double> get_Ls();
	double get_s();
	double get_U_A();
	void set_U_B();
	double get_U_B();
	void set_U_L();
	double get_U_L();
	double get_U_v();
	double get_h();
};

void Datas::init() {
	t = 19.8;
}

double Datas::get_v_0() {
	v_0 = 331.45 * sqrt((t + 273.15) / 273.15);
	return v_0;
}

void Datas::set_f(double new_f) { this->f = new_f; }

double Datas::get_f() { return f; }

void Datas::set_L_average(double new_L_average) { this->L_average = new_L_average; }

double Datas::get_L_average() { return L_average; }

double Datas::get_v_average() {
	v_average = 0.4 * get_L_average() * get_f();
	return v_average;
}

void Datas::set_Ls() {
	Ls.push_back(2.48);
	Ls.push_back(2.48);
	Ls.push_back(2.16);
	Ls.push_back(2.14);
	Ls.push_back(2.21);
}

vector<double> Datas::get_Ls() { return Ls; }

double Datas::get_s() {
	vector<double> x = get_Ls();
	double x_average = 0;
	for (int i = 0; i < x.size(); i++) { x_average += x[i]; }
	x_average = x_average / x.size();
	double sum = 0;
	for (int i = 0; i < x.size(); i++) {
		sum += pow((x[i] - x_average), 2);
	}
	s = sqrt(sum/(x.size() - 1));
	return s;
}

double Datas::get_U_A() {
	U_A = get_s() * 1.24;
	return U_A;
}

double Datas::get_U_v() {
	U_v = get_v_average() * sqrt(pow((get_U_L()/L_average), 2) + pow(0.005, 2));
	return U_v;
}

void Datas::set_U_B() { U_B = 0.02; }
double Datas::get_U_B() { return U_B; }

void Datas::set_U_L() { U_L = sqrt(U_A*U_A + U_B*U_B); }
double Datas::get_U_L() { return U_L; }

double Datas::get_h() {
	h = abs(v_average*10 - v_0) / v_0;
	return h;
}

int main() {

	Datas data;
	data.init();
	cout << data.get_v_0() << endl;
	data.set_f(36.974);
	data.set_L_average(2.294);
	cout << data.get_v_average() << endl;
	data.set_Ls();
	cout << data.get_s() << endl;
	cout << data.get_U_A() << endl;
	data.set_U_B();
	data.set_U_L();
	cout << data.get_U_L() << endl;
	cout << data.get_U_v() << endl;
	cout << data.get_h() << endl;
	return 0;
}