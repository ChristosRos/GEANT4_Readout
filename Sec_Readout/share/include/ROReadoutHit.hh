#ifndef ROReadoutHit_h
#define ROReadoutHit_h 1

#include "G4VHit.hh"
#include "G4THitsCollection.hh"
#include "G4Allocator.hh" 
#include "G4ThreeVector.hh"
#include "tls.hh" 


class ROReadoutHit : public G4VHit
{
    public: 
    ROReadoutHit(); 
    ROReadoutHit(const ROReadoutHit&);
    virtual ~ROReadoutHit(); 

    //operators
    const ROReadoutHit& operator=(const ROReadoutHit&);
    G4int operator==(const ROReadoutHit&) const; 

    inline void* operator new(size_t); 
    inline void  operator delete(void*); 

    //methods from base class 
    virtual void Draw(); 
    virtual void Print(); 

    //Set methods 
    void SetTrackID  (G4int track)      { fTrackID = track; }; 
    void SetReadoutNb(G4int read)       { fReadoutNb = read; }; 
    void SetEdep     (G4double de)      { fEdep = de; }; 
    void SetPos      (G4ThreeVector xyz){ fPos = xyz; };

    private: 

        G4int         fTrackID; 
        G4int         fReadoutNb;
        G4double      fEdep; 
        G4ThreeVector fPos; 
};

typedef G4THitsCollection<ROReadoutHit> ROReadoutHitsCollection; 

extern G4ThreadLocal G4Allocator<ROReadoutHit>* ROReadoutHitAllocator;

inline void* ROReadoutHit::operator new(size_t)
{
  if(!ROReadoutHitAllocator)
      ROReadoutHitAllocator = new G4Allocator<ROReadoutHit>;
  return (void *) ROReadoutHitAllocator->MallocSingle();
}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

inline void ROReadoutHit::operator delete(void *hit)
{
  ROReadoutHitAllocator->FreeSingle((ROReadoutHit*) hit);
}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

#endif