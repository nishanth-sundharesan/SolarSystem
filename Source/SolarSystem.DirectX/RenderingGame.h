#pragma once

#include "Game.h"
#include <windows.h>
#include <functional>

namespace Library
{
	class KeyboardComponent;
	class MouseComponent;
	class FpsComponent;
	class Camera;
	class RenderStateHelper;
	class Grid;	
}

namespace SolarSystem
{
	class CelestialObject;
}

namespace Rendering
{	
    class RenderingGame : public Library::Game
    {
    public:
		RenderingGame(std::function<void*()> getWindowCallback, std::function<void(SIZE&)> getRenderTargetSizeCallback);

		virtual void Initialize() override;
		virtual void Update(const Library::GameTime& gameTime) override;
		virtual void Draw(const Library::GameTime& gameTime) override;		
		virtual void Shutdown() override;

		void Exit();

    private:
		static const DirectX::XMVECTORF32 BackgroundColor;

		std::shared_ptr<Library::KeyboardComponent> mKeyboard;
		std::shared_ptr<Library::MouseComponent> mMouse;
		std::shared_ptr<Library::FpsComponent> mFpsComponent;
		std::shared_ptr<Library::Camera> mCamera;
		std::unique_ptr<Library::RenderStateHelper> mRenderStateHelper;
		std::shared_ptr<Library::Grid> mGrid;

		std::shared_ptr<SolarSystem::CelestialObject> mSun;
		std::shared_ptr<SolarSystem::CelestialObject> mMercury;
		std::shared_ptr<SolarSystem::CelestialObject> mVenus;
		std::shared_ptr<SolarSystem::CelestialObject> mEarth;
		std::shared_ptr<SolarSystem::CelestialObject> mMars;
		std::shared_ptr<SolarSystem::CelestialObject> mJupiter;
		std::shared_ptr<SolarSystem::CelestialObject> mSaturn;
		std::shared_ptr<SolarSystem::CelestialObject> mUranus;
		std::shared_ptr<SolarSystem::CelestialObject> mNeptune;
		std::shared_ptr<SolarSystem::CelestialObject> mPluto;
		std::shared_ptr<SolarSystem::CelestialObject> mMoon;
    };
}