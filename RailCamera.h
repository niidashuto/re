#pragma once

#include"WorldTransform.h"
#include"ViewProjection.h"
///<summary>
///���[���J����
///</summary>
class RailCamera
{
public:
	///<summary>
	///������
	///</summary>
	void Initialize(WorldTransform worldTransform);

	///<summary>
	///�X�V
	///</summary>
	void Update();
private:
	//���[���h�ϊ��f�[�^
	WorldTransform worldTransform_;
	//�r���[�v���W�F�N�V����
	ViewProjection viewProjection_;
};

