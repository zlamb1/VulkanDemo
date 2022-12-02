#pragma once

#include <vulkan/vulkan.h>

#include "window.h"

namespace Magma {

	class VulkanImpl : public WindowImpl {

	public:
		virtual VkResult getSurfaceKHR(VkInstance& vkInstance, VkSurfaceKHR& vkSurfaceKHR) = 0;

	};

}