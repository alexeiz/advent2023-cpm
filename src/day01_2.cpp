#include "common.hpp"
#include "puzzle_reg.hpp"
#include "day01.hpp"

using namespace std;
using namespace std::string_literals;

namespace {
/// Fix calibration document.
/// https://adventofcode.com/2023/day/1
puzzle_reg _{"1.2", []{
    auto const & calibration = day1::calibration;

    auto digit{R"(\d|one|two|three|four|five|six|seven|eight|nine)"s};
    map<string, int> digits{
        {"0"s, 0},
        {"1"s, 1},
        {"2"s, 2},
        {"3"s, 3},
        {"4"s, 4},
        {"5"s, 5},
        {"6"s, 6},
        {"7"s, 7},
        {"8"s, 8},
        {"9"s, 9},
        {"one"s, 1},
        {"two"s, 2},
        {"three"s, 3},
        {"four"s, 4},
        {"five"s, 5},
        {"six"s, 6},
        {"seven"s, 7},
        {"eight"s, 8},
        {"nine"s, 9},
    };

    regex calib2_re{fmt::format("({}).*({})", digit, digit), regex_constants::ECMAScript};  // search for 2 digits
    regex calib1_re{digit, regex_constants::ECMAScript};                                    // search for 1 digit

    int calib_tot = 0;
    for (auto && line: calibration)
    {
        cmatch m;
        if (regex_search(line, m, calib2_re))
            calib_tot += digits[m[1].str()] * 10 + digits[m[2].str()];
        else if (regex_search(line, m, calib1_re))
            calib_tot += digits[m[0].str()] * 11;
    }

    fmt::print(cout, "calibration: {}\n", calib_tot);
}};
}
