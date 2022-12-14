#include "stdafx.h"
#include "TestModel.h"

bool TestModel::Start()
{
	// tkmファイルパスを指定。
	const char* filePath = nullptr;
	bool isCaster = true;
	if (m_typeNum == 0) {
		filePath = "Assets/modelData/testStage/ground.tkm";

		m_model.Init(
			filePath,
			nullptr,
			0,
			enModelUpAxisZ,
			false,
			false,
			false,
			0
		);
	}
	if (m_typeNum == 1) {
		filePath = "Assets/modelData/backGroundModel/backGroundModel_box1.tkm";

		m_model.Init(
			filePath,
			nullptr,
			0,
			enModelUpAxisZ,
			false,
			false,
			true,
			0
		);
	}
	else if (m_typeNum == 2) {
		filePath = "Assets/modelData/backGroundModel/backGroundModel_box2.tkm";

		m_model.Init(
			filePath,
			nullptr,
			0,
			enModelUpAxisZ,
			false,
			false,
			true,
			0
		);

	}
	else if (m_typeNum == 3) {
		filePath = "Assets/modelData/backGroundModel/backGroundModel_box3.tkm";

		m_model.Init(
			filePath,
			nullptr,
			0,
			enModelUpAxisZ,
			false,
			false,
			true,
			0
		);
	}

	m_model.SetTRS(m_pos, m_rot, m_sca);
	m_model.Update();

	m_physicsStaticObject.CreateFromModel(
		m_model.GetModel(),
		m_model.GetModel().GetWorldMatrix()
	);

	// デバッグ用　当たり判定描画
	//PhysicsWorld::GetInstance()->EnableDrawDebugWireFrame();
	m_model.Update();
	return true;
}

void TestModel::Update()
{
	
}

void TestModel::Render(RenderContext& rc)
{
	m_model.Draw(rc);
}
