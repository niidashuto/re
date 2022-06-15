
#include"AxisIndicator.h"
#include"Matrix4.h"
#define PI =3.141592;
namespace affinTransformation {

	void Scale(WorldTransform worldTransform_) {

		//X,Y,Z•ûŒü‚ÌƒXƒP[ƒŠƒ“ƒO‚ðÝ’è

		//ƒXƒP[ƒŠƒ“ƒO”{—¦‚ðs—ñ‚ÉÝ’è‚·‚é
		Matrix4 matScale =
		{ 1.0f,0.0f,0.0f,0.0f,
		  0.0f,1.0f,0.0f,0.0f,
		  0.0f,0.0f,1.0f,0.0f,
		  0.0f,0.0f,0.0f,1.0f };


		matScale.m[0][0] = worldTransform_.scale_.x;
		matScale.m[1][1] = worldTransform_.scale_.y;
		matScale.m[2][2] = worldTransform_.scale_.z;
		//’PˆÊs—ñ‚ð‘ã“ü‚·‚é
		worldTransform_.matWorld_ = {
			1.0f,0.0f,0.0f,0.0f,
			0.0f,1.0f,0.0f,0.0f,
			0.0f,0.0f,1.0f,0.0f,
			0.0f,0.0f,0.0f,1.0f };

		//worldTransform_.matWorld_‚ÉmatScale‚ðŠ|‚¯ŽZ‚µ‚Ä‘ã“ü‚·‚é
		worldTransform_.matWorld_ *= matScale;

		//s—ñ‚Ì“]‘—
		worldTransform_.TransferMatrix();

	}

	void RotX(WorldTransform worldTransform_) {
		//X,Y,Z•ûŒü‚Ì‰ñ“]Šp‚ðÝ’è
		

		//XŽ²‰ñ“]s—ñ‚ðéŒ¾
		Matrix4 matRotX =
		{ 1.0f,0.0f,0.0f,0.0f,
		  0.0f,1.0f,0.0f,0.0f,
		  0.0f,0.0f,1.0f,0.0f,
		  0.0f,0.0f,0.0f,1.0f };


		matRotX.m[1][1] = cos(worldTransform_.rotation_.x);
		matRotX.m[1][2] = sin(worldTransform_.rotation_.x);
		matRotX.m[2][1] = -sin(worldTransform_.rotation_.x);
		matRotX.m[2][2] = cos(worldTransform_.rotation_.x);

		//’PˆÊs—ñ‚ð‘ã“ü‚·‚é
		worldTransform_.matWorld_ = {
				1.0f,0.0f,0.0f,0.0f,
				0.0f,1.0f,0.0f,0.0f,
				0.0f,0.0f,1.0f,0.0f,
				0.0f,0.0f,0.0f,1.0f };

		//worldTransform_.matWorld_‚ÉmatRotX‚ðŠ|‚¯ŽZ‚µ‚Ä‘ã“ü‚·‚é
		worldTransform_.matWorld_ *= matRotX;

		//s—ñ‚Ì“]‘—
		worldTransform_.TransferMatrix();

	}
	void RotY(WorldTransform worldTransform_) {
		//X,Y,Z•ûŒü‚Ì‰ñ“]Šp‚ðÝ’è
		

		//YŽ²‰ñ“]s—ñ‚ðéŒ¾
		Matrix4 matRotY =
		{ 1.0f,0.0f,0.0f,0.0f,
		  0.0f,1.0f,0.0f,0.0f,
		  0.0f,0.0f,1.0f,0.0f,
		  0.0f,0.0f,0.0f,1.0f };


		matRotY.m[0][0] = cos(worldTransform_.rotation_.y);
		matRotY.m[0][2] = sin(worldTransform_.rotation_.y);
		matRotY.m[2][0] = -sin(worldTransform_.rotation_.y);
		matRotY.m[2][2] = cos(worldTransform_.rotation_.y);

		//’PˆÊs—ñ‚ð‘ã“ü‚·‚é
		worldTransform_.matWorld_ = {
				1.0f,0.0f,0.0f,0.0f,
				0.0f,1.0f,0.0f,0.0f,
				0.0f,0.0f,1.0f,0.0f,
				0.0f,0.0f,0.0f,1.0f };

		//worldTransform_.matWorld_‚ÉmatRotY‚ðŠ|‚¯ŽZ‚µ‚Ä‘ã“ü‚·‚é
		worldTransform_.matWorld_ *= matRotY;

		//s—ñ‚Ì“]‘—
		worldTransform_.TransferMatrix();

	}
	void RotZ(WorldTransform worldTransform_) {
		//X,Y,Z•ûŒü‚Ì‰ñ“]Šp‚ðÝ’è
		

		//ZŽ²‰ñ“]s—ñ‚ðéŒ¾
		Matrix4 matRotZ =
		{ 1.0f,0.0f,0.0f,0.0f,
		  0.0f,1.0f,0.0f,0.0f,
		  0.0f,0.0f,1.0f,0.0f,
		  0.0f,0.0f,0.0f,1.0f };


		matRotZ.m[0][0] = cos(worldTransform_.rotation_.z);
		matRotZ.m[0][1] = sin(worldTransform_.rotation_.z);
		matRotZ.m[1][0] = -sin(worldTransform_.rotation_.z);
		matRotZ.m[1][1] = cos(worldTransform_.rotation_.z);

		//’PˆÊs—ñ‚ð‘ã“ü‚·‚é
		worldTransform_.matWorld_ = {
				1.0f,0.0f,0.0f,0.0f,
				0.0f,1.0f,0.0f,0.0f,
				0.0f,0.0f,1.0f,0.0f,
				0.0f,0.0f,0.0f,1.0f };

		//worldTransform_.matWorld_‚ÉmatRotZ‚ðŠ|‚¯ŽZ‚µ‚Ä‘ã“ü‚·‚é
		worldTransform_.matWorld_ *= matRotZ;

		//s—ñ‚Ì“]‘—
		worldTransform_.TransferMatrix();

	}

