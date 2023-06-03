#include "Farfocel/Common/GUI/Widgets/Button.hpp"

frg::Button::Button(const std::string& id)
    : Widget(id, frg::WidgetType::BUTTON), mText(id), mState(ButtonState::BUTTON_NEUTRAL), mCallbackOnPressed(false), mCallback(false, [=](){fr::Console::AddLog("frg::Button (ID: "+id+") Callback not set", fr::LogLevel::WARNING);})
{

}

frg::Button::~Button()
{

}

void frg::Button::SetTextSize(const frg::WidgetSize& size) {
    GetStyle().sButtonText = size;
    ApplyWidgetChanges();
}


void frg::Button::SetTextString(const std::string& string)
{
    mText.SetString(string);

    ApplyWidgetChanges();
}

void frg::Button::SetCallbackOnPressed(const bool& onPressed)
{
    mCallbackOnPressed = onPressed;
}

const bool & frg::Button::GetCallbackOnPressed()
{
    return mCallbackOnPressed;
}

void frg::Button::SetCallbackRepeat(const bool& repeat)
{
    mCallback.SetRepeat(repeat);
}


const bool & frg::Button::GetCallbackRepeat()
{
    return mCallback.GetRepeat();
}


void frg::Button::SetCallback(const std::function<void()> callback)
{
    mCallback.SetCallback(callback);
}

void frg::Button::SetState(const frg::ButtonState& state)
{
    mState = state;
    ApplyButtonStyle();
    ApplyWidgetChanges();
}

const frg::ButtonState & frg::Button::GetState()
{
    return mState;
}

void frg::Button::Exec()
{
    mCallback.Execute();
}


void frg::Button::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    //target.draw(mBoundingBox);
    target.draw(mButton);
    target.draw(mText);
}

void frg::Button::SetWidgetPosition(const sf::Vector2f& position)
{
    mBoundingBox.setFillColor(sf::Color::Black);
    mButton.setPosition(position);
    mText.SetPosition(position);
}

void frg::Button::ApplyWidgetChanges()
{
    mText.SetOrigin(frg::WidgetOrigin::CENTER_MIDDLE);

    mButton.setSize({mText.GetLocalRect().width + GetStyle().sButtonMargins.x, mText.GetLocalRect().height + GetStyle().sButtonMargins.y});
    mButton.setOrigin({mButton.getLocalBounds().width / 2.f, mButton.getLocalBounds().height / 2.f});

    InitBoundingBox({mButton.getGlobalBounds().width, mButton.getGlobalBounds().height});

    SetWidgetPosition(GetPosition(frg::WidgetOrigin::CENTER_MIDDLE));
}

void frg::Button::SetWidgetStyle(frg::Style& style)
{
    mText.SetStyle(style);

    ApplyButtonStyle();
}

void frg::Button::ApplyButtonStyle()
{
    switch (mState){
        case ButtonState::BUTTON_NEUTRAL:
            mText.SetFillColor(GetStyle().cButtonText.neutral);
            mText.SetOutlineColor(GetStyle().cButtonTextOutline.neutral);

            mButton.setFillColor(GetStyle().cButton.neutral);
            mButton.setOutlineColor(GetStyle().cButtonOutline.neutral);

            mText.SetCharacterSize(GetStyle().sButtonText.neutral);
            mText.SetOutlineSize(GetStyle().sButtonTextOutline.neutral);
            mButton.setOutlineThickness(GetStyle().sButtonOutline.neutral);

            ApplyWidgetChanges();
            break;
        case ButtonState::BUTTON_HOVERED:
            mText.SetFillColor(GetStyle().cButtonText.hovered);
            mText.SetOutlineColor(GetStyle().cButtonTextOutline.hovered);

            mButton.setFillColor(GetStyle().cButton.hovered);
            mButton.setOutlineColor(GetStyle().cButtonOutline.hovered);

            mText.SetCharacterSize(GetStyle().sButtonText.hovered);
            mText.SetOutlineSize(GetStyle().sButtonTextOutline.hovered);
            mButton.setOutlineThickness(GetStyle().sButtonOutline.hovered);

            ApplyWidgetChanges();
            break;
        case ButtonState::BUTTON_PRESSED:
            mText.SetFillColor(GetStyle().cButtonText.pressed);
            mText.SetOutlineColor(GetStyle().cButtonTextOutline.pressed);

            mButton.setFillColor(GetStyle().cButton.pressed);
            mButton.setOutlineColor(GetStyle().cButtonOutline.pressed);

            mText.SetCharacterSize(GetStyle().sButtonText.pressed);
            mText.SetOutlineSize(GetStyle().sButtonTextOutline.pressed);
            mButton.setOutlineThickness(GetStyle().sButtonOutline.pressed);

            ApplyWidgetChanges();
            break;
        case ButtonState::BUTTON_RELEASED:
            mState = frg::ButtonState::BUTTON_NEUTRAL;
            ApplyButtonStyle();
            break;
    }
}
