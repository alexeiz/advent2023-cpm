#include "common.hpp"
#include "puzzle_reg.hpp"
#include "day03.hpp"

using namespace std;

namespace {
/// Find missing engine part.
/// https://adventofcode.com/2023/day/3
puzzle_reg _{"3.2", []{
    using namespace day3;

    map<pair<int, int>, vector<int>> gears;

    // find gears
    for (auto & s: schematic)
        if (ispunct(s))
        {
            if (s == '*')
            {
                int sy = (&s - schematic) / schem_cols;
                int sx = &s - schematic - sy * schem_cols;
                gears[pair{sx, sy}];
            }

            s = ' ';  // remove symbol
        }

    // read part numbers and find adjacent gears
    auto find_gear = [&gears](int x, int y, int num) {
        if (auto it = gears.find(pair{x, y}); it != gears.end())
            it->second.push_back(num);
    };

    istringstream in{schematic};
    string num_s;

    while (in >> num_s)
    {
        auto num = stoi(num_s);
        int pos = int(in.tellg()) - 1;  // pos at the last char of num
        int ny = pos / schem_cols;
        int nx = pos - ny * schem_cols;

        for (int x = nx - num_s.size(); x != nx + 2; ++x)
        {
            find_gear(x, ny - 1, num);
            find_gear(x, ny + 1, num);
        }

        find_gear(nx - num_s.size(), ny, num);
        find_gear(nx + 1, ny, num);
    }

    // find all gears with two adjacent parts
    int parts_tot = 0;
    for (auto & [pos, parts]: gears)
    {
        if (parts.size() == 2)
            parts_tot += parts[0] * parts[1];
    }

    fmt::print(cout, "engine parts: {}\n", parts_tot);
}};
}
