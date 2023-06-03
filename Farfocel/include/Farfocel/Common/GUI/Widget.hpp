#pragma once
#include <SFML/Graphics.hpp>

#include "Farfocel/Common/GUI/Style.hpp"

#include "Farfocel/Common/Console.hpp"

namespace frg{
    enum class WidgetOrigin{
        TOP_LEFT = 1,
        TOP_RIGHT = -1,

        CENTER_LEFT = 2,
        CENTER_RIGHT = -2,

        BOTTOM_LEFT = 3,
        BOTTOM_RIGHT = -3,

        CENTER_MIDDLE = 4,
        TOP_MIDDLE = -4,
        BOTTOM_MIDDLE = 5
    };

    enum class WidgetType{
        CUSTOM = 0,
        TEXT,
        BUTTON
    };

    class Widget : public sf::Drawable{
    public:
        Widget(const std::string& id, const WidgetType& type);
        ~Widget();

        const std::string& GetId();
        const WidgetType& GetType();

        void SetStyle(Style& style);
        Style& GetStyle();

        void SetGridPosition(const sf::Vector2u& pos);
        const sf::Vector2u& GetGridPosition();

        void SetOrigin(const WidgetOrigin& origin);

        void SetPosition(const sf::Vector2f& position);

        const sf::Vector2f& GetPosition();
        const sf::Vector2f GetPosition(const WidgetOrigin& origin);

        const sf::FloatRect GetGlobalRect();
        const sf::FloatRect GetLocalRect();

        const sf::Vector2f GetSize();
        const sf::Vector2f GetOriginSize();

        const frg::WidgetOrigin& GetOrigin();
        const sf::Vector2f& GetOriginPoint();

        virtual void draw (sf::RenderTarget &target, sf::RenderStates states) const = 0;

        bool breakRow;
    protected:
        void InitBoundingBox(const sf::Vector2f& size);
        void ApplyBoundingBoxPosition();

        virtual void SetWidgetStyle(Style& style) = 0;

        // This keeps widget synced to its bounding box,
        // call it every time widget's position a/or size changes
        virtual void ApplyWidgetChanges() = 0;

        virtual void SetWidgetPosition(const sf::Vector2f& position) = 0;

        //virtual const sf::FloatRect GetWidgetRect() = 0;
        sf::RectangleShape mBoundingBox;
    private:
        sf::Vector2f mPosition;
        const sf::Vector2f CalcOriginPoint(const WidgetOrigin& origin);

        const std::string& mId;
        const WidgetType& mType;

        sf::Vector2u mGridPos;

        Style* mStyle;

        WidgetOrigin mOrigin;
        sf::Vector2f mOriginPoint;

        bool mInitializedBoundingBox;
    };
}
