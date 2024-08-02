#pragma once
#include<Matrix4x4.h>
#include <Novice.h>
#include<Vector3.h>
#include <math.h>
#include<cmath>
#include <numbers>
#include <Vector2.h>
#include <segment.h>
#include <stdio.h>

struct Segment
{
	Vector3 origin;
	Vector3 diff;
};

struct Line
{
	Vector3 origin;
	Vector3 diff;
};

struct Ray
{
	Vector3 origin;
	Vector3 diff;
};


static const int kRowHeight = 20;
static const int kColumnWidth = 60;

//Vectorスクリーンプリント
void VectorScreenPrintf(int x, int y, const Vector3& vector, const char* label);
//Matrixスクリーンプリント
void MatrixScreenPrintf(int x, int y, const Matrix4x4& matrix, const char* label);


struct Sphere {
	Vector3 center;//中心点
	float radius;//半径
};


	//行列加算
	Matrix4x4 Add(const Matrix4x4& m1, const Matrix4x4& m2);
	// 行列引き算
	Matrix4x4 Subtract(const Matrix4x4& m1, const Matrix4x4& m2);
	//行列掛け算
	Matrix4x4 Multiply(const Matrix4x4& m1, const Matrix4x4& m2);
	//逆行列
	Matrix4x4 Inverse(const Matrix4x4& m);
	//転置行列
	Matrix4x4 Transpose(const Matrix4x4& m);
	//単位行列
	Matrix4x4 MakeIdentity4x4();
	//平行移動行列を作る
	Matrix4x4 MakeTranslateMatrix(const Vector3& translate);
	//拡大縮小行列を作る
	Matrix4x4 MakeScaleMatrix(const Vector3& scale);
	//座標変換
	Vector3 Transform(const Vector3& vector, const Matrix4x4& matrix);
	//XYZ各軸の回転行列
	Matrix4x4 MakeRotateXMatrix(float radian);
	Matrix4x4 MakeRotateYMatrix(float radian);
	Matrix4x4 MakeRotateZMatrix(float radian);
	//アフィン変換
	Matrix4x4 MakeAffineMatrix(const Vector3& scale, const Vector3& rotate, const Vector3& translate);
	//透視投影
	Matrix4x4 MakePerspectiveFovMatrix(float fovY, float aspectRatio, float nearClip, float farClip);
	//正射影行列
	Matrix4x4 MakeOrthographicMatrix(float left, float top, float right, float bottom, float nearClip, float farClip);
	//ビューポート変換行列
	Matrix4x4 MakeViewportMatrix(float left, float top, float width, float height, float minDepth, float maxDepth);
	//クロス積
	Vector3 Cross(const Vector3& v1, const Vector3& v2);
	//アフィン変換行列
	Matrix4x4 MakeAffineMatrixQueue(const Vector3& scale, const Vector3& rot, const Vector3& translate);
	//グリッド
	void DrawGrid(const Matrix4x4& viewProjectionMatrix, const Matrix4x4& viewportMatrix);
	//球体
	void DrawSphere(const Sphere& sphere, const Matrix4x4& viewProjectionMatrix, const Matrix4x4& viewportMatrix, uint32_t color);

	struct SphericalCoordinate {
		float theta;
		float phi;
		float radius;
	};
	//Vectorの加算
	Vector3 AddV(const Vector3& v1, const Vector3& v2);
	//Vectorの減算
	Vector3 SubtractV(const Vector3& v1, const Vector3& v2);
	//内積
	float Dot(const Vector3& v1, const Vector3& v2);
	//長さ
	float Length(const Vector3& v);
	//正規化
	inline Vector3 Normalize(const Vector3& v);
	//正射影ベクトル
	Vector3 Project(const Vector3& v1, const Vector3& v2);
	//最近接点
	Vector3 ClosestPoint(const Vector3& point, const Segment& segment);

	Matrix4x4 MakeViewProjectionMatrix(Vector3 scale, Vector3 rotate, Vector3 translate, Vector3 cameraScale, Vector3 cameraRotate, Vector3 cameraTranslate);