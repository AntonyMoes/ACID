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

b2Vec2 ACIDMath::get_b2Vec_from_angle(float angle) {
    while (angle < 0) {
        angle += 360;
    }

    while (angle > 360) {
        angle -= 360;
    }

    switch (static_cast<int>(angle)) {
        case 0:
            return b2Vec2(1, 0);
        case 90:
            return b2Vec2(0, 1);
        case 180:
            return b2Vec2(-1, 0);
        case 270:
            return b2Vec2(0, -1);
        default:
            auto tangens = tan(angle);
            float x = 1;
            if (angle > 90 && angle < 270) {
                x = -1;
            }

            float y = tangens*x;
            if (angle > 180 && angle < 360) {
                y *= -1;
            }
            auto vec = b2Vec2(x, y);
            ACIDMath::get_unit_b2Vec2(vec);

            return vec;
    }
}

sf::Vector2f ACIDMath::get_Vector2f_from_angle(float angle) {
    while (angle < 0) {
        angle += 360;
    }

    while (angle > 360) {
        angle -= 360;
    }

    switch (static_cast<int>(angle)) {
        case 0:
            return sf::Vector2f(1, 0);
        case 90:
            return sf::Vector2f(0, 1);
        case 180:
            return sf::Vector2f(-1, 0);
        case 270:
            return sf::Vector2f(0, -1);
        default:
            auto tangens = tan(angle);
            float x = 1;
            if (angle > 90 && angle < 270) {
                x = -1;
            }

            float y = tangens*x;
            auto vec = sf::Vector2f(x, y);
            ACIDMath::get_unit_Vector2f(vec);

            return vec;
    }
}
