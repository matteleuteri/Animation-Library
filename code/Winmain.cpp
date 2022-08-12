#include "headers/Winmain.h"

LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
    LRESULT result = 0;
    // POINT pt;
    switch (uMsg)
    {
        case WM_CLOSE: 
        {
            isRunning = false;
            // if (MessageBox(hwnd, L"Really quit?", L"My application", MB_OKCANCEL) == IDOK) 
            DestroyWindow(hwnd);
            break;
        } 
        case WM_DESTROY:
        {
            isRunning = false;
            PostQuitMessage(0);
            break;
        }
        default: 
        {
            result = DefWindowProc(hwnd, uMsg, wParam, lParam);
        } 
    }
    return result;
}

int WINAPI wWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, PWSTR pCmdLine, int nCmdShow)
{
    const wchar_t CLASS_NAME[]  = L"Animation Library";
    
    WNDCLASS wc = { };
    wc.style = CS_HREDRAW | CS_VREDRAW | CS_OWNDC;
    wc.lpfnWndProc   = WindowProc;
    wc.cbClsExtra = 0;
    wc.cbWndExtra = 0;
    wc.hInstance = hInstance;
    wc.hIcon = 0;
    wc.hCursor = 0;
    wc.hbrBackground = 0;
    wc.lpszMenuName = 0;
    wc.lpszClassName = CLASS_NAME;

    if(RegisterClass(&wc))
    {
        HWND hwnd = CreateWindowEx(0, CLASS_NAME, L"Animation Library", 
                    WS_OVERLAPPEDWINDOW|WS_VISIBLE, CW_USEDEFAULT, CW_USEDEFAULT, 
                    CW_USEDEFAULT, CW_USEDEFAULT, 0, 0, hInstance, 0);
        if(hwnd) 
        {
            isRunning = true;
            RECT rc;
            GetClientRect(hwnd, &rc);

            std::filesystem::path p = std::filesystem::current_path().remove_filename();
            p /= "assets";


            AnimationController* animationController = new AnimationController(hwnd, &rc, p);
            animationController->loadAnimation({ "image1.png", "image2.png" }, "EXAMPLE1", GetTickCount(), 100);
            animationController->loadAnimation({ "image3.png", "image4.png" }, "EXAMPLE2", GetTickCount(), 100);
            
            
            
            animationController->animationMap["EXAMPLE1"]->currentBitmapIndex = 0;
            animationController->currentAnimation = animationController->animationMap["EXAMPLE1"];
            
            GameObject* go = new GameObject(animationController, 200.0f, 200.0f, 0.5f);
            // go->animation = animation1;


            // int32_t startTime = GetTickCount();
            // int32_t endTime;            
            while(isRunning)
            {
                MSG msg;
                while(PeekMessage(&msg, 0, 0, 0, PM_REMOVE))
                {
                    if(msg.message == WM_QUIT)
                    {
                        isRunning = false;
                        break;
                    }
                    TranslateMessage(&msg);
                    DispatchMessageA(&msg);
                }

                go->animate(GetTickCount());

                // endTime = GetTickCount();
                // scene->updateState(hwnd, endTime, startTime);
                // scene->renderState(hwnd, renderTarget, pTextFormat_);                    
                // startTime = endTime;
            }
        }
    }
    return 0;
}
