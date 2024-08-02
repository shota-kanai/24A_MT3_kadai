#include "Matrix4x4Math.h"

using namespace std;



void VectorScreenPrintf(int x, int y, const Vector3& vector, const char* label)
{
	Novice::ScreenPrintf(x, y, "%.02f", vector.x);
	Novice::ScreenPrintf(x + kColumnWidth, y, "%.02f", vector.y);
	Novice::ScreenPrintf(x + kColumnWidth * 2, y, "%.02f", vector.z);
	Novice::ScreenPrintf(x + kColumnWidth * 3, y, "%s", label);
}

void MatrixScreenPrintf(int x, int y, const Matrix4x4& matrix, const char* label)
{
	Novice::ScreenPrintf(
		x , y  , "%s", label
	);
	for (int row = 0; row < 4; ++row) {
		for (int column = 0; column < 4; ++column) {
			Novice::ScreenPrintf(
				x + column * kColumnWidth, y + row * kRowHeight+20, "%6.02f", matrix.m[row][column]
			);
		}
	}
}

//行列たし算
Matrix4x4 Add(const Matrix4x4& m1, const Matrix4x4& m2) {
	Matrix4x4 result{};
	result.m[0][0] = m1.m[0][0] + m2.m[0][0];
	result.m[0][1] = m1.m[0][1] + m2.m[0][1];
	result.m[0][2] = m1.m[0][2] + m2.m[0][2];
	result.m[0][3] = m1.m[0][3] + m2.m[0][3];

	result.m[1][0] = m1.m[1][0] + m2.m[1][0];
	result.m[1][1] = m1.m[1][1] + m2.m[1][1];
	result.m[1][2] = m1.m[1][2] + m2.m[1][2];
	result.m[1][3] = m1.m[1][3] + m2.m[1][3];

	result.m[2][0] = m1.m[2][0] + m2.m[2][0];
	result.m[2][1] = m1.m[2][1] + m2.m[2][1];
	result.m[2][2] = m1.m[2][2] + m2.m[2][2];
	result.m[2][3] = m1.m[2][3] + m2.m[2][3];

	result.m[3][0] = m1.m[3][0] + m2.m[3][0];
	result.m[3][1] = m1.m[3][1] + m2.m[3][1];
	result.m[3][2] = m1.m[3][2] + m2.m[3][2];
	result.m[3][3] = m1.m[3][3] + m2.m[3][3];
	return result;
}

// 行列引き算
Matrix4x4 Subtract(const Matrix4x4& m1, const Matrix4x4& m2) {
	Matrix4x4 result{};

	result.m[0][0] = m1.m[0][0] - m2.m[0][0];
	result.m[0][1] = m1.m[0][1] - m2.m[0][1];
	result.m[0][2] = m1.m[0][2] - m2.m[0][2];
	result.m[0][3] = m1.m[0][3] - m2.m[0][3];

	result.m[1][0] = m1.m[1][0] - m2.m[1][0];
	result.m[1][1] = m1.m[1][1] - m2.m[1][1];
	result.m[1][2] = m1.m[1][2] - m2.m[1][2];
	result.m[1][3] = m1.m[1][3] - m2.m[1][3];

	result.m[2][0] = m1.m[2][0] - m2.m[2][0];
	result.m[2][1] = m1.m[2][1] - m2.m[2][1];
	result.m[2][2] = m1.m[2][2] - m2.m[2][2];
	result.m[2][3] = m1.m[2][3] - m2.m[2][3];

	result.m[3][0] = m1.m[3][0] - m2.m[3][0];
	result.m[3][1] = m1.m[3][1] - m2.m[3][1];
	result.m[3][2] = m1.m[3][2] - m2.m[3][2];
	result.m[3][3] = m1.m[3][3] - m2.m[3][3];
	return result;
}

