#pragma once

#include <wrl.h>
#include <d3d11_2.h>
#include <DirectXMath.h>
#include <cstdint>
#include <memory>
#include "DrawableGameComponent.h"

namespace Library
{
	class Camera;
	class Mesh;
	class DirectionalLight;
}

namespace SolarSystem
{
	class CelestialObject : public Library::DrawableGameComponent
	{
		RTTI_DECLARATIONS(CelestialObject, Library::DrawableGameComponent)
	public:
		CelestialObject(Library::Game& game, const std::shared_ptr<Library::Camera>& camera, const std::wstring& texturePath, const DirectX::XMFLOAT3& orbitRadius, const DirectX::XMFLOAT3& scaleFactor, bool isAnimated, float rotationRate, float revolutionRate, float tiltAngle, bool shouldLit);

		CelestialObject(const CelestialObject&) = default;
		CelestialObject& operator=(const CelestialObject&) = default;
		CelestialObject(CelestialObject&&) = default;
		CelestialObject& operator=(CelestialObject&&) = default;
		virtual ~CelestialObject() = default;

		bool AnimationEnabled() const;
		void SetAnimationEnabled(bool enabled);
		void ToggleAnimation();

		const DirectX::XMFLOAT4X4& PositionMatrix() const;
		virtual void Initialize() override;
		virtual void Draw(const Library::GameTime& gameTime) override;

	private:
		struct VertexCBufferPerObject
		{
			DirectX::XMFLOAT4X4 WorldViewProjection;
			DirectX::XMFLOAT4X4 World;

			VertexCBufferPerObject() = default;
			VertexCBufferPerObject(const DirectX::XMFLOAT4X4& wvp, const DirectX::XMFLOAT4X4& world) : WorldViewProjection(wvp), World(world) { }
		};

		struct PixelCBufferPerFrame
		{
			DirectX::XMFLOAT3 LightDirection;
			float Padding;
			DirectX::XMFLOAT3 LightColor;
			float ShouldLit;

			PixelCBufferPerFrame() :
				LightDirection(0.0f, 0.0f, 1.0f), LightColor(DirectX::Colors::White) { }

			PixelCBufferPerFrame(const DirectX::XMFLOAT3& lightDirection, const DirectX::XMFLOAT3& lightColor) :
				LightDirection(lightDirection), LightColor(lightColor) { }
		};

		void CreateVertexBuffer(const Library::Mesh& mesh, ID3D11Buffer** vertexBuffer) const;

		Microsoft::WRL::ComPtr<ID3D11VertexShader> mVertexShader;
		Microsoft::WRL::ComPtr<ID3D11PixelShader> mPixelShader;
		Microsoft::WRL::ComPtr<ID3D11InputLayout> mInputLayout;
		Microsoft::WRL::ComPtr<ID3D11Buffer> mVertexBuffer;
		Microsoft::WRL::ComPtr<ID3D11Buffer> mIndexBuffer;
		Microsoft::WRL::ComPtr<ID3D11ShaderResourceView> mColorTexture;
		std::uint32_t mIndexCount;

	protected:
		virtual void UpdateDirectionalLight(const Library::GameTime& gameTime);

		VertexCBufferPerObject mVertexCBufferPerObjectData;
		PixelCBufferPerFrame mPixelCBufferPerFrameData;

		Microsoft::WRL::ComPtr<ID3D11Buffer> mVertexCBufferPerObject;
		Microsoft::WRL::ComPtr<ID3D11Buffer> mPixelCBufferPerFrame;

		std::unique_ptr<Library::DirectionalLight> mDirectionalLight;
		DirectX::XMFLOAT4X4 mPositionMatrix;
		DirectX::XMFLOAT4X4 mWorldMatrix;
		float mCurrentRotationAngle;
		float mCurrentRevolutionAngle;
		bool mAnimationEnabled;
		float mTiltAngle;
		float mRotationRate;
		float mRevolutionRate;
		std::wstring mTexturePath;
		DirectX::XMFLOAT3 mOrbitRadius;
		DirectX::XMFLOAT3 mObjectScale;
	};
}