#include <stdio.h>
/*【問題】
///OK
Objectクラス
x, y, z座標を保存する変数、Update関数を持つ。
Update関数はvirtualで作ってください。



Vehicle(乗り物)クラス
Objectクラスを継承したクラス。
ここではSpeedUpクラスを追加してください。
またspeedとaccelの変数をここで追加してください。
SpeedUpクラスはvirtualで作ってください。
(正確な速度の処理を行いたい場合は、向きと加速度で、
	ベクトルを計算する方法でも構いません。)



	Car(車)クラス
	Vehicleクラスを継承したクラス
	SpeedUpとSpeedDownをここでCar用に実装してください。




	流れを理解するという意味で、
	この親クラスから派生クラスを作っていってほしいので、
	中の計算処理やデータの設定の仕方は、
	適当に行ってもらって結構です。



	また、このクラスは必ず提出してください。
	成績に加味します。




	時間があれば、
	Vehicleクラスを継承して、
	bicycle(自転車)やbike(オートバイ)
	といったクラスの作成や、
	Carをさらに継承したpolice carや、truckなどの
	クラスを作成してみてください。
*/
class Object
{
public:
	virtual void Update(float num = 1)
	{
		vecX += num;
		printf("x=%f\n", vecX);
		printf("y=%f\n", vecY);
		printf("z=%f\n", vecZ);
	};
	virtual float Getvec()
	{
		printf("x=%f\n", vecX);
		printf("y=%f\n", vecY);
		printf("z=%f\n", vecZ);
		return 0;
	};
private:
	float vecX = 0;
	float vecY = 0;
	float vecZ = 0;
};
class Vehicle :public Object
{
public:
	virtual float _SpeedUP(float num)
	{
		num += Speed * accel;
		return num;
	};
	virtual void SetAccel(float num)
	{
		accel = num;
	}
private:
	float Speed = 10.0f;
	float accel = 0;
};
class Car :public Vehicle
{
public:

	void SpeedUP()
	{
		if (!(speed == 100))
			speed = _SpeedUP(speed);
		if (speed >= 100)
		{
			speed = 100;
		}
		printf("%f\n", speed);
	};
	void SpeedDown()
	{
		if (!(speed == 0))
			speed -= s_down;
		if (speed < 0)
		{
			speed = 0;
		}
		printf("%f\n", speed);
	};
	void UP()
	{
		Update(speed);
	};

private:
	float speed = 0;
	float s_down = 2.0f;
};
class Bicycle :public Vehicle
{
public:

	float SpeedUP()
	{
		if (!(speed == 100))
			speed = _SpeedUP(speed);
		if (speed >= 100)
		{
			speed = 100;
		}
		return 0;
	};
	float SpeedDown()
	{
		if (!(speed == 0))
			speed -= s_down;
		if (speed < 0)
		{
			speed = 0;
		}
		return 0;
	};

	void UP()
	{
		Update(speed);
	};

private:
	float speed = 0;
	float s_down = 2.0f;
};
class Bike :public Vehicle
{
public:

	float SpeedUP()
	{
		if (!(speed == 100))
			speed = _SpeedUP(speed);
		if (speed >= 100)
		{
			speed = 100;
		}
		return 0;
	};
	float SpeedDown()
	{
		if (!(speed == 0))
			speed -= s_down;
		if (speed < 0)
		{
			speed = 0;
		}
		return 0;
	};
	void UP()
	{
		Update(speed);
	};

private:
	float speed = 0;
	float s_down = 2.0f;
};
int main()
{

	Car car;
	car.SetAccel(0.1f);
	for (int i = 0; i < 200; i++)
	{
		car.SpeedUP();
		car.UP();

	}
	for (int j = 0; j < 300; j++)
	{
		car.SpeedDown();
		car.UP();

	}
	
	return 0;
}