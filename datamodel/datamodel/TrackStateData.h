#ifndef TrackStateDATA_H
#define TrackStateDATA_H

//  Longitudinal impact parameter
// author: C. Bernet, B. Hegner



namespace fcc {
class TrackStateData {
public:
  double Location; /// Location on the track. (Radius?) 
  double Omega; /// Track curvature in cm. 
  double D0; /// Transverse impact parameter 
  double Z0; /// Longitudinal impact parameter 

};
} // namespace fcc

#endif
