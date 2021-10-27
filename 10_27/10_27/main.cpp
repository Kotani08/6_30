#include <stdio.h>

/*
���z�֐�
�p�����̃N���X�̊֐������z�֐��ɂ��Ă����ƁA
�p����ŏ��������������邱�Ƃ��ł���B

// ���z�֐��ɂ��Ȃ��ꍇ
class ParentClass
{
public:
    ParentClass() {}
    void Print(){ printf("Parent\n"); }
};
class ChildClass : public ParentClass
{
public:
    ChildClass() {}
    void Print(){ printf("Child\n"); }
};
*/
/*
class ParentClass
{
public:
    ParentClass() {}
    void Print() { printf("Parent\n"); }
};
class ChildClass : public ParentClass
{
public:
    void Print() { printf("Child\n"); }
};
*/
/*int main()
{
    ParentClass* parent = new ParentClass();
    ParentClass* child = new ChildClass();

    parent->Print();
    child->Print();

    delete parent;
    delete child;
}
*/
/*
��L�����s�����
PrintClass�^�ɓ���Ă���̂�
���RParentClass�̏������Ăяo����Ă���
���̂���.Print�̓��e��Parent�ƂȂ�B
���z�֐��ɂ��鏈���ł�
�p����̏������s����B
*/
/*
��L�����s�����
Print�̎��s���ʂ��ς���Ă��邱�Ƃ��m�F�ł���Ǝv���܂�
���̂悤�ɓ������O�̊֐��ł��邱�Ƃ�
�p���悲�ƂɈႤ�U�镑����}���邱�Ƃ�
�|�����[�t�B�Y���ƌ����܂�
*/

/*
�ȉ��̂悤��ClassAdd�N���X���쐬���p����
Calc�������Z���s���悤�ɂ���CalcSub�N���X���쐬���Ă��������B
*/
/*
class CalcAdd
{
public:
    CalcAdd() {}
    virtual int Calc(int x, int y)
    {
        int ans;
        ans = x + y;
        printf("%d + %d = %d\n", x, y, ans);
        return ans;
    }
};
class CalcSub : public CalcAdd
{
public:
    virtual int Calc(int x, int y)
    {
        int ans;
        ans = x - y;
        printf("%d - %d = %d\n", x, y, ans);
        return ans;
    }
};
int main()
{
    CalcAdd add;
    CalcSub sub;
    
    add.Calc(10, 5);
    sub.Calc(10, 5);
}
*/

/*
�킴�킴��L�̂悤�ȕϐ��̐錾�̂����͂��Ȃ��A
�Ǝv����������܂��񂪁A
�Ⴆ�Ί֐��ɓn���悤�ȏꍇ�́A
�|�C���^�Ŏ󂯎��̂ŁA
���z�֐��ō���Ă����Ȃ��ƁA
�]�񂾌��ʂ������Ȃ��ꍇ������̂ŁA
�p����ł��ꂼ�ꋓ����ς������ꍇ�́A
���z�֐��ō��悤�ɂ��܂��傤�B
*/
// Object�N���X���p�����āAPlayer,Enemy�����
/*class Object
{
public:
    Object() {}
    virtual ~Object() { printf("Exec Object Destructor.\n"); }
public:
    virtual void Update() {}//�Ƃ肠����virtual�͕t���Ƃ�
};

class Player : public Object
{
public:
    Player() {}
    ~Player() { printf("Exec Player Destructor.\n"); }
public:
    void Update() { printf("Player Update.\n"); }
};

class Enemy : public Object
{
public:
    Enemy() {}
    ~Enemy() { printf("Exec Enemy Destructor.\n"); }
public:
    void Update() { printf("Enemy Update.\n"); }
};

void DoUpdate(Object* obj)
{
    obj->Update();
}

int main()
{
    Player player;
    Enemy enemy;

    DoUpdate(&player);
    DoUpdate(&enemy);
}*/