	void Trans(WorldTransform worldTransform_) {
		//X,Y,ZŽ²Žü‚è‚Ì•½sˆÚ“®‚ðÝ’è
		

		//ˆÚ“®—Ê‚ðs—ñ‚ÉÝ’è‚·‚é
		Matrix4 matTrans =
		{ 1.0f,0.0f,0.0f,0.0f,
		  0.0f,1.0f,0.0f,0.0f,
		  0.0f,0.0f,1.0f,0.0f,
		  0.0f,0.0f,0.0f,1.0f };

		matTrans.m[3][0] = worldTransform_.translation_.x;
		matTrans.m[3][1] = worldTransform_.translation_.y;
		matTrans.m[3][2] = worldTransform_.translation_.z;

		worldTransform_.matWorld_ =
		{ 1.0f,0.0f,0.0f,0.0f,
		  0.0f,1.0f,0.0f,0.0f,
		  0.0f,0.0f,1.0f,0.0f,
		  0.0f,0.0f,0.0f,1.0f };

		worldTransform_.matWorld_ *= matTrans;

		//s—ñ‚Ì“]‘—
		worldTransform_.TransferMatrix();

	}
	void Com(WorldTransform worldTransform_) {
		//ƒXƒP[ƒŠƒ“ƒOs—ñ‚ÌÝ’è
		

		//ƒXƒP[ƒŠƒ“ƒO”{—¦‚ðs—ñ‚ÉÝ’è‚·‚é
		Matrix4 matScale =
		{ 1.0f,0.0f,0.0f,0.0f,
		  0.0f,1.0f,0.0f,0.0f,
		  0.0f,0.0f,1.0f,0.0f,
		  0.0f,0.0f,0.0f,1.0f };


		matScale.m[0][0] = worldTransform_.scale_.x;
		matScale.m[1][1] = worldTransform_.scale_.y;
		matScale.m[2][2] = worldTransform_.scale_.z;

		//‰ñ“]s—ñ‚ÌÝ’è
		

		//‡¬—p‰ñ“]s—ñ‚ðéŒ¾
		Matrix4 matRot =
		{ 1.0f,0.0f,0.0f,0.0f,
		  0.0f,1.0f,0.0f,0.0f,
		  0.0f,0.0f,1.0f,0.0f,
		  0.0f,0.0f,0.0f,1.0f };
		//ŠeŽ²—p‰ñ“]s—ñ‚ðéŒ¾
		Matrix4 matRotZ =
		{ 1.0f,0.0f,0.0f,0.0f,
		  0.0f,1.0f,0.0f,0.0f,
		  0.0f,0.0f,1.0f,0.0f,
		  0.0f,0.0f,0.0f,1.0f };

		Matrix4 matRotX =
		{ 1.0f,0.0f,0.0f,0.0f,
		  0.0f,1.0f,0.0f,0.0f,
		  0.0f,0.0f,1.0f,0.0f,
		  0.0f,0.0f,0.0f,1.0f };

		Matrix4 matRotY =
		{ 1.0f,0.0f,0.0f,0.0f,
		  0.0f,1.0f,0.0f,0.0f,
		  0.0f,0.0f,1.0f,0.0f,
		  0.0f,0.0f,0.0f,1.0f };

		//ZŽ²‰ñ“]s—ñ‚ÌŠe—v‘f‚ðÝ’è‚·‚é(‰ñ“]ŠpƒÆZ)
		matRotZ.m[0][0] = cos(worldTransform_.rotation_.z);
		matRotZ.m[0][1] = sin(worldTransform_.rotation_.z);
		matRotZ.m[1][0] = -sin(worldTransform_.rotation_.z);
		matRotZ.m[1][1] = cos(worldTransform_.rotation_.z);

		//XŽ²‰ñ“]s—ñ‚ÌŠe—v‘f‚ðÝ’è‚·‚é(‰ñ“]ŠpƒÆX)
		matRotX.m[1][1] = cos(worldTransform_.rotation_.x);
		matRotX.m[1][2] = sin(worldTransform_.rotation_.x);
		matRotX.m[2][1] = -sin(worldTransform_.rotation_.x);
		matRotX.m[2][2] = cos(worldTransform_.rotation_.x);

		//YŽ²‰ñ“]s—ñ‚ÌŠe—v‘f‚ðÝ’è‚·‚é(‰ñ“]ŠpƒÆY)
		matRotY.m[0][0] = cos(worldTransform_.rotation_.y);
		matRotY.m[0][2] = -sin(worldTransform_.rotation_.y);
		matRotY.m[2][0] = sin(worldTransform_.rotation_.y);
		matRotY.m[2][2] = cos(worldTransform_.rotation_.y);

		//ŠeŽ²‚Ì‰ñ“]s—ñ‚ð‡¬
		matRot *= matRotZ *= matRotX *= matRotY;

		//•½sˆÚ“®s—ñ‚ÌÝ’è
		

		Matrix4 matTrans =
		{ 1.0f,0.0f,0.0f,0.0f,
		  0.0f,1.0f,0.0f,0.0f,
		  0.0f,0.0f,1.0f,0.0f,
		  0.0f,0.0f,0.0f,1.0f };

		matTrans.m[3][0] = worldTransform_.translation_.x;
		matTrans.m[3][1] = worldTransform_.translation_.y;
		matTrans.m[3][2] = worldTransform_.translation_.z;

		//s—ñ‚Ì‡¬
		worldTransform_.matWorld_ =
		{ 1.0f,0.0f,0.0f,0.0f,
		  0.0f,1.0f,0.0f,0.0f,
		  0.0f,0.0f,1.0f,0.0f,
		  0.0f,0.0f,0.0f,1.0f };

		worldTransform_.matWorld_ *= matScale *= matRot *= matTrans;

		//s—ñ‚Ì“]‘—
		worldTransform_.TransferMatrix();

	}
	void Par(WorldTransform worldTransforms_[100])
	{
		//‘åŒ³‚©‚ç‡‚ÉXV‚µ‚Ä‚¢‚­

		Matrix4 matScale =
		{ 1.0f,0.0f,0.0f,0.0f,
		  0.0f,1.0f,0.0f,0.0f,
		  0.0f,0.0f,1.0f,0.0f,
		  0.0f,0.0f,0.0f,1.0f };


		matScale.m[0][0] = worldTransforms_[1].scale_.x;
		matScale.m[1][1] = worldTransforms_[1].scale_.y;
		matScale.m[2][2] = worldTransforms_[1].scale_.z;

		//‰ñ“]s—ñ‚ÌÝ’è


		//‡¬—p‰ñ“]s—ñ‚ðéŒ¾
		Matrix4 matRot =
		{ 1.0f,0.0f,0.0f,0.0f,
		  0.0f,1.0f,0.0f,0.0f,
		  0.0f,0.0f,1.0f,0.0f,
		  0.0f,0.0f,0.0f,1.0f };
		//ŠeŽ²—p‰ñ“]s—ñ‚ðéŒ¾
		Matrix4 matRotZ =
		{ 1.0f,0.0f,0.0f,0.0f,
		  0.0f,1.0f,0.0f,0.0f,
		  0.0f,0.0f,1.0f,0.0f,
		  0.0f,0.0f,0.0f,1.0f };

		Matrix4 matRotX =
		{ 1.0f,0.0f,0.0f,0.0f,
		  0.0f,1.0f,0.0f,0.0f,
		  0.0f,0.0f,1.0f,0.0f,
		  0.0f,0.0f,0.0f,1.0f };

		Matrix4 matRotY =
		{ 1.0f,0.0f,0.0f,0.0f,
		  0.0f,1.0f,0.0f,0.0f,
		  0.0f,0.0f,1.0f,0.0f,
		  0.0f,0.0f,0.0f,1.0f };

		//ZŽ²‰ñ“]s—ñ‚ÌŠe—v‘f‚ðÝ’è‚·‚é(‰ñ“]ŠpƒÆZ)
		matRotZ.m[0][0] = cos(worldTransforms_[1].rotation_.z);
		matRotZ.m[0][1] = sin(worldTransforms_[1].rotation_.z);
		matRotZ.m[1][0] = -sin(worldTransforms_[1].rotation_.z);
		matRotZ.m[1][1] = cos(worldTransforms_[1].rotation_.z);

		//XŽ²‰ñ“]s—ñ‚ÌŠe—v‘f‚ðÝ’è‚·‚é(‰ñ“]ŠpƒÆX)
		matRotX.m[1][1] = cos(worldTransforms_[1].rotation_.x);
		matRotX.m[1][2] = sin(worldTransforms_[1].rotation_.x);
		matRotX.m[2][1] = -sin(worldTransforms_[1].rotation_.x);
		matRotX.m[2][2] = cos(worldTransforms_[1].rotation_.x);

		//YŽ²‰ñ“]s—ñ‚ÌŠe—v‘f‚ðÝ’è‚·‚é(‰ñ“]ŠpƒÆY)
		matRotY.m[0][0] = cos(worldTransforms_[1].rotation_.y);
		matRotY.m[0][2] = -sin(worldTransforms_[1].rotation_.y);
		matRotY.m[2][0] = sin(worldTransforms_[1].rotation_.y);
		matRotY.m[2][2] = cos(worldTransforms_[1].rotation_.y);

		//ŠeŽ²‚Ì‰ñ“]s—ñ‚ð‡¬
		matRot *= matRotZ *= matRotX *= matRotY;

		//•½sˆÚ“®s—ñ‚ÌÝ’è


		Matrix4 matTrans =
		{ 1.0f,0.0f,0.0f,0.0f,
		  0.0f,1.0f,0.0f,0.0f,
		  0.0f,0.0f,1.0f,0.0f,
		  0.0f,0.0f,0.0f,1.0f };

		matTrans.m[3][0] = worldTransforms_[1].translation_.x;
		matTrans.m[3][1] = worldTransforms_[1].translation_.y;
		matTrans.m[3][2] = worldTransforms_[1].translation_.z;

		//s—ñ‚Ì‡¬
		worldTransforms_[1].matWorld_ =
		{ 1.0f,0.0f,0.0f,0.0f,
		  0.0f,1.0f,0.0f,0.0f,
		  0.0f,0.0f,1.0f,0.0f,
		  0.0f,0.0f,0.0f,1.0f };

		worldTransforms_[1].matWorld_ *= matScale *= matRot *= matTrans *= worldTransforms_[1].parent_->matWorld_;

		worldTransforms_[1].TransferMatrix();
	}

}
