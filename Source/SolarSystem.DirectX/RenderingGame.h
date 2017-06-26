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
	class Star;
	class Planet;
	class Satellite;
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

		std::vector<std::shared_ptr<SolarSystem::Star>> mStars;
		std::vector<std::shared_ptr<SolarSystem::Planet>> mPlanets;
		std::vector<std::shared_ptr<SolarSystem::Satellite>> mSatellites;			
	};
}
