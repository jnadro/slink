#ifndef SlinkDirectX11Geometry_h
#define SlinkDirectX11Geometry_h

#include <vector>
#include "ResourcePointers.h"

namespace Slink
{
	class Geometry 
	{
	public:
		Geometry();
		~Geometry();

		// Raw Data
		std::vector<UINT> indices;
		std::vector<float> vertices;

	private:
		// GPU Resources
		ID3D11BufferPtr IndexBuffer;
		ID3D11BufferPtr VertexBuffer;
	};
}


#endif
