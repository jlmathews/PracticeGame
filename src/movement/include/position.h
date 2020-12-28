#pragma once

namespace PGame
{
    class Position
    {
        public:
            Position(int x, int y);

            int X() { return p_x; }
            int Y() { return p_y; }

            void X(int x) { p_x = x; }
            void Y(int y) { p_y = y; }

            void Print();

        private:
            int p_x, p_y;
    };
}

