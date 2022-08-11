#ifndef _ANIMATION
#define _ANIMATION

#include <d2d1.h>
#include <vector>
#include <string>
#include <wincodec.h>
class Animation
{
public:
    std::vector<ID2D1Bitmap*> bitmaps;
    int currentBitmapIndex;
    int64_t timeSince;
    int64_t timeFrame;
    std::vector<std::string> fileNames;
    Animation::Animation(HWND hwnd, RECT* rc, std::vector<std::string> fileNames, int64_t timeSince, int64_t timeFrame);
};

#endif