//掛け算
Matrix4x4 Multiply(const Matrix4x4& m1, const Matrix4x4& m2) {
	Matrix4x4 result{};

	result.m[0][0] = m1.m[0][0] * m2.m[0][0] + m1.m[0][1] * m2.m[1][0] + m1.m[0][2] * m2.m[2][0] + m1.m[0][3] * m2.m[3][0];
	result.m[0][1] = m1.m[0][0] * m2.m[0][1] + m1.m[0][1] * m2.m[1][1] + m1.m[0][2] * m2.m[2][1] + m1.m[0][3] * m2.m[3][1];
	result.m[0][2] = m1.m[0][0] * m2.m[0][2] + m1.m[0][1] * m2.m[1][2] + m1.m[0][2] * m2.m[2][2] + m1.m[0][3] * m2.m[3][2];
	result.m[0][3] = m1.m[0][0] * m2.m[0][3] + m1.m[0][1] * m2.m[1][3] + m1.m[0][2] * m2.m[2][3] + m1.m[0][3] * m2.m[3][3];

	result.m[1][0] = m1.m[1][0] * m2.m[0][0] + m1.m[1][1] * m2.m[1][0] + m1.m[1][2] * m2.m[2][0] + m1.m[1][3] * m2.m[3][0];
	result.m[1][1] = m1.m[1][0] * m2.m[0][1] + m1.m[1][1] * m2.m[1][1] + m1.m[1][2] * m2.m[2][1] + m1.m[1][3] * m2.m[3][1];
	result.m[1][2] = m1.m[1][0] * m2.m[0][2] + m1.m[1][1] * m2.m[1][2] + m1.m[1][2] * m2.m[2][2] + m1.m[1][3] * m2.m[3][2];
	result.m[1][3] = m1.m[1][0] * m2.m[0][3] + m1.m[1][1] * m2.m[1][3] + m1.m[1][2] * m2.m[2][3] + m1.m[1][3] * m2.m[3][3];

	result.m[2][0] = m1.m[2][0] * m2.m[0][0] + m1.m[2][1] * m2.m[1][0] + m1.m[2][2] * m2.m[2][0] + m1.m[2][3] * m2.m[3][0];
	result.m[2][1] = m1.m[2][0] * m2.m[0][1] + m1.m[2][1] * m2.m[1][1] + m1.m[2][2] * m2.m[2][1] + m1.m[2][3] * m2.m[3][1];
	result.m[2][2] = m1.m[2][0] * m2.m[0][2] + m1.m[2][1] * m2.m[1][2] + m1.m[2][2] * m2.m[2][2] + m1.m[2][3] * m2.m[3][2];
	result.m[2][3] = m1.m[2][0] * m2.m[0][3] + m1.m[2][1] * m2.m[1][3] + m1.m[2][2] * m2.m[2][3] + m1.m[2][3] * m2.m[3][3];

	result.m[3][0] = m1.m[3][0] * m2.m[0][0] + m1.m[3][1] * m2.m[1][0] + m1.m[3][2] * m2.m[2][0] + m1.m[3][3] * m2.m[3][0];
	result.m[3][1] = m1.m[3][0] * m2.m[0][1] + m1.m[3][1] * m2.m[1][1] + m1.m[3][2] * m2.m[2][1] + m1.m[3][3] * m2.m[3][1];
	result.m[3][2] = m1.m[3][0] * m2.m[0][2] + m1.m[3][1] * m2.m[1][2] + m1.m[3][2] * m2.m[2][2] + m1.m[3][3] * m2.m[3][2];
	result.m[3][3] = m1.m[3][0] * m2.m[0][3] + m1.m[3][1] * m2.m[1][3] + m1.m[3][2] * m2.m[2][3] + m1.m[3][3] * m2.m[3][3];


	return result;
}

