#include "Farfocel/Common/GUI/Widget.hpp"

frg::Widget::Widget(const std::string& id, const WidgetType& type)
    : mId(id), mType(type), mOrigin(WidgetOrigin::CENTER_MIDDLE), mInitializedBoundingBox(false), breakRow(false), mStyle(nullptr), mPosition(0,0)
{
    mOriginPoint = CalcOriginPoint(mOrigin);

    mBoundingBox.setFillColor(sf::Color(255,255,255,90));
}

frg::Widget::~Widget()
{

}

const std::string & frg::Widget::GetId()
{
    return mId;
}

const frg::WidgetType & frg::Widget::GetType()
{
    return mType;
}

void frg::Widget::SetStyle(frg::Style& style)
{
    mStyle = &style;
    SetWidgetStyle(*mStyle);
}

frg::Style& frg::Widget::GetStyle()
{
    return *mStyle;
}

void frg::Widget::SetGridPosition(const sf::Vector2u& pos)
{
    mGridPos = pos;
}

const sf::Vector2u& frg::Widget::GetGridPosition()
{
    return mGridPos;
}

void frg::Widget::SetOrigin(const frg::WidgetOrigin& origin)
{
    if(!mInitializedBoundingBox)
        fr::Console::AddLog("frg::Widget::SetOrigin (ID: "+mId+"): Bounding box hasn't been initialized, yet attempting to set origin of the widget.\nCall InitBoundingBox() before calling this function", fr::LogLevel::WARNING);

    mOrigin = origin;
    mOriginPoint = CalcOriginPoint(mOrigin);
    mBoundingBox.setOrigin(mBoundingBox.getGlobalBounds().width * mOriginPoint.x, mBoundingBox.getGlobalBounds().height * mOriginPoint.y);
    ApplyWidgetChanges();
}

void frg::Widget::SetPosition(const sf::Vector2f& position)
{
    if(!mInitializedBoundingBox)
        fr::Console::AddLog("frg::Widget::SetPosition (ID: "+mId+"): Bounding box hasn't been initialized, yet attempting to set position of the widget.\nCall InitBoundingBox() before calling this function", fr::LogLevel::WARNING);

    mPosition = position;
    mBoundingBox.setPosition(mPosition);
    ApplyWidgetChanges();
}

const sf::Vector2f & frg::Widget::GetPosition()
{
    if(!mInitializedBoundingBox)
        fr::Console::AddLog("frg::Widget::GetPosition (ID: "+mId+"): Bounding box hasn't been initialized, yet attempting to get position of the widget.\nCall InitBoundingBox() before calling this function", fr::LogLevel::WARNING);

    return mPosition;
}

const sf::Vector2f frg::Widget::GetPosition(const frg::WidgetOrigin& origin)
{
    if(!mInitializedBoundingBox)
        fr::Console::AddLog("frg::Widget::GetPosition (ID: "+mId+"): Bounding box hasn't been initialized, yet attempting to get position of the widget.\nCall InitBoundingBox() before calling this function", fr::LogLevel::WARNING);

    return { mBoundingBox.getGlobalBounds().left + mBoundingBox.getGlobalBounds().width * CalcOriginPoint(origin).x, mBoundingBox.getGlobalBounds().top + mBoundingBox.getGlobalBounds().height * CalcOriginPoint(origin).y};
}

const sf::FloatRect frg::Widget::GetGlobalRect()
{
    if(!mInitializedBoundingBox)
        fr::Console::AddLog("frg::Widget::GetGlobalRect (ID: "+mId+"): Widget's bounding box hasn't been initialized, yet attempting to get its rect.\nCall InitBoundingBox() before calling this function", fr::LogLevel::WARNING);

    return mBoundingBox.getGlobalBounds();
}

const sf::FloatRect frg::Widget::GetLocalRect()
{
    if(!mInitializedBoundingBox)
        fr::Console::AddLog("frg::Widget::GetLocalRect (ID: "+mId+"): Widget's bounding box hasn't been initialized, yet attempting to get its rect.Call InitBoundingBox() before calling this function", fr::LogLevel::WARNING);

    return mBoundingBox.getLocalBounds();
}

const sf::Vector2f frg::Widget::GetSize()
{
    return {GetGlobalRect().width, GetGlobalRect().height};
}

const sf::Vector2f frg::Widget::GetOriginSize()
{
    return {GetGlobalRect().width * mOriginPoint.x, GetGlobalRect().height * mOriginPoint.y};
}

const sf::Vector2f & frg::Widget::GetOriginPoint()
{
    return mOriginPoint;
}

const frg::WidgetOrigin & frg::Widget::GetOrigin()
{
    return mOrigin;
}

void frg::Widget::InitBoundingBox(const sf::Vector2f& size)
{
    mBoundingBox.setSize(size);
    mInitializedBoundingBox = true;
}

const sf::Vector2f frg::Widget::CalcOriginPoint(const frg::WidgetOrigin& origin)
{
    sf::Vector2f originPoint;
    switch (origin){
        case WidgetOrigin::TOP_LEFT:
            originPoint = sf::Vector2f(0.f,0.f);
            break;
        case WidgetOrigin::TOP_MIDDLE:
            originPoint = sf::Vector2f(0.5f,0.f);
            break;
        case WidgetOrigin::TOP_RIGHT:
            originPoint = sf::Vector2f(1.f,0.f);
            break;
        case WidgetOrigin::CENTER_LEFT:
            originPoint = sf::Vector2f(0.f,0.5f);
            break;
        case WidgetOrigin::CENTER_MIDDLE:
            originPoint = sf::Vector2f(0.5f,0.5f);
            break;
        case WidgetOrigin::CENTER_RIGHT:
            originPoint = sf::Vector2f(1.f,0.5f);
            break;
        case WidgetOrigin::BOTTOM_LEFT:
            originPoint = sf::Vector2f(0.f,1.f);
            break;
        case WidgetOrigin::BOTTOM_MIDDLE:
            originPoint = sf::Vector2f(0.5f,1.f);
            break;
        case WidgetOrigin::BOTTOM_RIGHT:
            originPoint = sf::Vector2f(1.f,1.f);
            break;
    }
    return originPoint;
}

