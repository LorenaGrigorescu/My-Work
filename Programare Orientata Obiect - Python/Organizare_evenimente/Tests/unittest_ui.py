# import unittest
#
# from Service.service import *
# from Validator.validators import *
# from Repository.repozitory import *
#
#
# class unittest_tests(unittest.TestCase):
#     def test_creeaza_persoana(self):
#         id_persoana = '1'
#         nume = 'Iordache Alina'
#         adresa = 'Strada Teodor Mihali, FN, bl. 56, sc. E,ap 88'
#         persoana = Persoana(id_persoana, nume, adresa)
#         self.assertEqual(persoana.get_id_persoana(), id_persoana)
#         self.assertEqual(persoana.get_nume(), nume)
#         self.assertEqual(persoana.get_adresa(), adresa)
#
#     def test_validare_persoana(self):
#         id_persoana = '1'
#         nume = 'Iordache Alina'
#         adresa = 'Strada Teodor Mihali, FN, bl. 56, sc. E,ap 88'
#         persoana = Persoana(id_persoana, nume, adresa)
#         validator_persoana = Validare_persoana()
#         self.assertTrue(validator_persoana.validare_persoana(persoana) == "", "Valid person!")
#
#         id_persoana = '-1'
#         nume = 'Iordache Alina'
#         adresa = 'Strada Teodor Mihali, FN, bl. 56, sc. E,ap 88'
#         persoana = Persoana(id_persoana, nume, adresa)
#         validator_persoana = Validare_persoana()
#         self.assertTrue(validator_persoana.validare_persoana(persoana) == 'Invalid id_persoana!')
#
#         id_persoana = '2'
#         nume = "Mihnea Buza"
#         adresa = ""
#         persoana = Persoana(id_persoana, nume, adresa)
#         validator_persoana = Validare_persoana()
#         self.assertTrue(validator_persoana.validare_persoana(persoana) == "Invalid address!")
#
#         id_persoana = '1'
#         nume = ''
#         adresa = 'Bulevardul Independentei, nr. 67'
#         persoana = Persoana(id_persoana, nume, adresa)
#         validator_persoana = Validare_persoana()
#         self.assertTrue(validator_persoana.validare_persoana(persoana) == "Invalid name!")
#
#         id_persoana = '-22'
#         nume = ''
#         adresa = ''
#         persoana = Persoana(id_persoana, nume, adresa)
#         validator_persoana = Validare_persoana()
#         self.assertTrue(
#             validator_persoana.validare_persoana(persoana) == "Invalid id_persoana!Invalid name!Invalid address!")
#
#     def test_cautare_persoana(self):
#         with open("test_persoane.txt", 'w') as f:
#             f.write("")
#
#         lista_persoane = Repository_persoane_file("test_persoane.txt")
#         validator_persoane = Validare_persoana()
#         srv_p = Service_persoane(validator_persoane, lista_persoane)
#
#         id_persoana = '2'
#         nume = 'Diana Dulgheru'
#         adresa = 'Strada Mihai Viteazu nr. 69'
#         persoana1 = Persoana(id_persoana, nume, adresa)
#         srv_p.adaugare_persoana(id_persoana, nume, adresa)
#
#         id_persoana = '1'
#         nume = 'Daiana Dumitru'
#         adresa = 'Strada Revolutiei, FN, bloc 43, et. 4, ap 10, judetul Suceava'
#         persoana2 = Persoana(id_persoana, nume, adresa)
#         srv_p.adaugare_persoana(id_persoana, nume, adresa)
#
#         id_de_cautat = '1'
#         self.assertTrue(srv_p.cautare_persoana(id_de_cautat) == 1)
#
#         id_persoana = '-23'
#         nume = 'Aida Macovei'
#         adresa = "Comuna Dolhesti, Judetul Suceava"
#         persoana2 = Persoana(id_persoana, nume, adresa)
#         srv_p.adaugare_persoana(id_persoana, nume, adresa)
#
#         id_de_cautat = '12'
#         self.assertTrue(srv_p.cautare_persoana(id_de_cautat) == 0)
#
#     def test_inlocuire_persoana(self):
#         with open("test_persoane.txt", 'w') as f:
#             f.write("")
#         lista_repo_pers = Repository_persoane_file("test_persoane.txt")
#         validare_persoane = Validare_persoana()
#         srv_p = Service_persoane(validare_persoane, lista_repo_pers)
#
#         id_persoana = '3'
#         nume_initial = 'Emilian Macovei'
#         adresa = 'Strada Simion Barnutiu, numar 45, Zalau'
#         persoana1 = Persoana(id_persoana, nume_initial, adresa)
#         lista_repo_pers.add_persoana(persoana1)
#
#         id_persoana = '7'
#         nume_initial = 'Flaviu Pargea'
#         adresa = "Strada Carol 1, sector 6, Bucuresti"
#         persoana2 = Persoana(id_persoana, nume_initial, adresa)
#         lista_repo_pers.add_persoana(persoana2)
#
#         nume_initial = 'Flaviu Pargea'
#         nume_final = 'Lorena Grigorescu'
#         self.assertTrue(srv_p.modifica_nume_persoana(nume_initial, nume_final) == 1)
#         # modificarea a fost facuta deoarece testul nu pica
#
#         nume_initial = 'Brad Pitt'
#         nume_final = 'Anamaria Solcan'
#         self.assertTrue(srv_p.modifica_nume_persoana(nume_initial, nume_final) == 0)
#         # modificarea nu a fost facuta deoarece testul pica
#
#     def test_stergere_lista_persoana(self):
#         with open("test_persoane.txt", 'w') as f:
#             f.write("")
#         repository_persoane = Repository_persoane_file("test_persoane.txt")
#         validare_persoana = Validare_persoana()
#         srv = Service_persoane(validare_persoana, repository_persoane)
#
#         id_persoana = '1'
#         nume = 'Ioana Grigore'
#         adresa = 'Strada Independentei, nr. 45, oras Focsani, judet Vrancea'
#         persoana = Persoana(id_persoana, nume, adresa)
#         self.assertTrue(validare_persoana.validare_persoana(persoana) == '')
#         repository_persoane.add_persoana(persoana)
#
#         id_persoana = '2'
#         nume = 'Delia Sur'
#         adresa = 'Strada Sucevei, bl. 56, sc. A, oras Falticeni, judet Suceava'
#         persoana = Persoana(id_persoana, nume, adresa)
#         self.assertTrue(validare_persoana.validare_persoana(persoana) == '')
#         repository_persoane.add_persoana(persoana)
#
#         id_persoana = '-22'
#         nume = ''
#         adresa = ''
#         persoana = Persoana(id_persoana, nume, adresa)
#         self.assertTrue(
#             validare_persoana.validare_persoana(persoana) == "Invalid id_persoana!Invalid name!Invalid address!")
#
#         id_de_cautat = '2'
#         srv.sterge_persoana_lista(id_de_cautat)
#         self.assertTrue(len(srv.get_repository_persoane().get_lista_persoane()) == 1)
#
#     def test_adaugare_eveniment_test(self):
#         with open("test_evenimente.txt", 'w') as f:
#             f.write("")
#         lista_persoana = Repository_evenimente_file("test_evenimente.txt")
#         validare_eveniment = Validare_evenimente()
#         srv_e = Service_evenimente(validare_eveniment, lista_persoana)
#
#         id_eveniment = '231'
#         data = '2020/12/3'
#         timp = '100'
#         descriere = 'Lansarea filmului romanesc "Filantropica"'
#         eveniment1 = Eveniment(id_eveniment, data, timp, descriere)
#         self.assertTrue((eveniment1.get_id_eveniment() == id_eveniment))
#         self.assertTrue((eveniment1.get_data() == data))
#         self.assertTrue((eveniment1.get_descriere() == descriere))
#
#     def test_validare_eveniment(self):
#         with open("test_evenimente.txt", 'w') as f:
#             f.write("")
#         lista_evenimente = Repository_evenimente_file("test_evenimente.txt")
#         validare_eveniment = Validare_evenimente()
#         srv_e = Service_evenimente(validare_eveniment, lista_evenimente)
#
#         id_eveniment = '-234'
#         data = '2016/12/12'
#         timp = '34'
#         descriere = "Premierea elevilor de clasa a 8 a de la Liceul Avram Iancu"
#         eveniment = Eveniment(id_eveniment, data, timp, descriere)
#         self.assertTrue(validare_eveniment.validare_eveniment(eveniment) == "Invalid id_eveniment!")
#
#         id_eveniment = '2345'
#         data = '11'
#         timp = '122'
#         descriere = 'Premiile Gopo'
#         eveniment = Eveniment(id_eveniment, data, timp, descriere)
#         self.assertTrue(validare_eveniment.validare_eveniment(eveniment) == "Invalid date time!")
#
#         id_eveniment = '111'
#         data = '2019/3/23'
#         timp = ''
#         descriere = 'Nunta surorii Deliei'
#         eveniment = Eveniment(id_eveniment, data, timp, descriere)
#         self.assertTrue(validare_eveniment.validare_eveniment(eveniment) == "Invalid period of time!")
#
#         id_eveniment = '113'
#         data = '2014/2/14'
#         timp = '222'
#         descriere = ''
#         eveniment = Eveniment(id_eveniment, data, timp, descriere)
#         self.assertTrue(validare_eveniment.validare_eveniment(eveniment) == 'Invalid event description!')
#
#         id_eveniment = '-1'
#         data = ''
#         timp = ''
#         descriere = ''
#         eveniment = Eveniment(id_eveniment, data, timp, descriere)
#         self.assertFalse(validare_eveniment.validare_eveniment(
#             eveniment) == 'Invalid id_eveniment!Invalid date time!Invalid period of time!Invalid event description!')
#
#         id_eveniment = '23'
#         data = '2021/6/13'
#         timp = '233'
#         descriere = 'Avanpremiera filmului "Dune"'
#         eveniment = Eveniment(id_eveniment, data, timp, descriere)
#         self.assertTrue(validare_eveniment.validare_eveniment(eveniment) == '')
#         lista_evenimente.add_eveniment(eveniment)
#
#         id_eveniment = '123'
#         data = '2002/2/1'
#         timp = '1000'
#         descriere = 'Balul de caritate al firmei Tehno World'
#         eveniment = Eveniment(id_eveniment, data, timp, descriere)
#         self.assertTrue(validare_eveniment.validare_eveniment(eveniment) == '')
#         lista_evenimente.add_eveniment(eveniment)
#
#         id_eveniment = '11'
#         data = '2005/12/31'
#         timp = '1003'
#         descriere = "Noaptea dintre ani"
#         eveniment = Eveniment(id_eveniment, data, timp, descriere)
#         self.assertTrue(validare_eveniment.validare_eveniment(eveniment) == "")
#         lista_evenimente.add_eveniment(eveniment)
#
#         id_eveniment = '-2'
#         data = '23ty'
#         timp = '-1111'
#         descriere = ''
#         eveniment = Eveniment(id_eveniment, data, timp, descriere)
#         self.assertFalse(validare_eveniment.validare_eveniment(eveniment) == "")
#
#         id_de_cautat = '23'
#
#         self.assertTrue(srv_e.cautare_eveniment(id_de_cautat) == 1)
#
#         id_de_cautat = '-2'
#         self.assertTrue(srv_e.cautare_eveniment(id_de_cautat) == 0)
#
#     def test_stergere_lista_eveniment(self):
#         with open("test_evenimente.txt", 'w') as f:
#             f.write("")
#         validare_evenimente = Validare_evenimente()
#         repository_evenimente = Repository_evenimente_file('test_evenimente.txt')
#         srv = Service_evenimente(validare_evenimente, repository_evenimente)
#
#         id_eveniment1 = '12'
#         data = '2019/4/2'
#         timp = '1111'
#         descriere = 'Balul Bobocilor de la Colegiul National "Stefan cel Mare" Suceava'
#         eveniment1 = Eveniment(id_eveniment1, data, timp, descriere)
#         self.assertTrue(validare_evenimente.validare_eveniment(eveniment1) == "")
#         repository_evenimente.add_eveniment(eveniment1)
#
#         id_eveniment2 = '1'
#         data = '2018/12/14'
#         timp = '111'
#         descriere = 'Concert Colinde de Craciun'
#         eveniment2 = Eveniment(id_eveniment2, data, timp, descriere)
#         self.assertTrue(validare_evenimente.validare_eveniment(eveniment2) == "")
#         repository_evenimente.add_eveniment(eveniment2)
#
#         id_eveniment3 = '-99'
#         data = ''
#         timp = '-1'
#         descriere = ''
#         eveniment3 = Eveniment(id_eveniment3, data, timp, descriere)
#         self.assertTrue(validare_evenimente.validare_eveniment(
#             eveniment3) == "Invalid id_eveniment!Invalid period of time!Invalid date time!Invalid event description!")
#
#         id_de_cautat = '123'
#         with self.assertRaises(Exception):
#             srv.sterge_eveniment_din_lista(id_de_cautat)
#         srv.get_repository_evenimente().get_lista_evenimente()
#
#         id_de_cautat1 = '1'
#         srv.sterge_eveniment_din_lista(id_de_cautat1)
#         self.assertTrue(len(srv.get_repository_evenimente().get_lista_evenimente()) == 1)
#
#     def test_raport_3(self):
#
#         repo_pers = Repository_persoane()
#         repo_event = Repository_evenimente()
#         repo_asig = Repository_asignare_persoana_eveniment()
#         validare_asig = Validare_asignare()
#         srv_asig = Service_asignare_pers_event(validare_asig, repo_pers, repo_event, repo_asig)
#
#         id_persoana1 = '1'
#         nume = 'Lorena Grigorescu'
#         adress = 'Eco1'
#         persoana1 = Persoana(id_persoana1, nume, adress)
#         repo_pers.add_persoana(persoana1)
#
#         id_persoana2 = '2'
#         nume = 'Iacob Ilinca'
#         adress = 'Hasdeu C1'
#         persoana2 = Persoana(id_persoana2, nume, adress)
#         repo_pers.add_persoana(persoana2)
#
#         id_persoana3 = '3'
#         nume = 'Florea Flaviu'
#         adress = 'Eco1'
#         persoana3 = Persoana(id_persoana3, nume, adress)
#         repo_pers.add_persoana(persoana3)
#
#         id_persoana4 = '4'
#         nume = 'Gigel Frone'
#         adress = 'Carcal'
#         persoana4 = Persoana(id_persoana4, nume, adress)
#         repo_pers.add_persoana(persoana4)
#
#         id_persoana5 = '5'
#         nume = 'Gheorghita Petriceica'
#         adress = 'Eco2'
#         persoana5 = Persoana(id_persoana5, nume, adress)
#         repo_pers.add_persoana(persoana5)
#
#         id_persoana6 = '6'
#         nume = 'Dani Grama'
#         adress = 'Reghin'
#         persoana6 = Persoana(id_persoana6, nume, adress)
#         repo_pers.add_persoana(persoana6)
#
#         id_eveniment1 = '1'
#         data = '2020/9/2'
#         timp = '1000'
#         descriere = 'Cabana info anul 1'
#         eveniment1 = Eveniment(id_eveniment1, data, timp, descriere)
#         repo_event.add_eveniment(eveniment1)
#
#         id_eveniment2 = '2'
#         data = '2021/1/7'
#         timp = '1000'
#         descriere = 'Karaoke anii 90'
#         eveniment2 = Eveniment(id_eveniment2, data, timp, descriere)
#         repo_event.add_eveniment(eveniment2)
#
#         id_eveniment3 = '3'
#         data = '2022/12/4'
#         timp = '2222'
#         descriere = 'Targul de Craciun din Cluj Napoca'
#         eveniment3 = Eveniment(id_eveniment3, data, timp, descriere)
#         repo_event.add_eveniment(eveniment3)
#
#         id_asig1 = '1'
#         id_asig2 = '2'
#         id_asig3 = '3'
#         id_asig4 = '4'
#         id_asig5 = '5'
#         id_asig6 = '6'
#         id_asig7 = '7'
#         id_asig8 = '8'
#         id_asig9 = '9'
#         id_asig10 = '10'
#         id_asig11 = '11'
#         id_asig12 = '12'
#
#         asignare1 = Asignare_per_event(persoana1, eveniment1)
#         srv_asig.adauga_persoana_la_eveniment(eveniment1, persoana1)
#
#         asignare2 = Asignare_per_event(persoana1, eveniment2)
#         srv_asig.adauga_persoana_la_eveniment(eveniment2, persoana1)
#
#         asignare3 = Asignare_per_event(persoana2, eveniment1)
#         srv_asig.adauga_persoana_la_eveniment(eveniment1, persoana2)
#
#         asignare4 = Asignare_per_event(persoana3, eveniment3)
#         srv_asig.adauga_persoana_la_eveniment(eveniment3, persoana3)
#
#         asignare5 = Asignare_per_event(persoana4, eveniment3)
#         srv_asig.adauga_persoana_la_eveniment(eveniment3, persoana4)
#
#         asignare6 = Asignare_per_event(persoana5, eveniment1)
#         srv_asig.adauga_persoana_la_eveniment(eveniment1, persoana5)
#
#         asignare7 = Asignare_per_event(persoana6, eveniment3)
#         srv_asig.adauga_persoana_la_eveniment(eveniment3, persoana6)
#
#         asignare8 = Asignare_per_event(persoana6, eveniment2)
#         srv_asig.adauga_persoana_la_eveniment(eveniment2, persoana6)
#
#         asignare9 = Asignare_per_event(persoana1, eveniment3)
#         srv_asig.adauga_persoana_la_eveniment(eveniment3, persoana1)
#
#         asignare10 = Asignare_per_event(persoana5, eveniment2)
#         srv_asig.adauga_persoana_la_eveniment(eveniment2, persoana5)
#
#         asignare11 = Asignare_per_event(persoana2, eveniment3)
#         srv_asig.adauga_persoana_la_eveniment(eveniment3, persoana2)
#
#         asignare_12 = Asignare_per_event(persoana6, eveniment1)
#         srv_asig.adauga_persoana_la_eveniment(eveniment1, persoana6)
#
#         self.assertTrue(srv_asig.raport_top_3_zile() == [['12', 5], ['9', 4], ['1', 3]])
#
#     def test_raport_top_3_zile(self):
#         validare_asig = Validare_asignare()
#         repo_pers = Repository_persoane()
#         repo_event = Repository_evenimente()
#         repo_asig = Repository_asignare_persoana_eveniment()
#         srv_asig = Service_asignare_pers_event(validare_asig, repo_pers, repo_event, repo_asig)
#
#         id_persoana1 = '1'
#         nume = 'Lorena'
#         adresa = 'Falticeni'
#         persoana1 = Persoana(id_persoana1, nume, adresa)
#         repo_pers.add_persoana(persoana1)
#
#         id_persoana2 = '2'
#         nume = 'Iacob Ilinca'
#         adress = 'Hasdeu C1'
#         persoana2 = Persoana(id_persoana2, nume, adress)
#         repo_pers.add_persoana(persoana2)
#
#         id_persoana3 = '3'
#         nume = 'Florea Flaviu'
#         adress = 'Eco1'
#         persoana3 = Persoana(id_persoana3, nume, adress)
#         repo_pers.add_persoana(persoana3)
#
#         id_eveniment1 = '1'
#         data = '2020/9/2'
#         timp = '1000'
#         descriere = 'Cabana info anul 1'
#         eveniment1 = Eveniment(id_eveniment1, data, timp, descriere)
#         repo_event.add_eveniment(eveniment1)
#
#         id_eveniment2 = '2'
#         data = '2021/1/7'
#         timp = '1000'
#         descriere = 'Karaoke anii 90'
#         eveniment2 = Eveniment(id_eveniment2, data, timp, descriere)
#         repo_event.add_eveniment(eveniment2)
#
#         id_eveniment3 = '3'
#         data = '2022/12/4'
#         timp = '2222'
#         descriere = 'Targul de Craciun din Cluj Napoca'
#         eveniment3 = Eveniment(id_eveniment3, data, timp, descriere)
#         repo_event.add_eveniment(eveniment3)
#
#         srv_asig.adauga_persoana_la_eveniment(id_persoana1, id_eveniment1)
#         srv_asig.adauga_persoana_la_eveniment(id_persoana1, id_eveniment2)
#         srv_asig.adauga_persoana_la_eveniment(id_persoana3, id_eveniment2)
#         srv_asig.adauga_persoana_la_eveniment(id_persoana2, id_eveniment3)
#         srv_asig.adauga_persoana_la_eveniment(id_persoana3, id_eveniment1)
#         srv_asig.adauga_persoana_la_eveniment(id_persoana2, id_eveniment1)
#
#         self.assertTrue(srv_asig.raport_top_3_zile() == [['9', 3], ['1', 2], ['12', 1]])
#
#     def test_raport_lista_evenimente_persoana(self):
#         validare_asig = Validare_asignare()
#         repo_pers = Repository_persoane()
#         repo_event = Repository_evenimente()
#         repo_asig = Repository_asignare_persoana_eveniment()
#         srv_asig = Service_asignare_pers_event(validare_asig, repo_pers, repo_event, repo_asig)
#
#         id_persoana1 = '1'
#         nume = 'Lorena'
#         adresa = 'Falticeni'
#         persoana1 = Persoana(id_persoana1, nume, adresa)
#         repo_pers.add_persoana(persoana1)
#
#         id_persoana2 = '2'
#         nume = 'Iacob Ilinca'
#         adress = 'Hasdeu C1'
#         persoana2 = Persoana(id_persoana2, nume, adress)
#         repo_pers.add_persoana(persoana2)
#
#         id_persoana3 = '3'
#         nume = 'Florea Flaviu'
#         adress = 'Eco1'
#         persoana3 = Persoana(id_persoana3, nume, adress)
#         repo_pers.add_persoana(persoana3)
#
#         id_eveniment1 = '1'
#         data = '2020/9/2'
#         timp = '1000'
#         descriere = 'Cabana info anul 1'
#         eveniment1 = Eveniment(id_eveniment1, data, timp, descriere)
#         repo_event.add_eveniment(eveniment1)
#
#         id_eveniment2 = '2'
#         data = '2021/1/7'
#         timp = '1000'
#         descriere = 'Karaoke anii 90'
#         eveniment2 = Eveniment(id_eveniment2, data, timp, descriere)
#         repo_event.add_eveniment(eveniment2)
#
#         id_eveniment3 = '3'
#         data = '2022/12/4'
#         timp = '2222'
#         descriere = 'Targul de Craciun din Cluj Napoca'
#         eveniment3 = Eveniment(id_eveniment3, data, timp, descriere)
#         repo_event.add_eveniment(eveniment3)
#
#         srv_asig.adauga_persoana_la_eveniment(id_persoana1, id_eveniment1)
#         srv_asig.adauga_persoana_la_eveniment(id_persoana1, id_eveniment2)
#         srv_asig.adauga_persoana_la_eveniment(id_persoana3, id_eveniment2)
#         srv_asig.adauga_persoana_la_eveniment(id_persoana2, id_eveniment3)
#         srv_asig.adauga_persoana_la_eveniment(id_persoana3, id_eveniment1)
#         srv_asig.adauga_persoana_la_eveniment(id_persoana2, id_eveniment1)
#
#         self.assertTrue(len(srv_asig.raport_lista_evenimente_persoana(id_persoana2)) == 2)
#         self.assertTrue(len(srv_asig.raport_lista_evenimente_persoana(id_persoana1)) == 2)
#         self.assertTrue(len(srv_asig.raport_lista_evenimente_persoana(id_persoana3)) == 2)
#
#     def test_raport_persoane_participante_evenimente(self):
#         validare_asig = Validare_asignare()
#         repo_pers = Repository_persoane()
#         repo_event = Repository_evenimente()
#         repo_asig = Repository_asignare_persoana_eveniment()
#         srv_asig = Service_asignare_pers_event(validare_asig, repo_pers, repo_event, repo_asig)
#
#         id_persoana1 = '1'
#         nume = 'Lorena Grigorescu'
#         adress = 'Eco1'
#         persoana1 = Persoana(id_persoana1, nume, adress)
#         repo_pers.add_persoana(persoana1)
#
#         id_persoana2 = '2'
#         nume = 'Iacob Ilinca'
#         adress = 'Hasdeu C1'
#         persoana2 = Persoana(id_persoana2, nume, adress)
#         repo_pers.add_persoana(persoana2)
#
#         id_persoana3 = '3'
#         nume = 'Florea Flaviu'
#         adress = 'Eco1'
#         persoana3 = Persoana(id_persoana3, nume, adress)
#         repo_pers.add_persoana(persoana3)
#
#         id_persoana4 = '4'
#         nume = 'Gigel Frone'
#         adress = 'Carcal'
#         persoana4 = Persoana(id_persoana4, nume, adress)
#         repo_pers.add_persoana(persoana4)
#
#         id_persoana5 = '5'
#         nume = 'Gheorghita Petriceica'
#         adress = 'Eco2'
#         persoana5 = Persoana(id_persoana5, nume, adress)
#         repo_pers.add_persoana(persoana5)
#
#         id_persoana6 = '6'
#         nume = 'Dani Grama'
#         adress = 'Reghin'
#         persoana6 = Persoana(id_persoana6, nume, adress)
#         repo_pers.add_persoana(persoana6)
#
#         id_eveniment1 = '1'
#         data = '2020/9/2'
#         timp = '1000'
#         descriere = 'Cabana info anul 1'
#         eveniment1 = Eveniment(id_eveniment1, data, timp, descriere)
#         repo_event.add_eveniment(eveniment1)
#
#         id_eveniment2 = '2'
#         data = '2021/1/7'
#         timp = '1000'
#         descriere = 'Karaoke anii 90'
#         eveniment2 = Eveniment(id_eveniment2, data, timp, descriere)
#         repo_event.add_eveniment(eveniment2)
#
#         id_eveniment3 = '3'
#         data = '2022/12/4'
#         timp = '2222'
#         descriere = 'Targul de Craciun din Cluj Napoca'
#         eveniment3 = Eveniment(id_eveniment3, data, timp, descriere)
#         repo_event.add_eveniment(eveniment3)
#
#         srv_asig.adauga_persoana_la_eveniment(id_persoana1, id_eveniment1)
#         srv_asig.adauga_persoana_la_eveniment(id_persoana1, id_eveniment2)
#         srv_asig.adauga_persoana_la_eveniment(id_persoana3, id_eveniment2)
#         srv_asig.adauga_persoana_la_eveniment(id_persoana2, id_eveniment3)
#         srv_asig.adauga_persoana_la_eveniment(id_persoana3, id_eveniment1)
#         srv_asig.adauga_persoana_la_eveniment(id_persoana2, id_eveniment1)
#         srv_asig.adauga_persoana_la_eveniment(id_persoana6, id_eveniment2)
#         srv_asig.adauga_persoana_la_eveniment(id_persoana5, id_eveniment3)
#         srv_asig.adauga_persoana_la_eveniment(id_persoana6, id_eveniment1)
#         srv_asig.adauga_persoana_la_eveniment(id_persoana4, id_eveniment1)
#
#         self.assertTrue(len(srv_asig.raport_persoane_participante_evenimente()) == 6)
#         self.assertTrue(srv_asig.raport_persoane_participante_evenimente()[0][1] == 2)
#         self.assertTrue(srv_asig.raport_persoane_participante_evenimente()[1][1] == 2)
#         self.assertTrue(srv_asig.raport_persoane_participante_evenimente()[2][1] == 2)
#         self.assertTrue(srv_asig.raport_persoane_participante_evenimente()[3][1] == 2)
#         self.assertTrue(srv_asig.raport_persoane_participante_evenimente()[4][1] == 1)
#         self.assertTrue(srv_asig.raport_persoane_participante_evenimente()[5][1] == 1)
#
#     def test_raport_evenimente_populare(self):
#         validare_asig = Validare_asignare()
#         repo_pers = Repository_persoane()
#         repo_event = Repository_evenimente()
#         repo_asig = Repository_asignare_persoana_eveniment()
#         srv_asig = Service_asignare_pers_event(validare_asig, repo_pers, repo_event, repo_asig)
#
#         id_persoana1 = '1'
#         nume = 'Lorena Grigorescu'
#         adress = 'Eco1'
#         persoana1 = Persoana(id_persoana1, nume, adress)
#         repo_pers.add_persoana(persoana1)
#
#         id_persoana2 = '2'
#         nume = 'Iacob Ilinca'
#         adress = 'Hasdeu C1'
#         persoana2 = Persoana(id_persoana2, nume, adress)
#         repo_pers.add_persoana(persoana2)
#
#         id_persoana3 = '3'
#         nume = 'Florea Flaviu'
#         adress = 'Eco1'
#         persoana3 = Persoana(id_persoana3, nume, adress)
#         repo_pers.add_persoana(persoana3)
#
#         id_persoana4 = '4'
#         nume = 'Gigel Frone'
#         adress = 'Carcal'
#         persoana4 = Persoana(id_persoana4, nume, adress)
#         repo_pers.add_persoana(persoana4)
#
#         id_persoana5 = '5'
#         nume = 'Gheorghita Petriceica'
#         adress = 'Eco2'
#         persoana5 = Persoana(id_persoana5, nume, adress)
#         repo_pers.add_persoana(persoana5)
#
#         id_persoana6 = '6'
#         nume = 'Dani Grama'
#         adress = 'Reghin'
#         persoana6 = Persoana(id_persoana6, nume, adress)
#         repo_pers.add_persoana(persoana6)
#
#         id_eveniment1 = '1'
#         data = '2020/9/2'
#         timp = '1000'
#         descriere = 'Cabana info anul 1'
#         eveniment1 = Eveniment(id_eveniment1, data, timp, descriere)
#         repo_event.add_eveniment(eveniment1)
#
#         id_eveniment2 = '2'
#         data = '2021/1/7'
#         timp = '1000'
#         descriere = 'Karaoke anii 90'
#         eveniment2 = Eveniment(id_eveniment2, data, timp, descriere)
#         repo_event.add_eveniment(eveniment2)
#
#         id_eveniment3 = '3'
#         data = '2022/12/4'
#         timp = '2222'
#         descriere = 'Targul de Craciun din Cluj Napoca'
#         eveniment3 = Eveniment(id_eveniment3, data, timp, descriere)
#         repo_event.add_eveniment(eveniment3)
#
#         id_eveniment4 = '4'
#         data = '2020/12/3'
#         timp = '100'
#         descriere = 'Lansarea filmului romanesc "Filantropica"'
#         eveniment4 = Eveniment(id_eveniment4, data, timp, descriere)
#         repo_event.add_eveniment(eveniment4)
#
#         id_eveniment5 = '5'
#         data = '2019/3/8'
#         timp = '200'
#         descriere = 'ziua femeii'
#         eveniment5 = Eveniment(id_eveniment5, data, timp, descriere)
#         repo_event.add_eveniment(eveniment5)
#
#         srv_asig.adauga_persoana_la_eveniment(id_persoana1, id_eveniment1)
#         srv_asig.adauga_persoana_la_eveniment(id_persoana1, id_eveniment2)
#         srv_asig.adauga_persoana_la_eveniment(id_persoana3, id_eveniment2)
#         srv_asig.adauga_persoana_la_eveniment(id_persoana2, id_eveniment3)
#         srv_asig.adauga_persoana_la_eveniment(id_persoana3, id_eveniment1)
#         srv_asig.adauga_persoana_la_eveniment(id_persoana2, id_eveniment1)
#         srv_asig.adauga_persoana_la_eveniment(id_persoana6, id_eveniment2)
#         srv_asig.adauga_persoana_la_eveniment(id_persoana5, id_eveniment3)
#         srv_asig.adauga_persoana_la_eveniment(id_persoana6, id_eveniment1)
#         srv_asig.adauga_persoana_la_eveniment(id_persoana4, id_eveniment1)
#         srv_asig.adauga_persoana_la_eveniment(id_persoana6, id_eveniment4)
#         srv_asig.adauga_persoana_la_eveniment(id_persoana1, id_eveniment4)
#         srv_asig.adauga_persoana_la_eveniment(id_persoana3, id_eveniment4)
#         srv_asig.adauga_persoana_la_eveniment(id_persoana5, id_eveniment2)
#         srv_asig.adauga_persoana_la_eveniment(id_persoana1, id_eveniment5)
#         srv_asig.adauga_persoana_la_eveniment(id_persoana2, id_eveniment5)
#
#         self.assertTrue(srv_asig.raport_evenimente_populare()[0][0] == 'Cabana info anul 1')
#         self.assertTrue(srv_asig.raport_evenimente_populare()[0][1] == 5)
#         self.assertTrue(len(srv_asig.raport_evenimente_populare()) == 1)
