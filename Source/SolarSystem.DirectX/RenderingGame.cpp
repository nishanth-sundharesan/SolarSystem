#include "pch.h"
#include "Star.h"
#include "Planet.h"
#include "Satellite.h"
#include "Orbit.h"
#include "CelestialBodyConstants.h"

using namespace std;
using namespace DirectX;
using namespace Library;
using namespace SolarSystem;;

namespace Rendering
{
	const XMVECTORF32 RenderingGame::BackgroundColor = Colors::Black;

	RenderingGame::RenderingGame(std::function<void*()> getWindowCallback, std::function<void(SIZE&)> getRenderTargetSizeCallback) :
		Game(getWindowCallback, getRenderTargetSizeCallback)
	{
	}

	void RenderingGame::Initialize()
	{
		SamplerStates::Initialize(mDirect3DDevice.Get());

		mKeyboard = make_shared<KeyboardComponent>(*this);
		mComponents.push_back(mKeyboard);
		mServices.AddService(KeyboardComponent::TypeIdClass(), mKeyboard.get());

		mMouse = make_shared<MouseComponent>(*this);
		mComponents.push_back(mMouse);
		mServices.AddService(MouseComponent::TypeIdClass(), mMouse.get());

		mCamera = make_shared<FirstPersonCamera>(*this);
		mComponents.push_back(mCamera);
		mServices.AddService(Camera::TypeIdClass(), mCamera.get());

#pragma region Orbits		
		mComponents.push_back(make_shared<Orbit>(*this, mCamera, MercuryConstants::sNumberOfVertices, static_cast<uint32_t>(MercuryConstants::sOrbitRadius.x)));

		mComponents.push_back(make_shared<Orbit>(*this, mCamera, VenusConstants::sNumberOfVertices, static_cast<uint32_t>(VenusConstants::sOrbitRadius.x)));

		mComponents.push_back(make_shared<Orbit>(*this, mCamera, EarthConstants::sNumberOfVertices, static_cast<uint32_t>(EarthConstants::sOrbitRadius.x)));

		mComponents.push_back(make_shared<Orbit>(*this, mCamera, MarsConstants::sNumberOfVertices, static_cast<uint32_t>(MarsConstants::sOrbitRadius.x)));

		mComponents.push_back(make_shared<Orbit>(*this, mCamera, JupiterConstants::sNumberOfVertices, static_cast<uint32_t>(JupiterConstants::sOrbitRadius.x)));

		mComponents.push_back(make_shared<Orbit>(*this, mCamera, SaturnConstants::sNumberOfVertices, static_cast<uint32_t>(SaturnConstants::sOrbitRadius.x)));

		mComponents.push_back(make_shared<Orbit>(*this, mCamera, UranusConstants::sNumberOfVertices, static_cast<uint32_t>(UranusConstants::sOrbitRadius.x)));

		mComponents.push_back(make_shared<Orbit>(*this, mCamera, NeptuneConstants::sNumberOfVertices, static_cast<uint32_t>(NeptuneConstants::sOrbitRadius.x)));

		mComponents.push_back(make_shared<Orbit>(*this, mCamera, PlutoConstants::sNumberOfVertices, static_cast<uint32_t>(PlutoConstants::sOrbitRadius.x)));
#pragma endregion

#pragma region Stars

		shared_ptr<SolarSystem::Star> mSun = make_shared<Star>(*this, mCamera, SunConstants::sTexturePath, SunConstants::sOrbitRadius, SunConstants::sScale, false, SunConstants::sRotationRate, SunConstants::sRevolutionRate, SunConstants::sTiltAngle);
		mStars.push_back(mSun);
		mComponents.push_back(mSun);
#pragma endregion

#pragma region Planets
		shared_ptr<SolarSystem::Planet> mMercury = make_shared<Planet>(*this, mCamera, MercuryConstants::sTexturePath, MercuryConstants::sOrbitRadius, MercuryConstants::sScale, true, MercuryConstants::sRotationRate, MercuryConstants::sRevolutionRate, MercuryConstants::sTiltAngle, mSun);
		mPlanets.push_back(mMercury);
		mComponents.push_back(mMercury);

		shared_ptr<SolarSystem::Planet> mVenus = make_shared<Planet>(*this, mCamera, VenusConstants::sTexturePath, VenusConstants::sOrbitRadius, VenusConstants::sScale, true, VenusConstants::sRotationRate, VenusConstants::sRevolutionRate, VenusConstants::sTiltAngle, mSun);
		mPlanets.push_back(mVenus);
		mComponents.push_back(mVenus);

		shared_ptr<SolarSystem::Planet> mEarth = make_shared<Planet>(*this, mCamera, EarthConstants::sTexturePath, EarthConstants::sOrbitRadius, EarthConstants::sScale, true, EarthConstants::sRotationRate, EarthConstants::sRevolutionRate, EarthConstants::sTiltAngle, mSun);
		mPlanets.push_back(mEarth);
		mComponents.push_back(mEarth);

		shared_ptr<SolarSystem::Planet> mMars = make_shared<Planet>(*this, mCamera, MarsConstants::sTexturePath, MarsConstants::sOrbitRadius, MarsConstants::sScale, true, MarsConstants::sRotationRate, MarsConstants::sRevolutionRate, MarsConstants::sTiltAngle, mSun);
		mPlanets.push_back(mMars);
		mComponents.push_back(mMars);

		shared_ptr<SolarSystem::Planet> mJupiter = make_shared<Planet>(*this, mCamera, JupiterConstants::sTexturePath, JupiterConstants::sOrbitRadius, JupiterConstants::sScale, true, JupiterConstants::sRotationRate, JupiterConstants::sRevolutionRate, JupiterConstants::sTiltAngle, mSun);
		mPlanets.push_back(mJupiter);
		mComponents.push_back(mJupiter);

		shared_ptr<SolarSystem::Planet> mSaturn = make_shared<Planet>(*this, mCamera, SaturnConstants::sTexturePath, SaturnConstants::sOrbitRadius, SaturnConstants::sScale, true, SaturnConstants::sRotationRate, SaturnConstants::sRevolutionRate, SaturnConstants::sTiltAngle, mSun);
		mPlanets.push_back(mSaturn);
		mComponents.push_back(mSaturn);

		shared_ptr<SolarSystem::Planet> mUranus = make_shared<Planet>(*this, mCamera, UranusConstants::sTexturePath, UranusConstants::sOrbitRadius, UranusConstants::sScale, true, UranusConstants::sRotationRate, UranusConstants::sRevolutionRate, UranusConstants::sTiltAngle, mSun);
		mPlanets.push_back(mUranus);
		mComponents.push_back(mUranus);

		shared_ptr<SolarSystem::Planet> mNeptune = make_shared<Planet>(*this, mCamera, NeptuneConstants::sTexturePath, NeptuneConstants::sOrbitRadius, NeptuneConstants::sScale, true, NeptuneConstants::sRotationRate, NeptuneConstants::sRevolutionRate, NeptuneConstants::sTiltAngle, mSun);
		mPlanets.push_back(mNeptune);
		mComponents.push_back(mNeptune);

		shared_ptr<SolarSystem::Planet> mPluto = make_shared<Planet>(*this, mCamera, PlutoConstants::sTexturePath, PlutoConstants::sOrbitRadius, PlutoConstants::sScale, true, PlutoConstants::sRotationRate, PlutoConstants::sRevolutionRate, PlutoConstants::sTiltAngle, mSun);
		mPlanets.push_back(mPluto);
		mComponents.push_back(mPluto);
#pragma endregion

#pragma region Satellites
		shared_ptr<SolarSystem::Satellite> mMoon = make_shared<Satellite>(*this, mCamera, MoonConstants::sTexturePath, MoonConstants::sOrbitRadius, MoonConstants::sScale, true, MoonConstants::sRotationRate, MoonConstants::sRevolutionRate, MoonConstants::sTiltAngle, mEarth);
		mSatellites.push_back(mMoon);
		mComponents.push_back(mMoon);
#pragma endregion

		Game::Initialize();

		mRenderStateHelper = make_unique<RenderStateHelper>(*this);
		mFpsComponent = make_shared<FpsComponent>(*this);
		mFpsComponent->Initialize();
		mCamera->SetPosition(0.0f, 50.0f, 350.0f);
	}

