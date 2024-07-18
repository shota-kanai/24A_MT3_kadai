#include <Novice.h>
#include <stdio.h>
#include<Matrix4x4.h>
#include <Vector3.h>
#include <Matrix4x4Math.h>
#define _USE_MATH_DEFINES

#include <imgui.h>

const char kWindowTitle[] = "GC1C_05_カナイショウタ_タイトル";


// Windowsアプリでのエントリーポイント(main関数)
int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int) {

	// ライブラリの初期化
	const int kWindowWidth = 1280;
	const int kWindowHeight = 720;
	Novice::Initialize(kWindowTitle, kWindowWidth, kWindowHeight);

	// キー入力結果を受け取る箱
	char keys[256] = { 0 };
	char preKeys[256] = { 0 };

	//=============================================
	
	Vector3 cameraTranslate{ 0.0f, 1.9f, -6.49f };
	Vector3 cameraRotate{ 0.26f, 0.0f, 0.0f };
	Vector3 rotate{};
	Vector3 translate{};


	Sphere sphere{};
	sphere.radius = 30;

	//=============================================

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



		//カメラの拡大縮小、回転、平行移動ベクトルからカメラ空間の行列を作る
		Matrix4x4 cameraMatrix =
			MakeAffineMatrixQueue({ 1.0f, 1.0f, 1.0f }, cameraRotate, cameraTranslate);

		//ビュー行列：
		//カメラから見た視錐台空間に変換する行列。カメラ行列の逆行列
		Matrix4x4 viewMatrix = Inverse(cameraMatrix);

		//プロジェクション行列：
		//ビュー空間の視錐台を幅と高さが2、奥行きが1の直方体空間に変換する行列
		//この座標系を正規デバイス座標系という
		Matrix4x4 projectionMatrix =
			MakePerspectiveFovMatrix(0.45f, float(kWindowWidth) / float(kWindowHeight), 0.1f, 100.0f);

		//ビュー行列とプロジェクション行列を掛けて1つの行列に
			//物体の頂点にこれを掛けると平面に投影された2次元画像の座標になる
		Matrix4x4 viewProjectionMatrix = Multiply(viewMatrix, projectionMatrix);

		

		//ビューポート行列：
		//投影面に投影された2次元映像を、スクリーン座標系で表された
		//ウインドウ上の指定領域であるビューポート内に表示する変換行列
		Matrix4x4 viewportMatrix =
			MakeViewportMatrix(0, 0, float(kWindowWidth), float(kWindowHeight), 0.0f, 1.0f);

		ImGui::Begin("Window");
		ImGui::DragFloat3("CameraTranslate", &cameraTranslate.x, 0.01f);
		ImGui::DragFloat3("CameraRotate", &cameraRotate.x, 0.01f);
		ImGui::DragFloat3("SphereCenter", &sphere.center.x, 0.01f);
		ImGui::DragFloat("SphereRadius", &sphere.radius, 0.01f);
		ImGui::End();

		///
		/// ↑更新処理ここまで
		///

		///
		/// ↓描画処理ここから
		///

		//ワールド空間の頂点×ビュープロジェクション行列×ビューポート行列で
		//スクリーン空間の座標になる
		DrawGrid(viewProjectionMatrix, viewportMatrix);
		DrawSphere(sphere, viewProjectionMatrix, viewportMatrix, BLACK);

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
