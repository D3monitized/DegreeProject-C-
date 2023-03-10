#pragma once

#include "List.h"

namespace Engine 
{
	class GameObject {

	public:

		GameObject();

	public:

		virtual void Awake();
		virtual void Start();
		virtual void Update();

	public:

		static List<GameObject> m_allGameObjects;
		GameObject* m_thisObject;

	};
}