	void RenderingGame::Update(const GameTime &gameTime)
	{
		mFpsComponent->Update(gameTime);

		if (mKeyboard->WasKeyPressedThisFrame(Keys::Escape))
		{
			Exit();
		}
		if (mKeyboard->WasKeyPressedThisFrame(Keys::Space))
		{
			for (auto celestialObject : mStars)
			{
				celestialObject->ToggleAnimation();
			}

			for (auto celestialObject : mPlanets)
			{
				celestialObject->ToggleAnimation();
			}

			for (auto celestialObject : mSatellites)
			{
				celestialObject->ToggleAnimation();
			}
		}
		Game::Update(gameTime);
	}

	void RenderingGame::Draw(const GameTime &gameTime)
	{
		mDirect3DDeviceContext->ClearRenderTargetView(mRenderTargetView.Get(), reinterpret_cast<const float*>(&BackgroundColor));
		mDirect3DDeviceContext->ClearDepthStencilView(mDepthStencilView.Get(), D3D11_CLEAR_DEPTH | D3D11_CLEAR_STENCIL, 1.0f, 0);

		Game::Draw(gameTime);

		mRenderStateHelper->SaveAll();
		mFpsComponent->Draw(gameTime);
		mRenderStateHelper->RestoreAll();

		HRESULT hr = mSwapChain->Present(1, 0);

		// If the device was removed either by a disconnection or a driver upgrade, we must recreate all device resources.
		if (hr == DXGI_ERROR_DEVICE_REMOVED || hr == DXGI_ERROR_DEVICE_RESET)
		{
			HandleDeviceLost();
		}
		else
		{
			ThrowIfFailed(hr, "IDXGISwapChain::Present() failed.");
		}
	}

	void RenderingGame::Shutdown()
	{
		SamplerStates::Shutdown();
	}

	void RenderingGame::Exit()
	{
		PostQuitMessage(0);
	}
}