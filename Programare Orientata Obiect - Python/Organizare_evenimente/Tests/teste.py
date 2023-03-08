# from service import *
# from validators import *
# from repozitory import *
#
#
# class adauga_persoana_teste:
#     def test_creeaza_persoana(self):
#         id_persoana = '1'
#         nume = 'Iordache Alina'
#         adresa = 'Strada Teodor Mihali, FN, bl. 56, sc. E,ap 88'
#         persoana = Persoana(id_persoana, nume, adresa)
#         assert (persoana.get_id_persoana() == id_persoana)
#         assert (persoana.get_nume() == nume)
#         assert (persoana.get_adresa() == adresa)
#
#     def test_validare_persoana(self):
#
#         id_persoana = '1'
#         nume = 'Iordache Alina'
#         adresa = 'Strada Teodor Mihali, FN, bl. 56, sc. E,ap 88'
#         persoana = Persoana(id_persoana, nume, adresa)
#         validator_persoana = Validare_persoana()
#         try:
#             validator_persoana.validare_persoana(persoana)
#             assert True
#         except ValueError as errors:
#             print(errors)
#             assert False
#         id_persoana = '-1'
#         nume = 'Iordache Alina'
#         adresa = 'Strada Teodor Mihali, FN, bl. 56, sc. E,ap 88'
#         persoana = Persoana(id_persoana, nume, adresa)
#         validator_persoana = Validare_persoana()
#         try:
#             validator_persoana.validare_persoana(persoana)
#             assert True
#         except ValueError as errors:
#             assert ("Invalid id_persoana!" in str(errors))
#             assert True
#         id_persoana = '2'
#         nume = "Mihnea Buza"
#         adresa = ""
#         persoana = Persoana(id_persoana, nume, adresa)
#         validator_persoana = Validare_persoana()
#         try:
#             validator_persoana.validare_persoana(persoana)
#             assert True
#         except ValueError as errors:
#             assert ('Invalid address!' in str(errors))
#             assert True
#         id_persoana = '1'
#         nume = ''
#         adresa = 'Bulevardul Independentei, nr. 67'
#         persoana = Persoana(id_persoana, nume, adresa)
#         validator_persoana = Validare_persoana()
#         try:
#             validator_persoana.validare_persoana(persoana)
#             assert True
#         except ValueError as errors:
#             assert ("Invalid name!" in str(errors))
#             assert True
#         id_persoana = '-22'
#         nume = ''
#         adresa = ''
#         persoana = Persoana(id_persoana, nume, adresa)
#         validator_persoana = Validare_persoana()
#         try:
#             validator_persoana.validare_persoana(persoana)
#             assert True
#         except ValueError as errors:
#             assert ("Invalid id_persoana!" in str(errors))
#             assert ("Invalid name!" in str(errors))
#             assert ("Invalid address!" in str(errors))
#             assert True
#
#     def test_cautare_persoana(self):
#         lista_persoane = Repository_persoane()
#         id_persoana = '2'
#         nume = 'Diana Dulgheru'
#         adresa = 'Strada Mihai Viteazu nr. 69'
#         persoana1 = Persoana(id_persoana, nume, adresa)
#         lista_persoane.add_persoana(persoana1)
#         id_persoana = '1'
#         nume = 'Daiana Dumitru'
#         adresa = 'Strada Revolutiei, FN, bloc 43, et. 4, ap 10, judetul Suceava'
#         persoana2 = Persoana(id_persoana, nume, adresa)
#         lista_persoane.add_persoana(persoana2)
#         id_de_cautat = '1'
#         try:
#             for persoana in lista_persoane.get_lista_persoane():
#                 if persoana.get_id_persoana == id_de_cautat:
#                     assert True
#         except id_not_available("Persoana cu id-ul cautat nu se afla in lista!"):
#             assert False
#         id_persoana = '-23'
#         nume = 'Aida Macovei'
#         adresa = "Comuna Dolhesti, Judetul Suceava"
#         persoana2 = Persoana(id_persoana, nume, adresa)
#         lista_persoane.add_persoana(persoana2)
#         id_de_cautat = '12'
#         try:
#             for persoana in lista_persoane.get_lista_persoane():
#                 if persoana.get_id_persoana() == id_de_cautat:
#                     assert True
#         except id_not_found("Nu exista nicio persoana cu id-ul cautat"):
#             assert False
#
#     def test_inlocuire_persoana(self):
#         id_persoana_initial = '3'
#         nume = 'Emilian Macovei'
#         adresa = 'Strada Simion Barnutiu, numar 45, Zalau'
#         persoana1 = Persoana(id_persoana_initial, nume, adresa)
#         lista_repo_pers = Repository_persoane()
#         lista_repo_pers.add_persoana(persoana1)
#         id_persoana_initial = '7'
#         nume = 'Flaviu Pargea'
#         adresa = "Strada Carol 1, sector 6, Bucuresti"
#         persoana2 = Persoana(id_persoana_initial, nume, adresa)
#         lista_repo_pers.add_persoana(persoana2)
#         id_persoana_final = '5'
#         try:
#             for persoana in lista_repo_pers.get_lista_persoane():
#                 if persoana.get_id_persoana() == '3':
#                     assert True
#                     persoana.set_id_persoana(id_persoana_final)
#         except id_not_found("Nu exista nicio persoana cu acest id"):
#             assert False
#         try:
#             for persoana in lista_repo_pers.get_lista_persoane():
#                 if persoana.get_id_persoana() == '12':
#                     assert True
#                     persoana.set_id_persoana(id_persoana_final)
#         except id_not_found("Nu exista nicio persoana cu acest id!"):
#             assert False
#
#     # def test_sort_by_id(self):
#     #     id_persoana = '1'
#     #     nume = 'Vlad Grigore'
#     #     adresa = 'Strada Borzesti, nr 45, oras Tecuci, judet Galati'
#     #     validator_persoana = Validare_persoana()
#     #     lista_repo_persoana = Repository_persoane()
#     #     persoana1 = Persoana(id_persoana, nume, adresa)
#     #     try:
#     #         validator_persoana.validare_persoana(persoana1)
#     #         assert True
#     #         lista_repo_persoana.add_persoana(persoana1)
#     #     except invalid_person("Persoana pe care vreti sa o introduceti este invalida!"):
#     #         assert False
#     #     id_persoana = '-23'
#     #     nume = ''
#     #     adresa = 'comuna Siret, judetul Suceava'
#     #     persoana2 = Persoana(id_persoana, nume, adresa)
#     #     try:
#     #         error = validator_persoana.validare_persoana(persoana2)
#     #         if len(error) == 0:
#     #             assert True
#     #         lista_repo_persoana.add_persoana(persoana2)
#     #     except invalid_person("Persoana pe care vreti sa o introduceti este invalida!"):
#     #         assert False
#     #     id_persoana = '45'
#     #     nume = 'Lorena Grigorescu'
#     #     adresa = 'Strada Sucevei, bl. 82, sc. B ap. 10'
#     #     persoana3 = Persoana(id_persoana, nume, adresa)
#     #     try:
#     #         validator_persoana.validare_persoana(persoana3)
#     #         assert True
#     #         lista_repo_persoana.add_persoana(persoana3)
#     #     except invalid_person("Persoana pe care vreti sa o introduceti este invalida!"):
#     #         assert False
#     #     id_persoana = '22'
#     #     nume = 'Ilinca Iacob'
#     #     adresa = 'Strada Horia, Closca si Crisan, nr. 56, oras Alba-Iulia, judet Alba'
#     #     persoana4 = Persoana(id_persoana, nume, adresa)
#     #     try:
#     #         validator_persoana.validare_persoana(persoana4)
#     #         assert True
#     #         lista_repo_persoana.add_persoana(persoana4)
#     #     except invalid_person("Persoana pe care vreti sa o introduceti este invalida!"):
#     #         assert False
#     #     srv = Service_persoane(validator_persoana, lista_repo_persoana)
#     #     srv1 = [persoana1, persoana3, persoana4]
#     #     srv2 = srv.sort_by_id(lista_repo_persoana.get_lista_persoane())
#     #     for i in range(len(srv1)):
#     #         if int(srv1[i].get_id_persoana()) == int(srv2[i].get_id_persoana()):
#     #             assert True
#
#     def test_stergere_lista_persoana(self):
#         validare_persoana = Validare_persoana()
#         repozitory_persoane = Repository_persoane()
#
#         id_persoana = '1'
#         nume = 'Ioana Grigore'
#         adresa = 'Strada Independentei, nr. 45, oras Focsani, judet Vrancea'
#         persoana = Persoana(id_persoana, nume, adresa)
#         errors = validare_persoana.validare_persoana(persoana)
#         if len(errors) == 0:
#             repozitory_persoane.add_persoana(persoana)
#
#         id_persoana = '2'
#         nume = 'Delia Sur'
#         adresa = 'Strada Sucevei, bl. 56, sc. A, oras Falticeni, judet Suceava'
#         persoana = Persoana(id_persoana, nume, adresa)
#         errors = validare_persoana.validare_persoana(persoana)
#         if len(errors) == 0:
#             repozitory_persoane.add_persoana(persoana)
#
#         id_persoana = '-22'
#         nume = ''
#         adresa = ''
#         persoana = Persoana(id_persoana, nume, adresa)
#         errors = validare_persoana.validare_persoana(persoana)
#         if len(errors) == 0:
#             repozitory_persoane.add_persoana(persoana)
#
#         id_de_cautat = '2'
#         try:
#             srv = Service_persoane(validare_persoana, repozitory_persoane)
#             srv.sterge_persoana_lista(id_de_cautat)
#             if len(srv.get_repository_persoane().get_lista_persoane()) == 1:
#                 assert True
#         except Exception as errors:
#             assert False
#
#
# class adauga_eveniment_teste:
#     def adaugare_eveniment_test(self):
#         id_eveniment = '231'
#         data = '2020/12/3'
#         timp = '100'
#         descriere = 'Lansarea filmului romanesc "Filantropica"'
#         eveniment1 = Eveniment(id_eveniment, data, timp, descriere)
#         assert (eveniment1.get_id_eveniment() == id_eveniment)
#         assert (eveniment1.get_data() == data)
#         assert (eveniment1.get_desciere() == descriere)
#
#     def validare_eveniment(self):
#         validare_eveniment = Validare_evenimente()
#         id_eveniment = '-234'
#         data = '2016/12/12'
#         timp = '34'
#         descriere = "Premierea elevilor de clasa a 8 a de la Liceul Avram Iancu"
#         eveniment = Eveniment(id_eveniment, data, timp, descriere)
#         try:
#             validare_eveniment.validare_eveniment(eveniment)
#             assert True
#         except ValueError as errors:
#             print(errors)
#             assert False
#         id_eveniment = '2345'
#         data = '11'
#         timp = '122'
#         descriere = 'Premiile Gopo'
#         eveniment = Eveniment(id_eveniment, data, timp, descriere)
#         try:
#             errors = validare_eveniment.validare_eveniment(eveniment)
#             if len(errors) < 0:
#                 assert False
#         except ValueError as errors:
#             print(errors)
#             assert True
#         id_eveniment = '111'
#         data = '2019/3/23'
#         timp = ''
#         descriere = 'Nunta surorii Deliei'
#         eveniment = Eveniment(id_eveniment, data, timp, descriere)
#         try:
#             validare_eveniment.validare_eveniment(eveniment)
#             assert True
#         except ValueError as errors:
#             print(errors)
#             assert False
#         id_eveniment = '113'
#         data = '2014/2/14'
#         timp = '222'
#         descriere = ''
#         eveniment = Eveniment(id_eveniment, data, timp, descriere)
#         try:
#             errors=validare_eveniment.validare_eveniment(eveniment)
#             if len(errors) == 0:
#                 assert True
#         except ValueError as errors:
#             print(errors)
#             assert False
#         id_eveniment = '-1'
#         data = ''
#         timp = ''
#         descriere = ''
#         eveniment = Eveniment(id_eveniment, data, timp, descriere)
#         try:
#             errors=validare_eveniment.validare_eveniment(eveniment)
#             if len(errors)<=0:
#                 assert False
#         except ValueError as errors:
#             print(errors)
#             assert True
#
#     def cautare_eveniment_test(self):
#         lista_evenimente = Repository_evenimente()
#         validare_eveniment = Validare_evenimente()
#
#         id_eveniment = '23'
#         data = '2021/6/13'
#         timp = '233'
#         descriere = 'Avanpremiera filmului "Dune"'
#         eveniment = Eveniment(id_eveniment, data, timp, descriere)
#         error = validare_eveniment.validare_eveniment(eveniment)
#         if len(error) == 0:
#             lista_evenimente.add_eveniment(eveniment)
#
#         id_eveniment = '123'
#         data = '2002/2/1'
#         timp = '1000'
#         descriere = 'Balul de caritate al firmei Tehno World'
#         eveniment = Eveniment(id_eveniment, data, timp, descriere)
#         error = validare_eveniment.validare_eveniment(eveniment)
#         if len(error) == 0:
#             lista_evenimente.add_eveniment(eveniment)
#
#         id_eveniment = '11'
#         data = '2005/12/31'
#         timp = '1003'
#         descriere = "Noaptea dintre ani"
#         eveniment = Eveniment(id_eveniment, data, timp, descriere)
#         error = validare_eveniment.validare_eveniment(eveniment)
#         if len(error) == 0:
#             lista_evenimente.add_eveniment(eveniment)
#
#         id_eveniment = '-2'
#         data = '23ty'
#         timp = '-1111'
#         descriere = ''
#         eveniment = Eveniment(id_eveniment, data, timp, descriere)
#         error = validare_eveniment.validare_eveniment(eveniment)
#         if len(error) == 0:
#             lista_evenimente.add_eveniment(eveniment)
#
#         id_de_cautat = '23'
#         try:
#             for event in lista_evenimente.get_lista_evenimente():
#                 if event.get_id_eveniment() == id_de_cautat:
#                     assert True
#         except id_not_found("Nu exista niciun eveniment cu id-ul cautat!"):
#             assert False
#         id_de_cautat = '-2'
#         try:
#             for event in lista_evenimente.get_lista_evenimente():
#                 if event.get_id_eveniment() == id_de_cautat:
#                     assert True
#         except id_not_found("Nu exista niciun eveniment cu id-ul cautat!"):
#             assert False
#
#     def test_stergere_lista_eveniment(self):
#         validare_evenimete = Validare_evenimente()
#         repozitory_evenimente = Repository_evenimente()
#
#         id_eveniment = '12'
#         data = '2019/4/2'
#         timp = '1111'
#         descriere = 'Balul Bobocilor de la Colegiul National "Stefan cel Mare" Suceava'
#         eveniment = Eveniment(id_eveniment, data, timp, descriere)
#         errors = validare_evenimete.validare_eveniment(eveniment)
#         if len(errors) == 0:
#             repozitory_evenimente.add_eveniment(eveniment)
#
#         id_eveniment = '1'
#         data = '2018/12/14'
#         timp = '111'
#         descriere = 'Concert Colinde de Craciun'
#         eveniment = Eveniment(id_eveniment, data, timp, descriere)
#         errors = validare_evenimete.validare_eveniment(eveniment)
#         if len(errors) == 0:
#             repozitory_evenimente.add_eveniment(eveniment)
#         id_eveniment = '-99'
#         data = ''
#         timp = '-1'
#         descriere = ''
#         eveniment = Eveniment(id_eveniment, data, timp, descriere)
#         errors = validare_evenimete.validare_eveniment(eveniment)
#         if len(errors) == 0:
#             repozitory_evenimente.add_eveniment(eveniment)
#
#         id_de_cautat = '123'
#         try:
#             srv = Service_evenimente(validare_evenimete, repozitory_evenimente)
#             srv.sterge_eveniment_din_lista(id_de_cautat)
#             if len(srv.get_repository_evenimente().get_lista_evenimente()) == 2:
#                 assert False
#         except Exception as errors:
#             assert True
#
#
# def run_all_tests():
#     test_p = adauga_persoana_teste()
#     test_e = adauga_eveniment_teste()
#
#     test_p.test_creeaza_persoana()
#     test_p.test_validare_persoana()
#     test_p.test_cautare_persoana()
#     test_p.test_inlocuire_persoana()
#     test_p.test_sort_by_id()
#     test_p.test_stergere_lista_persoana()
#
#     test_e.adaugare_eveniment_test()
#     test_e.validare_eveniment()
#     test_e.adaugare_eveniment_test()
#     test_e.test_stergere_lista_eveniment()
#
#
# run_all_tests()
