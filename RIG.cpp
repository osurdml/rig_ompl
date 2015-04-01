#include "RIG.h"

RIG::RIG(const ompl::base::SpaceInformationPtr &si) :
    ompl::base::Planner(si, "RIG")
{
}

RIG::~RIG()
{
}

ompl::base::PlannerStatus RIG::solve(const ompl::base::PlannerTerminationCondition &ptc)
{
    // Ensure that the planner is set up correctly (at least one input state and a
    // goal are set).
    checkValidity();

    ompl::base::Goal *goal = pdef_->getGoal().get();

    // Add all of the start states to the graph.
    while (const ompl::base::State *st = pis_.nextStart()) {
      Motion *motion = new Motion(si_);
      si_->copyState(motion->state, st);
      nn_->add(motion);
    }

    if (nn_->size() == 0) {
      OMPL_ERROR("%s: There are no start states!", getName().c_str());
      return ompl::base::PlannerStatus::INVALID_START;
    }

    while (ptc() == false) {
    }

    return ompl::base::PlannerStatus::APPROXIMATE_SOLUTION;
}
