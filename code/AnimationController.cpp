#include "headers/AnimationController.h"

HRESULT AnimationController::LoadBitmapFromFile(LPCWSTR uri, UINT destinationWidth, UINT destinationHeight, ID2D1Bitmap **ppBitmap)
{
    IWICBitmapDecoder *pDecoder = NULL;
    IWICBitmapFrameDecode *pSource = NULL;
    IWICFormatConverter *pConverter = NULL;

    HRESULT hr = pIWICFactory->CreateDecoderFromFilename(uri, NULL, GENERIC_READ, WICDecodeMetadataCacheOnLoad, &pDecoder);

    if(SUCCEEDED(hr))
    {
        hr = pDecoder->GetFrame(0, &pSource);
    }
    if(SUCCEEDED(hr))
    {
        hr = pIWICFactory->CreateFormatConverter(&pConverter);
    }
    if(SUCCEEDED(hr))
    {
        hr = pConverter->Initialize(pSource, GUID_WICPixelFormat32bppPBGRA, WICBitmapDitherTypeNone, NULL, 0.f, WICBitmapPaletteTypeMedianCut);
    }
    if(SUCCEEDED(hr))
    {
        hr = renderTarget->CreateBitmapFromWicBitmap(pConverter, ppBitmap);
    }
    return hr;
}
std::vector<ID2D1Bitmap*> AnimationController::loadBitmapVector(std::vector<std::string>& assetNames)
{
    std::vector<ID2D1Bitmap*> bitmapVector = {};
    for(auto& asset : assetNames)
    {
        p /= asset;
        ID2D1Bitmap *currBitmap;
        LoadBitmapFromFile(p.c_str(), 20, 20, &currBitmap);  
        p.remove_filename();
        bitmapVector.push_back(currBitmap);
    }
    return bitmapVector;
}

void AnimationController::createResources(HWND hwnd, RECT* rc)
{
    ID2D1Factory* pD2DFactory = nullptr;
    D2D1CreateFactory(D2D1_FACTORY_TYPE_SINGLE_THREADED, &pD2DFactory);
    D2D1_SIZE_U clientSize = D2D1::SizeU(rc->right - rc->left, rc->bottom - rc->top);
    pD2DFactory->CreateHwndRenderTarget(D2D1::RenderTargetProperties(), D2D1::HwndRenderTargetProperties(hwnd, clientSize), &renderTarget);
    CoInitializeEx(NULL, COINIT_MULTITHREADED); 
    CoCreateInstance(CLSID_WICImagingFactory, NULL, CLSCTX_INPROC_SERVER, IID_PPV_ARGS(&pIWICFactory));    
}

AnimationController::AnimationController(HWND hwnd, RECT* rc, std::filesystem::path p): p(p)
{
    createResources(hwnd, rc);
}

void AnimationController::loadAnimation(std::vector<std::string> strings, std::string name, DWORD creationTime, int timeFrame)
{
    std::vector<ID2D1Bitmap*> bitmapVector = loadBitmapVector(strings);
    // use the bitmap vector ot create an animation, then add it to the controller's animations component
    Animation* animation = new Animation(bitmapVector, creationTime, timeFrame);
    animationMap[name] = animation;
}