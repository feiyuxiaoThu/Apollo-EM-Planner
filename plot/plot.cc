#include "plot/plot.h"

namespace plt = matplotlibcpp;

Plot::Plot() {}

void Plot::PlotRoutingPath(std::vector<MapPoint> routing_path_points,
                           const std::string &color) {
  std::vector<double> x, y;
  for (const auto point : routing_path_points) {
    x.push_back(point.x);
    y.push_back(point.y);
  }
  plt::plot(x, y, color);

  // std::vector<double> x = {1, 2, 3, 4};
  // std::vector<double> y = {1, 4, 9, 16};

  // plt::plot(x, y);
  // plt::show();
}
void Plot::PlotReferenceLine(ReferenceLine reference_line,
                             const std::string &color) {
  std::vector<double> x, y;
  for (const auto point : reference_line.reference_points()) {
    x.push_back(point.x);
    y.push_back(point.y);
  }
  plt::plot(x, y, color);

  // std::vector<double> x = {1, 2, 3, 4};
  // std::vector<double> y = {1, 4, 9, 16};

  // plt::plot(x, y);
  // plt::show();
}

void Plot::PlotTrajetory(Trajectory trajectory, const std::string &color) {

  std::vector<double> x, y;
  for (const auto point : trajectory.trajectory_points()) {
    x.push_back(point.x);
    y.push_back(point.y);
  }
  plt::plot(x, y, color);
}

void Plot::PlotSLPath(std::vector<SLPoint> sl_path_points,
                      const std::string &color) {
  std::vector<double> x, y;
  for (const auto point : sl_path_points) {
    x.push_back(point.s);
    y.push_back(point.l);
  }
  plt::plot(x, y, color);

  // std::vector<double> x = {1, 2, 3, 4};
  // std::vector<double> y = {1, 4, 9, 16};

  // plt::plot(x, y);
  // plt::show();
}

void Plot::PlotObs(ObstacleInfo obs, const std::string &color) {
  std::vector<double> x, y;
  x.push_back(obs.x + 2);
  y.push_back(obs.y + 1);

  x.push_back(obs.x - 2);
  y.push_back(obs.y + 1);

  x.push_back(obs.x - 2);
  y.push_back(obs.y - 1);

  x.push_back(obs.x + 2);
  y.push_back(obs.y - 1);

  std::map<std::string, std::string> keywords;
  keywords["color"] = "grey";
  plt::fill(x, y, keywords);
}