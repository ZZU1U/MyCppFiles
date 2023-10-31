#include <iostream>
#include <vector>
#include <algorithm>

#define through(x) x.begin(), x.end()

using namespace std;

struct segment_dot {
    /*
     * This struct is used in other struct
     * Needed for our scan line method
     */
    int cord;
    bool is_start;

    bool operator<(const segment_dot& d) const {
        if (cord < d.cord) {
            return true;
        }

        if (cord == d.cord && is_start && !d.is_start) {
            return true;
        }

        return false;
    }
};

struct vertical_segment {
    /*
     * The structure of our vertical segments
     * It's end or start of rectangles
     */
    segment_dot start;
    segment_dot end;
    int x;
    bool is_start;

    bool operator<(const vertical_segment& s) const {
        if (x < s.x) {
            return true;
        }
        if (x == s.x && !is_start && s.is_start) {
            return true;
        }
        return false;
    }
};

// Equal operators

bool operator==(const segment_dot& dt1, const segment_dot& dt2) {
    return (dt1.cord == dt2.cord) && (dt1.is_start == dt2.is_start);
}

bool operator==(const vertical_segment& sgm1, const vertical_segment& sgm2) {
    return (sgm1.start == sgm2.start) && (sgm1.end == sgm2.end)
           && (sgm1.x == sgm2.x) && (sgm1.is_start == sgm2.is_start);
}

// Solution functions

int scan_line_length(vector<segment_dot> &map) {
    /*
     * Simple scan line realisation
     */

    sort(through(map));

    int total_length = 0;
    int balance = 0;
    int start;

    for (segment_dot dt : map) {
        if (!balance) {
            balance = 1;
            start = dt.cord;
            if (!dt.is_start) {
              cout << "There's an error 002";
              return 0;
            }
        } else {
            if (dt.is_start) {
                balance++;
            } else {
                balance--;
                if (!balance) {
                    total_length += dt.cord - start;
                }
            }
        }
    }

    return total_length;
}

unsigned int scan_line_area(vector<vertical_segment> &segments) {
    /*
     * Scab line method for calculating area of overlaying rectangles
     */

    sort(through(segments));

    unsigned int area = 0;
    vector<segment_dot> dots;
    int last_x = 0;
    unsigned int last_length = 0;

    for (vertical_segment sgm : segments) {
        if (sgm.is_start) {
            dots.push_back(sgm.start);
            dots.push_back(sgm.end);
        } else {
            bool deleted_end = false;
            bool deleted_start = false;
            unsigned int i = 0;

            while (!(deleted_end && deleted_start) && i < dots.size()) {
                if (!deleted_end && dots[i] == sgm.end) {
                    dots.erase(dots.begin() + i);
                    deleted_end = true;
                    continue;
                }
                if (!deleted_start && dots[i] == sgm.start) {
                    dots.erase(dots.begin() + i);
                    deleted_start = true;
                    continue;
                }
                i++;
            }
            if (!deleted_end || !deleted_start) {
                cout << "There's an Error 001\n";
                return 0;
            }
        }
        if (last_x != sgm.x) {
            if (last_length != 0){
              area += (sgm.x - last_x) * last_length;
            }
            last_x = sgm.x;
        }
        last_length = scan_line_length(dots);
        cout << "iter\n";
    }

    return area;
}

// Main program

int main() {
  int n, x1, y1, x2, y2;

  vector<vertical_segment> lines;

  cin >> n;

  for (int i = 0; i < n; i++) {
      cin >> x1 >> y1 >> x2 >> y2;

      auto first_start = segment_dot{y1, true};
      auto first_end = segment_dot{y2, false};
      auto second_start = segment_dot{y1, true};
      auto second_end = segment_dot{y2, false};

      auto start = vertical_segment{first_start, first_end, x1, true};
      auto end = vertical_segment{second_start, second_end, x2, false};

      lines.push_back(start);
      lines.push_back(end);
  }

  cout << scan_line_area(lines);
}
