#ifndef UNICODE
#define UNICODE
#endif 

#include <windows.h>
#include <stdint.h>
#include <profileapi.h>
#include <filesystem>
#include <array>
#include <dwrite.h>


#include <d2d1.h>
#include <vector>
#include <memory>
#include <wincodec.h>
#include <combaseapi.h>
#include <Objbase.h>

#include "JsonParser.h"

static bool isRunning;
std::filesystem::path p;
ID2D1HwndRenderTarget* renderTarget;

IDWriteFactory *pDWriteFactory_;
IDWriteTextFormat *pTextFormat_;
