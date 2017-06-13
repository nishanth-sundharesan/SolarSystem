#pragma once
#include "DrawableGameComponent.h"

namespace SolarSystem
{
	class Orbit final : public Library::DrawableGameComponent
	{
		RTTI_DECLARATIONS(Orbit, Library::DrawableGameComponent)
	public:
		Orbit(Library::Game& game, const std::shared_ptr<Library::Camera>& camera, std::uint32_t numberOfVertices,std::uint32_t radius);

		Orbit(const Orbit&) = delete;
		Orbit& operator=(const Orbit&) = delete;

		virtual void Initialize() override;
		virtual void Draw(const Library::GameTime& gameTime) override;

	private:
		struct VertexCBufferPerObject
		{
			DirectX::XMFLOAT4X4 WorldViewProjection;

			VertexCBufferPerObject() { }
			VertexCBufferPerObject(const DirectX::XMFLOAT4X4& wvp) : WorldViewProjection(wvp) { }
		};
		
		void InitializeOrbit();
		
		static const DirectX::XMFLOAT4 sDefaultColor;

		Microsoft::WRL::ComPtr<ID3D11VertexShader> mVertexShader;
		Microsoft::WRL::ComPtr<ID3D11PixelShader> mPixelShader;
		Microsoft::WRL::ComPtr<ID3D11InputLayout> mInputLayout;
		Microsoft::WRL::ComPtr<ID3D11Buffer> mVertexBuffer;
		Microsoft::WRL::ComPtr<ID3D11Buffer> mVertexCBufferPerObject;
		VertexCBufferPerObject mVertexCBufferPerObjectData;
				
		DirectX::XMFLOAT4X4 mWorldMatrix;
		std::uint32_t mNumberOfVertices;
		std::uint32_t mRadius;
	};
}