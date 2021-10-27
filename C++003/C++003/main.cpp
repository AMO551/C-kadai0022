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
#include <stdio.h>
 
class Object
{
public:
    virtual void Update(float num)
    { 
        x += num;
        printf("x=%f\n", x);
        printf("y=%f\n", y);
        printf("z=%f\n", z);
    };


private:
    float x = 0;
    float y = 0;
    float z = 0;
};


class Vehicle :public Object
{
public:
 
   virtual float _SpeedUP(float num)
    {
        num += Speed;
        return num;
    }
private:
    float Speed = 10.0f;
    int accel = 1;
};

class Car:public Vehicle
{
public:
   
    float SpeedUP()
    {
        speed =_SpeedUP(speed);
    };
    float SpeedDown()
    {
        speed -= s_down;
    };
    void UP()
    {
        Update(speed);
    }
   
private: 
    float speed;
    float s_down=2.0f;
};









//class Car
//{
//public:
//    Car();
//    void    SetAcceleration(float _a);
//    float   GetSpeed() const;
//
//    // public�������̂ŃA�N�Z�X�w��q��ύX����Ӗ������͂Ȃ����A
//    // ��̃u���b�N��public��Set,Get�ł��������public�͏����n��
//    // �܂Ƃ߂��u���b�N�Ƃ��ĕ����Č��₷�����Ă���B
//public:
//    void    Update();
//
//private:
//    void    setSpeed(float _s); // ���x�͉����x��p�����v�Z�ł̂ݕύX�ł���悤�ɂ������̂ŁA
//                                // private�ɂ��Ă����B
//private:
//    float   acceleration;
//    float   speed;
//};
//
//class PoliceCar : public Car
//{
//public:
//    PoliceCar()
//    {
//        sirenFlag = false;
//    }
//
//public:
//    void SirenOn()
//    {
//        sirenFlag = true;
//        printf("�T�C�����@�\��On�ɂ��܂���\n");
//    }
//    void SirenOff()
//    {
//        sirenFlag = false;
//        printf("�T�C�����@�\��Off�ɂ��܂���\n");
//    }
//
//private:
//    bool    sirenFlag;
//};
//
//// �R���X�g���N�^
//Car::Car()
//{
//    acceleration = speed = 0.0f;
//}
//
////
//void Car::SetAcceleration(float _a)
//{
//    if (_a < -10 || _a > 5)
//    {
//        printf("SetAcceleration Error\n");
//        return;
//    }
//    acceleration = _a;
//}
//
//// 
//float Car::GetSpeed() const
//{
//    return speed;
//}
//
////
//void Car::Update()
//{
//    setSpeed(acceleration);
//}
//
////
//void Car::setSpeed(float _s)
//{
//    float tmpSpeed = speed + _s;
//    if (tmpSpeed < -30 || tmpSpeed > 200)
//    {
//        printf("setSpeed Error.\n");
//        return;
//    }
//    speed = tmpSpeed;
//}
//int main()
//{
//    PoliceCar policeCar;
//
//    policeCar.SirenOn();
//    policeCar.SirenOff();
//
//
//    // �������Car�̋@�\�����ׂĎg���� 
//    policeCar.SetAcceleration(1.0f);
//
//    for (int i = 0; i < 100; ++i)
//    {
//        policeCar.Update();
//        printf("Speed = %f\n", policeCar.GetSpeed());
//    }
//    policeCar.SetAcceleration(-0.1f);
//
//    for (int i = 0; i < 100; ++i)
//    {
//        policeCar.Update();
//        printf("Speed = %f\n", policeCar.GetSpeed());
//    }
//}