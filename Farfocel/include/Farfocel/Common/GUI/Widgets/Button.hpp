#pragma once
#include <SFML/Graphics.hpp>

#include "Farfocel/Common/GUI/Widget.hpp"
#include "Farfocel/Common/GUI/Widgets/Text.hpp"

#include "Farfocel/Utils/FunctionCallback.hpp"

namespace frg{
    enum class ButtonState{
        BUTTON_NEUTRAL = 0,
        BUTTON_HOVERED = 1,
        BUTTON_PRESSED = 2,
        BUTTON_RELEASED = 3
    };

    class Button : public frg::Widget{
    public:
        Button(const std::string& id);
        ~Button();


        void SetTextString(const std::string& string);

        void SetTextSize(const frg::WidgetSize& size);

        void SetColor(const frg::WidgetColor& color);

        // Sets the callback to be invoked when button is pressed or released; Default: ON RELEASE
        void SetCallbackOnPressed(const bool& onPressed);
        const bool& GetCallbackOnPressed();

        // Repeat only works when callback is set to invoke when pressed
        void SetCallbackRepeat(const bool& repeat);
        const bool& GetCallbackRepeat();

        void SetCallback(const std::function<void()> callback);

        void SetState(const ButtonState& state);
        const frg::ButtonState& GetState();

        void Exec();

        void draw(sf::RenderTarget & target, sf::RenderStates states) const override;
    protected:
        void SetWidgetStyle(frg::Style & style) override;
        void ApplyWidgetChanges() override;
        void SetWidgetPosition(const sf::Vector2f & position) override;

    private:
        void ApplyButtonStyle();

        sf::RectangleShape mButton;
        frg::Text mText;

        ButtonState mState;

        bool mCallbackOnPressed;
        fru::FunctionCallback mCallback;
    };
}
