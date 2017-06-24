#pragma once
#include "CelestialObject.h"

namespace SolarSystem
{
	class Star final : public CelestialObject
	{
	public:
		Star(Library::Game& game, const std::shared_ptr<Library::Camera>& camera, const std::wstring& texturePath, const DirectX::XMFLOAT3& position, const DirectX::XMFLOAT3& scaleFactor, bool isAnimated, float rotationRate, float revolutionRate, float tiltAngle);
		Star(const Star&) = default;
		Star& operator=(const Star&) = default;
		Star(Star&&) = default;
		Star& operator=(Star&&) = default;
		virtual ~Star() = default;

		virtual void Update(const Library::GameTime& gameTime) override;
		const DirectX::XMFLOAT3& Position() const;
		DirectX::XMVECTOR PositionInXMVector() const;
	private:		
		DirectX::XMFLOAT3 mPosition;		
	};
}