// TO-DO: State machine dopiescic
#include "Sandbox.hpp"

namespace sb{
    Sandbox::Sandbox()
        : mLogo(), mResourceManager(), mAnimationManager(renderer), mInputManager(renderer.GetRenderWindow()), mScenesManager()
    {
        Init();
        StartUpdateLoop();
    }

    Sandbox::~Sandbox(){

    }

    void Sandbox::Start(){
        mResourceManager.LoadTexture("farfocel_background", "res/farfocel_background.png");
        mBackground.setTexture(*mResourceManager.GetTexture("farfocel_background"));
        mResourceManager.LoadTextureAtlas("logo", "res/logo.png", { 1,5 });
        mAnimationManager.AddTextureAtlas("logoTex", *mResourceManager.GetTextureAtlas("logo"));
        mAnimationManager.Add("logo", mLogo, "logoTex", 1, 5, 10, true);

        mScenesManager.Add(new Scene("scene", renderer, mScenesManager));

    }

    void Sandbox::HandleEvents(){
        
    }

    void Sandbox::HandleInput(){

    }

    void Sandbox::Update(){
        mAnimationManager.Update();
        mScenesManager.Update();
        mInputManager.UpdateMouse();
        
    }

    void Sandbox::Render(){


        renderer.GetRenderWindow().draw(mBackground);
        renderer.GetRenderWindow().draw(mLogo);
    
        mScenesManager.Render();
        
    }
}