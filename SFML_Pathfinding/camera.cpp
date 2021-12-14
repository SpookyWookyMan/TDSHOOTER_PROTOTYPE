#include "camera.h"

Camera::Camera() 
{

}

void Camera::bind(sf::RenderWindow*& window) 
{
	window->setView(view);
}
void Camera::center(const sf::Vector2f& target) 
{
	view.setCenter(target);
}
void Camera::setSize(const sf::Vector2f& size) 
{
	view.setSize(size);
}