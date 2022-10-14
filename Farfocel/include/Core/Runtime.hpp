/*
    Name:
    Runtime

    Description:
    A runtime. Inherit from it and voilà - now you can make AAA games, FUCKING gigantic apps and more!
*/

#pragma once
#include <iostream>
#include <string>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

#include "Farfocel.hpp"

namespace fr
{
#define WINDOW_DEF_RES_X 1280
#define WINDOW_DEF_RES_Y 720
#define WINDOW_DEF_FPS_LIMIT 144
#define WINDOW_DEF_TITLE "Farfocel Game"

    class Runtime
    {
    public:
        Runtime();

        virtual ~Runtime();

        void initWindow();
        void initWindow(const std::string& window_title, const std::uint16_t& resolution_x, const std::uint16_t& resolution_y);
        void initAppLoop();
        
        void setWindowFramerateLimit(const std::uint16_t& fps);
        void setWindowIcon(const sf::Image& icon);

        // this is used for doing stuff after the Runtime has initialized and the window created
        virtual void start() = 0;
    	virtual void update(const float& delta_time) = 0;
        virtual void draw() = 0;

    protected:
        fr::SFMLUtils SFML;
        fr::FRCLUtils FRCL;

        float delta_time;

    private:
        void init(const std::string& window_title, const std::uint16_t& resolution_x, const std::uint16_t& resolution_y);
        std::uint16_t m_window_fps_limit;

        sf::RenderWindow* m_render_window;

        sf::Event m_event;
        sf::Clock m_clock;

    };

    Runtime* initApplication();
}

