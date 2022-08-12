#ifndef _ANIMATIONCONTROLLER
#define _ANIMATIONCONTROLLER

#include <filesystem>
#include <map>

#include "Animation.h"

class AnimationController
{
public:
    std::map<std::string, Animation*> animationMap;
    Animation* currentAnimation;
    AnimationController::AnimationController(HWND hwnd, RECT* rc, std::filesystem::path p);
    virtual AnimationController::~AnimationController();
    void AnimationController::createResources(HWND hwnd, RECT* rc);
    void AnimationController::loadAnimation(std::vector<std::string> strings, std::string name, DWORD creationTime, int timeFrame);
    std::vector<ID2D1Bitmap*> AnimationController::loadBitmapVector(std::vector<std::string>& assetNames);
    HRESULT AnimationController::LoadBitmapFromFile(LPCWSTR uri, UINT destinationWidth, UINT destinationHeight, ID2D1Bitmap **ppBitmap);
    void AnimationController::animate(int32_t currentTime);
    void AnimationController::setAnimation(std::string animationName);
    IWICImagingFactory* pIWICFactory;
    ID2D1HwndRenderTarget* renderTarget;
    std::filesystem::path p;
};

#endif