
/**
 *	Include Header
 */
#include "DemoActor.h"



ING_BEGIN_REFLECTED_CLASS	
	(DemoActor, C_Actor)

	ING_CLASS_CONSTRUCTOR	
		(DemoActor)
		.ACCESS	(CLASS_MEMBER_ACCESS_PROTECTED)
		.TAG	(CLASS_MEMBER_TAG_VISIBLE_EVERYWHERE);

ING_END_REFLECTED_CLASS		
	()

void DemoActor::Constructor() {

	C_Actor::Constructor("Demo");

}

void DemoActor::Release() {

	C_Actor::Release();

}