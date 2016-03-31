#ifndef TrackState_H
#define TrackState_H
#include "TrackStateData.h"

#include <vector>
#include "podio/ObjectID.h"

//  Longitudinal impact parameter
// author: C. Bernet, B. Hegner

//forward declarations


#include "TrackStateConst.h"
#include "TrackStateObj.h"

namespace fcc {

class TrackStateCollection;
class TrackStateCollectionIterator;
class ConstTrackState;

class TrackState {

  friend TrackStateCollection;
  friend TrackStateCollectionIterator;
  friend ConstTrackState;

public:

  /// default constructor
  TrackState();
    TrackState(double Location,double Omega,double D0,double Z0);

  /// constructor from existing TrackStateObj
  TrackState(TrackStateObj* obj);
  /// copy constructor
  TrackState(const TrackState& other);
  /// copy-assignment operator
  TrackState& operator=(const TrackState& other);
  /// support cloning (deep-copy)
  TrackState clone() const;
  /// destructor
  ~TrackState();

  /// conversion to const object
  operator ConstTrackState () const;

public:

  const double& Location() const;
  const double& Omega() const;
  const double& D0() const;
  const double& Z0() const;

  void Location(double value);
  void Omega(double value);
  void D0(double value);
  void Z0(double value);


  /// check whether the object is actually available
  bool isAvailable() const;
  /// disconnect from TrackStateObj instance
  void unlink(){m_obj = nullptr;}

  bool operator==(const TrackState& other) const {
       return (m_obj==other.m_obj);
  }

  bool operator==(const ConstTrackState& other) const;

// less comparison operator, so that objects can be e.g. stored in sets.
//  friend bool operator< (const TrackState& p1,
//       const TrackState& p2 );

  const podio::ObjectID getObjectID() const;

private:
  TrackStateObj* m_obj;

};

} // namespace fcc

#endif
