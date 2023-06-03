#pragma once
#include <SFML/Graphics.hpp>
#include <vector>

#include "Farfocel/Common/Console.hpp"
#include "Farfocel/Core/Window.hpp"

#include "Farfocel/Common/GUI/Widget.hpp"
#include "Farfocel/Common/GUI/ContainerColumn.hpp"

namespace frg{
    enum class ContainerAlignment{
    //  -----------
    //  |*   *   *|
    //  |*   *   *|
    //  |*   *   *|
    //  -----------
        NONE = 0,

        TOP_LEFT,
        TOP_MIDDLE,
        TOP_RIGHT,

        CENTER_LEFT,
        CENTER_MIDDLE,
        CENTER_RIGHT,

        BOTTOM_LEFT,
        BOTTOM_MIDDLE,
        BOTTOM_RIGHT,
    };

    enum class WidgetAlignment{
        MIN = 0,
        HALF = 1,
        MAX = 2
    };

    class Container{
    public:
        Container(const std::string& id);
        ~Container();

        const std::string& GetId();
        void AddWidget(Widget& _widget);

        void SetPosition(const ContainerAlignment& dynamicPosition);
        void SetPosition(const sf::Vector2f& position);

        void SetOrigin(const ContainerAlignment& alignment);
        void SetHorizontalAlignment(const WidgetAlignment& alignment);
        void SetVerticalAlignment(const WidgetAlignment& alignment);

        void SetMargins(const sf::Vector2f& margins);
        void SetDynamicPositionMargins(const sf::Vector2f& margins);

        void BreakRow();

        // Call when using a dynamic position and detected that window has resized; keeps widgets properly aligned
        void Update(const sf::Vector2f& viewSize);

        std::vector<frgu::ContainerColumn> mColumns;
    private:
        const sf::Vector2f CalcAlignmentPosition(const ContainerAlignment& alignment, const sf::Vector2f& startingPos, const sf::Vector2f& size);

        const std::string& mId;

        std::uint16_t mRowCount;
        std::uint16_t mColumnCount;
        std::uint32_t mWidgetCount;

        bool mBreakRow;

        sf::Vector2f mSize;

        sf::Vector2f mStartingPos;
        sf::Vector2f mPosition;
        ContainerAlignment mDynamicPosition;

        ContainerAlignment mOrigin;
        WidgetAlignment mVerticalAlignment;
        WidgetAlignment mHorizontalAlignment;

        sf::Vector2f mMargins;
        sf::Vector2f mDynamicPositionMargins;
    };
}
