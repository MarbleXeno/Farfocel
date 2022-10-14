#include "Core/Runtime.hpp"

fr::Runtime::Runtime()
	: delta_time(), m_event()
{
	setWindowFramerateLimit(WINDOW_DEF_FPS_LIMIT);
}

fr::Runtime::~Runtime()
{

}

void fr::Runtime::initWindow()
{
	init(WINDOW_DEF_TITLE, WINDOW_DEF_RES_X, WINDOW_DEF_RES_Y);
}

void fr::Runtime::initWindow(const std::string& window_title, const std::uint16_t& resolution_x,
	const std::uint16_t& resolution_y)
{
	init(window_title, resolution_x, resolution_y);
}

void fr::Runtime::initAppLoop()
{
	while (m_render_window && m_render_window->isOpen())
	{
		delta_time = m_clock.restart().asSeconds();
		if (delta_time > 1.0f / m_window_fps_limit)
			delta_time = 1.0f / m_window_fps_limit;

		FRCL.event_manager.updateEvents();

		update(delta_time);

		m_render_window->clear(sf::Color::Yellow);

		draw();

		FRCL.scene_manager.update(delta_time);
		FRCL.scene_manager.draw();

		m_render_window->display();
	}
}

void fr::Runtime::setWindowFramerateLimit(const std::uint16_t& fps)
{
	m_window_fps_limit = fps;
	SFML.render_window.setFramerateLimit(m_window_fps_limit);
}

void fr::Runtime::setWindowIcon(const sf::Image& icon)
{
	SFML.render_window.setIcon(icon.getSize().x, icon.getSize().y, icon.getPixelsPtr());
}

void fr::Runtime::init(const std::string& window_title, const std::uint16_t& resolution_x, const std::uint16_t& resolution_y)
{
#ifdef _WIN32
	system("cls");
#endif
	SFML.render_window.create(sf::VideoMode(resolution_x, resolution_y), window_title, sf::Style::Close);
	SFML.render_window.setView(sf::View(sf::FloatRect(0.f, 0.f, resolution_x, resolution_y)));

	m_render_window = &SFML.render_window;

	FRCL.event_manager = fr::EventManager(*m_render_window, m_event);
	FRCL.event_manager.addBinding(sf::Event::Closed, false, [=]() {m_render_window->close(); });

	start();
}
