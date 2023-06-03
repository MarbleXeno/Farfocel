#pragma once
#include "Farfocel/Common/GUI/Widget.hpp"

namespace frgu{
    class ContainerColumn{
    public:
        ContainerColumn(const std::uint16_t& _column)
            : position(0,0), nextPosition(0,0), size(0,0), rows(0), column(_column), alignmentAdjustion(0), margin(0)
        {
            boundingBox.setFillColor(sf::Color(100,100,100,100));
        }
        ~ContainerColumn(){

        }

        void AddWidget(frg::Widget& widget){
            widget.SetOrigin(frg::WidgetOrigin::TOP_LEFT);
            size.x += widget.GetSize().x;

            if(widget.GetSize().y > size.y)
                size.y = widget.GetSize().y;

            widgets[rows] = &widget;
            rows++;
        }
        void SetPosition(const sf::Vector2f& _position){
            position = _position;
            nextPosition = position;
            boundingBox.setPosition(position);
            UpdatePosition();
        }

        void UpdatePosition(){
            nextPosition = position;
            sf::Vector2f maxSize = {0,0};

            for(auto& [row, widget] : widgets){
                maxSize.x += widget->GetSize().x + margin;
                if(maxSize.y < widget->GetSize().y) {
                    maxSize.y = widget->GetSize().y;
                }
            }
            
            for(auto& [row, widget] : widgets){
                widget->SetPosition({nextPosition.x, nextPosition.y});

                if(maxSize.y > widget->GetSize().y && alignmentAdjustion == 1)
                    widget->SetPosition({nextPosition.x, nextPosition.y + ((maxSize.y - widget->GetSize().y) / 2.f) });
                if(maxSize.y > widget->GetSize().y && alignmentAdjustion == 2)
                    widget->SetPosition({nextPosition.x, nextPosition.y + (maxSize.y - widget->GetSize().y)});

                nextPosition.x += widget->GetSize().x + margin;
            }
            maxSize.x -= margin;
            size = maxSize;
            boundingBox.setSize(size);
        }

        sf::Vector2f position;
        sf::Vector2f nextPosition;

        // the max width and height
        sf::Vector2f size;

        std::uint16_t rows;
        std::uint16_t column;

        std::uint8_t alignmentAdjustion;

        float margin;

        sf::RectangleShape boundingBox;

        std::map<std::uint16_t, frg::Widget*> widgets;
    };
}