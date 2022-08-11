#ifndef _SCENE
#define _SCENE

#define PI 3.141592653589793238463f

#include <windows.h>
#include <stdint.h>
#include <d2d1.h>
#include <vector>
#include <memory>
#include <wincodec.h>
#include <combaseapi.h>
#include <Objbase.h>
#include <map>

#include "AnimationController.h"
#include "GameObject.h"

class Scene
{
public:
    bool isActive;
    float x;
    float y;
    float width;
    float height;
    float xSpeed;
    RECT *rc;
    int32_t lastTimestamp;
    Scene::Scene(int32_t currentTime, bool active, std::vector<AnimationController*> animationControllers, float x, float y, RECT *rc);
    void Scene::renderState(HWND hwnd, ID2D1HwndRenderTarget* renderTarget, IDWriteTextFormat* pTextFormat_);
    void Scene::updateState(HWND hwnd, int32_t startTime, int32_t endTime); 
};

#endif