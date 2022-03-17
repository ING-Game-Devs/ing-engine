
/**
 * Include Header
 */
#include "Pipeline.h"



/**
 *	Include Camera
 */
#include <ING/Camera/Camera.h>



/**
 *	Include Renderer
 */
#include <ING/Rendering/Renderer/Renderer.h>



/**
 *	Include Rendering API
 */
#include <ING/Rendering/API/API.h>



/**
 *	Include Rendering Device Context
 */
#include <ING/Rendering/API/Device/Context/Context.h>



/**
 *	Include Rendering Device
 */
#include <ING/Rendering/API/Device/Device.h>



/**
 *	Include Rendering Pass
 */
#include <ING/Rendering/Pass/Pass.h>



/**
 *	Include StandardRP First Pass
 */
#include <ING/Rendering/StandardRP/Pass/First/First.h>



/**
 *	Include StandardRP Final Pass
 */
#include <ING/Rendering/StandardRP/Pass/Final/Final.h>



/**
 *	Include Rendering System
 */
#include <ING/Rendering/System/System.h>




namespace ING {

	namespace Rendering {

		namespace StandardRP {

			/**
			 *	Constructors And Destructor
			 */
			Pipeline::Pipeline(std::string name) : IPipeline(name) {

				/**
				 *	Create Default Passes
				 */
				targetFirstPass	= new FirstPass	("Standard Main Pass");
				firstPass		= targetFirstPass;
				 
				targetFinalPass = new FinalPass	("Standard Final Pass");
				finalPass		= targetFinalPass;



				/**
				 *	Create SubRPs
				 */
				AddSubPipeline(new SubRP::Pipeline("After First Pipeline"), 0);

				AddSubPipeline(new SubRP::Pipeline("Befrore Final Pipeline"), 0);

			}

			Pipeline::~Pipeline() {



			}



			/**
			 *	Release Methods
			 */
			void Pipeline::Release() {

				IPipeline::Release();

			}



			/**
			 *	Properties
			 */
			void Pipeline::SetFirstPass	(IPass* firstPass) {

				/* New First Pass Will Be Used In Next Frame */
				targetFirstPass = firstPass;

			}

			void Pipeline::SetFinalPass	(IPass* finalPass) {

				/* New Main Pass Will Be Used In Next Frame */
				targetFinalPass = finalPass;

			}




			/**
			 *	Methods
			 */
			bool Pipeline::Render(IDeviceContext* context) {

				IPipeline::BeginRender(context);

				for (Camera* camera : CameraManager::GetInstance()->GetCameraList()) {

					/* Draw First Pass */
					firstPass = targetFirstPass;

					FirstPassInput	firstPassInput;
					FirstPassOutput	firstPassOutput;

					RENDERING_ASSERTION(firstPass->Render(context, camera, &firstPassInput, &firstPassOutput));



					SubRP::PassInput	subPipelinesInput;
					SubRP::PassOutput	subPipelinesOutput;

					RENDERING_ASSERTION(RenderSubPipelines(context, camera, subPipelinesInput, subPipelinesOutput));



					/* Get Final Pass */
					finalPass = targetFinalPass;

					FinalPassInput	finalPassInput;
					FinalPassOutput	finalPassOutput;

					RENDERING_ASSERTION(finalPass->Render(context, camera, &finalPassInput, &finalPassOutput));

				}

				IPipeline::EndRender(context);

				return true;

			}

			bool Pipeline::RenderSubPipelines(IDeviceContext* context, Camera* camera, const Rendering::SubRP::PassInput& input, Rendering::SubRP::PassOutput& output) {

				unsigned int subPipelineVectorSize = subPipelineVector.size();

				SubRP::PassInput renderRS = input;

				for (unsigned int i = 0; i < subPipelineVectorSize; ++i) {

					SubRP::Pipeline* pipeline = subPipelineVector[i];

					SubRP::PassOutput passOutput;

					RENDERING_ASSERTION(pipeline->SubRender(context, camera, renderRS, passOutput));

					renderRS = passOutput;

				}

				output = renderRS;

				return true;
			}

			void Pipeline::AddSubPipeline	(SubRP::Pipeline* subPipeline) {

				unsigned int index = subPipelineVector.size();

				subPipelineVector.resize(index + 1);

				subPipelineVector[index] = subPipeline;

				subPipelineName2supPipeLineIndex[subPipeline->GetName()] = index;

			}

			void Pipeline::AddSubPipeline	(SubRP::Pipeline* subPipeline, unsigned int index) {

				unsigned int subPipelineVectorSize = subPipelineVector.size();

				subPipelineVector.resize(subPipelineVectorSize + 1);

				for (unsigned int i = index + 1; i < subPipelineVector.size(); ++i) {

					subPipelineVector[i] = subPipelineVector[i - 1];

					subPipelineName2supPipeLineIndex[subPipelineVector[i]->GetName()] = i;

				}

				subPipelineVector[index] = subPipeline;

				subPipelineName2supPipeLineIndex[subPipeline->GetName()] = index;

			}

		}

	}

}