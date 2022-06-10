#pragma once

#include "../EntryPoint/EntryPoint.h"
#include <ING/Utils/Utils.h>



/**
 *	Declare Classes
 */
namespace ING {

	class Engine;
	class IPlugin;

}



/**
 *	Plugin Info
 */
DECLARE_PLUGIN(DEMO_PLUGIN);



/**
 *	Plugin Events
 */
DECLARE_PLUGIN_FUNCTION(DEMO_PLUGIN, bool, Load)			(ING::Engine* engine, ING::IPlugin * plugin);
DECLARE_PLUGIN_FUNCTION(DEMO_PLUGIN, bool, Unload)		();

DECLARE_PLUGIN_FUNCTION(DEMO_PLUGIN, bool, LateCreate)	();

DECLARE_PLUGIN_FUNCTION(DEMO_PLUGIN, bool, PreInit)		();
DECLARE_PLUGIN_FUNCTION(DEMO_PLUGIN, bool, LateInit)		();

DECLARE_PLUGIN_FUNCTION(DEMO_PLUGIN, bool, PreRun)		();

DECLARE_PLUGIN_FUNCTION(DEMO_PLUGIN, bool, PreRelease)	();