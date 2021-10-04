#pragma once

#include "util.h"

#define FUNC_NONE []{}

namespace gui
{
	class Widget
	{
	protected:

		bool hidden = false;

		std::function<void()> funcmc = FUNC_NONE;
		std::function<void()> funcmo = FUNC_NONE;
		std::function<void()> funcmr = FUNC_NONE;

	public:

		virtual void update(sf::RenderWindow*& window) {};
		virtual void draw(sf::RenderWindow*& window) = 0;

		void hide(const bool& hide) { hidden = hide; };

		void onMouseClick(std::function<void()> func)   { funcmc = func; }
		void onMouseOver(std::function<void()> func)    { funcmo = func; }
		void onMouseRelease(std::function<void()> func) { funcmr = func; }
	};

	class Button : public Widget
	{
	private:

		sf::RectangleShape rect;
		sf::Color color, colormc, colormo;
		sf::Text text;
		
		std::string textString;

		bool mouseClicked = false;

	public:

		Button();
		Button(const sf::Vector2f& size, const sf::Vector2f& pos, const sf::Color& color);

		void update(sf::RenderWindow*& window) override;
		void draw(sf::RenderWindow*& window) override;

		void setText(const std::string& string);
		void setMoColor(const sf::Color& color) { colormo = color; }
		void setMcColor(const sf::Color& color) { colormc = color; }

		sf::RectangleShape& getRect(void) {  return rect; }
		sf::Color& getColor(void)		  { return color; }
		sf::Text& getText(void)           {  return text; }
	};

	class Panel : public Widget
	{
	private:

		sf::RectangleShape rect;
		sf::Color color;

	public:

		Panel();
		Panel(const sf::Vector2f& size, const sf::Vector2f& pos, const sf::Color& color);

		void update(sf::RenderWindow*& window) override;
		void draw(sf::RenderWindow*& window) override;

		void setPos(const sf::Vector2f& pos);
		void setSize(const sf::Vector2f& size);
		void setColor(const sf::Color& color);
		void setOutline(const float& thickness, const sf::Color& color);
	};
	
	class HealthBar : public Widget 
	{
	private:

		sf::RectangleShape main;
		sf::RectangleShape filr;
		sf::RectangleShape back;

		sf::Vector2f size;
		sf::Vector2f position;

		float timer = 0.0f;
		float tick = 0.0f;
		bool changeF = false;

		int64_t max;
		int64_t cur;

		float& nwidth(void);

	public:

		HealthBar();
		HealthBar(const sf::Vector2f& position, const sf::Vector2f& size, const int64_t& max);

		void update(sf::RenderWindow*& window, const float& dt);
		void draw(sf::RenderWindow*& window) override;

		void setPosition(const sf::Vector2f& pos);
		sf::Vector2f& getPosition(void);
		sf::Vector2f& getSize(void);

		void changeBy(const int64_t& amount);
	};

	class PopUpText : public Widget
	{
	private:

		sf::Text text;

		sf::Vector2f position;
		sf::Vector2f direction;
		sf::Vector2f size;

		int64_t amount = 0;
		unsigned short charSize = 10;

		float timer = 0.0f;
		float ctimer = 0.0f;
		float tick = 0.0f;

		bool fade = false;
		bool changeF = true;

	public:

		float duration = 1.0f;
		float speed = 50.0f;

		short fadeOutDuration = 200;

		bool isCritical = false;
		bool delete_ = false;

		PopUpText();
		PopUpText(const sf::Vector2f& position, const sf::Vector2f& direction,
				  const int64_t& amount, const float& duration, 
			      const unsigned short& size);

		void update(sf::RenderWindow*& window, const float& dt);
		void draw(sf::RenderWindow*& window) override;

		void setDirection(const sf::Vector2f& dir) { direction = dir; }
		void setSpeed(const float& speed) { this->speed = speed; }
		void setColor(const sf::Color& color) { text.setFillColor(color); }
	};

	class PopUpTextMgr 
	{
	private:

		static std::vector<PopUpText> popups;

	public:

		static void instantiate(const sf::Vector2f& position, const sf::Vector2f& direction,
							    const int64_t& amount, const float& speed,
							    const float& duration, const short& fadeOutDuration,
				                const unsigned short& size, const sf::Color& color,
								const bool& isCritical);

		static void update(sf::RenderWindow*& window, const float& dt);
		static void draw(sf::RenderWindow*& window);
	};
};

