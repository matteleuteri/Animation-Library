#include "headers/AnimationController.h"

AnimationController::AnimationController(ID2D1HwndRenderTarget* renderTarget, HWND hwnd, RECT* rc, std::filesystem::path p): renderTarget(renderTarget), p(p)
{}

HRESULT AnimationController::LoadBitmapFromFile(IWICImagingFactory* pIWICFactory, LPCWSTR uri, UINT destinationWidth, UINT destinationHeight, ID2D1Bitmap **ppBitmap) {
    IWICBitmapDecoder *pDecoder = NULL;
    IWICBitmapFrameDecode *pSource = NULL;
    IWICFormatConverter *pConverter = NULL;

    HRESULT hr = pIWICFactory->CreateDecoderFromFilename(uri, NULL, GENERIC_READ, WICDecodeMetadataCacheOnLoad, &pDecoder);

    if(SUCCEEDED(hr)) {
        hr = pDecoder->GetFrame(0, &pSource);
    }
    if(SUCCEEDED(hr)) {
        hr = pIWICFactory->CreateFormatConverter(&pConverter);
    }
    if(SUCCEEDED(hr)) {
        hr = pConverter->Initialize(pSource, GUID_WICPixelFormat32bppPBGRA, WICBitmapDitherTypeNone, NULL, 0.f, WICBitmapPaletteTypeMedianCut);
    }
    if(SUCCEEDED(hr)) {
        hr = renderTarget->CreateBitmapFromWicBitmap(pConverter, ppBitmap);
    }
    return hr;
}

std::vector<ID2D1Bitmap*> AnimationController::loadBitmapVector(IWICImagingFactory* pIWICFactory, std::vector<std::string>& assetNames) {
    std::vector<ID2D1Bitmap*> bitmapVector = {};
    for(auto& asset : assetNames) {
        p /= asset;
        ID2D1Bitmap *currBitmap;
        LoadBitmapFromFile(pIWICFactory, p.c_str(), 20, 20, &currBitmap);  
        p.remove_filename();
        bitmapVector.push_back(currBitmap);
    }
    return bitmapVector;
}

void AnimationController::loadAnimation(IWICImagingFactory* pIWICFactory, std::vector<std::string> strings, std::string name, DWORD creationTime, int timeFrame) {
    std::vector<ID2D1Bitmap*> bitmapVector = loadBitmapVector(pIWICFactory, strings);
    // use the bitmap vector ot create an animation, then add it to the controller's animations component
    Animation* animation = new Animation(bitmapVector, creationTime, timeFrame, 0);
    animationMap[name] = animation;
}

void AnimationController::animate(int32_t currentTime, float x, float y) {
    renderTarget->DrawBitmap(
                currentAnimation->bitmaps[
                currentAnimation->currentBitmapIndex], 
                D2D1::RectF(x, y, x+100, y+100));
    
    if(currentTime - currentAnimation->timeSince >= currentAnimation->timeFrame) {
        currentAnimation->currentBitmapIndex = (currentAnimation->currentBitmapIndex + 1) % currentAnimation->bitmaps.size();
        currentAnimation->timeSince = currentTime;
    }
}

void AnimationController::setAnimation(std::string animationName) {
    currentAnimation = animationMap[animationName];
}
AnimationController::~AnimationController(){}