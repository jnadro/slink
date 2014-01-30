#pragma once

#include <comdef.h>
#include <d3d11.h>

namespace Slink
{
	_COM_SMARTPTR_TYPEDEF(IDXGISwapChain, __uuidof(IDXGISwapChain));
	_COM_SMARTPTR_TYPEDEF(ID3D11Device, __uuidof(ID3D11Device));
	_COM_SMARTPTR_TYPEDEF(ID3D11DeviceContext, __uuidof(ID3D11DeviceContext));
	_COM_SMARTPTR_TYPEDEF(ID3D11Debug, __uuidof(ID3D11Debug));
	
	_COM_SMARTPTR_TYPEDEF(ID3D11Texture2D, __uuidof(ID3D11Texture2D));

	_COM_SMARTPTR_TYPEDEF(ID3D11RenderTargetView, __uuidof(ID3D11RenderTargetView));

	_COM_SMARTPTR_TYPEDEF(ID3D11VertexShader, __uuidof(ID3D11VertexShader));
	_COM_SMARTPTR_TYPEDEF(ID3D11PixelShader, __uuidof(ID3D11PixelShader));

	_COM_SMARTPTR_TYPEDEF(ID3D11Buffer, __uuidof(ID3D11Buffer));

	_COM_SMARTPTR_TYPEDEF(ID3D11InputLayout, __uuidof(ID3D11InputLayout));
	_COM_SMARTPTR_TYPEDEF(ID3DBlob, __uuidof(ID3DBlob));
}

