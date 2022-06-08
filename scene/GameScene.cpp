#include "GameScene.h"
#include "TextureManager.h"
#include <cassert>
#include"AxisIndicator.h"
#include"PrimitiveDrawer.h"

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
	//ワールドトランスフォームの初期化
	worldTransform_.Initialize();
	//ビュープロジェクションの初期化
	viewProjection_.Initialize();
	//デバッグカメラの生成
	debugCamera_ = new DebugCamera(1280, 720);
	//軸方向表示の表示を有効にする
	AxisIndicator::GetInstance()->SetVisible(true);
	//軸方向表示が参照するビュープロジェクションを指定する(アドレス渡し)
	AxisIndicator::GetInstance()->SetTargetViewProjection(&debugCamera_->GetViewProjection());
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
	
	worldTransform_.rotation_ = { 0.0f,0.0f,PI / 4 };

	Matrix4 matRotZ=
	{ 1.0f,0.0f,0.0f,0.0f,
      0.0f,1.0f,0.0f,0.0f,
      0.0f,0.0f,1.0f,0.0f,
      0.0f,0.0f,0.0f,1.0f };

	matRotZ.m[0][0] = cos(worldTransform_.rotation_.z);
	matRotZ.m[0][1] = sin(worldTransform_.rotation_.z);
	matRotZ.m[1][0] = -sin(worldTransform_.rotation_.z);
	matRotZ.m[1][1] = cos(worldTransform_.rotation_.z);

	worldTransform_.matWorld_ = {
			1.0f,0.0f,0.0f,0.0f,
			0.0f,1.0f,0.0f,0.0f,
			0.0f,0.0f,1.0f,0.0f,
		    0.0f,0.0f,0.0f,1.0f };

	worldTransform_.matWorld_ *= matRotZ;

	//行列の転送
	worldTransform_.TransferMatrix();
}

void GameScene::Update() { debugCamera_->Update(); }

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
	model_->Draw(worldTransform_, debugCamera_->GetViewProjection(), textureHandle_);
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
