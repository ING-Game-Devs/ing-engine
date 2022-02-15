#pragma once

/**
 *	Include Entry Point
 */
#include <ING/EntryPoint/EntryPoint.h>



/**
 *	Include Utils
 */
#include <ING/Utils/Utils.h>

using namespace ING::Utils;



/**
 *	Include Id
 */
#include <ING/ECS/Component/Id/Id.h>



namespace ING {

	namespace ECS {

		struct ING_API Component
		{

			/**
			 *	Constructors And Destructor
			 */
		public:
			Component();
			~Component();

		};

	}

}