
#include"AxisIndicator.h"
#include"Matrix4.h"
#define PI =3.141592;
namespace affinTransformation {

	void Scale(WorldTransform worldTransform_) {

		//X,Y,Z方向のスケーリングを設定

		//スケーリング倍率を行列に設定する
		Matrix4 matScale =
		{ 1.0f,0.0f,0.0f,0.0f,
		  0.0f,1.0f,0.0f,0.0f,
		  0.0f,0.0f,1.0f,0.0f,
		  0.0f,0.0f,0.0f,1.0f };


		matScale.m[0][0] = worldTransform_.scale_.x;
		matScale.m[1][1] = worldTransform_.scale_.y;
		matScale.m[2][2] = worldTransform_.scale_.z;
		//単位行列を代入する
		worldTransform_.matWorld_ = {
			1.0f,0.0f,0.0f,0.0f,
			0.0f,1.0f,0.0f,0.0f,
			0.0f,0.0f,1.0f,0.0f,
			0.0f,0.0f,0.0f,1.0f };

		//worldTransform_.matWorld_にmatScaleを掛け算して代入する
		worldTransform_.matWorld_ *= matScale;

		//行列の転送
		worldTransform_.TransferMatrix();

	}

	void RotX(WorldTransform worldTransform_) {
		//X,Y,Z方向の回転角を設定
		

		//X軸回転行列を宣言
		Matrix4 matRotX =
		{ 1.0f,0.0f,0.0f,0.0f,
		  0.0f,1.0f,0.0f,0.0f,
		  0.0f,0.0f,1.0f,0.0f,
		  0.0f,0.0f,0.0f,1.0f };


		matRotX.m[1][1] = cos(worldTransform_.rotation_.x);
		matRotX.m[1][2] = sin(worldTransform_.rotation_.x);
		matRotX.m[2][1] = -sin(worldTransform_.rotation_.x);
		matRotX.m[2][2] = cos(worldTransform_.rotation_.x);

		//単位行列を代入する
		worldTransform_.matWorld_ = {
				1.0f,0.0f,0.0f,0.0f,
				0.0f,1.0f,0.0f,0.0f,
				0.0f,0.0f,1.0f,0.0f,
				0.0f,0.0f,0.0f,1.0f };

		//worldTransform_.matWorld_にmatRotXを掛け算して代入する
		worldTransform_.matWorld_ *= matRotX;

		//行列の転送
		worldTransform_.TransferMatrix();

	}
	void RotY(WorldTransform worldTransform_) {
		//X,Y,Z方向の回転角を設定
		

		//Y軸回転行列を宣言
		Matrix4 matRotY =
		{ 1.0f,0.0f,0.0f,0.0f,
		  0.0f,1.0f,0.0f,0.0f,
		  0.0f,0.0f,1.0f,0.0f,
		  0.0f,0.0f,0.0f,1.0f };


		matRotY.m[0][0] = cos(worldTransform_.rotation_.y);
		matRotY.m[0][2] = sin(worldTransform_.rotation_.y);
		matRotY.m[2][0] = -sin(worldTransform_.rotation_.y);
		matRotY.m[2][2] = cos(worldTransform_.rotation_.y);

		//単位行列を代入する
		worldTransform_.matWorld_ = {
				1.0f,0.0f,0.0f,0.0f,
				0.0f,1.0f,0.0f,0.0f,
				0.0f,0.0f,1.0f,0.0f,
				0.0f,0.0f,0.0f,1.0f };

		//worldTransform_.matWorld_にmatRotYを掛け算して代入する
		worldTransform_.matWorld_ *= matRotY;

		//行列の転送
		worldTransform_.TransferMatrix();

	}
	void RotZ(WorldTransform worldTransform_) {
		//X,Y,Z方向の回転角を設定
		

		//Z軸回転行列を宣言
		Matrix4 matRotZ =
		{ 1.0f,0.0f,0.0f,0.0f,
		  0.0f,1.0f,0.0f,0.0f,
		  0.0f,0.0f,1.0f,0.0f,
		  0.0f,0.0f,0.0f,1.0f };


		matRotZ.m[0][0] = cos(worldTransform_.rotation_.z);
		matRotZ.m[0][1] = sin(worldTransform_.rotation_.z);
		matRotZ.m[1][0] = -sin(worldTransform_.rotation_.z);
		matRotZ.m[1][1] = cos(worldTransform_.rotation_.z);

		//単位行列を代入する
		worldTransform_.matWorld_ = {
				1.0f,0.0f,0.0f,0.0f,
				0.0f,1.0f,0.0f,0.0f,
				0.0f,0.0f,1.0f,0.0f,
				0.0f,0.0f,0.0f,1.0f };

		//worldTransform_.matWorld_にmatRotZを掛け算して代入する
		worldTransform_.matWorld_ *= matRotZ;

		//行列の転送
		worldTransform_.TransferMatrix();

	}

