#include<iostream>
#include<cmath>

#define g 9.8
#define k 3.8e-8

double x, y, z,v0, vx0, T,Theta,Z_act, err, Z_temp;

int main()
{
	x = 3;
	y = 4;
	z = 0.25;
	v0 = 17;

	Theta = 1;//从1rad开始迭代
	Z_temp = 0.25;//将指向的点设为目标点Z

	double distance;
	distance = sqrt(pow(x, 2) + pow(y, 2));

	int i = 1;
	for(i=0;i<20;i++)
	{
		vx0 = v0 * cos(Theta);
		T = (exp(k * distance) - 1) / (k * vx0);//时间，根据公式可得

		Z_act = v0 * T * sin(Theta) - 0.5*g* pow(T, 2);//实际Z

		err = z - Z_act;
		Z_temp = Z_temp + err;//将指向的点迭代
		Theta = atan(Z_temp / distance);

	}
	printf("枪口角度：%f", Theta);
}