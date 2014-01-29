#pragma once

#include <vector>
#include "ResourcePointers.h"

namespace Slink
{
	class Geometry 
	{
	public:
		Geometry();
		~Geometry();

		void createFromData(ID3D11DevicePtr device, const float* const verts, int numVerts);
		void setVertexShader(ID3DBlobPtr shader);
		void draw();

	private:
		// GPU Resources
		ID3D11BufferPtr indexBuffer;
		ID3D11BufferPtr vertexBuffer;
		ID3DBlobPtr vsBlob;
		ID3D11InputLayoutPtr inputLayout;

		bool created;
		int numVertices;
	};
}

