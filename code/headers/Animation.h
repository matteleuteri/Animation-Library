#ifndef _ANIMATION
#define _ANIMATION

#include <d2d1.h>
#include <vector>
#include <string>
#include <wincodec.h>

class Animation {
public:
    std::vector<ID2D1Bitmap*> bitmaps;
    int currentBitmapIndex;
    int64_t timeSince;
    int64_t timeFrame;
    Animation::Animation(std::vector<ID2D1Bitmap*> bitmaps, int64_t timeSince, int64_t timeFrame, int startFrame);
};

#endif