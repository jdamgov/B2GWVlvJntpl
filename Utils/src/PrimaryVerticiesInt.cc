// -*- C++ -*-
//
// Package:    PrimaryVericiesInt
// Class:      PrimaryVericiesInt
// 
/**\class PrimaryVericiesInt PrimaryVericiesInt.cc RA2Classic/PrimaryVericiesInt/src/PrimaryVericiesInt.cc
 * 
 * Description: [one line class summary]
 * 
 * Implementation:
 *     [Notes on implementation]
 */
//
// Original Author:  Arne-Rasmus Draeger,68/111,4719,
//         Created:  Fri Apr 11 16:35:33 CEST 2014
// $Id$
//
//


// system include files
#include <memory>

// user include files
#include "FWCore/Framework/interface/Frameworkfwd.h"
#include "FWCore/Framework/interface/EDProducer.h"

#include "FWCore/Framework/interface/Event.h"
#include "FWCore/Framework/interface/MakerMacros.h"

#include "FWCore/ParameterSet/interface/ParameterSet.h"
#include "DataFormats/JetReco/interface/Jet.h"
#include "DataFormats/PatCandidates/interface/MET.h"
#include <DataFormats/Math/interface/deltaR.h>
#include "DataFormats/PatCandidates/interface/PackedGenParticle.h"
#include "DataFormats/Candidate/interface/Candidate.h"

//
// class declaration
//

class PrimaryVericiesInt : public edm::EDProducer {
public:
	explicit PrimaryVericiesInt(const edm::ParameterSet&);
	~PrimaryVericiesInt();
	
	static void fillDescriptions(edm::ConfigurationDescriptions& descriptions);
	
private:
	virtual void beginJob() ;
	virtual void produce(edm::Event&, const edm::EventSetup&);
	virtual void endJob() ;
	
	virtual void beginRun(edm::Run&, edm::EventSetup const&);
	virtual void endRun(edm::Run&, edm::EventSetup const&);
	virtual void beginLuminosityBlock(edm::LuminosityBlock&, edm::EventSetup const&);
	virtual void endLuminosityBlock(edm::LuminosityBlock&, edm::EventSetup const&);

  edm::EDGetTokenT<reco::VertexCollection> VertexCollectionToken_;
	
	// ----------member data ---------------------------
};

//
// constants, enums and typedefs
//


//
// static data member definitions
//

//
// constructors and destructor
//
PrimaryVericiesInt::PrimaryVericiesInt(const edm::ParameterSet& iConfig):
  VertexCollectionToken_(consumes<reco::VertexCollection>(iConfig.getParameter<edm::InputTag>("VertexCollection")))
{
	//register your produc
	
	produces<int>("");
	/* Examples
	 *   produces<ExampleData2>();
	 * 
	 *   //if do put with a label
	 *   produces<ExampleData2>("label");
	 * 
	 *   //if you want to put into the Run
	 *   produces<ExampleData2,InRun>();
	 */
	//now do what ever other initialization is needed
	
}


PrimaryVericiesInt::~PrimaryVericiesInt()
{
	
	// do anything here that needs to be done at desctruction time
	// (e.g. close files, deallocate resources etc.)
	
}


//
// member functions
//

// ------------ method called to produce the data  ------------
void
PrimaryVericiesInt::produce(edm::Event& iEvent, const edm::EventSetup& iSetup)
{
	using namespace edm;
	int nVertices=0;
	edm::Handle<reco::VertexCollection> vertices;
	iEvent.getByToken(VertexCollectionToken_,vertices);
	if( vertices.isValid() ) {
		nVertices = vertices->size();
	}
	else std::cout<<"Warning VertexCollection Tag not valid "<<std::endl;
	std::auto_ptr<int> htp(new int(nVertices));
	iEvent.put(htp);
	
}

// ------------ method called once each job just before starting event loop  ------------
void 
PrimaryVericiesInt::beginJob()
{
}

// ------------ method called once each job just after ending the event loop  ------------
void 
PrimaryVericiesInt::endJob() {
}

// ------------ method called when starting to processes a run  ------------
void 
PrimaryVericiesInt::beginRun(edm::Run&, edm::EventSetup const&)
{
}

// ------------ method called when ending the processing of a run  ------------
void 
PrimaryVericiesInt::endRun(edm::Run&, edm::EventSetup const&)
{
}

// ------------ method called when starting to processes a luminosity block  ------------
void 
PrimaryVericiesInt::beginLuminosityBlock(edm::LuminosityBlock&, edm::EventSetup const&)
{
}

// ------------ method called when ending the processing of a luminosity block  ------------
void 
PrimaryVericiesInt::endLuminosityBlock(edm::LuminosityBlock&, edm::EventSetup const&)
{
}

// ------------ method fills 'descriptions' with the allowed parameters for the module  ------------
void
PrimaryVericiesInt::fillDescriptions(edm::ConfigurationDescriptions& descriptions) {
	//The following says we do not know what parameters are allowed so do no validation
	// Please change this to state exactly what you do use, even if it is no parameters
	edm::ParameterSetDescription desc;
	desc.setUnknown();
	descriptions.addDefault(desc);
}

//define this as a plug-in
DEFINE_FWK_MODULE(PrimaryVericiesInt);
