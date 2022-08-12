#include "headers/GameObject.h"

GameObject::GameObject(AnimationController *animationController, float x, float y, float xSpeed): animationController(animationController), x(x), y(y), xSpeed(xSpeed)
{
    // animation = animationController->animations[0];
    // D2D1_SIZE_F size = animation->bitmaps[0]->GetSize();
    // width = size.width;
    // height = size.height;
    // ySpeed = 0;
}

void GameObject::animate(int32_t currentTime) 
{
    animationController->renderTarget->BeginDraw();
    animationController->renderTarget->Clear(D2D1::ColorF(D2D1::ColorF::Black));            
    


    //   initialize the bitmap the animation begins with
    // as well as the animation that could initially be played by the controller




    animationController->renderTarget->DrawBitmap(
                animationController->currentAnimation->bitmaps[
                animationController->currentAnimation->currentBitmapIndex], 
                D2D1::RectF(100, 100, 100, 100));
    
    animationController->renderTarget->EndDraw();




    // if(currentTime - animation->lastFlipTime >= animation->timeFrame)
    // {
    //     animation->currentFrame = (animation->currentFrame + 1) % animation->bitmaps.size();
    //     animation->lastFlipTime = currentTime;
    //     width = animation->bitmaps[animation->currentFrame]->GetSize().width;
    //     height = animation->bitmaps[animation->currentFrame]->GetSize().height;
    // }
}