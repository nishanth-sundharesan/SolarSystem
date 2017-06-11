#include "CelestialBodyConstants.h"

using namespace std;
using namespace DirectX;

namespace SolarSystem
{
	const XMFLOAT3 SunConstants::sOrbitRadius(0.0f, 0.0f, 0.0f);
	const XMFLOAT3 SunConstants::sScale(1.0f, 1.0f, 1.0f);
	const wstring SunConstants::sTexturePath = L"Content\\Textures\\Sun.jpg";
	const float SunConstants::sRotationRate = 0.0f;
	const float SunConstants::sRevolutionRate = 0.0f;

	const XMFLOAT3 MoonConstants::sOrbitRadius(20.0f, 0.0f, 0.0f);
	const XMFLOAT3 MoonConstants::sScale(0.3f, 0.3f, 0.3f);
	const wstring MoonConstants::sTexturePath = L"Content\\Textures\\Moon.jpg";
	const float MoonConstants::sRotationRate = 5.0f;
	const float MoonConstants::sRevolutionRate = 10.0f;

	const XMFLOAT3 MercuryConstants::sOrbitRadius(10.0f, 0.0f, 0.0f);
	const XMFLOAT3 MercuryConstants::sScale(0.5f, 0.5f, 0.5f);
	const wstring MercuryConstants::sTexturePath = L"Content\\Textures\\Mercury.jpg";
	const float MercuryConstants::sRotationRate = 8.0f;
	const float MercuryConstants::sRevolutionRate = 4.0f;

	const XMFLOAT3 VenusConstants::sOrbitRadius(30.0f, 0.0f, 0.0f);
	const XMFLOAT3 VenusConstants::sScale(1.0f, 1.0f, 1.0f);
	const wstring VenusConstants::sTexturePath = L"Content\\Textures\\Venus.jpg";
	const float VenusConstants::sRotationRate = 6.0f;
	const float VenusConstants::sRevolutionRate = 3.0f;

	const XMFLOAT3 EarthConstants::sOrbitRadius(50.0f, 0.0f, 0.0f);
	const XMFLOAT3 EarthConstants::sScale(1.0f, 1.0f, 1.0f);
	const wstring EarthConstants::sTexturePath = L"Content\\Textures\\Earth.jpg";
	const float EarthConstants::sRotationRate = 4.0f;
	const float EarthConstants::sRevolutionRate = 2.0f;

	const XMFLOAT3 MarsConstants::sOrbitRadius(70.0f, 0.0f, 0.0f);
	const XMFLOAT3 MarsConstants::sScale(1.0f, 1.0f, 1.0f);
	const wstring MarsConstants::sTexturePath = L"Content\\Textures\\Mars.jpg";
	const float MarsConstants::sRotationRate = 3.0f;
	const float MarsConstants::sRevolutionRate = 1.8f;

	const XMFLOAT3 JupiterConstants::sOrbitRadius(90.0f, 0.0f, 0.0f);
	const XMFLOAT3 JupiterConstants::sScale(1.0f, 1.0f, 1.0f);
	const wstring JupiterConstants::sTexturePath = L"Content\\Textures\\Jupiter.jpg";
	const float JupiterConstants::sRotationRate = 1.5f;
	const float JupiterConstants::sRevolutionRate = 1.5f;

	const XMFLOAT3 SaturnConstants::sOrbitRadius(110.0f, 0.0f, 0.0f);
	const XMFLOAT3 SaturnConstants::sScale(1.0f, 1.0f, 1.0f);
	const wstring SaturnConstants::sTexturePath = L"Content\\Textures\\Saturn.jpg";
	const float SaturnConstants::sRotationRate = 1.2f;
	const float SaturnConstants::sRevolutionRate = 1.2f;

	const XMFLOAT3 UranusConstants::sOrbitRadius(130.0f, 0.0f, 0.0f);
	const XMFLOAT3 UranusConstants::sScale(1.0f, 1.0f, 1.0f);
	const wstring UranusConstants::sTexturePath = L"Content\\Textures\\Uranus.jpg";
	const float UranusConstants::sRotationRate = 1.0f;
	const float UranusConstants::sRevolutionRate = 1.0f;

	const XMFLOAT3 NeptuneConstants::sOrbitRadius(150.0f, 0.0f, 0.0f);
	const XMFLOAT3 NeptuneConstants::sScale(1.0f, 1.0f, 1.0f);
	const wstring NeptuneConstants::sTexturePath = L"Content\\Textures\\Neptune.jpg";
	const float NeptuneConstants::sRotationRate = 0.8f;
	const float NeptuneConstants::sRevolutionRate = 0.8f;

	const XMFLOAT3 PlutoConstants::sOrbitRadius(170.0f, 0.0f, 0.0f);
	const XMFLOAT3 PlutoConstants::sScale(1.0f, 1.0f, 1.0f);
	const wstring PlutoConstants::sTexturePath = L"Content\\Textures\\Pluto.jpg";
	const float PlutoConstants::sRotationRate = 0.5f;
	const float PlutoConstants::sRevolutionRate = 0.5f;
}