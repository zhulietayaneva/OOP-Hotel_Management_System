#pragma once
#include <iostream>

enum class RoomType { Invalid = 0, Single = 1, Double = 2, Suite = 3 };

std::ostream& operator<<(std::ostream& os, const RoomType& rt);

