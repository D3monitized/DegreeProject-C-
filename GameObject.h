#pragma once

#include "List.h"

namespace Engine
{

	class GameObject {

	public:

		GameObject()
		{
		}
		~GameObject()
		{
		}

		static void Init()
		{
			m_allGameObjects = List<GameObject>();
		}

		static void Clear()
		{
			m_allGameObjects.~List(); 
		}

		virtual void Start()
		{
		}
		virtual void Update()
		{
		}		

	public:

		static List<GameObject> m_allGameObjects;
	};
}
