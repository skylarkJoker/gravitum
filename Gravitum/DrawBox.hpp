#pragma once
#include "box2d/b2_draw.h"
#include "SFML/Graphics.hpp"

class DrawBox : public b2Draw
{
private:
    sf::RenderWindow *window;

public:
    void setWindow(sf::RenderWindow &);
    void DrawPolygon(const b2Vec2 *, int32, const b2Color &);
    void DrawSolidPolygon(const b2Vec2 *, int32, const b2Color &);
    void DrawCircle(const b2Vec2 &, float, const b2Color &);
    void DrawSolidCircle(const b2Vec2 &, float, const b2Vec2 &, const b2Color &);
    void DrawSegment(const b2Vec2 &, const b2Vec2 &, const b2Color &);
    void DrawTransform(const b2Transform &);
    void DrawPoint(const b2Vec2 &, float, const b2Color &);
};