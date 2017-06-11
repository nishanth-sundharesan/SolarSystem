#include "pch.h"
#include "Satellite.h"

using namespace std;
using namespace Library;
using namespace DirectX;
using namespace Rendering;

namespace SolarSystem
{
	Satellite::Satellite(Game& game, const shared_ptr<Camera>& camera, const wstring& texturePath, XMFLOAT3 orbitRadius, XMFLOAT3 scaleFactor, bool isAnimated, float rotationRate, float revolutionRate, const std::shared_ptr<CelestialObject>& planet)
		:CelestialObject(game, camera, texturePath, orbitRadius, scaleFactor, isAnimated, rotationRate, revolutionRate), mPlanet(planet)
	{

	}

	void Satellite::Update(const GameTime& gameTime)
	{
		if (mAnimationEnabled)
		{
			mCurrentRotationAngle += gameTime.ElapsedGameTimeSeconds().count() * mRotationRate;
			mCurrentRevolutionAngle += gameTime.ElapsedGameTimeSeconds().count() * mRevolutionRate;						
			XMMATRIX planetSpaceMatrix = mPlanet->PositionMatrix();
			XMMATRIX translatedMatrix = XMMatrixScaling(mObjectScale.x, mObjectScale.y, mObjectScale.y) * XMMatrixRotationY(mCurrentRotationAngle) * XMMatrixTranslation(mOrbitRadius.x, mOrbitRadius.y, mOrbitRadius.z) * XMMatrixRotationY(mCurrentRevolutionAngle) * planetSpaceMatrix;

			XMStoreFloat4x4(&mWorldMatrix, translatedMatrix);
		}
	}
}
