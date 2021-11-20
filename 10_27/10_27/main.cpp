#include <stdio.h>
#include <stdlib.h>

//速度計算を簡易化した分色んな機能を積んで遊びました

class Object
{
//Objectクラス
//x, y, z座標を保存する変数、Update関数を持つ。
//Update関数はvirtualで作ってください。
public:
    Object(){};
    int   object_x = 0;
    int   object_y = 0;
    int   object_z = 0;
};

class Vehicle : public Object
{
    Object Object;
    int hoge=0;
//Vehicle(乗り物)クラス Objectクラスを継承したクラス。
//ここではSpeedUpクラスを追加してください。
//またspeedとaccelの変数をここで追加してください。
//SpeedUpクラスはvirtualで作ってください。
public:
    Vehicle() {};
    //現在のスピードの表示、加速
    //Bikeでも同じ加速方法を使うのでここに計算を置きました
    virtual void Speed()
    {
        if (accel >= 0)
        {
            speed += accel;
            printf("[現在のspeed:%d]\n", speed);
        }
        else
        {
            printf("[現在のspeed:ERROR]\n");
        }
    };
    //現在の状態を確認、表示
    virtual void NowCondition()
    {
        if (speed == 0)
        {
            printf("現在の状態:停止中\n");
        }
        else if (speed >= 1)
        {
            printf("現在の状態:動作中\n");
        }
        else
        {
            printf("現在の状態:故障中\n");
        }
    };
    //現在地の表示
    virtual void NowPosition(int speed)
    {
        hoge = rand() % 3;//xyzの確認ように適当に動かす

        switch (hoge)
        {
        case 0:
            Object.object_z += speed;
            break;
        case 1:
            Object.object_y += speed;
            break;
        case 2:
            Object.object_x += speed;
            break;
        default:
            printf("[ERROR]\n[四次元方向に移動したため、現在の座標を見失いました]\n");
        }
        if (speed >= 0) {
            printf("現在の座標[%d,%d,%d]", Object.object_x, Object.object_y, Object.object_z);
        }
        else
        {
            //speedがエラー中に通る場所
        }
    };

    int   speed = 0;
    int   accel = 0;
};

class Car : public Vehicle
{
//Car(車)クラス Vehicleクラスを継承したクラス
//SpeedUpをここでCar用に実装してください。
public:
    Car()
    {
        speed = 0;//直接打ち込むことで変更
        accel = 0;//その際はmainの入力項目は消すこと
    };
    void Update()
    {
        printf("\n--------------------[Car]--------------------\n");
        Speed();
        NowCondition();
        NowPosition(speed);
    }
};

class Bike : public Vehicle
{
//Bikeクラス Carクラスと機能は所持品は同じ
public:
    Bike()
    {
        speed = 0;//直接打ち込むことで変更
        accel = 0;//その際はmainの入力項目は消すこと
    };
    void Update()
    {
        printf("\n--------------------[Bike]-------------------\n");
        Speed();
        NowCondition();
        NowPosition(speed);
    }
};

int main()
{
    Car Car;
    Bike Bike;
    int accel;

    //入力した数値分加速減速を行う
    //0以下のスピードになる場合はエラーメッセージの表示
    //練習のため色んな機能を追加

    printf("[Carのスピードを入力してください]\n");
    scanf_s("%d", &accel);
    Car.accel = accel;

    printf("[Bikeのスピードを入力してください]\n");
    scanf_s("%d", &accel);
    Bike.accel = accel;

    for (int i = 1; i < 5; i++)
    {
        Car.Update();
        Bike.Update();
    }
    printf("\n");
}