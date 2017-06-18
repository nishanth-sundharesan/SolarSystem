#include "CelestialBodyConstants.h"

using namespace std;
using namespace DirectX;

namespace SolarSystem
{
	const XMFLOAT3 SunConstants::sOrbitRadius(0.0f, 0.0f, 0.0f);
	const XMFLOAT3 SunConstants::sScale(10.0f, 10.0f, 10.0f);
	const wstring SunConstants::sTexturePath = L"Content\\Textures\\Sun.jpg";
	const float SunConstants::sRotationRate = 0.0f;
	const float SunConstants::sRevolutionRate = 0.0f;
	const float SunConstants::sTiltAngle = 0.0f;

	const XMFLOAT3 MoonConstants::sOrbitRadius(20.0f, 0.0f, 0.0f);
	const XMFLOAT3 MoonConstants::sScale(0.3f, 0.3f, 0.3f);
	const wstring MoonConstants::sTexturePath = L"Content\\Textures\\Moon.jpg";
	const float MoonConstants::sRotationRate = 5.0f;
	const float MoonConstants::sRevolutionRate = 5.0f;
	const float MoonConstants::sTiltAngle = 0.0f;
	const uint32_t MoonConstants::sNumberOfVertices = 200;	

	const XMFLOAT3 MercuryConstants::sOrbitRadius(80.0f, 0.0f, 0.0f);
	const XMFLOAT3 MercuryConstants::sScale(0.382f, 0.382f, 0.382f);
	const wstring MercuryConstants::sTexturePath = L"Content\\Textures\\Mercury.jpg";
	const float MercuryConstants::sRotationRate = 92.0f;
	const float MercuryConstants::sRevolutionRate = 1.65f;
	const float MercuryConstants::sTiltAngle = 0.0f;
	const uint32_t MercuryConstants::sNumberOfVertices = 300;	

	const XMFLOAT3 VenusConstants::sOrbitRadius(144.6f, 0.0f, 0.0f);
	const XMFLOAT3 VenusConstants::sScale(0.949f, 0.949f, 0.949f);
	const wstring VenusConstants::sTexturePath = L"Content\\Textures\\Venus.jpg";
	const float VenusConstants::sRotationRate = 20.0f;
	const float VenusConstants::sRevolutionRate = 0.493f;
	const float VenusConstants::sTiltAngle = 177.4f;
	const uint32_t VenusConstants::sNumberOfVertices = 400;	

	const XMFLOAT3 EarthConstants::sOrbitRadius(200.0f, 0.0f, 0.0f);
	const XMFLOAT3 EarthConstants::sScale(1.0f, 1.0f, 1.0f);
	const wstring EarthConstants::sTexturePath = L"Content\\Textures\\Earth.jpg";
	const float EarthConstants::sRotationRate = 15.0f;
	const float EarthConstants::sRevolutionRate = 0.3f;
	const float EarthConstants::sTiltAngle = 23.27f;
	const uint32_t EarthConstants::sNumberOfVertices = 500;	

	const XMFLOAT3 MarsConstants::sOrbitRadius(304.8f, 0.0f, 0.0f);
	const XMFLOAT3 MarsConstants::sScale(0.532f, 0.532f, 0.532f);
	const wstring MarsConstants::sTexturePath = L"Content\\Textures\\Mars.jpg";
	const float MarsConstants::sRotationRate = 15.5f;
	const float MarsConstants::sRevolutionRate = 0.51f;
	const float MarsConstants::sTiltAngle = 25.11f;
	const uint32_t MarsConstants::sNumberOfVertices = 600;	

	const XMFLOAT3 JupiterConstants::sOrbitRadius(1040.6f, 0.0f, 0.0f);
	const XMFLOAT3 JupiterConstants::sScale(10.47f, 10.47f, 10.47f);
	const wstring JupiterConstants::sTexturePath = L"Content\\Textures\\Jupiter.jpg";
	const float JupiterConstants::sRotationRate = 15.0f;
	const float JupiterConstants::sRevolutionRate = 0.025f;
	const float JupiterConstants::sTiltAngle = 3.4f;
	const uint32_t JupiterConstants::sNumberOfVertices = 700;	

	const XMFLOAT3 SaturnConstants::sOrbitRadius(1916.4f, 0.0f, 0.0f);
	const XMFLOAT3 SaturnConstants::sScale(8.27f, 8.27f, 8.27f);
	const wstring SaturnConstants::sTexturePath = L"Content\\Textures\\Saturn.jpg";
	const float SaturnConstants::sRotationRate = 10.2f;
	const float SaturnConstants::sRevolutionRate = 0.010f;
	const float SaturnConstants::sTiltAngle = 27.0f;
	const uint32_t SaturnConstants::sNumberOfVertices = 800;	

	const XMFLOAT3 UranusConstants::sOrbitRadius(3840.0f, 0.0f, 0.0f);
	const XMFLOAT3 UranusConstants::sScale(4.01f, 4.01f, 4.01f);
	const wstring UranusConstants::sTexturePath = L"Content\\Textures\\Uranus.jpg";
	const float UranusConstants::sRotationRate = 10.0f;
	const float UranusConstants::sRevolutionRate = 0.00357f;
	const float UranusConstants::sTiltAngle = 97.9f;
	const uint32_t UranusConstants::sNumberOfVertices = 1000;	

	const XMFLOAT3 NeptuneConstants::sOrbitRadius(5010.0f, 0.0f, 0.0f);
	const XMFLOAT3 NeptuneConstants::sScale(3.88f, 3.88f, 3.88f);
	const wstring NeptuneConstants::sTexturePath = L"Content\\Textures\\Neptune.jpg";
	const float NeptuneConstants::sRotationRate = 8.8f;
	const float NeptuneConstants::sRevolutionRate = 0.0018f;
	const float NeptuneConstants::sTiltAngle = 29.6f;
	const uint32_t NeptuneConstants::sNumberOfVertices = 1100;	

	const XMFLOAT3 PlutoConstants::sOrbitRadius(7896.0f, 0.0f, 0.0f);
	const XMFLOAT3 PlutoConstants::sScale(3.18f, 3.18f, 3.18f);
	const wstring PlutoConstants::sTexturePath = L"Content\\Textures\\Pluto.jpg";
	const float PlutoConstants::sRotationRate = 4.5f;
	const float PlutoConstants::sRevolutionRate = 0.0012f;
	const float PlutoConstants::sTiltAngle = 122.0f;
	const uint32_t PlutoConstants::sNumberOfVertices = 1500;	
}