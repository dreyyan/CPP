#include <cmath>
#include <iostream>
using namespace std;
// CC 203 - Exercise #1 [#9]
/* ------------------------------------------
   Line Equation:
   ax + by = c; (a & b != 0 || a, b, & c ∈ ℝ)

   Determine the Slope:
 *  a = 0 >> horizontal line [slope = 0]
 *  b = 0 >> vertical line [undefined slope]
 * b != 0 >> -a / b

   Parallel:
 * Same slope
 * Both are vertical lines

   Perpendicular:
 * 1 Horizontal & 1 Vertical
 * Product of Slopes = -1
------------------------------------------ */
static int test_case_counter = 0;

struct Line {
    double a, b, c; // Coefficients of the first line
    Line(double a, double b, double c) : a(a), b(b), c(c) {} // Parameterized Constructor
};

class lineType {
    Line line1, line2; // For comparing the 2 lines
    double slope1, slope2; // To store slopes of each line
public:
    lineType(double a1, double b1, double c1, double a2, double b2, double c2)
    : line1(a1, b1, c1), line2(a2, b2, c2) {} // Parameterized Constructor

    /* UTILS */
    void display_format(size_t length) {
        for (size_t i = 0; i < length; ++i) {
            cout << '-';
        } cout << '\n';
    }

    /* METHODS */
    void print_test_case(double a1, double b1, double c1, double a2, double b2, double c2) {
        cout << "    [ TEST CASE # " << ++test_case_counter << "]\n";
        display_format(25);
        cout << "Line 1: (" << a1 << ", " << b1 << ", " << c1 << ")\n";
        cout << "Line 2: (" << a2 << ", " << b2 << ", " << c2 << ")\n";
        display_format(18);

    }
    // [a] If a line is non-vertical, determine its slope
    double compute_for_slope(Line& line) {
        double slope;

        cout << "Slope: ";
        if (line.a == 0) {
            slope = 0;
            cout << "Horizontal Line(Slope = 0)";
        } else if (line.b == 0) {
            slope = numeric_limits<double>::quiet_NaN();
            cout << "Vertical Line(Slope = Undefined)";
        } else {
            slope = -line.a / line.b;
            cout << slope;
        } cout << '\n';
        return slope;
    }

    // [b] Determine if two lines are equal
    void check_if_equal_lines() {
        // Check if coefficient values are equal
        if (line1.a == line2.a && line1.b == line2.b && line1.c == line2.c) {
            cout << "* Equal Lines";
            return;
        }

        // Check if proportional values
        if (line1.a * line2.b == line1.b * line2.a
            && line1.a * line2.c == line1.c * line2.a
            && line1.b * line2.c == line1.c * line2.b) {
            cout << "* Equal Lines";
        } else {
            cout << "* Not Equal Lines";
        } cout << '\n';
    }
    // [c] Determine if two lines are parallel (same slope / vertical lines)
    void check_if_parallel_lines() {
        if (slope1 == slope2 || (isnan(slope1) && isnan(slope2))) {
            cout << "* Parallel Lines\n";
        } else {
            cout << "* Non-parallel Lines\n";
            check_point_of_intersection();
        }
    }
    // [d] Determine if two lines are perpendicular
    void check_if_perpendicular_lines() {
        // If line1 is horizontal & line2 is vertical or vv.
        if ((line1.a == 0 && line2.b == 0) || (line1.b == 0 && line2.a == 0)) {
            cout << "* Perpendicular Lines";
        } else if ((!isnan(slope1) && !isnan(slope2)) && (slope1 * slope2 == -1)) {
            cout << "* Perpendicular Lines";
        } else {
            cout << "* Non-perpendicular Lines";
        } cout << '\n';
    }
    // [e] If two lines are non-parallel, find the point of intersection
    void check_point_of_intersection() {
        double d = line1.a * line2.b - line2.a * line1.b;

        if (d == 0) {
            cout << "* No unique intersection\n";
            return;
        }

        double x = (line1.c * line2.b - line2.c * line1.b) / d;
        double y = (line1.a * line2.c - line2.a * line1.c) / d;

        cout << "* Intersects at: (" << x << ", " << y << ")\n";
    }
    // Solve
    void solve_line_equation() {
        if (line1.b != 0) slope1 = compute_for_slope(line1);
        if (line2.b != 0) slope2 = compute_for_slope(line2);
        display_format(18);

        check_if_equal_lines();
        check_if_parallel_lines();
        check_if_perpendicular_lines();
        display_format(25); cout << '\n';
    }
};

int main() {
    // Test Case #1
    lineType test_case_one(2, 3, 6, 4, 6, 12);
    test_case_one.print_test_case(2, 3, 6, 4, 6, 12);
    test_case_one.solve_line_equation();
    // Test Case #2
    lineType test_case_two(2, 3, 6, 4, 6, 15);
    test_case_two.print_test_case(2, 3, 6, 4, 6, 15);
    test_case_two.solve_line_equation();
    // Test Case #3
    lineType test_case_three(1, 1, 4, 1, -1, 2);
    test_case_three.print_test_case(1, 1, 4, 1, -1, 2);
    test_case_three.solve_line_equation();
    cout << "Press 'Enter' to continue...";
    cin.get();
    return 0;
}