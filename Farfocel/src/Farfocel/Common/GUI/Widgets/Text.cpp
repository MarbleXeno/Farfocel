#include "Farfocel/Common/GUI/Widgets/Text.hpp"

frg::Text::Text(const std::string& id)
    : Widget(id, WidgetType::TEXT), mString(id), mCharSize(0), mOutlineSize(0), mFillColor(sf::Color::White), mOutlineColor(sf::Color::Black)
{

}

frg::Text::~Text(){

}

void frg::Text::SetString(const std::string& string)
{
    mString = string;
    mText.setString(mString);

    ApplyWidgetChanges();
}

const std::string & frg::Text::GetString()
{
    return mString;
}

void frg::Text::ChangeFont(const sf::Font& font)
{
    mText.setFont(font);

    ApplyWidgetChanges();
}

void frg::Text::SetCharacterSize(const float& characterSize)
{
    mCharSize = characterSize;
    mText.setCharacterSize(mCharSize);
    ApplyWidgetChanges();
}

void frg::Text::SetOutlineSize(const float& size) {
    mOutlineSize = size;
    mText.setOutlineThickness(mOutlineSize);
    ApplyWidgetChanges();
}

const float& frg::Text::GetCharacterSize() {
    return mCharSize;
}

const float& frg::Text::GetOutlineSize() {
    return mOutlineSize;
}

const sf::Color &frg::Text::GetFillColor() {
    return mFillColor;
}

const sf::Color &frg::Text::GetOutlineColor() {
    return mFillColor;
}

void frg::Text::SetFillColor(const sf::Color &color) {
    mText.setFillColor(color);
}

void frg::Text::SetOutlineColor(const sf::Color &color) {
    mText.setOutlineColor(color);
}

void frg::Text::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    //target.draw(mBoundingBox);
    target.draw(mText);
}

void frg::Text::SetWidgetStyle(frg::Style& style)
{
    if(style.fText)
        mText.setFont(*style.fText);

    mText.setFillColor(style.cText);
    mText.setOutlineColor(style.cTextOutline);

    mText.setCharacterSize(style.sText);
    mText.setOutlineThickness(style.sTextOutline);

    ApplyWidgetChanges();
}

void frg::Text::ApplyWidgetChanges()
{
    mText.setOrigin({mText.getLocalBounds().left + mText.getLocalBounds().width / 2.f, mText.getLocalBounds().top + mText.getLocalBounds().height / 2.f});

    InitBoundingBox({mText.getLocalBounds().width, mText.getLocalBounds().height});
    SetWidgetPosition(GetPosition(frg::WidgetOrigin::CENTER_MIDDLE));
}

void frg::Text::SetWidgetPosition(const sf::Vector2f& position)
{
    mText.setPosition(position);
}
