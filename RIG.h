#ifndef RIG_
#define RIG_

#include <ompl/base/Planner.h>
#include <ompl/base/OptimizationObjective.h>
#include <ompl/base/StateSampler.h>

class RIG : ompl::base::Planner {
public:
    RIG(const ompl::base::SpaceInformationPtr &si);
    virtual ~RIG();

    virtual ompl::base::PlannerStatus solve(const ompl::base::PlannerTerminationCondition &ptc);
};

#endif
