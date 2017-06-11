#pragma once
#include "CelestialObject.h"

namespace SolarSystem
{
	class Satellite final : public CelestialObject
	{
	public:
		Satellite(Library::Game& game, const std::shared_ptr<Library::Camera>& camera, const std::wstring& texturePath, DirectX::XMFLOAT3 orbitRadius, DirectX::XMFLOAT3 scaleFactor, bool isAnimated, float rotationRate, float revolutionRate, const std::shared_ptr<CelestialObject>& planet);
		Satellite(const Satellite&) = default;
		Satellite& operator=(const Satellite&) = default;
		Satellite(Satellite&&) = default;
		Satellite& operator=(Satellite&&) = default;
		virtual ~Satellite() = default;

		virtual void Update(const Library::GameTime& gameTime) override;
	private:
		std::shared_ptr<CelestialObject> mPlanet;
	};
}