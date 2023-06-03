#include "Vifon.hpp"

vi::Vifon::Vifon()
    : mResourceManager(), mInputManager(window.GetSFMLWindow()), mContainer("container"), mStyle("style"), mText("text"), mText2("text"), mText3("text"), mButton("button")
{
    Init();
    StartUpdateLoop();

    SetDevMode(true);
}

vi::Vifon::~Vifon() {

}

void vi::Vifon::Start() {
    fr::Console::GetTimestamp();

    mResourceManager.LoadFont("font", "res/fonts/font.ttf");

    mStyle.fText = &mResourceManager.GetFont("font");

    // yeah this whole thing will be handled by the manager

    mText.SetStyle(mStyle);
    mText.SetString("TextONE");
    mText.SetCharacterSize(30.f);
    mText.SetOutlineSize(2.f);
    mText.SetOrigin(frg::WidgetOrigin::TOP_LEFT);
    mText.SetPosition({1280.f/2.f,720.f/2.f});

    mText2.SetStyle(mStyle);
    mText2.SetString("TextTWOTWO");
    mText2.SetCharacterSize(30.f);
    mText2.SetOutlineSize(2.f);
    mText2.SetOrigin(frg::WidgetOrigin::TOP_LEFT);
    mText2.SetPosition({1280.f/2.f,720.f/2.f});

    mText3.SetStyle(mStyle);
    mText3.SetString("TextTHREETHREETHREE");
    mText3.SetCharacterSize(30.f);
    mText3.SetOutlineSize(2.f);
    mText3.SetOrigin(frg::WidgetOrigin::TOP_LEFT);
    mText3.SetPosition({1280.f/2.f,720.f/2.f});

    mButton.SetStyle(mStyle);
    mButton.SetTextString("CLOSE");
    mButton.SetTextSize({30.f,50.f,50.f});

    mButton.SetOrigin(frg::WidgetOrigin::CENTER_MIDDLE);
    mButton.SetPosition({1280.f/2.f,720.f/2.f});

    mButton.SetCallback([&](){window.GetSFMLWindow().close();});

    mContainer.BreakRow();
    mContainer.AddWidget(mText3);
    mContainer.AddWidget(mText2);
    mContainer.AddWidget(mButton);
    mContainer.BreakRow();
    mContainer.AddWidget(mText);

    mContainer.SetPosition({1280.f/2.f,720.f/2.f});
    mContainer.SetPosition(frg::ContainerAlignment::TOP_LEFT);
    mContainer.SetOrigin(frg::ContainerAlignment::TOP_LEFT);
    mContainer.SetVerticalAlignment(frg::WidgetAlignment::HALF);
    mContainer.SetHorizontalAlignment(frg::WidgetAlignment::HALF);

    mContainer.SetMargins({20.f,20.f});

    fr::EventManager::AddEventFunction([&](){if(mButton.GetGlobalRect().contains(mInputManager.GetMouseRelativeCoords())){
            mButton.SetState(frg::ButtonState::BUTTON_HOVERED);
            mContainer.Update(window.GetViewSize());
            if(mInputManager.IsPressed(sf::Mouse::Left)){
                mButton.SetState(frg::ButtonState::BUTTON_PRESSED);
                mContainer.Update(window.GetViewSize());
            }
            else if(fr::EventManager::IsActive(sf::Event::MouseButtonReleased) && window.GetEvent().mouseButton.button == sf::Mouse::Left) {
                mButton.Exec();
            }
        }
        else{
            mButton.SetState(frg::ButtonState::BUTTON_NEUTRAL);
            mContainer.Update(window.GetViewSize());
        };});
}

void vi::Vifon::HandleEvents() {

}

void vi::Vifon::HandleInput() {

}