//逆行列
Matrix4x4 Inverse(const Matrix4x4& m) {
	float determinant = +m.m[0][0] * m.m[1][1] * m.m[2][2] * m.m[3][3]
		+ m.m[0][0] * m.m[1][2] * m.m[2][3] * m.m[3][1]
		+ m.m[0][0] * m.m[1][3] * m.m[2][1] * m.m[3][2]

		- m.m[0][0] * m.m[1][3] * m.m[2][2] * m.m[3][1]
		- m.m[0][0] * m.m[1][2] * m.m[2][1] * m.m[3][3]
		- m.m[0][0] * m.m[1][1] * m.m[2][3] * m.m[3][2]

		- m.m[0][1] * m.m[1][0] * m.m[2][2] * m.m[3][3]
		- m.m[0][2] * m.m[1][0] * m.m[2][3] * m.m[3][1]
		- m.m[0][3] * m.m[1][0] * m.m[2][1] * m.m[3][2]

		+ m.m[0][3] * m.m[1][0] * m.m[2][2] * m.m[3][1]
		+ m.m[0][2] * m.m[1][0] * m.m[2][1] * m.m[3][3]
		+ m.m[0][1] * m.m[1][0] * m.m[2][3] * m.m[3][2]

		+ m.m[0][1] * m.m[1][2] * m.m[2][0] * m.m[3][3]
		+ m.m[0][2] * m.m[1][3] * m.m[2][0] * m.m[3][1]
		+ m.m[0][3] * m.m[1][1] * m.m[2][0] * m.m[3][2]

		- m.m[0][3] * m.m[1][2] * m.m[2][0] * m.m[3][1]
		- m.m[0][2] * m.m[1][1] * m.m[2][0] * m.m[3][3]
		- m.m[0][1] * m.m[1][3] * m.m[2][0] * m.m[3][2]

		- m.m[0][1] * m.m[1][2] * m.m[2][3] * m.m[3][0]
		- m.m[0][2] * m.m[1][3] * m.m[2][1] * m.m[3][0]
		- m.m[0][3] * m.m[1][1] * m.m[2][2] * m.m[3][0]

		+ m.m[0][3] * m.m[1][2] * m.m[2][1] * m.m[3][0]
		+ m.m[0][2] * m.m[1][1] * m.m[2][3] * m.m[3][0]
		+ m.m[0][1] * m.m[1][3] * m.m[2][2] * m.m[3][0];

	Matrix4x4 result{};

	float recpDeterminant = 1.0f / determinant;
	result.m[0][0] = (m.m[1][1] * m.m[2][2] * m.m[3][3] + m.m[1][2] * m.m[2][3] * m.m[3][1] +
		m.m[1][3] * m.m[2][1] * m.m[3][2] - m.m[1][3] * m.m[2][2] * m.m[3][1] -
		m.m[1][2] * m.m[2][1] * m.m[3][3] - m.m[1][1] * m.m[2][3] * m.m[3][2]) * recpDeterminant;
	result.m[0][1] = (-m.m[0][1] * m.m[2][2] * m.m[3][3] - m.m[0][2] * m.m[2][3] * m.m[3][1] -
		m.m[0][3] * m.m[2][1] * m.m[3][2] + m.m[0][3] * m.m[2][2] * m.m[3][1] +
		m.m[0][2] * m.m[2][1] * m.m[3][3] + m.m[0][1] * m.m[2][3] * m.m[3][2]) * recpDeterminant;
	result.m[0][2] = (m.m[0][1] * m.m[1][2] * m.m[3][3] + m.m[0][2] * m.m[1][3] * m.m[3][1] +
		m.m[0][3] * m.m[1][1] * m.m[3][2] - m.m[0][3] * m.m[1][2] * m.m[3][1] -
		m.m[0][2] * m.m[1][1] * m.m[3][3] - m.m[0][1] * m.m[1][3] * m.m[3][2]) * recpDeterminant;
	result.m[0][3] = (-m.m[0][1] * m.m[1][2] * m.m[2][3] - m.m[0][2] * m.m[1][3] * m.m[2][1] -
		m.m[0][3] * m.m[1][1] * m.m[2][2] + m.m[0][3] * m.m[1][2] * m.m[2][1] +
		m.m[0][2] * m.m[1][1] * m.m[2][3] + m.m[0][1] * m.m[1][3] * m.m[2][2]) * recpDeterminant;

	result.m[1][0] = (-m.m[1][0] * m.m[2][2] * m.m[3][3] - m.m[1][2] * m.m[2][3] * m.m[3][0] -
		m.m[1][3] * m.m[2][0] * m.m[3][2] + m.m[1][3] * m.m[2][2] * m.m[3][0] +
		m.m[1][2] * m.m[2][0] * m.m[3][3] + m.m[1][0] * m.m[2][3] * m.m[3][2]) * recpDeterminant;
	result.m[1][1] = (m.m[0][0] * m.m[2][2] * m.m[3][3] + m.m[0][2] * m.m[2][3] * m.m[3][0] +
		m.m[0][3] * m.m[2][0] * m.m[3][2] - m.m[0][3] * m.m[2][2] * m.m[3][0] -
		m.m[0][2] * m.m[2][0] * m.m[3][3] - m.m[0][0] * m.m[2][3] * m.m[3][2]) * recpDeterminant;
	result.m[1][2] = (-m.m[0][0] * m.m[1][2] * m.m[3][3] - m.m[0][2] * m.m[1][3] * m.m[3][0] -
		m.m[0][3] * m.m[1][0] * m.m[3][2] + m.m[0][3] * m.m[1][2] * m.m[3][0] +
		m.m[0][2] * m.m[1][0] * m.m[3][3] + m.m[0][0] * m.m[1][3] * m.m[3][2]) * recpDeterminant;
	result.m[1][3] = (m.m[0][0] * m.m[1][2] * m.m[2][3] + m.m[0][2] * m.m[1][3] * m.m[2][0] +
		m.m[0][3] * m.m[1][0] * m.m[2][2] - m.m[0][3] * m.m[1][2] * m.m[2][0] -
		m.m[0][2] * m.m[1][0] * m.m[2][3] - m.m[0][0] * m.m[1][3] * m.m[2][2]) * recpDeterminant;

	result.m[2][0] = (m.m[1][0] * m.m[2][1] * m.m[3][3] + m.m[1][1] * m.m[2][3] * m.m[3][0] +
		m.m[1][3] * m.m[2][0] * m.m[3][1] - m.m[1][3] * m.m[2][1] * m.m[3][0] -
		m.m[1][1] * m.m[2][0] * m.m[3][3] - m.m[1][0] * m.m[2][3] * m.m[3][1]) * recpDeterminant;
	result.m[2][1] = (-m.m[0][0] * m.m[2][1] * m.m[3][3] - m.m[0][1] * m.m[2][3] * m.m[3][0] -
		m.m[0][3] * m.m[2][0] * m.m[3][1] + m.m[0][3] * m.m[2][1] * m.m[3][0] +
		m.m[0][1] * m.m[2][0] * m.m[3][3] + m.m[0][0] * m.m[2][3] * m.m[3][1]) * recpDeterminant;
	result.m[2][2] = (m.m[0][0] * m.m[1][1] * m.m[3][3] + m.m[0][1] * m.m[1][3] * m.m[3][0] +
		m.m[0][3] * m.m[1][0] * m.m[3][1] - m.m[0][3] * m.m[1][1] * m.m[3][0] -
		m.m[0][1] * m.m[1][0] * m.m[3][3] - m.m[0][0] * m.m[1][3] * m.m[3][1]) * recpDeterminant;
	result.m[2][3] = (-m.m[0][0] * m.m[1][1] * m.m[2][3] - m.m[0][1] * m.m[1][3] * m.m[2][0] -
		m.m[0][3] * m.m[1][0] * m.m[2][1] + m.m[0][3] * m.m[1][1] * m.m[2][0] +
		m.m[0][1] * m.m[1][0] * m.m[2][3] + m.m[0][0] * m.m[1][3] * m.m[2][1]) * recpDeterminant;

	result.m[3][0] = (-m.m[1][0] * m.m[2][1] * m.m[3][2] - m.m[1][1] * m.m[2][2] * m.m[3][0] -
		m.m[1][2] * m.m[2][0] * m.m[3][1] + m.m[1][2] * m.m[2][1] * m.m[3][0] +
		m.m[1][1] * m.m[2][0] * m.m[3][2] + m.m[1][0] * m.m[2][2] * m.m[3][1]) * recpDeterminant;
	result.m[3][1] = (m.m[0][0] * m.m[2][1] * m.m[3][2] + m.m[0][1] * m.m[2][2] * m.m[3][0] +
		m.m[0][2] * m.m[2][0] * m.m[3][1] - m.m[0][2] * m.m[2][1] * m.m[3][0] -
		m.m[0][1] * m.m[2][0] * m.m[3][2] - m.m[0][0] * m.m[2][2] * m.m[3][1]) * recpDeterminant;
	result.m[3][2] = (-m.m[0][0] * m.m[1][1] * m.m[3][2] - m.m[0][1] * m.m[1][2] * m.m[3][0] -
		m.m[0][2] * m.m[1][0] * m.m[3][1] + m.m[0][2] * m.m[1][1] * m.m[3][0] +
		m.m[0][1] * m.m[1][0] * m.m[3][2] + m.m[0][0] * m.m[1][2] * m.m[3][1]) * recpDeterminant;
	result.m[3][3] = (m.m[0][0] * m.m[1][1] * m.m[2][2] + m.m[0][1] * m.m[1][2] * m.m[2][0] +
		m.m[0][2] * m.m[1][0] * m.m[2][1] - m.m[0][2] * m.m[1][1] * m.m[2][0] -
		m.m[0][1] * m.m[1][0] * m.m[2][2] - m.m[0][0] * m.m[1][2] * m.m[2][1]) * recpDeterminant;

	return result;
}

