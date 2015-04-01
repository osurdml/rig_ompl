#ifndef RIG_
#define RIG_

#include <ompl/geometric/planners/PlannerIncludes.h>
#include <ompl/datastructures/NearestNeighbors.h>

class RIG : ompl::base::Planner {
public:
    RIG(const ompl::base::SpaceInformationPtr &si);
    virtual ~RIG();

    virtual ompl::base::PlannerStatus solve(const ompl::base::PlannerTerminationCondition &ptc);

protected:
    /** \brief Representation of a motion

      This only contains pointers to parent motions as we
      only need to go backwards in the tree. */
    class Motion
    {
    public:
        Motion() : state(NULL), parent(NULL)
        {
        }

        /** \brief Constructor that allocates memory for the state */
        Motion(const ompl::base::SpaceInformationPtr &si) : state(si->allocState()), parent(NULL)
        {
        }

        ~Motion()
        {
        }

        /** \brief The state contained by the motion */
        ompl::base::State       *state;

        /** \brief The parent motion in the exploration tree */
        Motion            *parent;

    };

private:
    ompl::base::StateSamplerPtr sampler_;
    ompl::base::OptimizationObjectivePtr obj_;

    boost::shared_ptr<ompl::NearestNeighbors<Motion *> > nn_;
};

#endif