void vi::Vifon::Update() {

    // idc
    const char* containerAlignment[] = { "TOP LEFT", "TOP MIDDLE", "TOP RIGHT", "CENTER LEFT", "CENTER MIDDLE", "CENTER RIGHT", "BOTTOM LEFT", "BOTTOM MIDDLE", "BOTTOM RIGHT"};
    const char* widgetAlignment[] = { "MIN", "HALF", "MAX"};


    ImGui::Begin("GUI Controls");

    ImGui::Text("Container Dynamic Position: ");

    static const char* currentDynamicPos = "TOP LEFT";
    if (ImGui::BeginCombo("  ", currentDynamicPos))
    {
        for (int n = 0; n < IM_ARRAYSIZE(containerAlignment); n++)
        {
            bool is_selected = (currentDynamicPos == containerAlignment[n]);
            if (ImGui::Selectable(containerAlignment[n], is_selected))
                currentDynamicPos = containerAlignment[n];
                if(currentDynamicPos == "TOP LEFT")
                    mContainer.SetPosition(frg::ContainerAlignment::TOP_LEFT);
                if(currentDynamicPos == "TOP MIDDLE")
                    mContainer.SetPosition(frg::ContainerAlignment::TOP_MIDDLE);
                if(currentDynamicPos == "TOP RIGHT")
                    mContainer.SetPosition(frg::ContainerAlignment::TOP_RIGHT);
                if(currentDynamicPos == "CENTER LEFT")
                    mContainer.SetPosition(frg::ContainerAlignment::CENTER_LEFT);
                if(currentDynamicPos == "CENTER MIDDLE")
                    mContainer.SetPosition(frg::ContainerAlignment::CENTER_MIDDLE);
                if(currentDynamicPos == "CENTER RIGHT")
                    mContainer.SetPosition(frg::ContainerAlignment::CENTER_RIGHT);
                if(currentDynamicPos == "BOTTOM LEFT")
                    mContainer.SetPosition(frg::ContainerAlignment::BOTTOM_LEFT);
                if(currentDynamicPos == "BOTTOM MIDDLE")
                    mContainer.SetPosition(frg::ContainerAlignment::BOTTOM_MIDDLE);
                if(currentDynamicPos == "BOTTOM RIGHT")
                    mContainer.SetPosition(frg::ContainerAlignment::BOTTOM_RIGHT);
        }
        ImGui::EndCombo();
    }

    ImGui::Text("Container Origin: ");

    static const char* currentContainerOrigin = "TOP LEFT";
    if (ImGui::BeginCombo(" ", currentContainerOrigin))
    {
        for (int n = 0; n < IM_ARRAYSIZE(containerAlignment); n++)
        {
            bool is_selected = (currentContainerOrigin == containerAlignment[n]);
            if (ImGui::Selectable(containerAlignment[n], is_selected))
                currentContainerOrigin = containerAlignment[n];
                if(currentContainerOrigin == "TOP LEFT")
                    mContainer.SetOrigin(frg::ContainerAlignment::TOP_LEFT);
                if(currentContainerOrigin == "TOP MIDDLE")
                    mContainer.SetOrigin(frg::ContainerAlignment::TOP_MIDDLE);
                if(currentContainerOrigin == "TOP RIGHT")
                    mContainer.SetOrigin(frg::ContainerAlignment::TOP_RIGHT);
                if(currentContainerOrigin == "CENTER LEFT")
                    mContainer.SetOrigin(frg::ContainerAlignment::CENTER_LEFT);
                if(currentContainerOrigin == "CENTER MIDDLE")
                    mContainer.SetOrigin(frg::ContainerAlignment::CENTER_MIDDLE);
                if(currentContainerOrigin == "CENTER RIGHT")
                    mContainer.SetOrigin(frg::ContainerAlignment::CENTER_RIGHT);
                if(currentContainerOrigin == "BOTTOM LEFT")
                    mContainer.SetOrigin(frg::ContainerAlignment::BOTTOM_LEFT);
                if(currentContainerOrigin == "BOTTOM MIDDLE")
                    mContainer.SetOrigin(frg::ContainerAlignment::BOTTOM_MIDDLE);
                if(currentContainerOrigin == "BOTTOM RIGHT")
                    mContainer.SetOrigin(frg::ContainerAlignment::BOTTOM_RIGHT);
        }
        ImGui::EndCombo();
    }

    ImGui::Text("Widget Horizontal Alignment: ");

    static const char* currentHorizontalAlignment = "HALF";
    if (ImGui::BeginCombo("    ", currentHorizontalAlignment))
    {
        for (int n = 0; n < IM_ARRAYSIZE(widgetAlignment); n++)
        {
            bool is_selected = (currentHorizontalAlignment == widgetAlignment[n]);
            if (ImGui::Selectable(widgetAlignment[n], is_selected))
                currentHorizontalAlignment = widgetAlignment[n];
                if(currentHorizontalAlignment == "MIN")
                    mContainer.SetHorizontalAlignment(frg::WidgetAlignment::MIN);
                if(currentHorizontalAlignment == "HALF")
                    mContainer.SetHorizontalAlignment(frg::WidgetAlignment::HALF);
                if(currentHorizontalAlignment == "MAX")
                    mContainer.SetHorizontalAlignment(frg::WidgetAlignment::MAX);
        }
        ImGui::EndCombo();
    }

    ImGui::Text("Widget Vertical Alignment: ");

    static const char* currentVerticalAlignment = "HALF";
    if (ImGui::BeginCombo("   ", currentVerticalAlignment))
    {
        for (int n = 0; n < IM_ARRAYSIZE(widgetAlignment); n++)
        {
            bool is_selected = (currentVerticalAlignment == widgetAlignment[n]);
            if (ImGui::Selectable(widgetAlignment[n], is_selected))
                currentVerticalAlignment = widgetAlignment[n];
                if(currentVerticalAlignment == "MIN")
                    mContainer.SetVerticalAlignment(frg::WidgetAlignment::MIN);
                if(currentVerticalAlignment == "HALF")
                    mContainer.SetVerticalAlignment(frg::WidgetAlignment::HALF);
                if(currentVerticalAlignment == "MAX")
                    mContainer.SetVerticalAlignment(frg::WidgetAlignment::MAX);
        }
        ImGui::EndCombo();
    }


    ImGui::End();

    mInputManager.UpdateMouse();
    mContainer.Update(window.GetViewSize());
}

void vi::Vifon::Render() {
    window.GetSFMLWindow().draw(mText);
    window.GetSFMLWindow().draw(mText2);
    window.GetSFMLWindow().draw(mText3);
    window.GetSFMLWindow().draw(mButton);
}