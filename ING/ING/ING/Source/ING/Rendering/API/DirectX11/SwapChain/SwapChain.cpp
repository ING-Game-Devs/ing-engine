
/**
 *	Include Header
 */
#include "SwapChain.h"



/**
 *	Include API Manager
 */
#include <ING/Rendering/API/Manager/Manager.h>



/**
 *	Include Rendering Device
 */
#include <ING/Rendering/API/Device/Device.h>



/**
 *	Include DirectX11 Rendering Device
 */
#include <ING/Rendering/API/DirectX11/Device/Device.h>



namespace ING {

	namespace Rendering {

		namespace DirectX11 {

			/**
			 *	Constructors And Destructor
			 */
			SwapChain::SwapChain(Rendering::Device* device) :
				Rendering::SwapChain(device)
			{

				IDXGIFactory* dxgiFactory = ((DirectX11::Device*)device)->GetDXGIFactory();

				//dxgiFactory->CreateSwapChain();

			}

			SwapChain::~SwapChain() {



			}



			/**
			 *	Release Methods
			 */
			void SwapChain::Release() {

				Rendering::SwapChain::Release();

			}

		}

	}

}