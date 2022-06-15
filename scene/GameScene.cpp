#include "GameScene.h"
#include "TextureManager.h"
#include <cassert>
#include"AxisIndicator.h"
#include"PrimitiveDrawer.h"
#include"Object.h"
#include<random>
float PI = 3.14159265f;

GameScene::GameScene() {}

GameScene::~GameScene() {}

void GameScene::Initialize() {

	dxCommon_ = DirectXCommon::GetInstance();
	input_ = Input::GetInstance();
	audio_ = Audio::GetInstance();
	debugText_ = DebugText::GetInstance();
	//ファイル名を指定してテクスチャを読み込む
	textureHandle_ = TextureManager::Load("mario.jpg");
	//3Dモデルの生成
	model_ = Model::Create();
	//乱数シード生成器
	std::random_device seed_gen;
	//メルセンヌ・ツイスターの乱数エンジン
	std::mt19937_64 engin(seed_gen());

	

		//親(0番)
		worldTransforms_[0].Initialize();
		//子(1番)
		worldTransforms_[1].Initialize();
		worldTransforms_[1].translation_ = { 0,4.5f,0 };
		worldTransforms_[1].parent_ = &worldTransforms_[0];
		
		
	
	
	
	
	
	//ビュープロジェクションの初期化
	viewProjection_.Initialize();
	
	//デバッグカメラの生成
	debugCamera_ = new DebugCamera(1280, 720);
	//軸方向表示の表示を有効にする
	AxisIndicator::GetInstance()->SetVisible(true);
	//軸方向表示が参照するビュープロジェクションを指定する(アドレス渡し)
	AxisIndicator::GetInstance()->SetTargetViewProjection(&viewProjection_);
	//ライン描画が参照するビュープロジェクションを指定する(アドレス渡し)
	PrimitiveDrawer::GetInstance()->SetViewProjection(&debugCamera_->GetViewProjection());
	
	
	

	

	
#pragma region スケーリング
	////X,Y,Z方向のスケーリングを設定
	//worldTransform_.scale_ = { 2.0f, 2.0f, 2.0f };
	////スケーリング行列を宣言
	////Matrix4 matScale;

	////スケーリング倍率を行列に設定する
	//Matrix4 matScale =
	//{ 1.0f,0.0f,0.0f,0.0f,
	//  0.0f,1.0f,0.0f,0.0f,
	//  0.0f,0.0f,1.0f,0.0f,
	//  0.0f,0.0f,0.0f,1.0f };


	//matScale.m[0][0] = worldTransform_.scale_.x;
	//matScale.m[1][1] = worldTransform_.scale_.y;
	//matScale.m[2][2] = worldTransform_.scale_.z;
	////単位行列を代入する
	//worldTransform_.matWorld_ = {
	//	1.0f,0.0f,0.0f,0.0f,
	//	0.0f,1.0f,0.0f,0.0f,
	//	0.0f,0.0f,1.0f,0.0f,
	//    0.0f,0.0f,0.0f,1.0f };
	////worldTransform_.matWorld_にmatScaleを掛け算して代入する
	//worldTransform_.matWorld_ *= matScale;

	////行列の転送
	//worldTransform_.TransferMatrix();
#pragma endregion

#pragma region Z軸まわりの回転

	////X,Y,Z方向の回転角を設定
	//worldTransform_.rotation_ = { 0.0f,0.0f,PI / 4 };

	////Z軸回転行列を宣言
	//Matrix4 matRotZ=
	//{ 1.0f,0.0f,0.0f,0.0f,
 //     0.0f,1.0f,0.0f,0.0f,
 //     0.0f,0.0f,1.0f,0.0f,
 //     0.0f,0.0f,0.0f,1.0f };


	//matRotZ.m[0][0] = cos(worldTransform_.rotation_.z);
	//matRotZ.m[0][1] = sin(worldTransform_.rotation_.z);
	//matRotZ.m[1][0] = -sin(worldTransform_.rotation_.z);
	//matRotZ.m[1][1] = cos(worldTransform_.rotation_.z);

	////単位行列を代入する
	//worldTransform_.matWorld_ = {
	//		1.0f,0.0f,0.0f,0.0f,
	//		0.0f,1.0f,0.0f,0.0f,
	//		0.0f,0.0f,1.0f,0.0f,
	//	    0.0f,0.0f,0.0f,1.0f };

	////worldTransform_.matWorld_にmatRotZを掛け算して代入する
	//worldTransform_.matWorld_ *= matRotZ;

	////行列の転送
	//worldTransform_.TransferMatrix();
#pragma endregion

#pragma region X軸まわりの回転
	////X,Y,Z方向の回転角を設定
	//worldTransform_.rotation_ = { PI/4,0.0f,0.0f };

	////X軸回転行列を宣言
	//Matrix4 matRotX=
	//{ 1.0f,0.0f,0.0f,0.0f,
 //     0.0f,1.0f,0.0f,0.0f,
 //     0.0f,0.0f,1.0f,0.0f,
 //     0.0f,0.0f,0.0f,1.0f };


	//matRotX.m[1][1] = cos(worldTransform_.rotation_.x);
	//matRotX.m[1][2] = sin(worldTransform_.rotation_.x);
	//matRotX.m[2][1] = -sin(worldTransform_.rotation_.x);
	//matRotX.m[2][2] = cos(worldTransform_.rotation_.x);

	////単位行列を代入する
	//worldTransform_.matWorld_ = {
	//		1.0f,0.0f,0.0f,0.0f,
	//		0.0f,1.0f,0.0f,0.0f,
	//		0.0f,0.0f,1.0f,0.0f,
	//	    0.0f,0.0f,0.0f,1.0f };

	////worldTransform_.matWorld_にmatRotXを掛け算して代入する
	//worldTransform_.matWorld_ *= matRotX;

	////行列の転送
	//worldTransform_.TransferMatrix();
#pragma endregion

#pragma region Y軸まわりの回転
	////X,Y,Z方向の回転角を設定
	//worldTransform_.rotation_ = { 0.0f,PI/4,0.0f };

	////Y軸回転行列を宣言
	//Matrix4 matRotY =
	//{ 1.0f,0.0f,0.0f,0.0f,
	//  0.0f,1.0f,0.0f,0.0f,
	//  0.0f,0.0f,1.0f,0.0f,
	//  0.0f,0.0f,0.0f,1.0f };


	//matRotY.m[0][0] = cos(worldTransform_.rotation_.y);
	//matRotY.m[0][2] = sin(worldTransform_.rotation_.y);
	//matRotY.m[2][0] = -sin(worldTransform_.rotation_.y);
	//matRotY.m[2][2] = cos(worldTransform_.rotation_.y);

	////単位行列を代入する
	//worldTransform_.matWorld_ = {
	//		1.0f,0.0f,0.0f,0.0f,
	//		0.0f,1.0f,0.0f,0.0f,
	//		0.0f,0.0f,1.0f,0.0f,
	//		0.0f,0.0f,0.0f,1.0f };

	////worldTransform_.matWorld_にmatRotYを掛け算して代入する
	//worldTransform_.matWorld_ *= matRotY;

	////行列の転送
	//worldTransform_.TransferMatrix();
#pragma endregion

#pragma region 回転の合成
 //   //X,Y,Z軸周りの回転角を設定
 //   worldTransform_.rotation_ = { PI / 4,PI / 4,PI / 4 };
 //   //合成用回転行列を宣言
 //   Matrix4 matRot =
 //   { 1.0f,0.0f,0.0f,0.0f,
 //     0.0f,1.0f,0.0f,0.0f,
 //     0.0f,0.0f,1.0f,0.0f,
 //     0.0f,0.0f,0.0f,1.0f };
 //   //各軸用回転行列を宣言
 //   Matrix4 matRotZ =
 //   { 1.0f,0.0f,0.0f,0.0f,
 //     0.0f,1.0f,0.0f,0.0f,
 //     0.0f,0.0f,1.0f,0.0f,
 //     0.0f,0.0f,0.0f,1.0f };

 //   Matrix4 matRotX =
 //   { 1.0f,0.0f,0.0f,0.0f,
 //     0.0f,1.0f,0.0f,0.0f,
 //     0.0f,0.0f,1.0f,0.0f,
 //     0.0f,0.0f,0.0f,1.0f };

 //   Matrix4 matRotY =
 //   { 1.0f,0.0f,0.0f,0.0f,
 //     0.0f,1.0f,0.0f,0.0f,
 //     0.0f,0.0f,1.0f,0.0f,
 //     0.0f,0.0f,0.0f,1.0f };

 //   //Z軸回転行列の各要素を設定する(回転角θZ)
 //   matRotZ.m[0][0] = cos(worldTransform_.rotation_.z);
 //   matRotZ.m[0][1] = sin(worldTransform_.rotation_.z);
 //   matRotZ.m[1][0] = -sin(worldTransform_.rotation_.z);
 //   matRotZ.m[1][1] = cos(worldTransform_.rotation_.z);

 //   //X軸回転行列の各要素を設定する(回転角θX)
 //   matRotX.m[1][1] = cos(worldTransform_.rotation_.x);
 //   matRotX.m[1][2] = sin(worldTransform_.rotation_.x);
 //   matRotX.m[2][1] = -sin(worldTransform_.rotation_.x);
 //   matRotX.m[2][2] = cos(worldTransform_.rotation_.x);

 //   //ZY軸回転行列の各要素を設定する(回転角θY)
 //   matRotY.m[0][0] = cos(worldTransform_.rotation_.y);
 //   matRotY.m[0][2] = sin(worldTransform_.rotation_.y);
 //   matRotY.m[2][0] = -sin(worldTransform_.rotation_.y);
 //   matRotY.m[2][2] = cos(worldTransform_.rotation_.y);

 //   //各軸の回転行列を合成
 //   matRot = matRotZ *= matRotX *= matRotY;

 //   //単位行列を代入する
 //   worldTransform_.matWorld_ = {
	//	1.0f,0.0f,0.0f,0.0f,
	//	0.0f,1.0f,0.0f,0.0f,
	//	0.0f,0.0f,1.0f,0.0f,
	//	0.0f,0.0f,0.0f,1.0f };

 //   //worldTransform_.matWorld_にmatRotを掛け算して代入する
 //   worldTransform_.matWorld_ *= matRot;

 //   //行列の転送
	//worldTransform_.TransferMatrix();

#pragma endregion

#pragma region 平行移動
 //   //X,Y,Z軸周りの平行移動を設定
 //   worldTransform_.translation_ = { 10.0f,10.0f,10.0f };
	//
	////移動量を行列に設定する
	//Matrix4 matTrans =
	//{ 1.0f,0.0f,0.0f,0.0f,
	//  0.0f,1.0f,0.0f,0.0f,
	//  0.0f,0.0f,1.0f,0.0f,
	//  0.0f,0.0f,0.0f,1.0f };

	//matTrans.m[3][0] = worldTransform_.translation_.x;
	//matTrans.m[3][1] = worldTransform_.translation_.y;
	//matTrans.m[3][2] = worldTransform_.translation_.z;

	//worldTransform_.matWorld_=
	//{ 1.0f,0.0f,0.0f,0.0f,
 //     0.0f,1.0f,0.0f,0.0f,
 //     0.0f,0.0f,1.0f,0.0f,
 //     0.0f,0.0f,0.0f,1.0f };

	//worldTransform_.matWorld_ *= matTrans;

	////行列の転送
	//worldTransform_.TransferMatrix();
#pragma endregion

#pragma region 組み合わせ
	////スケーリング行列の設定
 //   worldTransform_.scale_ = { 5.0f, 5.0f, 5.0f };

	////スケーリング倍率を行列に設定する
	//Matrix4 matScale =
	//{ 1.0f,0.0f,0.0f,0.0f,
	//  0.0f,1.0f,0.0f,0.0f,
	//  0.0f,0.0f,1.0f,0.0f,
	//  0.0f,0.0f,0.0f,1.0f };


	//matScale.m[0][0] = worldTransform_.scale_.x;
	//matScale.m[1][1] = worldTransform_.scale_.y;
	//matScale.m[2][2] = worldTransform_.scale_.z;

	////回転行列の設定
	//worldTransform_.rotation_ = { PI/4,PI/4,0.0f };

	////合成用回転行列を宣言
	//Matrix4 matRot =
	//{ 1.0f,0.0f,0.0f,0.0f,
	//  0.0f,1.0f,0.0f,0.0f,
	//  0.0f,0.0f,1.0f,0.0f,
	//  0.0f,0.0f,0.0f,1.0f };
	////各軸用回転行列を宣言
	//Matrix4 matRotZ =
	//{ 1.0f,0.0f,0.0f,0.0f,
	//  0.0f,1.0f,0.0f,0.0f,
	//  0.0f,0.0f,1.0f,0.0f,
	//  0.0f,0.0f,0.0f,1.0f };

	//Matrix4 matRotX =
	//{ 1.0f,0.0f,0.0f,0.0f,
	//  0.0f,1.0f,0.0f,0.0f,
	//  0.0f,0.0f,1.0f,0.0f,
	//  0.0f,0.0f,0.0f,1.0f };

	//Matrix4 matRotY =
	//{ 1.0f,0.0f,0.0f,0.0f,
	//  0.0f,1.0f,0.0f,0.0f,
	//  0.0f,0.0f,1.0f,0.0f,
	//  0.0f,0.0f,0.0f,1.0f };

	////Z軸回転行列の各要素を設定する(回転角θZ)
	//matRotZ.m[0][0] = cos(worldTransform_.rotation_.z);
	//matRotZ.m[0][1] = sin(worldTransform_.rotation_.z);
	//matRotZ.m[1][0] = -sin(worldTransform_.rotation_.z);
	//matRotZ.m[1][1] = cos(worldTransform_.rotation_.z);

	////X軸回転行列の各要素を設定する(回転角θX)
	//matRotX.m[1][1] = cos(worldTransform_.rotation_.x);
	//matRotX.m[1][2] = sin(worldTransform_.rotation_.x);
	//matRotX.m[2][1] = -sin(worldTransform_.rotation_.x);
	//matRotX.m[2][2] = cos(worldTransform_.rotation_.x);

	////Y軸回転行列の各要素を設定する(回転角θY)
	//matRotY.m[0][0] = cos(worldTransform_.rotation_.y);
	//matRotY.m[0][2] = -sin(worldTransform_.rotation_.y);
	//matRotY.m[2][0] = sin(worldTransform_.rotation_.y);
	//matRotY.m[2][2] = cos(worldTransform_.rotation_.y);

	////各軸の回転行列を合成
	//matRot *= matRotZ *= matRotX *= matRotY;

	////平行移動行列の設定
	//worldTransform_.translation_ = { 10.0f, 10.0f, 10.0f };

	//Matrix4 matTrans =
	//{ 1.0f,0.0f,0.0f,0.0f,
	//  0.0f,1.0f,0.0f,0.0f,
	//  0.0f,0.0f,1.0f,0.0f,
	//  0.0f,0.0f,0.0f,1.0f };

	//matTrans.m[3][0] = worldTransform_.translation_.x;
	//matTrans.m[3][1] = worldTransform_.translation_.y;
	//matTrans.m[3][2] = worldTransform_.translation_.z;

	////行列の合成
	//worldTransform_.matWorld_=
	//{ 1.0f,0.0f,0.0f,0.0f,
	//  0.0f,1.0f,0.0f,0.0f,
	//  0.0f,0.0f,1.0f,0.0f,
	//  0.0f,0.0f,0.0f,1.0f };

	//worldTransform_.matWorld_ *= matScale *= matRot *= matTrans;

	////行列の転送
	//worldTransform_.TransferMatrix();
#pragma endregion
}

