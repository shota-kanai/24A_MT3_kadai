#include <Novice.h>
#include <stdio.h>
#include<Matrix4x4.h>
#include <Vector3.h>
#include <Matrix4x4Math.h>

const char kWindowTitle[] = "GC1C_05_カナイショウタ_タイトル";


// Windowsアプリでのエントリーポイント(main関数)
int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int) {

	// ライブラリの初期化
	Novice::Initialize(kWindowTitle, 1280, 720);

	// キー入力結果を受け取る箱
	char keys[256] = { 0 };
	char preKeys[256] = { 0 };

	Vector3 cameraTranslate{ 0.0f,1.9f,-6.49f };
	Vector3 cameraRotato{ 0.26f,0.0f,0.0f };

	Sphere sphere;
	sphere.center = { -10.0f, -40.0f, 162.0f };
	sphere.radius = 30;

	Sphere sphere2;
	sphere2.center = { 40.0f, -40.0f,162.0f };
	sphere2.radius = 20;

	Vector3 rotate{};
	Vector3 translate{};
	Vector3 Scale = { 1.0f,1.0f,1.0f };

	// ウィンドウの×ボタンが押されるまでループ
	while (Novice::ProcessMessage() == 0) {
		// フレームの開始
		Novice::BeginFrame();

		// キー入力を受け取る
		memcpy(preKeys, keys, 256);
		Novice::GetHitKeyStateAll(keys);

		///
		/// ↓更新処理ここから
		///


		//XYZ各軸の回転成分
		Vector3 rotate{ 0.4f, 1.43f, -0.8f };
		//X軸回転行列を作る
		Matrix4x4 rotateXMatrix = MakeRotateXMatrix(rotate.x);
		//Y軸回転行列を作る
		Matrix4x4 rotateYMatrix = MakeRotateYMatrix(rotate.y);
		//Z軸回転行列を作る
		Matrix4x4 rotateZMatrix = MakeRotateZMatrix(rotate.z);
		//XYZ各軸の回転行列を1つに合体する
		Matrix4x4 rotateXYZMatrix = Multiply(rotateXMatrix, Multiply(rotateYMatrix, rotateZMatrix));

		///
		/// ↑更新処理ここまで
		///

		///
		/// ↓描画処理ここから
		///

		MatrixScreenPrintf(0, 0, rotateXMatrix, "rotateXMatrix");
		MatrixScreenPrintf(0, kRowHeight * 5, rotateYMatrix, "rotateYMatrix");
		MatrixScreenPrintf(0, kRowHeight * 5 * 2, rotateZMatrix, "rotateZMatrix");
		MatrixScreenPrintf(0, kRowHeight * 5 * 3, rotateXYZMatrix, "rotateXYZMatrix"); 


		///
		/// ↑描画処理ここまで
		///

		// フレームの終了
		Novice::EndFrame();

		// ESCキーが押されたらループを抜ける
		if (preKeys[DIK_ESCAPE] == 0 && keys[DIK_ESCAPE] != 0) {
			break;
		}
	}

	// ライブラリの終了
	Novice::Finalize();
	return 0;
}
