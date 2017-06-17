#include "pch.h"
#include "Planet.h"

using namespace std;
using namespace Library;
using namespace DirectX;
using namespace Rendering;

namespace SolarSystem
{
	Planet::Planet(Game& game, const shared_ptr<Camera>& camera, const wstring& texturePath, const XMFLOAT3& orbitRadius, const XMFLOAT3& scaleFactor, bool isAnimated, float rotationRate, float revolutionRate, float tiltAngle, const shared_ptr<Star>& star)
		:CelestialObject(game, camera, texturePath, orbitRadius, scaleFactor, isAnimated, rotationRate, revolutionRate, tiltAngle, true), mStar(star)
	{
	}

	void Planet::Update(const Library::GameTime & gameTime)
	{
		if (mAnimationEnabled)
		{
			mCurrentRotationAngle += gameTime.ElapsedGameTimeSeconds().count() * mRotationRate;
			mCurrentRevolutionAngle += gameTime.ElapsedGameTimeSeconds().count() * mRevolutionRate;
			XMStoreFloat4x4(&mPositionMatrix, XMMatrixTranslation(mOrbitRadius.x, mOrbitRadius.y, mOrbitRadius.z) * XMMatrixRotationY(mCurrentRevolutionAngle));
			XMMATRIX translatedMatrix = XMMatrixScaling(mObjectScale.x, mObjectScale.y, mObjectScale.y) * XMMatrixRotationY(mCurrentRotationAngle) * XMMatrixRotationX(XMConvertToRadians(mTiltAngle)) * XMMatrixTranslation(mOrbitRadius.x, mOrbitRadius.y, mOrbitRadius.z) * XMMatrixRotationY(mCurrentRevolutionAngle);
			XMStoreFloat4x4(&mWorldMatrix, translatedMatrix);
		}
		UpdateDirectionalLight(gameTime);
	}

	void Planet::UpdateDirectionalLight(const GameTime& gameTime)
	{
		UNREFERENCED_PARAMETER(gameTime);

		XMFLOAT3 lightDirection(1.0f, 1.0f, 1.0f);
		XMVECTOR starPosition = XMVector3Transform(XMLoadFloat3(&lightDirection), XMLoadFloat4x4(&mPositionMatrix));
		XMStoreFloat3(&lightDirection, XMVector3Normalize(mStar->PositionInXMVector() - starPosition));
		mPixelCBufferPerFrameData.LightDirection = lightDirection;
		mGame->Direct3DDeviceContext()->UpdateSubresource(mPixelCBufferPerFrame.Get(), 0, nullptr, &mPixelCBufferPerFrameData, 0, 0);
	}
}