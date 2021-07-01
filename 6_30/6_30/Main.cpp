#include <stdio.h>

/*
��P��
x, y���W�����\����Vector2���A����Ă��������B
x, y��public�ō쐬���A�O���Œl��ݒ肵�āA
�l���\������邱�Ƃ��m�F���Ă��������B

struct Vector2
{

	//public��x��y���ꂼ��̕ϐ���int�^�쐬
public :
	int x;
	int y;
};
*/

/*
��Q��
x,y���W�����\����Vector2���A����Ă��������B
x,y��private�ō쐬���A�֐�����Ēl��ݒ�ł���悤�ɂ��āA
�l���\������邱�Ƃ��m�F���Ă��������B

struct Vector2
{
	//x��y���ꂼ��̕ϐ���public�Ɋi�[����Z�b�^�[�Q�b�^�[�̏���
public:
	int Setx(int n) { return x = n; }
	int Sety(int n) { return y = n; }

	int Getx() { return x; }
	int Gety() { return y; }

	//private��x��y���ꂼ��̕ϐ���int�^�쐬
private:
	int x;
	int y;
};
*/


/*��R��
x, y, z���W�����\����Vector3������Ă��������B
x, y, z��private�ō쐬���A�֐�����Ēl��ݒ�ł���悤�ɂ��āA
�l���\������邱�Ƃ��m�F���Ă��������B
*/
struct Vector3
{
	//x,y,z���ꂼ��̕ϐ���public�Ɋi�[����Z�b�^�[�Q�b�^�[�̏���
public:
	int Setx(int n) { return x = n; }
	int Sety(int n) { return y = n; }
	int Setz(int n) { return z = n; }

	int Getx() { return x; }
	int Gety() { return y; }
	int Getz() { return z; }

	//private��x,y,z���ꂼ��̕ϐ���int�^�쐬
private:
	int x;
	int y;
	int z;
};

int main()
{
	/*
	//��P��
	//�\���̂̌Ăяo��
	Vector2 vec2;

	//x,y���ꂼ��ɒl������
	vec2.x = 1;
	vec2.y = 2;

	//x,y�̒l���o�͂��m�F
	printf("%d\n", vec2.x);
	printf("%d\n", vec2.y);
	//Set�ɓ��ꂽ���l���o�͂����ΐ���
	*/

	/*
	//��Q��
	//�\���̂̌Ăяo��
	Vector2 vec2;

	//x,y���ꂼ��ɒl������
	vec2.Setx(3);
	vec2.Sety(4);

	//x,y�̒l���o�͂��m�F
	printf("%d\n", vec2.Getx());
	printf("%d\n", vec2.Gety());
	//Set�ɓ��ꂽ���l���o�͂����ΐ���
	*/

	/*
	//��R��
	//�\���̂̌Ăяo��
	*/
	Vector3 vec3;

	//x,y,z���ꂼ��ɒl������
	vec3.Setx(5);
	vec3.Sety(6);
	vec3.Setz(7);

	//x,y�̒l���o�͂��m�F
	printf("%d\n", vec3.Getx());
	printf("%d\n", vec3.Gety());
	printf("%d\n", vec3.Getz());
	//Set�ɓ��ꂽ���l���o�͂����ΐ���

}