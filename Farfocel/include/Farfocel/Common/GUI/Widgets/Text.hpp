#pragma once
#include <SFML/Graphics.hpp>

#include "Farfocel/Common/GUI/Widget.hpp"

namespace frg{
    class Text : public frg::Widget{
    public:
        Text(const std::string& id);
        ~Text();

        void SetString(const std::string& string);
        const std::string& GetString();

        void ChangeFont(const sf::Font& font);

        void SetCharacterSize(const float& characterSize);
        void SetOutlineSize(const float& size);

        const float& GetCharacterSize();
        const float& GetOutlineSize();

        void SetFillColor(const sf::Color& color);
        void SetOutlineColor(const sf::Color& color);

        const sf::Color& GetFillColor();
        const sf::Color& GetOutlineColor();

        void draw(sf::RenderTarget & target, sf::RenderStates states) const override;

    protected:
        void SetWidgetStyle(frg::Style & style) override;
        void ApplyWidgetChanges() override;
        void SetWidgetPosition(const sf::Vector2f & position) override;

    protected:
        std::string mString;
        sf::Text mText;

        float mCharSize;
        float mOutlineSize;

        sf::Color mFillColor;
        sf::Color mOutlineColor;
    };
}
