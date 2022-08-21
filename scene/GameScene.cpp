﻿#include "GameScene.h"
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

	textureHandle2_ = TextureManager::Load("backscreen.jpg");
	//3Dモデルの生成
	model_ = Model::Create();
	//3Dモデルの生成(背景)
	//modelSkydome_ = Model::Create("tenkyu", true);
	//乱数シード生成器
	std::random_device seed_gen;
	//メルセンヌ・ツイスターの乱数エンジン
	std::mt19937_64 engin(seed_gen());



	//カメラ視点座標を設定
	//viewProjection_.eye = { 0,0,-50 };
	//カメラ注視点座標を設定
	//viewProjection_.target = { 10,0,0 };
	//カメラ上方向ベクトルを設定(右上45度指定)
	//viewProjection_.up = { cosf(PI / 4.0f),sinf(PI / 4.0f),0.0f };
	//カメラ垂直方向視野角を設定       ラジアン変換    
	viewProjection_.fovAngleY = 10 * PI / 180;
	//アスペクト比を設定
	//viewProjection_.aspectRatio = 1.0f;
	//ニアクリップ距離を設定
	//viewProjection_.nearZ = 52.0f;
	//ファークリップ距離を設定
	//viewProjection_.farZ = 53.0f;
	//ビュープロジェクションの初期化
	viewProjection_.Initialize();
	//ワールド変換の初期化
	worldTransform_.Initialize();

	//デバッグカメラの生成
	debugCamera_ = new DebugCamera(1280, 720);
	//軸方向表示の表示を有効にする
	AxisIndicator::GetInstance()->SetVisible(true);
	//軸方向表示が参照するビュープロジェクションを指定する(アドレス渡し)
	AxisIndicator::GetInstance()->SetTargetViewProjection(&viewProjection_);
	//ライン描画が参照するビュープロジェクションを指定する(アドレス渡し)
	PrimitiveDrawer::GetInstance()->SetViewProjection(&debugCamera_->GetViewProjection());





	enemy_ = new Enemy();

	enemy_->Initialize(model_, textureHandle_);

	//skydome_ = new Skydome();

	//skydome_->Initialize();

	//modelSkydome_ = Model::CreateFromOBJ("tenkyu", true);
	

	


}

