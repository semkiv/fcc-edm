#ifndef GenVertex_H
#define GenVertex_H
#include "GenVertexData.h"
#include "Point.h"

#include <vector>
#include "podio/ObjectID.h"

//  Time coordinate in cm
// author: C. Bernet, B. Hegner

//forward declarations


#include "GenVertexConst.h"
#include "GenVertexObj.h"

namespace fcc {

class GenVertexCollection;
class GenVertexCollectionIterator;
class ConstGenVertex;

class GenVertex {

  friend GenVertexCollection;
  friend GenVertexCollectionIterator;
  friend ConstGenVertex;

public:

  /// default constructor
  GenVertex();
    GenVertex(fcc::Point Position,double Ctau);

  /// constructor from existing GenVertexObj
  GenVertex(GenVertexObj* obj);
  /// copy constructor
  GenVertex(const GenVertex& other);
  /// copy-assignment operator
  GenVertex& operator=(const GenVertex& other);
  /// support cloning (deep-copy)
  GenVertex clone() const;
  /// destructor
  ~GenVertex();

  /// conversion to const object
  operator ConstGenVertex () const;

public:

  const fcc::Point& Position() const;
  const double& Ctau() const;

  fcc::Point& Position();
  void Position(class fcc::Point value);
  void Ctau(double value);


  /// check whether the object is actually available
  bool isAvailable() const;
  /// disconnect from GenVertexObj instance
  void unlink(){m_obj = nullptr;}

  bool operator==(const GenVertex& other) const {
       return (m_obj==other.m_obj);
  }

  bool operator==(const ConstGenVertex& other) const;

// less comparison operator, so that objects can be e.g. stored in sets.
//  friend bool operator< (const GenVertex& p1,
//       const GenVertex& p2 );

  const podio::ObjectID getObjectID() const;

private:
  GenVertexObj* m_obj;

};

} // namespace fcc

#endif
