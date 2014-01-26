#ifndef ShaderStrings_h
#define ShaderStrings_h

const char* VS = 
	"float4 Main(in float3 position : POSITION) : SV_Position"
	"{"
	"	return float4(position.xyz, 1.0f);"
	"}";

const char* PS =
	"struct VS_OUTPUT {"
	"};"
	"float4 Main(in VS_OUTPUT input) : SV_Target"
	"{"
	"	return float4(1.0f, 0.0, 1.0f, 1.0f);"
	"}";

#endif
