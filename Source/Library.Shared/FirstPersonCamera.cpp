#include "pch.h"

using namespace DirectX;

namespace Library
{
	RTTI_DEFINITIONS(FirstPersonCamera)

		const float FirstPersonCamera::DefaultMouseSensitivity = 0.1f;
	const float FirstPersonCamera::DefaultRotationRate = XMConvertToRadians(100.0f);
	const float FirstPersonCamera::DefaultMovementRate = 100.0f;

	FirstPersonCamera::FirstPersonCamera(Game& game) :
		PerspectiveCamera(game),
		mGamePad(nullptr), mKeyboard(nullptr), mMouse(nullptr), mMouseSensitivity(DefaultMouseSensitivity),
		mRotationRate(DefaultRotationRate), mMovementRate(DefaultMovementRate)
	{
	}

	FirstPersonCamera::FirstPersonCamera(Game& game, float fieldOfView, float aspectRatio, float nearPlaneDistance, float farPlaneDistance) :
		PerspectiveCamera(game, fieldOfView, aspectRatio, nearPlaneDistance, farPlaneDistance),
		mGamePad(nullptr), mKeyboard(nullptr), mMouse(nullptr), mMouseSensitivity(DefaultMouseSensitivity),
		mRotationRate(DefaultRotationRate), mMovementRate(DefaultMovementRate)
	{
	}

	GamePadComponent* FirstPersonCamera::GetGamePad() const
	{
		return mGamePad;
	}

	void FirstPersonCamera::SetGamePad(GamePadComponent* gamePad)
	{
		mGamePad = gamePad;
	}

	KeyboardComponent* FirstPersonCamera::GetKeyboard() const
	{
		return mKeyboard;
	}

	void FirstPersonCamera::SetKeyboard(KeyboardComponent* keyboard)
	{
		mKeyboard = keyboard;
	}

	MouseComponent* FirstPersonCamera::GetMouse() const
	{
		return mMouse;
	}

	void FirstPersonCamera::SetMouse(MouseComponent* mouse)
	{
		mMouse = mouse;
	}

	float& FirstPersonCamera::MouseSensitivity()
	{
		return mMouseSensitivity;
	}

	float& FirstPersonCamera::RotationRate()
	{
		return mRotationRate;
	}

	float& FirstPersonCamera::MovementRate()
	{
		return mMovementRate;
	}

	void FirstPersonCamera::Initialize()
	{
		mGamePad = (GamePadComponent*)mGame->Services().GetService(GamePadComponent::TypeIdClass());
		mKeyboard = (KeyboardComponent*)mGame->Services().GetService(KeyboardComponent::TypeIdClass());
		mMouse = (MouseComponent*)mGame->Services().GetService(MouseComponent::TypeIdClass());

		Camera::Initialize();
	}

	void FirstPersonCamera::Update(const GameTime& gameTime)
	{
		GamePad::State gamePadState;
		if (IsGamePadConnected(gamePadState))
		{
			XMFLOAT3 movementAmount(gamePadState.thumbSticks.leftX, gamePadState.thumbSticks.leftY, 0.0f);
			XMFLOAT2 rotationAmount(-gamePadState.thumbSticks.rightX, gamePadState.thumbSticks.rightY);
			UpdatePosition(movementAmount, rotationAmount, gameTime);
		}
		else
		{
			bool positionChanged = false;
			XMFLOAT3 movementAmount = Vector3Helper::Zero;
			if (mKeyboard != nullptr)
			{
				if (mKeyboard->IsKeyDown(Keys::W))
				{
					movementAmount.y = 1.0f;
					positionChanged = true;
				}
				if (mKeyboard->IsKeyDown(Keys::S))
				{
					movementAmount.y = -1.0f;
					positionChanged = true;
				}
				if (mKeyboard->IsKeyDown(Keys::A))
				{
					movementAmount.x = -1.0f;
					positionChanged = true;
				}
				if (mKeyboard->IsKeyDown(Keys::D))
				{
					movementAmount.x = 1.0f;
					positionChanged = true;
				}
				if (mKeyboard->IsKeyDown(Keys::E))
				{
					movementAmount.z = 1.0f;
					positionChanged = true;
				}
				if (mKeyboard->IsKeyDown(Keys::Q))
				{
					movementAmount.z = -1.0f;
					positionChanged = true;
				}
			}

			XMFLOAT2 rotationAmount = Vector2Helper::Zero;
			if (mMouse != nullptr)
			{
				if (mMouse->IsButtonHeldDown(MouseButtons::Left))
				{
					rotationAmount.x = -mMouse->X() * mMouseSensitivity;
					rotationAmount.y = -mMouse->Y() * mMouseSensitivity;
					positionChanged = true;
				}
			}

			if (positionChanged)
			{
				UpdatePosition(movementAmount, rotationAmount, gameTime);
			}
		}

		Camera::Update(gameTime);
	}

	void FirstPersonCamera::UpdatePosition(const XMFLOAT3& movementAmount, const XMFLOAT2& rotationAmount, const GameTime& gameTime)
	{
		float elapsedTime = gameTime.ElapsedGameTimeSeconds().count();
		XMVECTOR rotationVector = XMLoadFloat2(&rotationAmount) * mRotationRate * elapsedTime;
		XMVECTOR right = XMLoadFloat3(&mRight);
		XMVECTOR up = XMLoadFloat3(&mUp);

		XMMATRIX pitchMatrix = XMMatrixRotationAxis(right, XMVectorGetY(rotationVector));
		XMMATRIX yawMatrix = XMMatrixRotationY(XMVectorGetX(rotationVector));

		ApplyRotation(XMMatrixMultiply(pitchMatrix, yawMatrix));

		XMVECTOR position = XMLoadFloat3(&mPosition);
		XMVECTOR movement = XMLoadFloat3(&movementAmount) * mMovementRate * elapsedTime;

		XMVECTOR strafe = right * XMVectorGetX(movement);
		position += strafe;

		XMVECTOR forward = XMLoadFloat3(&mDirection) * XMVectorGetY(movement);
		position += forward;

		XMVECTOR upward = up * XMVectorGetZ(movement);
		position += upward;

		XMStoreFloat3(&mPosition, position);
	}
}
