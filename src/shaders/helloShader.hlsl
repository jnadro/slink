struct VS_INPUT {
};

struct VS_OUTPUT {
};

VS_OUTPUT VS(in VS_INPUT input)
{
	VS_OUTPUT output = (VS_OUTPUT)0;

	return output;
}


float4 PS(in VS_OUTPUT input) : SV_Target
{
	return float4(1.0f, 0.0, 1.0f, 1.0f);
}
