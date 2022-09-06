#pragma once
#include "WorldTransform.h"
#include "Model.h"
#include "Input.h"
#include "DebugText.h"
#include "TextureManager.h"

class Skydome
{
public:
	/// <summary>
	/// èâä˙âª
	/// </summary>
	void Initialize(Model* model);
	/// <summary>
	/// çXêV
	/// </summary>
	void Update();
	/// <summary>
	/// ï`âÊ
	/// </summary>
	void Draw(ViewProjection& viewProjection);

private:
	WorldTransform worldTransform_;
	Model* model_ = nullptr;
	DebugText* debugText_ = nullptr;
	Input* input_ = nullptr;
	
};

