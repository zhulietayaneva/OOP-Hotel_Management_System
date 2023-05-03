#include "Roomtype.h"
#include <iostream>

std::ostream& operator<<(std::ostream& os, const RoomType& rt) {
    switch (rt) {
    case RoomType::Invalid:
        os << "Invalid";
        break;
    case RoomType::Single:
        os << "Single";
        break;
    case RoomType::Double:
        os << "Double";
        break;
    case RoomType::Suite:
        os << "Suite";
        break;
    }
    return os;
}
