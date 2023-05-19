//
//  Created by Alex on 4/11/23.
//

#ifndef INC_11_4_LAB_SOLVING_MISSIONARIES_CANNIBALS_GAMESTATE_H
#define INC_11_4_LAB_SOLVING_MISSIONARIES_CANNIBALS_GAMESTATE_H

#include <iostream>

using std::cout;
using std::endl;
using std::ostream;
using std::string;

class GameState {
public:
    GameState() : missionaries(0), cannibals(0), boatIsLeft(false) {}

    GameState(int missionaries, int cannibals, bool boatIsLeft) : missionaries(missionaries), cannibals(cannibals),
                                                                  boatIsLeft(boatIsLeft) {}

    [[nodiscard]] int getMissionariesLeft() const { return missionaries; }

    [[nodiscard]] int getCannibalsLeft() const { return cannibals; }

    [[nodiscard]] bool isValidState() const {
        // Missionaries outnumber cannibals on right side
        if (missionaries < cannibals && missionaries > 0) {
            return false;
        }
        // Missionaries outnumber Cannibals left side
        if (3 - missionaries < 3 - cannibals && 3 - missionaries > 0) {
            return false;
        }
        if (missionaries < 0 || cannibals < 0 || missionaries > 3 || cannibals > 3) {
            return false;
        }
        return true;
    }

    [[nodiscard]] bool isBoatLeft() const {
        return boatIsLeft;
    }

    bool operator==(GameState other) const {
        return other.missionaries == missionaries && other.cannibals == cannibals && other.boatIsLeft == boatIsLeft;
    }

    bool operator!=(GameState other) {
        return !(other == *this);
    }

    friend ostream &operator<<(ostream &out, GameState &state) {

        for (int i = 0; i < state.missionaries; i++) {
            out << "M";
        }

        for (int i = 0; i < state.cannibals; i++) {
            out << "C";
        }

        if (state.boatIsLeft) {
            out << " B~~~~~~~ ";
        } else {
            out << " ~~~~~~~B ";
        }
        for (int i = 0; i < (3 - state.missionaries); i++) {
            out << "M";
        }
        for (int i = 0; i < (3 - state.cannibals); i++) {
            out << "C";
        }
        return out;
    }

    [[nodiscard]] bool isNeighbor(GameState other) const {
        if (boatIsLeft == other.boatIsLeft) {
            return false;
        }
        int m = abs(missionaries - other.missionaries);
        int c = abs(cannibals - other.cannibals);
        int boat = m + c;
        if (boat > 2) {
            return false;
        }

        return true;
    }

private:
    int missionaries;
    int cannibals;
    bool boatIsLeft;

};

#endif //INC_11_4_LAB_SOLVING_MISSIONARIES_CANNIBALS_GAMESTATE_H