	void Trans(WorldTransform worldTransform_) {
		//X,Y,Z軸周りの平行移動を設定
		

		//移動量を行列に設定する
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

		//行列の転送
		worldTransform_.TransferMatrix();

	}
	void Com(WorldTransform worldTransform_) {
		//スケーリング行列の設定
		

		//スケーリング倍率を行列に設定する
		Matrix4 matScale =
		{ 1.0f,0.0f,0.0f,0.0f,
		  0.0f,1.0f,0.0f,0.0f,
		  0.0f,0.0f,1.0f,0.0f,
		  0.0f,0.0f,0.0f,1.0f };


		matScale.m[0][0] = worldTransform_.scale_.x;
		matScale.m[1][1] = worldTransform_.scale_.y;
		matScale.m[2][2] = worldTransform_.scale_.z;

		//回転行列の設定
		

		//合成用回転行列を宣言
		Matrix4 matRot =
		{ 1.0f,0.0f,0.0f,0.0f,
		  0.0f,1.0f,0.0f,0.0f,
		  0.0f,0.0f,1.0f,0.0f,
		  0.0f,0.0f,0.0f,1.0f };
		//各軸用回転行列を宣言
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

		//Z軸回転行列の各要素を設定する(回転角θZ)
		matRotZ.m[0][0] = cos(worldTransform_.rotation_.z);
		matRotZ.m[0][1] = sin(worldTransform_.rotation_.z);
		matRotZ.m[1][0] = -sin(worldTransform_.rotation_.z);
		matRotZ.m[1][1] = cos(worldTransform_.rotation_.z);

		//X軸回転行列の各要素を設定する(回転角θX)
		matRotX.m[1][1] = cos(worldTransform_.rotation_.x);
		matRotX.m[1][2] = sin(worldTransform_.rotation_.x);
		matRotX.m[2][1] = -sin(worldTransform_.rotation_.x);
		matRotX.m[2][2] = cos(worldTransform_.rotation_.x);

		//Y軸回転行列の各要素を設定する(回転角θY)
		matRotY.m[0][0] = cos(worldTransform_.rotation_.y);
		matRotY.m[0][2] = -sin(worldTransform_.rotation_.y);
		matRotY.m[2][0] = sin(worldTransform_.rotation_.y);
		matRotY.m[2][2] = cos(worldTransform_.rotation_.y);

		//各軸の回転行列を合成
		matRot *= matRotZ *= matRotX *= matRotY;

		//平行移動行列の設定
		

		Matrix4 matTrans =
		{ 1.0f,0.0f,0.0f,0.0f,
		  0.0f,1.0f,0.0f,0.0f,
		  0.0f,0.0f,1.0f,0.0f,
		  0.0f,0.0f,0.0f,1.0f };

		matTrans.m[3][0] = worldTransform_.translation_.x;
		matTrans.m[3][1] = worldTransform_.translation_.y;
		matTrans.m[3][2] = worldTransform_.translation_.z;

		//行列の合成
		worldTransform_.matWorld_ =
		{ 1.0f,0.0f,0.0f,0.0f,
		  0.0f,1.0f,0.0f,0.0f,
		  0.0f,0.0f,1.0f,0.0f,
		  0.0f,0.0f,0.0f,1.0f };

		worldTransform_.matWorld_ *= matScale *= matRot *= matTrans;

		//行列の転送
		worldTransform_.TransferMatrix();

	}
	void Par(WorldTransform worldTransform_)
	{
		
			//大元から順に更新していく

			Matrix4 matScale =
			{ 1.0f,0.0f,0.0f,0.0f,
			  0.0f,1.0f,0.0f,0.0f,
			  0.0f,0.0f,1.0f,0.0f,
			  0.0f,0.0f,0.0f,1.0f };


			matScale.m[0][0] = worldTransform_.scale_.x;
			matScale.m[1][1] = worldTransform_.scale_.y;
			matScale.m[2][2] = worldTransform_.scale_.z;

			//回転行列の設定


			//合成用回転行列を宣言
			Matrix4 matRot =
			{ 1.0f,0.0f,0.0f,0.0f,
			  0.0f,1.0f,0.0f,0.0f,
			  0.0f,0.0f,1.0f,0.0f,
			  0.0f,0.0f,0.0f,1.0f };
			//各軸用回転行列を宣言
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

			//Z軸回転行列の各要素を設定する(回転角θZ)
			matRotZ.m[0][0] = cos(worldTransform_.rotation_.z);
			matRotZ.m[0][1] = sin(worldTransform_.rotation_.z);
			matRotZ.m[1][0] = -sin(worldTransform_.rotation_.z);
			matRotZ.m[1][1] = cos(worldTransform_.rotation_.z);

			//X軸回転行列の各要素を設定する(回転角θX)
			matRotX.m[1][1] = cos(worldTransform_.rotation_.x);
			matRotX.m[1][2] = sin(worldTransform_.rotation_.x);
			matRotX.m[2][1] = -sin(worldTransform_.rotation_.x);
			matRotX.m[2][2] = cos(worldTransform_.rotation_.x);

			//Y軸回転行列の各要素を設定する(回転角θY)
			matRotY.m[0][0] = cos(worldTransform_.rotation_.y);
			matRotY.m[0][2] = -sin(worldTransform_.rotation_.y);
			matRotY.m[2][0] = sin(worldTransform_.rotation_.y);
			matRotY.m[2][2] = cos(worldTransform_.rotation_.y);

			//各軸の回転行列を合成
			matRot *= matRotZ *= matRotX *= matRotY;

			//平行移動行列の設定


			Matrix4 matTrans =
			{ 1.0f,0.0f,0.0f,0.0f,
			  0.0f,1.0f,0.0f,0.0f,
			  0.0f,0.0f,1.0f,0.0f,
			  0.0f,0.0f,0.0f,1.0f };

			matTrans.m[3][0] = worldTransform_.translation_.x;
			matTrans.m[3][1] = worldTransform_.translation_.y;
			matTrans.m[3][2] = worldTransform_.translation_.z;

			//行列の合成
			worldTransform_.matWorld_ =
			{ 1.0f,0.0f,0.0f,0.0f,
			  0.0f,1.0f,0.0f,0.0f,
			  0.0f,0.0f,1.0f,0.0f,
			  0.0f,0.0f,0.0f,1.0f };

			worldTransform_.matWorld_ *= matScale *= matRot *= matTrans ;

			worldTransform_.TransferMatrix();
		
	}
	void mat(Vector3 vec, WorldTransform worldTransform_)
	{
		
	}

}