void GameScene::Update() { 
	
	//自キャラの更新
	//キャラクターの移動ベクトル
	Vector3 move = { 0.0f, 0.0f, 0.0f };

	//キャラクターの移動速度
	const float kCharactorSpeed = 0.2f;

	//視点の移動ベクトル
	Vector3 cameraMove = { 0.0f,0.0f,0.0f };
	//視点の移動速度
	const float kEyeSpeed = 0.2f;

	//キーボード入力による移動処理

	//押した方向で移動ベクトルを変更
	if (input_->PushKey(DIK_A)) {
		move = { -kCharactorSpeed, 0.0f, 0.0f };

		if (worldTransform_.translation_.x <= -5.0f && viewProjection_.target.x >= -5.0f) {
			cameraMove = { -kEyeSpeed,0.0f,0.0f };
		}

		else if (worldTransform_.translation_.x >= 5.0f && viewProjection_.target.x >= 0.0f) {
			cameraMove = { -kEyeSpeed,0.0f,0.0f };
		}

		if (viewProjection_.target.x <= -5.0f) {
			viewProjection_.fovAngleY += 0.004f;

		}

		else if (viewProjection_.target.x <= 0.0f) {
			viewProjection_.fovAngleY -= 0.004f;

		}

	}
	if (input_->PushKey(DIK_D)) {
		move = { kCharactorSpeed, 0.0f, 0.0f };
		//押した方向で移動ベクトルを変更
		if (worldTransform_.translation_.x >= 5.0f && viewProjection_.target.x <= 5.0f) {
			cameraMove = { kEyeSpeed,0.0f,0.0f };
		}

		else if (worldTransform_.translation_.x <= -5.0f && viewProjection_.target.x <= 0.0f) {
			cameraMove = { kEyeSpeed,0.0f,0.0f };
		}

		if (viewProjection_.target.x >= 5.0f) {
			viewProjection_.fovAngleY += 0.004f;
		}

		else if (viewProjection_.target.x >= 0.0f) {
			viewProjection_.fovAngleY -= 0.004f;
		}

	}
	if (input_->PushKey(DIK_W)) {
		move = { 0.0f,kCharactorSpeed,0.0f };

		if (worldTransform_.translation_.y >= 3.0f && viewProjection_.target.y <= 3.0f) {
			cameraMove = { 0.0f,kEyeSpeed,0.0f };
		}

		else if (worldTransform_.translation_.y <= -3.0f && viewProjection_.target.y <= 0.0f) {
			cameraMove = { 0.0f,kEyeSpeed,0.0f };
		}

		if (viewProjection_.target.y >= 3.0f) {
			viewProjection_.fovAngleY += 0.008f;
		}

		else if (viewProjection_.target.y >= 0.0f) {
			viewProjection_.fovAngleY -= 0.008f;
		}
	}
	if (input_->PushKey(DIK_S)) {
		move = { 0.0f,-kCharactorSpeed,0.0f };

		if (worldTransform_.translation_.y <= -3.0f && viewProjection_.target.y >= -3.0f) {
			cameraMove = { 0.0f,-kEyeSpeed,0.0f };
		}

		else if (worldTransform_.translation_.y >= 3.0f && viewProjection_.target.y >= 0.2f) {
			cameraMove = { 0.0f,-kEyeSpeed,0.0f };
		}

		if (viewProjection_.target.y <= -3.0f) {
			viewProjection_.fovAngleY += 0.008f;
		}

		else if (viewProjection_.target.y <= 0.2f) {
			viewProjection_.fovAngleY -= 0.008f;
		}


	}

	//移動限界座標
	const float kMoveLimitX = 35.0f;
	const float kMoveLimitY = 18.0f;
	//範囲を超えない処理
	worldTransform_.translation_.x = max(worldTransform_.translation_.x, -kMoveLimitX);
	worldTransform_.translation_.x = min(worldTransform_.translation_.x, +kMoveLimitX);
	worldTransform_.translation_.y = max(worldTransform_.translation_.y, -kMoveLimitY);
	worldTransform_.translation_.y = min(worldTransform_.translation_.y, +kMoveLimitY);

	viewProjection_.fovAngleY = min(viewProjection_.fovAngleY, 38.0f * PI / 180.0f);
	viewProjection_.fovAngleY = max(viewProjection_.fovAngleY, 10.0f * PI / 180.0f);

	//注視点移動(ベクトルの加算)
	worldTransform_.translation_.x += move.x;
	worldTransform_.translation_.y += move.y;
	worldTransform_.translation_.z += move.z;

	//関数を使ってプレイヤーを平行移動させる
	affinTransformation::Trans(worldTransform_);


	//視点移動(ベクトルの加算)
	viewProjection_.target += cameraMove;

	//行列の再計算
	viewProjection_.UpdateMatrix();


	//デバッグ用
	debugText_->SetPos(50, 150);
	debugText_->Printf("%f,%f,%f", worldTransform_.translation_.x, worldTransform_.translation_.y, worldTransform_.translation_.z);

	//デバッグ用表示
	debugText_->SetPos(50, 50);
	debugText_->Printf(
		"target:(%f,%f,%f)", viewProjection_.target.x, viewProjection_.target.y, viewProjection_.target.z);

	//デバッグ用表示
	debugText_->SetPos(50, 110);
	debugText_->Printf("fovAngleY(Degree):%f", viewProjection_.fovAngleY / PI * 180);




	enemy_->Update();

	//skydome_->Update();
#ifdef DEBUG
	if (input_->TriggerKey(DIK_0)) {
		isDebugCameraActive_ = true;
	}
#endif // DEBUG
	//カメラの処理
	/*if (isDebugCameraActive_) {
		debugCamera_->Update();
		viewProjection_.matView = ;
		viewProjection_.matProjection = ;
	}
	else {
		viewProjection_.UpdateMatrix();
	}*/
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
	model_->Draw(worldTransform_, viewProjection_, textureHandle_);

	enemy_->Draw(viewProjection_);
	
	
	//3Dモデル描画
	model_->Draw(worldTransform_, viewProjection_,textureHandle2_);
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
