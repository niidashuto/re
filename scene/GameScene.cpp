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
	textureHandle_ = TextureManager::Load("sentouki01.png");

	
	//3Dモデルの生成
	model_ = Model::Create();


	//3Dモデルの生成(天球)
	modelSkydome_ = Model::CreateFromOBJ("tenkyu", true);
	//乱数シード生成器
	std::random_device seed_gen;
	//メルセンヌ・ツイスターの乱数エンジン
	std::mt19937_64 engin(seed_gen());

	
	
	//カメラ視点座標を設定
	//viewProjection_.eye = { 0,0,-10 };
	//カメラ注視点座標を設定
	//viewProjection_.target = { 10,0,0 };
	//カメラ上方向ベクトルを設定(右上45度指定)
	//viewProjection_.up = { cosf(PI / 4.0f),sinf(PI / 4.0f),0.0f };
	//カメラ垂直方向視野角を設定       ラジアン変換    
	//viewProjection_.fovAngleY = 10 * PI / 180;
	//アスペクト比を設定
	//viewProjection_.aspectRatio = 1.0f;
	//ニアクリップ距離を設定
	//viewProjection_.nearZ = 52.0f;
	//ファークリップ距離を設定
	//viewProjection_.farZ = 53.0f;
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
	//自キャラの生成
	player_ = new Player();
	//自キャラの初期化
	player_->Initialize(model_,textureHandle_);
	
	enemy_ = new Enemy();
	
	enemy_->Initialize(model_, textureHandle_);

	enemy_->SetPlayer(player_);

	skydome_ = new Skydome();

	skydome_->Initialize(modelSkydome_);
}

void GameScene::Update() { 
	
	//自キャラの更新
	player_->Update();
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

	enemy_->Update();

	skydome_->Update();
}

void GameScene::CheckAllCollisions() {
	//判定対象AとBの座標
	Vector3 posA, posB;

	//自弾リストの取得
	const std::list<std::unique_ptr<PlayerBullet>>& playerBullets = player_->GetBullet();
	//敵弾リストの取得
	const std::list<std::unique_ptr<EnemyBullet>>& enemyBullets = enemy_->GetBullet();

#pragma region 自キャラと敵弾の当たり判定
#pragma endregion

#pragma region 自弾と敵キャラの当たり判定
#pragma endregion

#pragma region 自弾と敵弾の当たり判定
#pragma endregion
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
	player_->Draw(viewProjection_);

	enemy_->Draw(viewProjection_);

	skydome_->Draw(viewProjection_);
	
	//3Dモデル描画
	//model_->Draw(worldtransform_, debugCamera_->GetViewProjection(), textureHandle_);
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
