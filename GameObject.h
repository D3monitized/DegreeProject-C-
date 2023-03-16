#pragma once
#include <iostream>
#include <set>

#include "Transform.h"
#include "SpriteRenderer.h"

namespace Engine {

	class GameObject { //Abstract class not to be used as is 		
	#define transform GetTransform()
	#define spriteRenderer GetSpriteRenderer()

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
		
		static const std::set<GameObject*>& GetInstances() { return _instances; }
				
		void Draw(sf::RenderWindow& window) //Not to be used in derived class
		{
			_spriteRenderer->UpdatePosition(_transform->_position);
	
			if (_spriteRenderer->GetScale() != _transform->_scale) 
				_spriteRenderer->SetScale(_transform->_scale); 
			
			window.draw(_spriteRenderer->GetSprite());
		}

	protected: 
		Transform& GetTransform() { return *_transform; }
		SpriteRenderer& GetSpriteRenderer() { return *_spriteRenderer; }

	private:
		SpriteRenderer* _spriteRenderer;
		Transform* _transform;

		static std::set<GameObject*> _instances;

	};
}
