#ifndef INCLUDE_ADAPTIVEREFINEMENT_H_
#define INCLUDE_ADAPTIVEREFINEMENT_H_

#include <deal.II/base/quadrature_lib.h>
#include <deal.II/distributed/grid_refinement.h>
#include <deal.II/distributed/solution_transfer.h>
#include <deal.II/distributed/tria.h>
#include <deal.II/dofs/dof_handler.h>
#include <deal.II/fe/fe_system.h>
#include <deal.II/fe/fe_values.h>
#include <deal.II/lac/la_parallel_vector.h>

#include <core/fields.h>
#include <core/userInputParameters.h>

using namespace dealii;

/**
 * A class that handles the determination and application of AMR criterion.
 */
template <int dim, int degree>
class AdaptiveRefinement
{
public:
  /**
   * Default constructor.
   */
  AdaptiveRefinement(
    const userInputParameters<dim>                                    &_userInputs,
    parallel::distributed::Triangulation<dim>                         &_triangulation,
    std::vector<Field<dim>>                                           &_fields,
    std::vector<dealii::LinearAlgebra::distributed::Vector<double> *> &_solutionSet,
    std::vector<parallel::distributed::SolutionTransfer<
      dim,
      dealii::LinearAlgebra::distributed::Vector<double>> *>          &_soltransSet,
    std::vector<FESystem<dim> *>                                      &_FESet,
    std::vector<DoFHandler<dim> *>                 &_dofHandlersSet_nonconst,
    std::vector<const AffineConstraints<double> *> &_constraintsDirichletSet,
    std::vector<const AffineConstraints<double> *> &_constraintsOtherSet);

  /**
   * Perform the adaptive refinement based on the specified AMR criterion. Also apply
   * constraints when in the 0th timestep.
   */
  void
  do_adaptive_refinement(unsigned int _currentIncrement);

  /**
   * Refine the triangulation and transfer the solution.
   */
  void
  refine_grid();

protected:
  /**
   * Mark cells to be coarsened or refined based on the specified AMR criterion.
   */
  void
  adaptive_refinement_criterion();

private:
  userInputParameters<dim> userInputs;

  parallel::distributed::Triangulation<dim> &triangulation;

  std::vector<Field<dim>> &fields;

  std::vector<dealii::LinearAlgebra::distributed::Vector<double> *> &solutionSet;

  std::vector<parallel::distributed::SolutionTransfer<
    dim,
    dealii::LinearAlgebra::distributed::Vector<double>> *> &soltransSet;

  std::vector<FESystem<dim> *> &FESet;

  std::vector<DoFHandler<dim> *> &dofHandlersSet_nonconst;

  std::vector<const AffineConstraints<double> *> &constraintsDirichletSet;

  std::vector<const AffineConstraints<double> *> &constraintsOtherSet;
};

#endif