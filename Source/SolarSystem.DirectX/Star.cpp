#include "pch.h"
#include "Star.h"

using namespace std;
using namespace Library;

using namespace DirectX;
using namespace Rendering;
namespace SolarSystem
{
	Star::Star(Game& game, const shared_ptr<Library::Camera>& camera, const wstring& texturePath, const XMFLOAT3& position, const XMFLOAT3& scaleFactor, bool isAnimated, float rotationRate, float revolutionRate, float tiltAngle)
		:CelestialObject(game, camera, texturePath, position, scaleFactor, isAnimated, rotationRate, revolutionRate, tiltAngle, false), mPosition(position)
	{
		//mPositionInXMVector = XMLoadFloat3(&mPosition);
	}

	void Star::Update(const Library::GameTime& gameTime)
	{
		UNREFERENCED_PARAMETER(gameTime);
		XMMATRIX translatedMatrix = XMMatrixScaling(mObjectScale.x, mObjectScale.y, mObjectScale.y);
		XMStoreFloat4x4(&mWorldMatrix, translatedMatrix);
	}

	const XMFLOAT3& Star::Position() const
	{
		return mPosition;
	}

	XMVECTOR Star::PositionInXMVector() const
	{
		return XMLoadFloat3(&mPosition);
	}
}