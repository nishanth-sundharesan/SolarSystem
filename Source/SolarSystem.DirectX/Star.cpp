#include "pch.h"
#include "Star.h"

using namespace std;
using namespace Library;
using namespace DirectX;
using namespace Rendering;

namespace SolarSystem
{
	Star::Star(Game& game, const shared_ptr<Library::Camera>& camera, const wstring& texturePath, const XMFLOAT3& position, const XMFLOAT3& scaleFactor, bool isAnimated, float rotationRate, float revolutionRate)
		:CelestialObject(game, camera, texturePath, position, scaleFactor, isAnimated, rotationRate, revolutionRate, false), mPosition(position)
	{
		mPositionInXMVector = XMLoadFloat3(&mPosition);
	}

	const XMFLOAT3& Star::Position() const
	{
		return mPosition;
	}

	CXMVECTOR Star::PositionInXMVector() const
	{
		return mPositionInXMVector;
	}
}