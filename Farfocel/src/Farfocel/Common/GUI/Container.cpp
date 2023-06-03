#include "Farfocel/Common/GUI/Container.hpp"
#include "Farfocel/Common/GUI/Widget.hpp"

frg::Container::Container(const std::string& id)
    : mId(id), mRowCount(0), mColumnCount(0), mSize(0,0), mBreakRow(true), mStartingPos(0,0), mDynamicPosition(ContainerAlignment::NONE), mOrigin(ContainerAlignment::TOP_LEFT), mHorizontalAlignment(WidgetAlignment::MIN), mVerticalAlignment(WidgetAlignment::MIN), mMargins(0.f,0.f), mDynamicPositionMargins(0.f,0.f)
{

}

frg::Container::~Container(){

}


const std::string& frg::Container::GetId() {
    return mId;
}


void frg::Container::AddWidget(frg::Widget& _widget)
{
    if(mBreakRow){
        mColumns.emplace_back(mColumnCount);
        mColumnCount++;
        mBreakRow = false;
    }

    mColumns.back().AddWidget(_widget);
}

void frg::Container::SetPosition(const ContainerAlignment& dynamicPosition){
    mDynamicPosition = dynamicPosition;
}

void frg::Container::SetPosition(const sf::Vector2f& position){
    mDynamicPosition = ContainerAlignment::NONE;
    mStartingPos = position;
    mPosition = position;
}

void frg::Container::SetOrigin(const frg::ContainerAlignment &alignment) {
    mOrigin = alignment;
}

void frg::Container::SetHorizontalAlignment(const frg::WidgetAlignment &alignment) {
    mHorizontalAlignment = alignment;
}

void frg::Container::SetVerticalAlignment(const frg::WidgetAlignment &alignment) {
    mVerticalAlignment = alignment;
}

void frg::Container::SetMargins(const sf::Vector2f& margins){
    mMargins = margins;
}

void frg::Container::SetDynamicPositionMargins(const sf::Vector2f& margins){
    mDynamicPositionMargins = margins;
}

void frg::Container::BreakRow()
{
    mBreakRow = true;
}

void frg::Container::Update(const sf::Vector2f& viewSize)
{
    mSize.x = 0;
    mSize.y = 0;

    for(auto& column : mColumns){
        column.margin = mMargins.x;
        column.alignmentAdjustion = (std::uint8_t)mVerticalAlignment;
        column.UpdatePosition();

        if(column.size.x > mSize.x) {
            mSize.x = column.size.x;
        }
        mSize.y += column.size.y + mMargins.y;
    }
    mSize.y -= mMargins.y;

    mPosition = mStartingPos;

    if(mDynamicPosition != ContainerAlignment::NONE){
        // I feel like adam mickiewicz here
        mPosition = CalcAlignmentPosition(mDynamicPosition, {0.f,0.f}, viewSize);
        if(mPosition.x < 0) {mPosition.x *= -1.f;}
        if(mPosition.y < 0) {mPosition.y *= -1.f;}

        mPosition.x += mDynamicPositionMargins.x;
        mPosition.y += mDynamicPositionMargins.y;
    }

    mPosition = CalcAlignmentPosition(mOrigin, mPosition, mSize);

    for(auto& column : mColumns){
        column.SetPosition(mPosition);
        if(mSize.x > column.size.x && mHorizontalAlignment == WidgetAlignment::HALF)
            column.SetPosition({mPosition.x + ((mSize.x  - column.size.x ) / 2.f), mPosition.y});
        if(mSize.x > column.size.x && mHorizontalAlignment == WidgetAlignment::MAX)
            column.SetPosition({mPosition.x + (mSize.x  - column.size.x ), mPosition.y });

        mPosition.y += column.size.y + mMargins.y;
    }
    mPosition.y -= mMargins.y;
}

const sf::Vector2f frg::Container::CalcAlignmentPosition(const ContainerAlignment& alignment, const sf::Vector2f& startingPos, const sf::Vector2f& size){
    sf::Vector2f position;
    switch (alignment){
    case ContainerAlignment::NONE:
        position = startingPos;
        break;

    case ContainerAlignment::TOP_LEFT:
        position = startingPos;
        break;
    case ContainerAlignment::TOP_MIDDLE:
        position = {startingPos.x - size.x / 2.f, startingPos.y};
        break;
    case ContainerAlignment::TOP_RIGHT:
        position = {startingPos.x - size.x, startingPos.y};
        break;

    case ContainerAlignment::CENTER_LEFT:
        position = {startingPos.x, startingPos.y - size.y / 2.f};
        break;
    case ContainerAlignment::CENTER_MIDDLE:
        position = {startingPos.x - size.x / 2.f, startingPos.y - size.y / 2.f};
        break;
    case ContainerAlignment::CENTER_RIGHT:
        position = {startingPos.x - size.x, startingPos.y - size.y / 2.f};
        break;
    
    case ContainerAlignment::BOTTOM_LEFT:
        position = {startingPos.x, startingPos.y - size.y};
        break;
    case ContainerAlignment::BOTTOM_MIDDLE:
        position = {startingPos.x - size.x / 2.f, startingPos.y - size.y};
        break;
    case ContainerAlignment::BOTTOM_RIGHT:
        position = {startingPos.x - size.x, startingPos.y - size.y};
        break;
    }
    return position;
}