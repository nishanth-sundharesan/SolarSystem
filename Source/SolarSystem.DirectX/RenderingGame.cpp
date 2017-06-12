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

		mOrbit = make_shared<Orbit>(*this, mCamera, 40, 200);
		mComponents.push_back(mOrbit);

		mSun = make_shared<Star>(*this, mCamera, SunConstants::sTexturePath, SunConstants::sOrbitRadius, SunConstants::sScale, false, SunConstants::sRotationRate, SunConstants::sRevolutionRate);
		mComponents.push_back(mSun);

		mMercury = make_shared<Planet>(*this, mCamera, MercuryConstants::sTexturePath, MercuryConstants::sOrbitRadius, MercuryConstants::sScale, true, MercuryConstants::sRotationRate, MercuryConstants::sRevolutionRate, mSun);
		mComponents.push_back(mMercury);

		mVenus = make_shared<Planet>(*this, mCamera, VenusConstants::sTexturePath, VenusConstants::sOrbitRadius, VenusConstants::sScale, true, VenusConstants::sRotationRate, VenusConstants::sRevolutionRate, mSun);
		mComponents.push_back(mVenus);

		mEarth = make_shared<Planet>(*this, mCamera, EarthConstants::sTexturePath, EarthConstants::sOrbitRadius, EarthConstants::sScale, true, EarthConstants::sRotationRate, EarthConstants::sRevolutionRate, mSun);
		mComponents.push_back(mEarth);

		mMoon = make_shared<Satellite>(*this, mCamera, MoonConstants::sTexturePath, MoonConstants::sOrbitRadius, MoonConstants::sScale, true, MoonConstants::sRotationRate, MoonConstants::sRevolutionRate, mEarth);
		mComponents.push_back(mMoon);

		mMars = make_shared<Planet>(*this, mCamera, MarsConstants::sTexturePath, MarsConstants::sOrbitRadius, MarsConstants::sScale, true, MarsConstants::sRotationRate, MarsConstants::sRevolutionRate, mSun);
		mComponents.push_back(mMars);

		mJupiter = make_shared<Planet>(*this, mCamera, JupiterConstants::sTexturePath, JupiterConstants::sOrbitRadius, JupiterConstants::sScale, true, JupiterConstants::sRotationRate, JupiterConstants::sRevolutionRate, mSun);
		mComponents.push_back(mJupiter);

		mSaturn = make_shared<Planet>(*this, mCamera, SaturnConstants::sTexturePath, SaturnConstants::sOrbitRadius, SaturnConstants::sScale, true, SaturnConstants::sRotationRate, SaturnConstants::sRevolutionRate, mSun);
		mComponents.push_back(mSaturn);

		mUranus = make_shared<Planet>(*this, mCamera, UranusConstants::sTexturePath, UranusConstants::sOrbitRadius, UranusConstants::sScale, true, UranusConstants::sRotationRate, UranusConstants::sRevolutionRate, mSun);
		mComponents.push_back(mUranus);

		mNeptune = make_shared<Planet>(*this, mCamera, NeptuneConstants::sTexturePath, NeptuneConstants::sOrbitRadius, NeptuneConstants::sScale, true, NeptuneConstants::sRotationRate, NeptuneConstants::sRevolutionRate, mSun);
		mComponents.push_back(mNeptune);

		mPluto = make_shared<Planet>(*this, mCamera, PlutoConstants::sTexturePath, PlutoConstants::sOrbitRadius, PlutoConstants::sScale, true, PlutoConstants::sRotationRate, PlutoConstants::sRevolutionRate, mSun);
		mComponents.push_back(mPluto);

		Game::Initialize();

		mRenderStateHelper = make_unique<RenderStateHelper>(*this);
		mFpsComponent = make_shared<FpsComponent>(*this);
		mFpsComponent->Initialize();
		mCamera->SetPosition(0.0f, 5.0f, 100.0f);
	}

	void RenderingGame::Update(const GameTime &gameTime)
	{
		mFpsComponent->Update(gameTime);

		if (mKeyboard->WasKeyPressedThisFrame(Keys::Escape))
		{
			Exit();
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