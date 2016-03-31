#ifndef SimCaloHitMCParticleAssociation_H
#define SimCaloHitMCParticleAssociation_H
#include "SimCaloHitMCParticleAssociationData.h"

#include <vector>
#include "podio/ObjectID.h"

//  Fraction of the particle energy used in the hit.
// author: C. Bernet, B. Hegner

//forward declarations
namespace fcc {
class SimCaloHit;
class ConstSimCaloHit;
class MCParticle;
class ConstMCParticle;
}


#include "SimCaloHitMCParticleAssociationConst.h"
#include "SimCaloHitMCParticleAssociationObj.h"

namespace fcc {

class SimCaloHitMCParticleAssociationCollection;
class SimCaloHitMCParticleAssociationCollectionIterator;
class ConstSimCaloHitMCParticleAssociation;

class SimCaloHitMCParticleAssociation {

  friend SimCaloHitMCParticleAssociationCollection;
  friend SimCaloHitMCParticleAssociationCollectionIterator;
  friend ConstSimCaloHitMCParticleAssociation;

public:

  /// default constructor
  SimCaloHitMCParticleAssociation();
    SimCaloHitMCParticleAssociation(double Fraction);

  /// constructor from existing SimCaloHitMCParticleAssociationObj
  SimCaloHitMCParticleAssociation(SimCaloHitMCParticleAssociationObj* obj);
  /// copy constructor
  SimCaloHitMCParticleAssociation(const SimCaloHitMCParticleAssociation& other);
  /// copy-assignment operator
  SimCaloHitMCParticleAssociation& operator=(const SimCaloHitMCParticleAssociation& other);
  /// support cloning (deep-copy)
  SimCaloHitMCParticleAssociation clone() const;
  /// destructor
  ~SimCaloHitMCParticleAssociation();

  /// conversion to const object
  operator ConstSimCaloHitMCParticleAssociation () const;

public:

  const double& Fraction() const;
  const fcc::ConstSimCaloHit Hit() const;
  const fcc::ConstMCParticle Particle() const;

  void Fraction(double value);
  void Hit(fcc::ConstSimCaloHit value);
  void Particle(fcc::ConstMCParticle value);


  /// check whether the object is actually available
  bool isAvailable() const;
  /// disconnect from SimCaloHitMCParticleAssociationObj instance
  void unlink(){m_obj = nullptr;}

  bool operator==(const SimCaloHitMCParticleAssociation& other) const {
       return (m_obj==other.m_obj);
  }

  bool operator==(const ConstSimCaloHitMCParticleAssociation& other) const;

// less comparison operator, so that objects can be e.g. stored in sets.
//  friend bool operator< (const SimCaloHitMCParticleAssociation& p1,
//       const SimCaloHitMCParticleAssociation& p2 );

  const podio::ObjectID getObjectID() const;

private:
  SimCaloHitMCParticleAssociationObj* m_obj;

};

} // namespace fcc

#endif
