#include "RootWriter.hh" 

#include <stdexcept>

RootWriter* RootWriter::instance = 0;

RootWriter::RootWriter()
{
    if (instance)
        throw std::logic_error("RootWriter already exists");

    instance = this; 

    file = nullptr;
    tree = nullptr;
}

void RootWriter::createRootFile( std::string fileName)
{
    file = new TFile(fileName.c_str(), "RECREATE");
    tree = new TTree("tree", "tree");

    tree->Branch("eventNumber" , &eventNumber) ;
	tree->Branch("nHit" , &nHit) ;
	tree->Branch("primaryEnergy" , &primaryEnergy) ;
	tree->Branch("primaryPos" , &primaryPos , "primaryPos[3]/D") ;
	tree->Branch("depositedEnergy" , &depositedEnergy) ;
	tree->Branch("stepLength" , "std::vector<double>" , &stepLength) ;
    tree->Branch("stepTime" , "std::vector<double>" , &stepTime) ;
}

void RootWriter::closeRootFile()
{
    file->cd() ;
	tree->Write("tree") ;
	file->Purge() ;
    file->Close() ;
}

void RootWriter::fillTree()
{
	tree->Fill() ;
}