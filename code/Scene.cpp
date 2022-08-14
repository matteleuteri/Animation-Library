#include "headers/Scene.h"

Scene::Scene(int32_t currentTime, bool active, std::vector<AnimationController*> animationControllers, float x, float y, RECT *rc) : isActive(active), x(x), y(y), rc(rc)
{
    lastTimestamp = GetTickCount();
}

void Scene::drawBM(ID2D1HwndRenderTarget* renderTarget, GameObject *g)
{
}

void Scene::updateState(HWND hwnd, int32_t endTime, int32_t startTime)
{
}

void Scene::renderState(HWND hwnd, ID2D1HwndRenderTarget* renderTarget, IDWriteTextFormat* pTextFormat_)
{
    renderTarget->BeginDraw();
    renderTarget->Clear(D2D1::ColorF(D2D1::ColorF::Black));

    renderTarget->EndDraw();  
}
