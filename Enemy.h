#pragma once
#include"Model.h"
#include"WorldTransform.h"
#include "DebugText.h"
#include "Input.h"
class Enemy
{
public:
	///<summary>
	///������
	///</summary> 
	void Initialize(Model* model, uint32_t textureHandle);
	///<summary>
	///�X�V
	///</summary> 
	void Update();
	///<summary>
	///�`��
	///</summary> 
	void Draw(ViewProjection viewprojection_);
private:
	//���[���h�ϊ��f�[�^
	WorldTransform worldTransform_;
	//���f��
	Model* model_ = nullptr;
	//�e�N�X�`���n���h��
	uint32_t textureHandle_ = 0u;
	//�C���v�b�g
	Input* input_ = nullptr;
	//�f�o�b�O�e�L�X�g
	DebugText* debugText_ = nullptr;
};

