#include "pch.h"
#include "Satellite.h"

using namespace std;
using namespace Library;
using namespace DirectX;
using namespace Rendering;

namespace SolarSystem
{
	Satellite::Satellite(Game& game, const shared_ptr<Camera>& camera, const wstring& texturePath, const XMFLOAT3& orbitRadius, const XMFLOAT3& scaleFactor, bool isAnimated, float rotationRate, float revolutionRate, float tiltAngle, const shared_ptr<CelestialObject>& planet)
		:CelestialObject(game, camera, texturePath, orbitRadius, scaleFactor, isAnimated, rotationRate, revolutionRate, tiltAngle, true), mPlanet(planet)
	{

	}

	void Satellite::Update(const GameTime& gameTime)
	{
		if (mAnimationEnabled)
		{
			mCurrentRotationAngle += gameTime.ElapsedGameTimeSeconds().count() * mRotationRate;
			mCurrentRevolutionAngle += gameTime.ElapsedGameTimeSeconds().count() * mRevolutionRate;			
			XMMATRIX planetPosition = XMLoadFloat4x4(&mPlanet->PositionMatrix());						
			XMMATRIX translatedMatrix = XMMatrixScaling(mObjectScale.x, mObjectScale.y, mObjectScale.y) * XMMatrixRotationY(mCurrentRotationAngle) * XMMatrixRotationX(XMConvertToRadians(mTiltAngle)) * XMMatrixTranslation(mOrbitRadius.x, mOrbitRadius.y, mOrbitRadius.z) * XMMatrixRotationY(mCurrentRevolutionAngle) * planetPosition;
			XMStoreFloat4x4(&mWorldMatrix, translatedMatrix);
		}
	}
}