//転置行列
Matrix4x4 Transpose(const Matrix4x4& m) {
	Matrix4x4 result{};
	result.m[0][0] = m.m[0][0];
	result.m[0][1] = m.m[1][0];
	result.m[0][2] = m.m[2][0];
	result.m[0][3] = m.m[3][0];

	result.m[1][0] = m.m[0][1];
	result.m[1][1] = m.m[1][1];
	result.m[1][2] = m.m[2][1];
	result.m[1][3] = m.m[3][1];

	result.m[2][0] = m.m[0][2];
	result.m[2][1] = m.m[1][2];
	result.m[2][2] = m.m[2][2];
	result.m[2][3] = m.m[3][2];

	result.m[3][0] = m.m[0][3];
	result.m[3][1] = m.m[1][3];
	result.m[3][2] = m.m[2][3];
	result.m[3][3] = m.m[3][3];

	return result;
}

//単位行列
Matrix4x4 MakeIdentity4x4() {
	Matrix4x4 identity{};
	identity.m[0][0] = 1.0f;	identity.m[0][1] = 0.0f;	identity.m[0][2] = 0.0f;	identity.m[0][3] = 0.0f;
	identity.m[1][0] = 0.0f;	identity.m[1][1] = 1.0f;	identity.m[1][2] = 0.0f;	identity.m[1][3] = 0.0f;
	identity.m[2][0] = 0.0f;	identity.m[2][1] = 0.0f;	identity.m[2][2] = 1.0f;	identity.m[2][3] = 0.0f;
	identity.m[3][0] = 0.0f;	identity.m[3][1] = 0.0f;	identity.m[3][2] = 0.0f;	identity.m[3][3] = 1.0f;
	return identity;
}

