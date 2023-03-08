#
# class Service:
#     def __init__(self):
#         self.repository_persoane = []
#         self.repository_evenimente = []
#
#     @property
#     def get_repository_persoane(self):
#         return self.repository_persoane
#
#     @property
#     def get_repository_evenimente(self):
#         return self.repository_evenimente
#
#     def validare_persoane(self, persoana):
#
#         id = persoana.get_id_persoana()
#         nume = persoana.get_nume()
#         ok = True
#         if id.isnumeric():
#             assert True
#         else:
#             raise Exception("id_persoana invalid!")
#         spatii = nume.count(" ")
#         lista_nume = nume.split(" ", spatii + 1)
#         for i in range(0, len(lista_nume)):
#             if not lista_nume[i].isalpha():
#                 ok = False
#                 break
#         if ok:
#             assert True
#         else:
#             raise Exception("nume invalid!")
#         adresa = persoana.get_adresa()
#         if len(adresa) > 0:
#             assert True
#         else:
#             raise Exception("adresa invalida!")
#
#     def adaugare_persoana(self, persoana):
#         if self.validare_persoane(persoana):
#             length_persoana = len(self.repository_persoane)
#             if length_persoana > 0:
#                 for i in range(0, length_persoana):
#                     if self.repository_persoane[i].get_id_persoana == persoana.get_id_persoana:
#                         raise Exception("Exista o persoana cu acest id")
#             self.repository_persoane.append(persoana)
#
#     def cautare_persoana(self, id_persoana):
#         length_persoana=len(self.repository_persoane)
#         if length_persoana >0:
#             for i in range(0, length_persoana):
#                 if self.repository_persoane[i].get_id_persoana == id_persoana:
#                     assert True
#                 else:
#                     raise Exception("Persoana cu id-ul acesta nu a fost gasita!")
#
#     def validare_evenimente(self, eveniment):
#
#         id = eveniment.get_id_eveniment()
#         if id.isnumeric():
#             assert True
#         else:
#             raise Exception("id_eveniment invalid!")
#
#         data = eveniment.get_data()
#         if data.datetime():
#             assert True
#         else:
#             raise Exception("data este invalida")
#
#         timp = eveniment.get_timp()
#         if timp.isnumeric():
#             assert True
#         else:
#             raise Exception("timpul introdus este unul invalid!")
#
#         descriere = eveniment.get_desciere()
#         if len(descriere) > 0:
#             assert True
#         else:
#             raise Exception("descrierea evenimentului nu exista!")
#
#     def adaugare_eveniment(self, eveniment):
#         if self.validare_evenimente(eveniment):
#             length_eveniment = len(self.repository_evenimente)
#             if length_eveniment > 0:
#                 for i in range(0, length_eveniment):
#                     if self.repository_evenimente[i] == eveniment.get_id_eveniment:
#                         raise Exception("Un eveniment cu acest id a fost introdus!")
#             else:
#                 self.repository_evenimente.append(eveniment)
#
#     def cautare_eveniment(self, id_eveniment):
#         length_eveniment = len(self.repository_evenimente)
#         if length_eveniment > 0:
#             for i in range(0, length_eveniment):
#                 if self.repository_evenimente[i].get_id_persoana == id_eveniment:
#                     assert True
#                 else:
#                     raise Exception("Evenimentul cu id-ul acesta nu a fost gasit!")
#
#     def adauga_persoana_la_eveniment(self, id_persoana, id_eveniment):
#             len0=len(self.repository_evenimente)
#             for i in range (0, len0):
#                 if self.repository_evenimente[i].get_id_eveniment() == id_eveniment:
#                     eveniment1=self.repository_evenimente[i]
#                     l=len(eveniment1.get_lista_invitati)
#                     lista_event = eveniment1.get_lista_invitati()
#                     if l>0:
#                         for i in range (0, l):
#                             if lista_event[i].get_id_persoana() == id_persoana:
#                                 raise Exception("Persoana aceasta a fost deja invitata!")
#                             else:
#                                 len1=len(self.repository_persoane)
#                                 for i in range(0, len1):
#                                     if self.repository_persoane[i].get_id_persoana==id_persoana:
#                                         persoana1=self.repository_persoane[i]
#                                         lista_event.append(persoana1)
#                                         return
#                         raise Exception("Persoana cautata nu exista!")
#             raise Exception ("Evenimentul cautat nu exista!")
