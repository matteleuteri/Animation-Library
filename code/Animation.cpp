#include "headers/Animation.h"

Animation::Animation(std::vector<ID2D1Bitmap*> bitmaps, int64_t timeSince, int64_t timeFrame, int startFrame): 
            bitmaps(bitmaps), timeSince(timeSince), timeFrame(timeFrame), currentBitmapIndex(startFrame) {
    currentBitmapIndex = 0;
}