//平行移動行列を作る
Matrix4x4 MakeTranslateMatrix(const Vector3& translate) {
	return {
	  1.0f, 0.0f, 0.0f, 0.0f, 0.0f,        1.0f,        0.0f,        0.0f,
	  0.0f, 0.0f, 1.0f, 0.0f, translate.x, translate.y, translate.z, 1.0f,
	};
}

//拡大縮小行列を作る
Matrix4x4 MakeScaleMatrix(const Vector3& scale) {
	return {
		scale.x, 0.0f, 0.0f, 0.0f,
		0.0f, scale.y, 0.0f, 0.0f,
		0.0f, 0.0f, scale.z, 0.0f,
		0.0f, 0.0f, 0.0f, 1.0f,
	};
}

//座標変換
Vector3 Transform(const Vector3& vector, const Matrix4x4& matrix) {

	Vector3 result{};

	// w=1がデカルト座標系であるので(x,y,1)のベクトルとしてmatrixとの積をとる
	result.x = vector.x * matrix.m[0][0] +
		vector.y * matrix.m[1][0] +
		vector.z * matrix.m[2][0] +
		1.0f * matrix.m[3][0];

	result.y = vector.x * matrix.m[0][1] +
		vector.y * matrix.m[1][1] +
		vector.z * matrix.m[2][1] +
		1.0f * matrix.m[3][1];

	result.z = vector.x * matrix.m[0][2] +
		vector.y * matrix.m[1][2] +
		vector.z * matrix.m[2][2] +
		1.0f * matrix.m[3][2];

	float w = vector.x * matrix.m[0][3] +
		vector.y * matrix.m[1][3] +
		vector.z * matrix.m[2][3] +
		1.0f * matrix.m[3][3];

	// w=1がデカルト座標系であるので、w除算することで同次座標をデカルト座標に戻す
	result.x /= w;
	result.y /= w;
	result.z /= w;
	return result;
}

