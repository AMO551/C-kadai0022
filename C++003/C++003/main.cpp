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
//    // publicが続くのでアクセス指定子を変更する意味合いはないが、
//    // 上のブロックがpublicなSet,Getでここからのpublicは処理系を
//    // まとめたブロックとして分けて見やすくしている。
//public:
//    void    Update();
//
//private:
//    void    setSpeed(float _s); // 速度は加速度を用いた計算でのみ変更できるようにしたいので、
//                                // privateにしておく。
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
//        printf("サイレン機能をOnにしました\n");
//    }
//    void SirenOff()
//    {
//        sirenFlag = false;
//        printf("サイレン機能をOffにしました\n");
//    }
//
//private:
//    bool    sirenFlag;
//};
//
//// コンストラクタ
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
//    // もちろんCarの機能もすべて使える 
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