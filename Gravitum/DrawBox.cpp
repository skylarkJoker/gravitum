#include "DrawBox.hpp"
#include <math.h>
#include <iostream>

void DrawBox::setWindow(sf::RenderWindow &w)
{
    window = &w;
}

void DrawBox::DrawPolygon(const b2Vec2 *vertices, int32 vertexCount, const b2Color &color)
{
    sf::ConvexShape polygon;
    polygon.setPointCount(vertexCount);
    for (int i = 0; i < vertexCount; ++i)
    {
        polygon.setPoint(i, sf::Vector2f(vertices[i].x, vertices[i].y));
    }
    polygon.setOutlineColor(sf::Color(static_cast<int>(color.r * 100), static_cast<int>(color.g * 100), static_cast<int>(color.b * 100), static_cast<int>(color.a * 255)));
    polygon.setScale(16.f, 16.f);
    window->draw(polygon);
}

void DrawBox::DrawSolidPolygon(const b2Vec2 *vertices, int32 vertexCount, const b2Color &color)
{
    sf::ConvexShape polygon;
    polygon.setPointCount(vertexCount);
    for (int i = 0; i < vertexCount; ++i)
    {
        polygon.setPoint(i, sf::Vector2f(vertices[i].x, vertices[i].y));
    }

    polygon.setOutlineColor(sf::Color(static_cast<int>(color.r * 100), static_cast<int>(color.g * 100), static_cast<int>(color.b * 100), static_cast<int>(color.a * 255)));
    polygon.setScale(16.f, 16.f);
    window->draw(polygon);
}

void DrawBox::DrawCircle(const b2Vec2 &center, float radius, const b2Color &color)
{
    sf::CircleShape circle(radius);
    circle.setPosition(center.x, center.y);
    circle.setOutlineColor(sf::Color(static_cast<int>(color.r * 100), static_cast<int>(color.g * 100), static_cast<int>(color.b * 100), static_cast<int>(color.a * 255)));
    circle.setScale(16.f, 16.f);
    window->draw(circle);
}

void DrawBox::DrawSolidCircle(const b2Vec2 &center, float radius, const b2Vec2 &axis, const b2Color &color)
{
    sf::CircleShape circle(radius);
    circle.setPosition(center.x, center.y);
    circle.setOutlineColor(sf::Color(static_cast<int>(color.r * 100), static_cast<int>(color.g * 100), static_cast<int>(color.b * 100), static_cast<int>(color.a * 255)));
    circle.setScale(16.f, 16.f);
    window->draw(circle);
}

void DrawBox::DrawSegment(const b2Vec2 &p1, const b2Vec2 &p2, const b2Color &color)
{
    sf::Vertex line[] = {
        sf::Vertex(sf::Vector2f(p1.x, p1.y)),
        sf::Vertex(sf::Vector2f(p2.x, p2.y))};
    window->draw(line, 2, sf::Lines);
}

void DrawBox::DrawTransform(const b2Transform &)
{
}

void DrawBox::DrawPoint(const b2Vec2 &p, float size, const b2Color &color)
{
    sf::RectangleShape rect(sf::Vector2f(size, size));
    rect.setPosition(sf::Vector2f(p.x, p.y));
    rect.setScale(16.f, 16.f);
    window->draw(rect);
}