//X軸の回転行列
Matrix4x4 MakeRotateXMatrix(float radian) {
	float cosTheta = cosf(radian);
	float sinTheta = sinf(radian);
	return {
		1.0f,   0.0f,     0.0f,   0.0f,
		0.0f, cosTheta, sinTheta, 0.0f,
		0.0f, -sinTheta, cosTheta,0.0f,
		0.0f,    0.0f,    0.0f,   1.0f
	};
}

//Y軸の回転行列
Matrix4x4 MakeRotateYMatrix(float radian) {
	float cosTheta = cos(radian);
	float sinTheta = sin(radian);
	return {
		cosTheta, 0.0f, -sinTheta, 0.0f,
		0.0f,     1.0f,   0.0f,    0.0f,
		sinTheta, 0.0f, cosTheta,  0.0f,
		0.0f,     0.0f,   0.0f,    1.0f 
	};
}

//Z軸の回転行列
Matrix4x4 MakeRotateZMatrix(float radian) {

	float cosTheta = cos(radian);
	float sinTheta = sin(radian);
	return { 
		cosTheta, sinTheta, 0.0f, 0.0f,
		-sinTheta,cosTheta, 0.0f, 0.0f,
		0.0f,       0.0f,   0.0f, 0.0f,
		0.0f,       0.0f,   0.0f, 1.0f 
	};
}

//アフィン変換
Matrix4x4 MakeAffineMatrix(const Vector3& scale, const Vector3& rotate, const Vector3& translate)
{

	Matrix4x4 result = Multiply(
		Multiply(MakeRotateXMatrix(rotate.x), MakeRotateYMatrix(rotate.y)),
		MakeRotateZMatrix(rotate.z));
	result.m[0][0] *= scale.x;
	result.m[0][1] *= scale.x;
	result.m[0][2] *= scale.x;

	result.m[1][0] *= scale.y;
	result.m[1][1] *= scale.y;
	result.m[1][2] *= scale.y;

	result.m[2][0] *= scale.z;
	result.m[2][1] *= scale.z;
	result.m[2][2] *= scale.z;

	result.m[3][0] = translate.x;
	result.m[3][1] = translate.y;
	result.m[3][2] = translate.z;

	return result;

}

//透視投影
Matrix4x4 MakePerspectiveFovMatrix(float fovY, float aspectRatio, float nearClip, float farClip) {
	
	float cotHalfFovV = 1.0f / std::tan(fovY / 2.0f);

	return {
		(cotHalfFovV / aspectRatio), 0.0f, 0.0f, 0.0f,
		0.0f, cotHalfFovV, 0.0f, 0.0f,
		0.0f, 0.0f, farClip / (farClip - nearClip), 1.0f,
		0.0f, 0.0f, -(farClip * nearClip) / (farClip - nearClip), 0.0f
	};
}

//正射影行列
Matrix4x4 MakeOrthographicMatrix(float left, float top, float right, float bottom, float nearClip, float farClip) {

	return {
		2.0f / (right - left), 0.0f, 0.0f, 0.0f,
		0.0f, 2.0f / (top - bottom), 0.0f, 0.0f,
		0.0f, 0.0f, 1.0f / (farClip - nearClip), 0.0f,
		(left + right) / (left - right), (top + bottom) / (bottom - top), nearClip / (nearClip - farClip), 1.0f,
	};
}

//ビューポート変換行列
Matrix4x4 MakeViewportMatrix(float left, float top, float width, float height, float minDepth, float maxDepth) {

	return {
		width / 2.0f, 0.0f, 0.0f, 0.0f,
		0.0f, -height / 2.0f, 0.0f, 0.0f,
		0.0f, 0.0f, maxDepth - minDepth, 0.0f,
		left + width / 2.0f, top + height / 2.0f, minDepth, 1.0f,
	};
}

//クロス積
Vector3 Cross(const Vector3& v1, const Vector3& v2) {

	Vector3 result{};
	result.x = v1.y * v2.z - v1.z * v2.y;
	result.y = v1.z * v2.x - v1.x * v2.z;
	result.z = v1.x * v2.y - v1.y * v2.x;
	return result;

}

