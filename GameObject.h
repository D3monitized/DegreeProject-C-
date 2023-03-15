#pragma once
#include <iostream>
#include <set>

#include "SpriteRenderer.h"

namespace Engine {

	class GameObject { //Abstract class not to be used as is 		
	public:
		GameObject()
		{
			_transform = new Transform(); 
			_spriteRenderer = new SpriteRenderer();
			_instances.insert(this);
		}
		~GameObject()
		{
			delete _transform; 
			delete _spriteRenderer; 
			_instances.erase(this);
		}

		virtual void Start() = 0;
		virtual void Tick() = 0;
		virtual void Draw(sf::RenderWindow& window) = 0; 

		static const std::set<GameObject*>& GetInstances() { return _instances; }

	public: 
		SpriteRenderer* _spriteRenderer; 
		Transform* _transform; 

	private: 
		static std::set<GameObject*> _instances;

	};
}