/*
�O��쐬����PoliceCar���C�����Ă��������B
�C�����e��Car��SetAcceleration�̏���Ɖ����̒l��(-100,50)��
�ύX����-10�ȉ��A5�ȏオ�ݒ�ł���悤�ɂ��Ă��������B
���̎�SetAcceleration��virtual�����ď������������Ă��������B
*/
/*class Car
{
public:
    Car();
    virtual void    SetAcceleration(float _a);
    float           GetSpeed() const;

    // public�������̂ŃA�N�Z�X�w��q��ύX����Ӗ������͂Ȃ����A
    // ��̃u���b�N��public��Set,Get�ł��������public�͏����n��
    // �܂Ƃ߂��u���b�N�Ƃ��ĕ����Č��₷�����Ă���B
public:
    void    Update();

private:
    void    setSpeed(float _s); // ���x�͉����x��p�����v�Z�ł̂ݕύX�ł���悤�ɂ������̂ŁA
                                // private�ɂ��Ă����B
protected:
    float   acceleration;
private:
    float   speed;
};

class PoliceCar : public Car
{
public:
    PoliceCar() { sirenFlag = false; }

public:
    void SirenOn()
    {
        sirenFlag = true;
        printf("�T�C�����@�\��On�ɂ��܂����B\n");
    }
    void SirenOff()
    {
        sirenFlag = false;
        printf("�T�C�����@�\��Off�ɂ��܂����B\n");
    }
    virtual void    SetAcceleration(float _a);
private:
    bool    sirenFlag;
};



// �R���X�g���N�^
Car::Car()
{
    acceleration = speed = 0.0f;
}

//
void Car::SetAcceleration(float _a)
{
    if (_a < -10 || _a > 5)
    {
        printf("SetAcceleration Error\n");
        return;
    }
    acceleration = _a;
}

// 
float Car::GetSpeed() const
{
    return speed;
}

//
void Car::Update()
{
    setSpeed(acceleration);
}

//
void Car::setSpeed(float _s)
{
    float tmpSpeed = speed + _s;
    if (tmpSpeed < -30 || tmpSpeed > 200)
    {
        printf("setSpeed Error.\n");
        return;
    }
    speed = tmpSpeed;
}

//
void PoliceCar::SetAcceleration(float _a)
{
    if (_a < -100 || _a > 50)
    {
        printf("SetAcceleration Error\n");
        return;
    }
    acceleration = _a;
}

int main()
{
    PoliceCar policeCar;
    Car* car = &policeCar;

    policeCar.SirenOn();
    policeCar.SirenOff();


    // �������Car�̋@�\�����ׂĎg���� 
    car->SetAcceleration(50.0f);

    for (int i = 0; i < 100; ++i)
    {
        car->Update();
        printf("Speed = %f\n", car->GetSpeed());
    }
    car->SetAcceleration(-0.1f);

    for (int i = 0; i < 100; ++i)
    {
        car->Update();
        printf("Speed = %f\n", car->GetSpeed());
    }

}
*/
/*
�y���z
Object�N���X
x,y,z���W��ۑ�����ϐ��AUpdate�֐������B
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
SpeedUp��������Car�p�Ɏ������Ă��������B

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
//Object�N���X
//x, y, z���W��ۑ�����ϐ��AUpdate�֐������B
//Update�֐���virtual�ō���Ă��������B
public:
    Object(){};
    virtual void   Update(){};
    float   object_x = 0;
    float   object_y = 0;
    float   object_z = 0;
};

class Vehicle : public Object
{
//Vehicle(��蕨)�N���X Object�N���X���p�������N���X�B
//�����ł�SpeedUp�N���X��ǉ����Ă��������B
//�܂�speed��accel�̕ϐ��������Œǉ����Ă��������B
//SpeedUp�N���X��virtual�ō���Ă��������B
public:
    Vehicle() {};
    virtual void SpeedUp()
    {
        speed++;
        printf("���݂�speed:%d\n", speed);
    };
    int   speed;
    bool   accel;//ON,OFF
};

class Car : public Vehicle
{
//Car(��)�N���X Vehicle�N���X���p�������N���X
//SpeedUp��������Car�p�Ɏ������Ă��������B
public:
    Car()
    {
        speed = 0;
        accel = 1;
    };
    void SpeedUp()
    {
        speed += accel;
        printf("���݂�speed:%d\n", speed);
    };
    void Update()
    {
        if (accel == true)
        {
            printf("���݂̏��:���쒆\n");
        }
        else if (accel == false)
        {
            printf("���݂̏��:��~��\n");
        }
        else
        {
            printf("���݂̏��:�̏ᒆ\n");
        }
    }
};
int main()
{
    Car Car;

    for (int i = -1; i < 5; i++)
    {
        Car.SpeedUp();
        Car.Update();
    }
}