//アフィン変換行列
Matrix4x4 MakeAffineMatrixQueue(const Vector3& scale, const Vector3& rot, const Vector3& translate) {

	Matrix4x4 ScallMat,
		RotateMat, RotateMatX, RotateMatY, RotateMatZ,
		TranslateMat,
		returnMat;

	// スケール行列作成
	ScallMat = { scale.x, 0, 0, 0,
				0, scale.y, 0, 0,
				0, 0, scale.z, 0,
				0, 0, 0, 1 };

	// XYZ回転行列作成
	RotateMatX = { 1, 0, 0, 0,
				  0, cosf(rot.x), sinf(rot.x), 0,
				  0,-sinf(rot.x), cosf(rot.x), 0,
				  0, 0, 0, 1 };

	RotateMatY = { cosf(rot.y), 0,-sinf(rot.y), 0,
				  0, 1, 0, 0,
				  sinf(rot.y), 0, cosf(rot.y), 0,
				  0, 0, 0, 1 };

	RotateMatZ = { cosf(rot.z), sinf(rot.z), 0, 0,
				 -sinf(rot.z), cosf(rot.z), 0, 0,
				  0, 0, 1, 0,
				  0, 0, 0, 1 };

	// XYZ回転行列の合成(Z*X*Y)
	RotateMat = Multiply(RotateMatZ, RotateMatX);
	// ↑の結果＊Y軸回転
	RotateMat = Multiply(RotateMat, RotateMatY);

	// 平行移動行列作成
	TranslateMat = { 1, 0, 0, 0,
					0, 1, 0, 0,
					0, 0, 1, 0,
					translate.x, translate.y, translate.z, 1 };

	// スケール＊回転＊平行移動をワールド変換行列に
	returnMat = Multiply(ScallMat, RotateMat);
	returnMat = Multiply(returnMat, TranslateMat);

	return returnMat;
}

//グリッド
void DrawGrid(const Matrix4x4& viewProjectionMatrix, const Matrix4x4& viewportMatrix) {
	const float kGridHalfWidth = 2.0f;
	const uint32_t kSubdivision = 10;
	const float kGridEvery = (kGridHalfWidth * 2.0f) / float(kSubdivision);
	for (uint32_t xIndex = 0; xIndex <= kSubdivision; ++xIndex) {
		float x = -kGridHalfWidth + (xIndex * kGridEvery);
		Vector3 start{ x, 0.0f, -kGridHalfWidth };
		Vector3 end{ x, 0.0f, kGridHalfWidth };
		Vector3 startScreen = Transform(Transform(start, viewProjectionMatrix), viewportMatrix);
		Vector3 endScreen = Transform(Transform(end, viewProjectionMatrix), viewportMatrix);
		Novice::DrawLine(
			int(startScreen.x), int(startScreen.y), int(endScreen.x), int(endScreen.y),
			x == 0.0f ? BLACK : 0xAAAAAAFF);
	}
	for (uint32_t zIndex = 0; zIndex <= kSubdivision; ++zIndex) {
		float z = -kGridHalfWidth + (zIndex * kGridEvery);
		Vector3 start{ -kGridHalfWidth, 0.0f, z };
		Vector3 end{ kGridHalfWidth, 0.0f, z };
		Vector3 startScreen = Transform(Transform(start, viewProjectionMatrix), viewportMatrix);
		Vector3 endScreen = Transform(Transform(end, viewProjectionMatrix), viewportMatrix);
		Novice::DrawLine(
			int(startScreen.x), int(startScreen.y), int(endScreen.x), int(endScreen.y),
			z == 0.0f ? BLACK : 0xAAAAAAFF);
	}
}

