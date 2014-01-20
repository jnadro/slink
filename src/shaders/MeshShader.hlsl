cbuffer VertexConstantBuffer : register( b0 )
{
    matrix World;
    matrix View;
    matrix Projection;
    float3 EyePosition;
}

cbuffer LightConstantBuffer : register( b1 )
{
	float3 LightPosition;
	float4 LightColor;
}

struct VS_OUTPUT
{
    float4 Pos : SV_POSITION;
    float4 Color : COLOR0;
    float3 Normal : NORMAL;
    float3 WorldPos : POSITION1;
};

//--------------------------------------------------------------------------------------
// Vertex Shader
//--------------------------------------------------------------------------------------
VS_OUTPUT VS( float4 Pos : POSITION, float4 Color : COLOR, float3 Normal : NORMAL )
{
    VS_OUTPUT output = (VS_OUTPUT)0;
    
    output.Pos = mul(Pos, World);
    output.WorldPos = output.Pos.xyz;
    output.Pos = mul(output.Pos, View);
    output.Pos = mul(output.Pos, Projection);
    output.Normal = Normal;
    output.Color = Color;

    return output;
}

//--------------------------------------------------------------------------------------
// Pixel Shader
//--------------------------------------------------------------------------------------
float4 PS( VS_OUTPUT input ) : SV_Target
{
	input.Normal = normalize(input.Normal);
	
	float3 LightVec = normalize(LightPosition - input.WorldPos);
	float3 EyeVec	= normalize(EyePosition - input.WorldPos);
	
    return input.Color;
}
