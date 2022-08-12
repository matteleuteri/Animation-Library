#include "headers/Animation.h"

Animation::Animation(std::vector<ID2D1Bitmap*> bitmaps, int64_t timeSince, int64_t timeFrame): 
            bitmaps(bitmaps), timeSince(timeSince), timeFrame(timeFrame)
{
    currentBitmapIndex = 0;
}