//球体
void DrawSphere(const Sphere& sphere, const Matrix4x4& viewProjectionMatrix, const Matrix4x4& viewportMatrix, uint32_t color) {
	float pi = std::numbers::pi_v<float>;
	const uint32_t kSubdivision = 12;
	// 経度分割1つ分の角度
	const float kLonEvery = pi * 2.0f / float(kSubdivision);
	// 緯度分割1つ分の角度
	const float kLatEvery = pi / float(kSubdivision);
	// 緯度の方向に分割
	for (uint32_t latIndex = 0; latIndex < kSubdivision; ++latIndex) {
		float lat = -pi / 2.0f + kLatEvery * latIndex;
		// 経度の方向に分割しながら線を描く
		for (uint32_t lonIndex = 0; lonIndex < kSubdivision; ++lonIndex) {
			float lon = lonIndex * kLonEvery;
			Vector3 a = {
			  sphere.center.x + sphere.radius * cosf(lat) * cosf(lon),
			  sphere.center.y + sphere.radius * sinf(lat),
			  sphere.center.z + sphere.radius * cosf(lat) * sinf(lon) };
			Vector3 b = {
			  sphere.center.x + sphere.radius * cosf(lat + kLatEvery) * cosf(lon),
			  sphere.center.y + sphere.radius * sinf(lat + kLatEvery),
			  sphere.center.z + sphere.radius * cosf(lat + kLatEvery) * sinf(lon) };
			Vector3 c = {
			  sphere.center.x + sphere.radius * cosf(lat) * cosf(lon + kLonEvery),
			  sphere.center.y + sphere.radius * sinf(lat),
			  sphere.center.z + sphere.radius * cosf(lat) * sinf(lon + kLonEvery) };
			// 線を描く
			Vector3 screenA = Transform(Transform(a, viewProjectionMatrix), viewportMatrix);
			Vector3 screenB = Transform(Transform(b, viewProjectionMatrix), viewportMatrix);
			Vector3 screenC = Transform(Transform(c, viewProjectionMatrix), viewportMatrix);
			Novice::DrawLine(int(screenA.x), int(screenA.y), int(screenB.x), int(screenB.y), color);
			Novice::DrawLine(int(screenA.x), int(screenA.y), int(screenC.x), int(screenC.y), color);
		}
	}
}

//加算
Vector3 AddV(const Vector3& v1, const Vector3& v2) {
	return Vector3(v1.x + v2.x, v1.y + v2.y, v1.z + v2.z);

}
//減算
Vector3 SubtractV(const Vector3& v1, const Vector3& v2) {
	return Vector3(v1.x - v2.x, v1.y - v2.y, v1.z - v2.z);
}
//内積
float Dot(const Vector3& v1, const Vector3& v2) {
	return v1.x * v2.x + v1.y * v2.y + v1.z * v2.z;
}
//長さ
float Length(const Vector3& v) {
	return sqrtf(Dot(v, v));
}
//正規化
inline Vector3 Normalize(const Vector3& v) {
	float v2 = 0.0f;
	v2 = Length(v);
	return{ v.x / v2,v.y / v2,v.z / v2 };
}

//=-----------------------------------------------------------
//正射影ベクトル
Vector3 Project(const Vector3& v1, const Vector3& v2) {
	Vector3 result{};

	result.x = Dot(v1, Normalize(v2)) * Normalize(v2).x;
	result.y = Dot(v1, Normalize(v2)) * Normalize(v2).y;
	result.z = Dot(v1, Normalize(v2)) * Normalize(v2).z;

	return result;
}
//最近接点
Vector3 ClosestPoint(const Vector3& point, const Segment& segment) {

	return AddV(Project(SubtractV(point, segment.origin), segment.diff), segment.origin);

}

Matrix4x4 MakeViewProjectionMatrix(Vector3 scale, Vector3 rotate, Vector3 translate, Vector3 cameraScale, Vector3 cameraRotate, Vector3 cameraTranslate) {
	Matrix4x4 worldMatrix = MakeAffineMatrixQueue(scale, rotate, translate);
	Matrix4x4 cameraMatrix = MakeAffineMatrixQueue(cameraScale, cameraRotate, cameraTranslate);
	Matrix4x4 viewMatrix = Inverse(cameraMatrix);
	Matrix4x4 projectionMatrix = MakePerspectiveFovMatrix(0.45f, 720.0f / 1280.0f, 0.1f, 100.0f);
	MatrixScreenPrintf(0, 0, viewMatrix, "viewprojection");
	return (Multiply(worldMatrix, Multiply(viewMatrix, projectionMatrix)));

}
//=-----------------------------------------------------------