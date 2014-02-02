#pragma once

#include <vector>
#include <memory>

namespace Slink
{
	class Object;
	typedef std::shared_ptr<Object> ObjectPtr;

	class Scene
	{
	public:
		Scene();
		~Scene();

		void add(ObjectPtr);
		void remove();

	private:
		std::vector<ObjectPtr> objects;
	};
}