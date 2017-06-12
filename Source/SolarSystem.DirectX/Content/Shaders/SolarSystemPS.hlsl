cbuffer CBufferPerFrame
{	
	float3 LightDirection;
	float3 LightColor;
	float ShouldLit;
}

Texture2D ColorTexture;
SamplerState ColorSampler;

struct VS_OUTPUT
{
	float4 Position: SV_Position;
	float2 TextureCoordinate : TEXCOORD;
	float3 Normal : NORMAL;
};

float4 main(VS_OUTPUT IN) : SV_TARGET
{
	float4 color = ColorTexture.Sample(ColorSampler, IN.TextureCoordinate);
	if (ShouldLit > 0.0f)
	{
		float normal_dot = dot(LightDirection, IN.Normal);
		float3 diffuse = (normal_dot > 0 ? color.rgb * normal_dot * LightColor : (float3)0);
		return float4(diffuse, color.a);		
	}
	else
	{
		return color;
	}		
}