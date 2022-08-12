#ifndef _ANIMATIONCONTROLLER
#define _ANIMATIONCONTROLLER

#include <filesystem>
#include <map>

#include "Animation.h"

class AnimationController {
public:
    std::map<std::string, Animation*> animationMap;
    Animation* currentAnimation;
    AnimationController::AnimationController(ID2D1HwndRenderTarget* renderTarget, HWND hwnd, RECT* rc, std::filesystem::path p);
    virtual AnimationController::~AnimationController();
    void AnimationController::createResources(HWND hwnd, RECT* rc);
    void AnimationController::loadAnimation(IWICImagingFactory* pIWICFactory, std::vector<std::string> strings, std::string name, DWORD creationTime, int timeFrame);
    std::vector<ID2D1Bitmap*> AnimationController::loadBitmapVector(IWICImagingFactory* pIWICFactory, std::vector<std::string>& assetNames);
    HRESULT AnimationController::LoadBitmapFromFile(IWICImagingFactory* pIWICFactory, LPCWSTR uri, UINT destinationWidth, UINT destinationHeight, ID2D1Bitmap **ppBitmap);
    void AnimationController::animate(int32_t currentTime, float x, float y);
    void AnimationController::setAnimation(std::string animationName);
    ID2D1HwndRenderTarget* renderTarget;
    std::filesystem::path p;
};

#endif