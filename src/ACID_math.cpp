#include <ACID_math.h>

float ACIDMath::get_module_b2Vec2(const b2Vec2& point1, const b2Vec2& point2) {
    float x = point1.x - point2.x;
    float y = point1.y - point2.y;
    return sqrt(x * x + y * y);
}

float ACIDMath::get_module_Vector2f(const sf::Vector2f& point1, const sf::Vector2f& point2) {
    float x = point1.x - point2.x;
    float y = point1.y - point2.y;
    return sqrt(x * x + y * y);
}

void ACIDMath::get_unit_b2Vec2(b2Vec2& vector) {
    float module = sqrt(vector.x * vector.x + vector.y * vector.y);
    if (module) {
        vector.x = vector.x / module;
        vector.y = vector.y / module;
    }
}

void ACIDMath::get_unit_Vector2f(sf::Vector2f vector) {
    float module = sqrt(vector.x * vector.x + vector.y * vector.y);
    if (module) {
        vector.x = vector.x / module;
        vector.y = vector.y / module;
    }
}

float ACIDMath::get_angle_from_b2Vec(const b2Vec2& vector) {
    if (vector.x == 0) {
        if (vector.y > 0) {
            return 90.0f;
        }
        else {
            return 180.0f;
        }
    } else {
        float angle = atan(vector.y / vector.x) * 180.0 / PI;
        if (vector.x < 0 && vector.y > 0 || vector.x < 0 && vector.y < 0) {
            angle = 180.0f - angle;
        }
        return angle;
    }
}

float ACIDMath::get_angle_from_Vector2f(const sf::Vector2f vector) {
    if (vector.x == 0) {
        if (vector.y > 0) {
            return 90.0f;
        }
        else {
            return 180.0f;
        }
    } else {
        float angle = atan(vector.y / vector.x) * 180.0 / PI;
        if (vector.x < 0 && vector.y > 0 || vector.x < 0 && vector.y < 0) {
            angle = 180.0f - angle;
        }
        return angle;
    }
}