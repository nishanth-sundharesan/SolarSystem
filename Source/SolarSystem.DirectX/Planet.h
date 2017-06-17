#pragma once
#include "Star.h"

namespace SolarSystem
{
	class Planet final : public CelestialObject
	{
	public:
		Planet(Library::Game& game, const std::shared_ptr<Library::Camera>& camera, const std::wstring& texturePath, const DirectX::XMFLOAT3& orbitRadius, const DirectX::XMFLOAT3& scaleFactor, bool isAnimated, float rotationRate, float revolutionRate, float tiltAngle, const std::shared_ptr<Star>& star);
		Planet(const Planet&) = default;
		Planet& operator=(const Planet&) = default;
		Planet(Planet&&) = default;
		Planet& operator=(Planet&&) = default;
		virtual ~Planet() = default;

		virtual void Update(const Library::GameTime& gameTime) override;
	protected:
		virtual void UpdateDirectionalLight(const Library::GameTime& gameTime) override;
	private:
		std::shared_ptr<Star> mStar;
	};
}