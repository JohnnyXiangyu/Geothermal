#pragma once
#include "DeviceResources.h"
#include "CoreRenderPipeline.h"
#include "GameTimer.h"
#include "Input.h"
#include "Scene.h"

#define DEBUG_SCENE
#include "Mesh.h"
#include "ShadingAttributes.h"
#ifdef DEBUG_SCENE

#endif

using namespace Geothermal;
using namespace Geothermal::Graphics;

/// <summary>
/// Main gameplay loop
/// Singleton class that must be explicitly initialized once
/// </summary>
class GameMain
{
public:
	static GameMain* Instance();
	static void Initialize(std::shared_ptr<DeviceResources> deviceResources);

	WPARAM Run();
	void Update();
	void LateUpdate();
	void Close() { windowClosed = true; }

	float GetDeltaTime() const { return deltaTime; }
	float GetTime() const { return time; }
	Geothermal::Input* GetInput() const { return input.get(); }
private:
	UINT HandleMessage(MSG msg);
	GameMain(std::shared_ptr<DeviceResources> deviceResources);
	static GameMain* instance;

	bool windowClosed;
	std::unique_ptr<GameTimer> timer;
	float time;
	float deltaTime;
	std::unique_ptr<Geothermal::Input> input;
	std::shared_ptr<DeviceResources> deviceResources;
	std::unique_ptr<CoreRenderPipeline> coreRenderer;

#ifdef DEBUG_SCENE
	std::vector<std::shared_ptr<GameObject>> debugGameObjects;
	void InstantiateDebugScene();

	Meshes::Mesh* debugMesh;
	Graphics::Structures::PhongAttributes shadingParameters;
	void LoadDebugMesh();

	void AddDebugGameObject(XMMATRIX initialTransform);
#endif
};