#include <stdio.h>

/*
第１問
x, y座標を持つ構造体Vector2を、作ってください。
x, yはpublicで作成し、外部で値を設定して、
値が表示されることを確認してください。

struct Vector2
{

	//publicでxとyそれぞれの変数をint型作成
public :
	int x;
	int y;
};
*/

/*
第２問
x,y座標を持つ構造体Vector2を、作ってください。
x,yはprivateで作成し、関数を介して値を設定できるようにして、
値が表示されることを確認してください。

struct Vector2
{
	//xとyそれぞれの変数をpublicに格納するセッターゲッターの準備
public:
	int Setx(int n) { return x = n; }
	int Sety(int n) { return y = n; }

	int Getx() { return x; }
	int Gety() { return y; }

	//privateでxとyそれぞれの変数をint型作成
private:
	int x;
	int y;
};
*/


/*第３問
x, y, z座標を持つ構造体Vector3を作ってください。
x, y, zはprivateで作成し、関数を介して値を設定できるようにして、
値が表示されることを確認してください。
*/
struct Vector3
{
	//x,y,zそれぞれの変数をpublicに格納するセッターゲッターの準備
public:
	int Setx(int n) { return x = n; }
	int Sety(int n) { return y = n; }
	int Setz(int n) { return z = n; }

	int Getx() { return x; }
	int Gety() { return y; }
	int Getz() { return z; }

	//privateでx,y,zそれぞれの変数をint型作成
private:
	int x;
	int y;
	int z;
};

int main()
{
	/*
	//第１問
	//構造体の呼び出し
	Vector2 vec2;

	//x,yそれぞれに値を入れる
	vec2.x = 1;
	vec2.y = 2;

	//x,yの値を出力し確認
	printf("%d\n", vec2.x);
	printf("%d\n", vec2.y);
	//Setに入れた数値が出力されれば成功
	*/

	/*
	//第２問
	//構造体の呼び出し
	Vector2 vec2;

	//x,yそれぞれに値を入れる
	vec2.Setx(3);
	vec2.Sety(4);

	//x,yの値を出力し確認
	printf("%d\n", vec2.Getx());
	printf("%d\n", vec2.Gety());
	//Setに入れた数値が出力されれば成功
	*/

	/*
	//第３問
	//構造体の呼び出し
	*/
	Vector3 vec3;

	//x,y,zそれぞれに値を入れる
	vec3.Setx(5);
	vec3.Sety(6);
	vec3.Setz(7);

	//x,yの値を出力し確認
	printf("%d\n", vec3.Getx());
	printf("%d\n", vec3.Gety());
	printf("%d\n", vec3.Getz());
	//Setに入れた数値が出力されれば成功

}