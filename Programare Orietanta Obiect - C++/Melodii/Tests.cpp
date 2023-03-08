//
// Created by Lorena on 20.06.2022.
//

#include <string>
#include <cassert>
#include "Tests.h"
#include "Domain.h"
#include "Repository.h"
#include "Service.h"

void testAll() {
    int id = 3;
    std::string titlu = "Inevitabil va fi bine";
    std::string artist = "Andra Maruta";
    std::string gen = "pop";
    Melodie m{id, titlu, artist, gen};
    assert(m.getId() == id);
    assert(m.getTitlu() == titlu);
    assert(m.getArtist() == artist);
    assert(m.getGen() == gen);

    std::string path = "../melodiiTest.txt";
    Repository repository{path};
    assert(repository.getMelodii().size() == 1);
    assert(repository.adaugaMelodie(m) == true);
    assert(repository.adaugaMelodie(m) == false);
    assert(repository.getMelodii().size() == 2);
    assert(repository.stergeMelodie(id) == true);
    assert(repository.getMelodii().size() == 1);
    assert(repository.stergeMelodie(id) == false);
    assert(repository.getMelodii().size() == 1);
    Service service{repository};
    assert(service.getMelodii().size()==1);
    assert(service.adaugaMelodie(id, titlu, artist, gen)==true);
    assert(service.getMelodii().size()==2);
    assert(service.adaugaMelodie(id, titlu, artist, gen)==false);
    assert(service.getMelodii().size()==2);
    assert(service.stergeMelodie(id)==true);
    assert(service.getMelodii().size()==1);
    assert(service.stergeMelodie(id)== false);
    assert(service.getMelodii().size()==1);
    assert(service.acelasiAutor(titlu)==0);
    assert(service.acelasiGen(gen)==1);
    assert(service.acelasiGen("pop")==1);
}