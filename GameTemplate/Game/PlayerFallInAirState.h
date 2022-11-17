#pragma once
#include "PlayerState.h"

class PlayerFallInAirState : public PlayerState
{
public:
	/// <summary>
	/// ステート開始時の処理。
	/// </summary>
	void Enter(Player* player) override;
	/// <summary>
	/// ステートの遷移処理。
	/// </summary>
	/// <returns>遷移するステート</returns>
	PlayerState* StateChange(Player* player) override;
	/// <summary>
	/// ステートにおける更新処理。
	/// </summary>
	void Update(Player* player) override;
};

