#include "Skydome.h"
#include <cassert>
#include "Object.h"

void Skydome::Initialize(Model* model)
{
	// NULLポインタチェック
	assert(model);

	//引数として受け取ってデータをメンバ変数に記録する
	model_ = model;
	
	//シングルトンインスタンスを取得する
	input_ = Input::GetInstance();
	debugText_ = DebugText::GetInstance();

	//ワールド変換の初期化
	worldTransform_.Initialize();

}

void Skydome::Update()
{

}

void Skydome::Draw(ViewProjection& viewProjection)
{
	model_->Draw(worldTransform_,viewProjection);
}