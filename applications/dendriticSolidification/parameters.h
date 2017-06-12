// Parameter list for the coupled Allen-Cahn/Cahn-Hilliard example application
// All strictly numerical parameters should be set in this file

// =================================================================================
// Set the number of dimensions (1, 2, or 3 for a 1D, 2D, or 3D calculation)
// =================================================================================
#define problemDIM 2

// =================================================================================
// Set the length of the domain in all three dimensions
// =================================================================================
// Each axes spans from zero to the specified length
#define spanX 40.0
#define spanY 40.0
#define spanZ 40.0

// =================================================================================
// Set the element parameters
// =================================================================================
// The number of elements in each direction is 2^(refineFactor) * subdivisions
// For optimal performance, use refineFactor primarily to determine the element size
#define subdivisionsX 3
#define subdivisionsY 3
#define subdivisionsZ 3
#define refineFactor 7

// Set the polynomial degree of the element (suggested values: 1 or 2)
#define finiteElementDegree 3

// =================================================================================
// Set the adaptive mesh refinement parameters
// =================================================================================
// Set the flag determining if adaptive meshing is activated
#define hAdaptivity true

// Set the maximum and minimum level of refinement
#define maxRefinementLevel (refineFactor)
#define minRefinementLevel (refineFactor-6)

// Set the fields used to determine the refinement. Fields determined by the order
// declared in "equations.h", starting at zero
#define refineCriterionFields {1}

// Set the maximum and minimum value of the fields where the mesh should be refined
#define refineWindowMax {0.99999}
#define refineWindowMin {-0.99999}

// Set the number of time steps between remeshing operations
#define skipRemeshingSteps 500


// =================================================================================
// Set the time step parameters
// =================================================================================
// The size of the time step
#define timeStep (0.1e-4)

// The simulation ends when either timeFinal is reached or the number of time steps
// equals timeIncrements
#define timeFinal 2.0
#define timeIncrements 10000000

// =================================================================================
// Set the output parameters
// =================================================================================
// Each field in the problem will be output is writeOutput is set to "true"
#define writeOutput true

// Type of spacing between outputs ("EQUAL_SPACING", "LOG_SPACING", "N_PER_DECADE",
// or "LIST")
#define outputCondition "EQUAL_SPACING"

// Number of times the program outputs the fields (total number for "EQUAL_SPACING"
// and "LOG_SPACING", number per decade for "N_PER_DECADE", ignored for "LIST")
#define numOutputs 10

// User-defined list of time steps where the program should output. Only used if
// outputCondition is "LIST"
#define outputList {0}

// Status is printed to the screen every skipPrintSteps
#define skipPrintSteps 1000

// =================================================================================
// Set the flag determining if the total free energy is calculated for each output
// =================================================================================
#define calcEnergy false





