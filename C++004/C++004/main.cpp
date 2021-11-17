#include <stdio.h>
/*�y���z
///OK
Object�N���X
x, y, z���W��ۑ�����ϐ��AUpdate�֐������B
Update�֐���virtual�ō���Ă��������B



Vehicle(��蕨)�N���X
Object�N���X���p�������N���X�B
�����ł�SpeedUp�N���X��ǉ����Ă��������B
�܂�speed��accel�̕ϐ��������Œǉ����Ă��������B
SpeedUp�N���X��virtual�ō���Ă��������B
(���m�ȑ��x�̏������s�������ꍇ�́A�����Ɖ����x�ŁA
	�x�N�g�����v�Z������@�ł��\���܂���B)



	Car(��)�N���X
	Vehicle�N���X���p�������N���X
	SpeedUp��SpeedDown��������Car�p�Ɏ������Ă��������B




	����𗝉�����Ƃ����Ӗ��ŁA
	���̐e�N���X����h���N���X������Ă����Ăق����̂ŁA
	���̌v�Z������f�[�^�̐ݒ�̎d���́A
	�K���ɍs���Ă�����Č��\�ł��B



	�܂��A���̃N���X�͕K����o���Ă��������B
	���тɉ������܂��B




	���Ԃ�����΁A
	Vehicle�N���X���p�����āA
	bicycle(���]��)��bike(�I�[�g�o�C)
	�Ƃ������N���X�̍쐬��A
	Car������Ɍp������police car��Atruck�Ȃǂ�
	�N���X���쐬���Ă݂Ă��������B
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