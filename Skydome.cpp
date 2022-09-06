#include "Skydome.h"
#include <cassert>
#include "Object.h"

void Skydome::Initialize(Model* model)
{
	// NULL�|�C���^�`�F�b�N
	assert(model);

	//�����Ƃ��Ď󂯎���ăf�[�^�������o�ϐ��ɋL�^����
	model_ = model;
	
	//�V���O���g���C���X�^���X���擾����
	input_ = Input::GetInstance();
	debugText_ = DebugText::GetInstance();

	//���[���h�ϊ��̏�����
	worldTransform_.Initialize();

}

void Skydome::Update()
{

}

void Skydome::Draw(ViewProjection& viewProjection)
{
	model_->Draw(worldTransform_,viewProjection);
}