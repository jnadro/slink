#ifndef ShaderStrings_h
#define ShaderStrings_h

const char* VS = 
	"struct VS_INPUT {"
	"};"
	"struct VS_OUTPUT {"
	"};"
	"VS_OUTPUT Main(in VS_INPUT input)"
	"{"
	"	VS_OUTPUT output = (VS_OUTPUT)0;"
	"	return output;"
	"}";

const char* PS =
	"struct VS_OUTPUT {"
	"};"
	"float4 Main(in VS_OUTPUT input) : SV_Target"
	"{"
	"	return float4(1.0f, 0.0, 1.0f, 1.0f);"
	"}";

#endif
