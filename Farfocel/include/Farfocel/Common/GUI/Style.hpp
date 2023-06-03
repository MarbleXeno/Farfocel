#pragma once
#include <SFML/Graphics.hpp>

namespace frg{
    struct WidgetColor{
        WidgetColor(){}
        WidgetColor(const sf::Color& _color, const sf::Color& _hovered, const sf::Color& _pressed)
            : neutral(_color), hovered(_hovered), pressed(_pressed)
        {

        }

        ~WidgetColor(){}

        sf::Color neutral;
        sf::Color hovered;
        sf::Color pressed;
    };

    struct WidgetSize{
        WidgetSize(){}
        WidgetSize(const float& _size, const float& _hovered, const float& _pressed)
            : neutral(_size), hovered(_hovered), pressed(_pressed)
        {

        }

        ~WidgetSize(){

        }

        float neutral;
        float hovered;
        float pressed;
    };

    struct Style{
        Style(const std::string& _id)
            : id(_id), fText(nullptr), fButtonText(nullptr)
        {
            SetupDefaultStyle();
        }

        Style(const std::string& _id, const sf::Font& text, const sf::Font& buttonText)
            : id(_id), fText(&text), fButtonText(&buttonText)
        {
            SetupDefaultStyle();
        }

        ~Style(){

        }

        const std::string& id;

        // Fonts
        const sf::Font* fText;
        const sf::Font* fButtonText;

        // Text margin in buttons
        sf::Vector2f mButton;

        // Font sizes, outlines...
        float sText;
        float sTextOutline;

        WidgetSize sButtonText;

        sf::Vector2f sButtonMargins;

        WidgetSize sButtonOutline;
        WidgetSize sButtonTextOutline;

        // Colors
        sf::Color cText;
        sf::Color cTextOutline;

        WidgetColor cButton;
        WidgetColor cButtonText;

        WidgetColor cButtonOutline;
        WidgetColor cButtonTextOutline;

    private:
        void SetupDefaultStyle(){
            sText = 30.f;
            sTextOutline = 2.f;

            sButtonText = WidgetSize(30.f,30.f,30.f);

            sButtonMargins = {20.f,20.f};

            sButtonOutline = WidgetSize(0.f,0.f,1.f);
            sButtonTextOutline = WidgetSize(0.f,1.f,1.f);

            cText = sf::Color::White;
            cTextOutline = sf::Color::Black;

            cButton = WidgetColor(sf::Color(190,190,190,90), sf::Color(190,190,190,125), sf::Color(190,190,190,125));
            cButtonText = WidgetColor(sf::Color::White, sf::Color::Color::White, sf::Color::White);

            cButtonOutline = WidgetColor(sf::Color::Black, sf::Color::Black, sf::Color::Black);
            cButtonTextOutline = WidgetColor(sf::Color::Black, sf::Color::Black, sf::Color::Black);

        }

    };
}
