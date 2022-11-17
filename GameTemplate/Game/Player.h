#pragma once
#include "sound/SoundSource.h"

class PlayerState;

/// <summary>
/// プレイヤークラス
/// </summary>
class Player : public IGameObject
{
public:
	enum EnAnimationClip {
		enAnimationClip_Idle,		// 待機
		enAnimationClip_Walk,		// 歩き
		enAnimationClip_Run,		// 走り
		enAnimationClip_Slide,
		enAnimationClip_Num			// アニメーションクリップの数
	};
public:
	Player() {}
	~Player() {}

	/// <summary>
	/// 開始処理。
	/// インスタンス生成時に一度だけ実行。
	/// </summary>
	bool Start();
	/// <summary>
	/// 更新処理。
	/// </summary>
	void Update();
	/// <summary>
	/// 描画処理。
	/// </summary>
	/// <param name="rc"></param>
	void Render(RenderContext& rc);
	/// <summary>
	/// 再生するアニメーションクリップを設定する。
	/// </summary>
	/// <param name="enAnimationClip">アニメーションクリップ</param>
	void SetAnimation(EnAnimationClip enAnimationClip)
	{
		m_currentAnimationClip = enAnimationClip;
	}
	/// <summary>
	/// 座標を設定する。
	/// </summary>
	/// <param name="position">座標。</param>
	void SetPosition(Vector3& position)
	{
		m_position = position;
	}
	/// <summary>
	/// 回転を設定。
	/// </summary>
	/// <param name="rotation">回転。</param>
	void SetRotation(Quaternion& rotation)
	{
		m_rotation = rotation;
	}
	/// <summary>
	/// 拡大率を設定。
	/// </summary>
	/// <param name="scale">拡大率。</param>
	void SetScale(Vector3& scale)
	{
		m_scale = scale;
	}
	/// <summary>
	/// オブジェクトとの接地判定を設定。
	/// </summary>
	/// <param name="isTouchObject">オブジェクトとの接地判定。</param>
	void SetIsTouchObject(bool isTouchObject)
	{
		m_isTouchObject = isTouchObject;
	}
	/// <summary>
	/// 座標を取得。
	/// </summary>
	/// <returns>座標。</returns>
	const Vector3& GetPosition() const 
	{
		return m_position;
	}
	/// <summary>
	/// 現在のモデルの上方向を取得。
	/// </summary>
	/// <returns>モデルの上方向。</returns>
	const Vector3& GetCurrentModelUpAxis() const
	{
		return m_currentModelUpAxis;
	}
	/// <summary>
	/// 回転を取得。
	/// </summary>
	/// <returns>回転。</returns>
	const Quaternion& GetRotation() const
	{
		return m_rotation;
	}
	/// <summary>
	/// プレイヤーがオブジェクトとの接地判定を取得。
	/// </summary>
	/// <returns>オブジェクトの接地判定。</returns>
	const bool& IsPlayerTouchObject() const
	{
		return m_isTouchObject;
	}
	/// <summary>
	/// スライドを初期化する。
	/// </summary>
	const void InitSlide()
	{
		m_isSlide = true;
	}
	/// <summary>
	/// スライドをリセットする。
	/// </summary>
	const void ResetSlide()
	{
		m_isSlide = false;
	}
	/// <summary>
	/// スライド中か
	/// </summary>
	/// <returns>スライド中かどうか</returns>
	const bool& IsSlide() const
	{
		return m_isSlide;
	}
	const Vector3& GetForward() const
	{
		return m_forward;
	}

private:
	friend class PlayerIdleState;
	friend class PlayerWalkState;
	friend class PlayerSlideState;
	friend class PlayerIdleInAirState;
	friend class PlayerFallInAirState;
	/// <summary>
	/// 初期化処理。
	/// </summary>
	void Init();
	/// <summary>
	/// 回転処理。
	/// </summary>
	void Rotation();
	/// <summary>
	/// 歩く。
	/// </summary>
	void MoveOnGround();
	/// <summary>
	/// 移動方向を決める。
	/// </summary>
	void DecideMoveDirection();
	/// <summary>
	/// 空中での移動処理。
	/// </summary>
	void MoveOnAirspace();
	/// <summary>
	/// スライディング。
	/// </summary>
	void Slide();
	/// <summary>
	/// アニメーションイベント用関数。
	/// </summary>
	/// <param name="clipName"></param>
	/// <param name="eventName"></param>
	void OnAnimationEvent(const wchar_t* clipName, const wchar_t* eventName);

	void TestRotation();
	/// <summary>
	/// アニメーションを再生する。
	/// </summary>
	void PlayAnimation(EnAnimationClip currentAnimationClip);
	void A(Vector3& vector, const Vector3& axis, float deg, const Quaternion& q);
private:
	ModelRender				m_model;										// モデル
	Vector3					m_position = Vector3::Zero;						// 座標
	Vector3					m_scale = Vector3::One;							// 拡大率
	Quaternion				m_rotation = Quaternion::Identity;				// 回転
	AnimationClip			m_animationClips[enAnimationClip_Num];			// アニメーションクリップ
	Vector3					m_currentModelUpAxis;							// 現在のモデルの上方向
	bool					m_isTouchObject = true;							// モデルとオブジェクトとの接地判定
	Vector3					m_moveSpeed = Vector3::Zero;					// 移動速度
	CharacterController		m_charaCon;										// キャラクターコントローラー
	PlayerState*			m_playerState = nullptr;						// ステート
	EnAnimationClip			m_currentAnimationClip;							// 現在設定されているアニメーションクリップ
	Vector3					m_yawPitchRoll = Vector3::Zero;					// YawPitchRollの回転要素
	Vector3					m_moveVectorInAir = Vector3::Zero;				// 空中での移動方向
	Vector3					m_forward = Vector3::AxisZ;						// 正面方向
	SoundSource*			m_runFootstep = nullptr;						// 走りの足音
	Quaternion				m_slideRot = Quaternion::Identity;				// スライド中の進行方向の回転
	bool					m_isSlide = false;								// スライド中？	
	Vector3					m_forward2 = Vector3::Zero;
};

