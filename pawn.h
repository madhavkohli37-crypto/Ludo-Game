#include"turn.h"
class Pawn {
public:
    int position;      // -1 = in base, 0-56 = track/home stretch
    bool isHome;       // true if reached center H (position 56)
    bool isActive;     // true if on track

    Pawn() {
        position = -1;
        isHome = false;
        isActive = false;
    }
};
