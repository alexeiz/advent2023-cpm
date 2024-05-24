#include "common.hpp"
#include "puzzle_reg.hpp"
#include "day03.hpp"

using namespace std;

namespace {
/// Find missing engine part.
/// https://adventofcode.com/2023/day/3
puzzle_reg _{"3.1", []{
    using namespace day3;

    array<int, 3> d{-1, 0, 1};
    char shift = 'A' - '0';

    // mark numbers adjacent to symbols
    for (auto & s: schematic)
        if (ispunct(s))
        {
            s = ' ';  // remove symbol
            int sy = (&s - schematic) / schem_cols;
            int sx = &s - schematic - sy * schem_cols;

            for (auto dx: d)
                for (auto dy: d)
                {
                    int px = sx + dx;
                    int py = sy + dy;

                    if (px >= 0 && px < schem_cols && py >= 0 && py < schem_rows)
                    {
                        char * p = schematic + py * schem_cols + px;
                        if (isdigit(*p))
                            *p += shift;
                    }
                }
        }

    istringstream in{schematic};
    int parts_tot = 0;
    string num_s;

    // read numbers and select marked ones
    while (in >> num_s)
    {
        bool select = false;
        for (auto & s: num_s)
        {
            if (!isdigit(s))
            {
                s -= shift;
                select = true;
            }
        }

        if (select)
            parts_tot += stoi(num_s);
    }

    fmt::print(cout, "engine parts: {}\n", parts_tot);
}};
}
