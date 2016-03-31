#ifndef VertexDATA_H
#define VertexDATA_H

//  Stored flags
// author: C. Bernet, B. Hegner

#include "Point.h"


namespace fcc {
class VertexData {
public:
  double Chi2; /// chi2 returned by the vertex fit 
  unsigned Ndf; /// Number of degrees of freedom of the vertex fit 
  fcc::Point Position; /// Vertex position in cm 
  unsigned Bits; /// Stored flags 

};
} // namespace fcc

#endif
