#pragma once
#include "IPlayerState.h"
class PlayerJumpState : public IPlayerState
{
public:
	PlayerJumpState(Player* player) :
		IPlayerState(player) {}
	~PlayerJumpState() override;
	/// <summary>
	/// ステート開始時の処理。
	/// </summary>
	void Enter() override;
	/// <summary>
	/// ステートの遷移処理。
	/// </summary>
	/// <returns>遷移するステート</returns>
	IPlayerState* StateChange() override;
	/// <summary>
	/// ステートにおける更新処理。
	/// </summary>
	void Update() override;
private:
	float m_count = 0.0f;

};

