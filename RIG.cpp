#include "RIG.h"

RIG::RIG(const ompl::base::SpaceInformationPtr &si) : ompl::base::Planner(si, "RIG")
{
}

RIG::~RIG()
{
}

ompl::base::PlannerStatus RIG::solve(const ompl::base::PlannerTerminationCondition &ptc)
{
  checkValidity();

  return ompl::base::PlannerStatus::APPROXIMATE_SOLUTION;
}
