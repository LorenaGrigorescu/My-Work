import unittest
from Service.service import *
from Validator.validators import *
from Repository.repozitory import *


class White_box_testing(unittest.TestCase):

    def test_validare_persoana(self):
        validare_persoana = Validare_persoana()

        id_persoana = '12'
        nume = 'Mirabela'
        adresa = 'Ilfov'
        persoana = Persoana(id_persoana, nume, adresa)
        errors = validare_persoana.validare_persoana(persoana)
        self.assertTrue(errors == '')

        id_persoana = '-1'
        nume = 'Dana'
        adresa = 'Targu Frumos'
        persoana = Persoana(id_persoana, nume, adresa)
        errors = validare_persoana.validare_persoana(persoana)
        self.assertTrue(errors == 'Invalid id_persoana!')

        id_persoana = '23'
        nume = ''
        adresa = 'nicaieri'
        persoana = Persoana(id_persoana, nume, adresa)
        errors = validare_persoana.validare_persoana(persoana)
        self.assertTrue(errors == 'Invalid name!')

        id_persoana = '14'
        nume = 'Ioana Grama'
        adresa = ''
        persoana = Persoana(id_persoana, nume, adresa)
        errors = validare_persoana.validare_persoana(persoana)
        self.assertTrue(errors == 'Invalid address!')

    def test_adaugare_persoana(self):
        f = open("test_persoane.txt", 'a')
        repo_pers = Repository_persoane_file("test_persoane.txt")

        id_persoana = '13'
        nume = 'Anabela'
        adresa = 'Brasov'
        persoana = Persoana(id_persoana, nume, adresa)
        repo_pers.add_persoana(persoana)
        assert (len(repo_pers.get_lista_persoane()) == 1)
        f.close()

    def test_cautare_persoana_repo(self):
        f = open("test_persoane.txt", 'r')
        repo = Repository_persoane_file('test_persoane.txt')
        id_de_cautat = '13'
        assert (str(repo.cauta_dupa_id(id_de_cautat)) == "id_persoana:13\nnume:Anabela\nadresa:Brasov")
        f.close()

    def test_adauga_pers_repo(self):
        with open('test_persoane.txt', 'a') as f:
            f.write("")  # golim fisierul pentru teste
        repo = Repository_persoane_file('test_persoane.txt')
        # assert (len(repo.get_lista_persoane()) == 0)
        id_p = '1'
        nume = 'Isabela'
        adresa = 'Strada Unirii'
        persoana = Persoana(id_p, nume, adresa)
        repo.add_persoana(persoana)
        l = repo.get_lista_persoane()
        assert (len(repo.get_lista_persoane()) == 1)
        f.close()

    def test_adauga_serv(self):
        with open('test_persoane.txt', 'a') as f:
            f.write("")  # golim fisierul pentru teste
        repo = Repository_persoane_file('test_persoane.txt')
        valid = Validare_persoana()
        serv = Service_persoane(valid, repo)
        id_p = '2'
        nume = 'Ionel'
        adresa = 'Radauti'
        persoana = Persoana(id_p, nume, adresa)
        l = len(serv.get_all_persoane())
        serv.adaugare_persoana(id_p, nume, adresa)
        self.assertTrue(l == 2)

    def test_cautare_persoana(self):
        f = open("test_persoane.txt", 'r')
        validare_persoana = Validare_persoana()
        repo_pers = Repository_persoane_file("test_persoane.txt")
        serv_p = Service_persoane(validare_persoana, repo_pers)

        id_de_cautat = '1'
        rez = serv_p.cautare_persoana(id_de_cautat)
        self.assertTrue(rez == 1)

        id_de_cautat = -1
        rez = serv_p.cautare_persoana(id_de_cautat)
        self.assertTrue(rez == 0)

        f.close()

    def test_sterge_persoana_din_lista(self):
        f = open('test_persoane.txt', 'a')
        validare_persoana = Validare_persoana()
        repo_persoana = Repository_persoane_file("test_persoane.txt")
        serv_p = Service_persoane(validare_persoana, repo_persoana)

        id_persoana = '1'
        nume = 'Ionela'
        adresa = 'Iasi'
        persoana = Persoana(id_persoana, nume, adresa)
        errors = validare_persoana.validare_persoana(persoana)

        id_persoana1 = '2'
        nume = 'Anamaria'
        adresa = "Botosani"
        persoana1 = Persoana(id_persoana1, nume, adresa)
        errors1 = validare_persoana.validare_persoana(persoana1)

        try:
            self.assertTrue(len(errors) == 0)
            repo_persoana.add_persoana(persoana)
        except:
            print(errors)

        try:
            self.assertTrue(len(errors1) == 0)
            repo_persoana.add_persoana(persoana1)
        except:
            print(errors1)

        f.close()

        id_de_cautat = '1'
        repo_persoana.sterge_persoana(id_de_cautat)

    def test_validare_event(self):

        validare_eveniment = Validare_evenimente()
        id_eveniment = '1'
        data = '2019/1/3'
        timp = '100'
        descriere = 'Serbare'
        eveniment = Eveniment(id_eveniment, data, timp, descriere)
        errors = validare_eveniment.validare_eveniment(eveniment)
        try:
            self.assertTrue(errors == '')
        except:
            print(errors)

        id_eveniment = '-1'
        data = '2018/2/2'
        timp = '400'
        descriere = 'Targ de vechituri'
        eveniment = Eveniment(id_eveniment, data, timp, descriere)
        errors = validare_eveniment.validare_eveniment(eveniment)
        try:
            self.assertTrue(errors == '')
        except:
            print(errors)

    def test_adaugare_eveniment(self):

        validare_eveniment = Validare_evenimente()
        repo_event = Repository_evenimente_file("test_evenimente.txt")
        serv_e = Service_evenimente(validare_eveniment, repo_event)
        f = open("test_evenimente.txt", 'a')
        id_eveniment = '1'
        data = '2019/1/3'
        timp = '100'
        descriere = 'Serbare'
        eveniment = Eveniment(id_eveniment, data, timp, descriere)
        repo_event.add_eveniment(eveniment)
        f.close()

    def test_cautare_eveniment(self):

        validare_eveniment = Validare_evenimente()
        repo_event = Repository_evenimente_file("test_evenimente.txt")
        serv_e = Service_evenimente(validare_eveniment, repo_event)
        f = open("test_evenimente.txt", 'r')
        id_eveniment_de_cautat = '1'
        rez = serv_e.cautare_eveniment(id_eveniment_de_cautat)
        self.assertTrue(rez == 1)

        id_eveniment_de_cautat = '3'
        rez = serv_e.cautare_eveniment(id_eveniment_de_cautat)
        self.assertTrue(rez == 0)
        f.close()

    def test_adauga_eveniment_serv(self):
        with open('test_evenimente.txt', 'a') as f:
            f.write("")
        validare_eveniment = Validare_evenimente()
        repo = Repository_evenimente_file("test_evenimente.txt")
        serv_e = Service_evenimente(validare_eveniment, repo)
        id_e = '21'
        data = '2002/10/1'
        durata = '123'
        descriere = 'zbor'
        eveniment = Eveniment(id_e, data, durata, descriere)
        serv_e.adaugare_eveniment(id_e, data, durata, descriere)
        serv_e.adaugare_eveniment(id_e, data, durata, descriere)
        list = serv_e.get_all_evenimente()
        self.assertTrue(len(list) == 1)
        f.close()

    def test_adauga_asignare(self):
        with open('test_asignare.txt', 'a') as f:
            f.write("")
        valid = Validare_asignare()
        repo_p = Repository_persoane_file("test_persoane.txt")
        repo_e = Repository_evenimente_file('test_evenimente.txt')
        repo_a = Repository_asignare_persoana_eveniment_file('test_asignare.txt')
        serv = Service_asignare_pers_event(valid, repo_p, repo_e, repo_a)
        id_p = '13'
        id_e = '1'
        id_a = '1'
        # persoana = repo_p.cauta_dupa_id(id_p)
        # eveniment = repo_e.cauta_dupa_id(id_e)
        # asignare = PersoaneEvenimente_DTO(id_a, persoana, eveniment)
        asignare = PersoaneEvenimente_DTO(id_a, id_p, id_e)
        self.assertTrue(len(repo_a.get_lista_persoane_la_evenimente()) == 0)
        repo_a.add_persoana_la_eveniment(asignare)
        self.assertTrue(len(repo_a.get_lista_persoane_la_evenimente()) == 1)

    def test_cauta_asignare(self):
        f = open('test_asignare.txt', 'r')
        repo_a = Repository_asignare_persoana_eveniment_file('test_asignare.txt')
        id_a = '1'
        rezultat = []
        rez = repo_a.cauta_persoana_eveniment(id_a)
        rezultat.append(rez)
        self.assertTrue(len(rezultat) == 1)
        f.close()

    def test_sterge_asignare(self):
        f = open('test_asignare.txt', 'w')
        repo_a = Repository_asignare_persoana_eveniment_file('test_asignare.txt')
        id_a = '1'
        id_p = '13'
        id_e = '1'
        asignare = PersoaneEvenimente_DTO(id_a, id_p, id_e)
        self.assertTrue(len(repo_a.get_lista_persoane_la_evenimente()) == 1)
        repo_a.sterge_persoana_eveniment(asignare)
        self.assertTrue(len(repo_a.get_lista_persoane_la_evenimente()) == 0)
        f.close()

    def test_adauga_service(self):
        f = open('test_asignare.txt', 'a')
        valid = Validare_asignare()
        repo_p = Repository_persoane_file("test_persoane.txt")
        repo_e = Repository_evenimente_file('test_evenimente.txt')
        repo_a = Repository_asignare_persoana_eveniment_file('test_asignare.txt')
        serv = Service_asignare_pers_event(valid, repo_p, repo_e, repo_a)
        id_a = '12'
        id_p = '13'
        id_e = '1'
        asignare = PersoaneEvenimente_DTO(id_a, id_p, id_e)
        self.assertTrue(len(serv.get_all_asignari()) == 0)
        serv.adauga_persoana_la_eveniment(id_a, id_p, id_e)
        self.assertTrue(len(serv.get_all_asignari()) == 1)
        f.close()

    def test_cautare_service(self):
        f = open('test_asignare.txt', 'r')
        valid = Validare_asignare()
        repo_p = Repository_persoane_file("test_persoane.txt")
        repo_e = Repository_evenimente_file("test_evenimente.txt")
        repo_a = Repository_asignare_persoana_eveniment_file('test_asignare.txt')
        serv = Service_asignare_pers_event(valid, repo_p, repo_e, repo_a)
        id_a = '12'
        rezultate = []
        self.assertTrue(len(rezultate) == 0)
        rez = serv.cauta_persoana_in_evenimente(id_a)
        rezultate.append(rez)
        self.assertTrue(len(rezultate) == 1)
        f.close()

    def test_sterge_asignare_service(self):
        with open('test_asignare.txt', 'w') as f:
            f.write("15,13,1")
        valid = Validare_asignare()
        repo_p = Repository_persoane_file("test_persoane.txt")
        repo_e = Repository_evenimente_file("test_evenimente.txt")
        repo_a = Repository_asignare_persoana_eveniment_file('test_asignare.txt')
        serv = Service_asignare_pers_event(valid, repo_p, repo_e, repo_a)
        id_a = '15'
        tot = serv.get_all_asignari()
        self.assertTrue(len(tot) == 1)
        serv.sterge_persoana_la_eveniment(id_a)
        self.assertTrue(len(tot) == 0)
        f.close()

    def test_raport_top_3(self):
        f = open('test_asignare.txt', 'r')
        valid = Validare_asignare()
        repo_p = Repository_persoane_file("test_persoane.txt")
        repo_e = Repository_evenimente_file("test_evenimente.txt")
        repo_a = Repository_asignare_persoana_eveniment_file('test_asignare.txt')
        serv = Service_asignare_pers_event(valid, repo_p, repo_e, repo_a)
        with self.assertRaises(Exception):
            serv.raport_top_3_zile()
        f.close()

    def test_lista_evenimente_persoana(self):
        f = open('test_asignare.txt', 'r')
        valid = Validare_asignare()
        repo_p = Repository_persoane_file("test_persoane.txt")
        repo_e = Repository_evenimente_file("test_evenimente.txt")
        repo_a = Repository_asignare_persoana_eveniment_file('test_asignare.txt')
        serv = Service_asignare_pers_event(valid, repo_p, repo_e, repo_a)
        id_p = '-1'
        with self.assertRaises(Exception):
            serv.raport_lista_evenimente_persoana(id_p)
        id_p = '13'
        list = serv.raport_lista_evenimente_persoana(id_p)
        self.assertTrue(len(list)==1)
        #print(serv.raport_lista_evenimente_persoana(id_p))
        f.close()

    def test_evenimente_populare(self):
        f = open("test_asignare.txt", 'r')
        valid = Validare_asignare()
        repo_p = Repository_persoane_file("test_persoane.txt")
        repo_e = Repository_evenimente_file("test_evenimente.txt")
        repo_a = Repository_asignare_persoana_eveniment_file('test_asignare.txt')
        serv = Service_asignare_pers_event(valid, repo_p, repo_e, repo_a)
        with self.assertRaises(Exception):
            serv.raport_evenimente_populare()
        f.close()
