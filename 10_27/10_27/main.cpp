#include <stdio.h>
#include <stdlib.h>

//���x�v�Z���ȈՉ��������F��ȋ@�\��ς�ŗV�т܂���

class Object
{
//Object�N���X
//x, y, z���W��ۑ�����ϐ��AUpdate�֐������B
//Update�֐���virtual�ō���Ă��������B
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
//Vehicle(��蕨)�N���X Object�N���X���p�������N���X�B
//�����ł�SpeedUp�N���X��ǉ����Ă��������B
//�܂�speed��accel�̕ϐ��������Œǉ����Ă��������B
//SpeedUp�N���X��virtual�ō���Ă��������B
public:
    Vehicle() {};
    //���݂̃X�s�[�h�̕\���A����
    //Bike�ł������������@���g���̂ł����Ɍv�Z��u���܂���
    virtual void Speed()
    {
        if (accel >= 0)
        {
            speed += accel;
            printf("[���݂�speed:%d]\n", speed);
        }
        else
        {
            printf("[���݂�speed:ERROR]\n");
        }
    };
    //���݂̏�Ԃ��m�F�A�\��
    virtual void NowCondition()
    {
        if (speed == 0)
        {
            printf("���݂̏��:��~��\n");
        }
        else if (speed >= 1)
        {
            printf("���݂̏��:���쒆\n");
        }
        else
        {
            printf("���݂̏��:�̏ᒆ\n");
        }
    };
    //���ݒn�̕\��
    virtual void NowPosition(int speed)
    {
        hoge = rand() % 3;//xyz�̊m�F�悤�ɓK���ɓ�����

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
            printf("[ERROR]\n[�l���������Ɉړ��������߁A���݂̍��W���������܂���]\n");
        }
        if (speed >= 0) {
            printf("���݂̍��W[%d,%d,%d]", Object.object_x, Object.object_y, Object.object_z);
        }
        else
        {
            //speed���G���[���ɒʂ�ꏊ
        }
    };

    int   speed = 0;
    int   accel = 0;
};

class Car : public Vehicle
{
//Car(��)�N���X Vehicle�N���X���p�������N���X
//SpeedUp��������Car�p�Ɏ������Ă��������B
public:
    Car()
    {
        speed = 0;//���ڑł����ނ��ƂŕύX
        accel = 0;//���̍ۂ�main�̓��͍��ڂ͏�������
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
//Bike�N���X Car�N���X�Ƌ@�\�͏����i�͓���
public:
    Bike()
    {
        speed = 0;//���ڑł����ނ��ƂŕύX
        accel = 0;//���̍ۂ�main�̓��͍��ڂ͏�������
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

    //���͂������l�������������s��
    //0�ȉ��̃X�s�[�h�ɂȂ�ꍇ�̓G���[���b�Z�[�W�̕\��
    //���K�̂��ߐF��ȋ@�\��ǉ�

    printf("[Car�̃X�s�[�h����͂��Ă�������]\n");
    scanf_s("%d", &accel);
    Car.accel = accel;

    printf("[Bike�̃X�s�[�h����͂��Ă�������]\n");
    scanf_s("%d", &accel);
    Bike.accel = accel;

    for (int i = 1; i < 5; i++)
    {
        Car.Update();
        Bike.Update();
    }
    printf("\n");
}