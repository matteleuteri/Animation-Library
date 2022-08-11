#include "headers/Animation.h"






Animation::Animation(HWND hwnd, RECT* rc, std::vector<std::string> fileNames, int64_t timeSince, int64_t timeFrame): 
            timeSince(timeSince), timeFrame(timeFrame), fileNames(fileNames)
{
    bitmaps = { };
    for(std::string& fname: fileNames) 
    {

    }
}
