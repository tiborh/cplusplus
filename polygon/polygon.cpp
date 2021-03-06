#include "polygon.h"

Polygon::Polygon(int npoints, double coords[][NCOORDS]) {
  assert(npoints > MINPOINTS);
  points = new Point[npoints];
  num_of_points = npoints;
  for (int i = 0; i < npoints; ++i)
    points[i].set(Point(coords[i][0],coords[i][1]));
}

void Polygon::add_lines(int nlines, int cons[][NCOORDS]) {
  assert(nlines > MINLINES);
  lines = new Line[nlines];
  num_of_lines = nlines;
  for (int i = 0; i < nlines; ++i)
    lines[i].set(points[cons[i][0]],points[cons[i][1]]);
}

string Polygon::get_points_str() {
  ostringstream os;
  for (int i = 0; i < num_of_points; ++i) {
    os << i << ": " << points[i].print();
    if (i < num_of_points-1)
      os << ", ";
  }
  os << '\n';
  return os.str();
}

string Polygon::get_lines_str() {
  ostringstream os;
  for (int i = 0; i < num_of_lines; ++i) {
    os << "\t" << i << ": " << lines[i].print();
    if (i < num_of_lines-1)
      os << ",";
    os << '\n';
  }
  return os.str();
}