void GameScene::Update() { 
	
	//キャラクター移動処理
	{
		//キャラクターの移動ベクトル
		Vector3 move = { 0,0,0 };
		//キャラクターの移動速度
		const float kCharacterSpeed = 0.2f;
		//押した方向で移動ベクトルを変更
		if (input_->PushKey(DIK_LEFT)) {
			move = { -kCharacterSpeed,0,0 };
		}
		else if (input_->PushKey(DIK_RIGHT)) {
			move = { kCharacterSpeed,0,0 };
		}
		worldTransforms_[0].translation_.x += move.x;
		worldTransforms_[0].translation_.y += move.y;
		worldTransforms_[0].translation_.z += move.z;
		
		worldTransforms_[0].TransferMatrix();
		worldTransforms_[1].TransferMatrix();
		//デバッグ用表示
		debugText_->SetPos(50, 150);
		debugText_->Printf(
			"kRoot:(%f,%f,%f)", worldTransforms_[PartId::kRoot].translation_.x,
			worldTransforms_[PartId::kRoot].translation_.y,
			worldTransforms_[PartId::kRoot].translation_.z);
	}
}

void GameScene::Draw() {

	// コマンドリストの取得
	ID3D12GraphicsCommandList* commandList = dxCommon_->GetCommandList();

#pragma region 背景スプライト描画
	// 背景スプライト描画前処理
	Sprite::PreDraw(commandList);

	/// <summary>
	/// ここに背景スプライトの描画処理を追加できる
	/// </summary>

	// スプライト描画後処理
	Sprite::PostDraw();
	// 深度バッファクリア
	dxCommon_->ClearDepthBuffer();
#pragma endregion

#pragma region 3Dオブジェクト描画
	// 3Dオブジェクト描画前処理
	Model::PreDraw(commandList);

	/// <summary>
	/// ここに3Dオブジェクトの描画処理を追加できる
	/// </summary>
	//ライン描画が参照するビュープロジェクションを指定する(アドレス渡し)
	//PrimitiveDrawer::GetInstance()->DrawLine3d(Vector3,Vector3,Vector4)

	
		model_->Draw(worldTransforms_[0], viewProjection_, textureHandle_);
		model_->Draw(worldTransforms_[1], viewProjection_, textureHandle_);
	
	
	//3Dモデル描画
	//model_->Draw(worldTransform_, viewProjection_, textureHandle_);
	// 3Dオブジェクト描画後処理
	Model::PostDraw();
#pragma endregion

#pragma region 前景スプライト描画
	// 前景スプライト描画前処理
	Sprite::PreDraw(commandList);

	/// <summary>
	/// ここに前景スプライトの描画処理を追加できる
	/// </summary>

	// デバッグテキストの描画
	debugText_->DrawAll(commandList);
	//
	// スプライト描画後処理
	Sprite::PostDraw();

#pragma endregion
}
