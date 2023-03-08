import unittest

from Repository.repozitory import Repository_persoane_file, Repository_evenimente_file, \
    Repository_asignare_persoana_eveniment_file
from Service.service import Service_persoane, Service_evenimente, Service_asignare_pers_event
from Validator.validators import Validare_persoana, Validare_evenimente, Validare_asignare


class BlackBoxTesting(unittest.TestCase):
    def test_lista_evenimente_persoana(self):
        #validare = Validare_persoana()
        repo_pers = Repository_persoane_file("test_persoane.txt")
        #serv_p = Service_persoane(validare, repo_pers)
        # id_p = '2'
        # nume = 'Adrian'
        # adresa = 'Navodari'
        # serv_p.adaugare_persoana(id_p, nume, adresa)
        #
        # id_p = '3'
        # nume = 'Ioan'
        # adresa = 'Constanta'
        # serv_p.adaugare_persoana(id_p, nume, adresa)
        #
        # id_p = '4'
        # nume = 'Ninel'
        # adresa = 'Dolhasca'
        # serv_p.adaugare_persoana(id_p, nume, adresa)
        #
        # id_p='5'
        # nume = 'Ana-Maria'
        # adresa = 'Bacau'
        # serv_p.adaugare_persoana(id_p, nume, adresa)

        #validaree = Validare_evenimente()
        repo_events = Repository_evenimente_file("test_evenimente.txt")
        #serv_e = Service_evenimente(validaree, repo_events)

        # id_e = '2'
        # data = '2018/2/2'
        # durata = '3'
        # descriere = 'Simfonii de iarna'
        # serv_e.adaugare_eveniment(id_e, data, durata, descriere)
        #
        # id_e = '3'
        # data = '2021/12/31'
        # durata = '1'
        # descriere = 'Anul Nou'
        # serv_e.adaugare_eveniment(id_e, data, durata, descriere)
        #
        # id_e = '4'
        # data = '2020/3/4'
        # durata = '2'
        # descriere = 'Vacanta Predeal'
        # serv_e.adaugare_eveniment(id_e, data, durata, descriere)

        f = open('test_asignare.txt', 'a')
        valid = Validare_asignare()
        repo_asig = Repository_asignare_persoana_eveniment_file('test_asignare.txt')
        serv_a = Service_asignare_pers_event(valid, repo_pers, repo_events, repo_asig)
        # id_a = '1'
        # id_p = '2'
        # id_e = '3'
        # serv_a.adauga_persoana_la_eveniment(id_a, id_p, id_e)

        # id_a = '2'
        # id_p='13'
        # id_e='4'
        # serv_a.adauga_persoana_la_eveniment(id_a, id_p, id_e)
        #
        # id_a='3'
        # id_p='13'
        # id_e='2'
        # serv_a.adauga_persoana_la_eveniment(id_a, id_p, id_e)
        #
        # id_a='4'
        # id_p='2'
        # id_e='1'
        # serv_a.adauga_persoana_la_eveniment(id_a, id_p, id_e)
        id_a = '5'
        with self.assertRaises(Exception):
            serv_a.raport_lista_evenimente_persoana(id_a)
        id_a = '13'
        list = serv_a.raport_lista_evenimente_persoana(id_a)
        self.assertTrue(len(list) == 2)
        self.assertTrue(list[0].get_id_eveniment() == '4')
        self.assertTrue(list[1].get_id_eveniment() == '2')

        id_a ='2'
        list1 = serv_a.raport_lista_evenimente_persoana(id_a)
        self.assertTrue(len(list1) == 2)
        self.assertTrue(list1[0].get_id_eveniment() == '1')
        self.assertTrue(list1[1].get_id_eveniment() == '3')
        f.close()

if __name__ == '__main__':
    unittest.main()
