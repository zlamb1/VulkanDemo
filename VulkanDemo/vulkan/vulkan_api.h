#pragma once

#include <vector>
#include <map>

#include <GLFW/glfw3.h>

#include <vulkan/vulkan.h>

#include "vk_logger.h"
#include "vk_debug_wrapper.h"
#include "vk_device_wrapper.h"
#include "vk_surface_wrapper.h"
#include "vk_validation_wrapper.h"
#include "vk_swapchain.h"
#include "vk_pipeline.h"
#include "vk_cmd_wrapper.h"
#include "vk_sync_wrapper.h"
#include "vk_deque.h"
#include "vk_buffer.h"

#include "vk_vertex_state.h"

/*
* Naming Conventions =>
* vk = Vulkan class
* _vk prefix = Vulkan wrapper class (classes in this API)
* camelCase
*/

class VulkanAPI {

public:
	VulkanAPI(GLFWwindow& _window);
	~VulkanAPI();

	void initSetup();
	void initRender();
	void onNewFrame(uint32_t vertexCount);
	
	_VkShader* createShaderHandle(const char* code, _ShaderType);
	_VkShader* createShaderHandle(_VkShaderInfo info);
	_VkBuffer* createBufferHandle(uint32_t pSize);

	void addVertexInputState(_VkVertexState& _vkVertexState);

	void setFramebufferResized(bool framebufferResized);
	void addShaderHandle(_VkShader* _vkShaderHandle);
	void addBufferHandle(_VkBuffer* _vkBufferHandle);

private:
	const int MAX_FRAMES_IN_FLIGHT = 2;
	uint32_t currentFrame = 0;
	bool framebufferResized = false;

	GLFWwindow& glfwWindow;
	VkInstance vkInstance{};

	VulkanDeque deque{};

	_VkValidation _vkValidation{};
	VkDebugWrapper* _vkDebugWrapper = nullptr;
	_VkLogger& _vkLogger;

	_VkSurface* _vkSurface = nullptr;

	_VkDevice* _vkDevice = nullptr;
	_VkSwapchain* _vkSwapchain = nullptr;
	_VkPipeline* _vkPipeline{};
		
	std::vector<_VkCmdPool*> _vkCmdPools{};
	std::vector<_VkCmdBuffer*> _vkCmdBuffers{};
	std::vector<_VkRenderSync*> _vkRenderSyncs{};

	void initInstance();

	void initCmd();
	void initSync();

	void recreateSwapchain();

	std::vector<const char*> getRequiredExtensions();

};