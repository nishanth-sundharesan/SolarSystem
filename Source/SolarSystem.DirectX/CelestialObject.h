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
}

namespace SolarSystem
{
	class CelestialObject : public Library::DrawableGameComponent
	{
	public:
		CelestialObject(Library::Game& game, const std::shared_ptr<Library::Camera>& camera, const std::wstring& texturePath, DirectX::XMFLOAT3 orbitRadius, DirectX::XMFLOAT3 scaleFactor, bool isAnimated, float rotationRate, float revolutionRate);

		CelestialObject(const CelestialObject&) = default;
		CelestialObject& operator=(const CelestialObject&) = default;
		CelestialObject(CelestialObject&&) = default;
		CelestialObject& operator=(CelestialObject&&) = default;
		virtual ~CelestialObject() = default;

		bool AnimationEnabled() const;
		void SetAnimationEnabled(bool enabled);

		DirectX::XMMATRIX PositionMatrix() const;
		virtual void Initialize() override;
		virtual void Update(const Library::GameTime& gameTime) override;
		virtual void Draw(const Library::GameTime& gameTime) override;

	private:		
		struct CBufferPerObject
		{
			DirectX::XMFLOAT4X4 WorldViewProjection;

			CBufferPerObject() = default;
			CBufferPerObject(const DirectX::XMFLOAT4X4& wvp) : WorldViewProjection(wvp) { }
		};

		void CreateVertexBuffer(const Library::Mesh& mesh, ID3D11Buffer** vertexBuffer) const;

		DirectX::XMMATRIX mPositionMatrix;
		CBufferPerObject mCBufferPerObject;
		Microsoft::WRL::ComPtr<ID3D11VertexShader> mVertexShader;
		Microsoft::WRL::ComPtr<ID3D11PixelShader> mPixelShader;
		Microsoft::WRL::ComPtr<ID3D11InputLayout> mInputLayout;
		Microsoft::WRL::ComPtr<ID3D11Buffer> mVertexBuffer;
		Microsoft::WRL::ComPtr<ID3D11Buffer> mIndexBuffer;
		Microsoft::WRL::ComPtr<ID3D11Buffer> mConstantBuffer;
		Microsoft::WRL::ComPtr<ID3D11ShaderResourceView> mColorTexture;
		std::uint32_t mIndexCount;

	protected:
		DirectX::XMFLOAT4X4 mWorldMatrix;
		float mCurrentRotationAngle;
		float mCurrentRevolutionAngle;
		bool mAnimationEnabled;
		float mRotationRate;
		float mRevolutionRate;
		std::wstring mTexturePath;
		DirectX::XMFLOAT3 mOrbitRadius;
		DirectX::XMFLOAT3 mObjectScale;
	};
}