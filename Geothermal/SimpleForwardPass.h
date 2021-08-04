#pragma once
#include <functional>
#include "GraphicResources.h"
#include "RenderPass.h"
#include "GameObject.h"
#include "Camera.h"

namespace Geothermal::Graphics::Passes
{
	class SimpleForwardPass : public RenderPass
	{
	public:
		SimpleForwardPass
		(
			std::shared_ptr<DeviceResources> const& deviceResources,
			std::vector<Texture2D*> const& source,
			std::vector<Texture2D*> const& sink
		);

		void AddResources
		(
			std::list<GameObject*> renderables,
			Camera* camera,
			std::function<void(void)> uploadShadowResources,
			std::function<void(void)> uploadLightingResources
		);

		void operator()() override;

	protected:
		std::list<GameObject*> renderables;
		Camera* camera;
		std::function<void(void)> uploadShadowResources;
		std::function<void(void)> uploadLightingResources;
	};
}
