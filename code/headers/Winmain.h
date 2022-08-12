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

#include <combaseapi.h>
#include <Objbase.h>
#include "GameObject.h"

static bool isRunning;
GameObject* go;