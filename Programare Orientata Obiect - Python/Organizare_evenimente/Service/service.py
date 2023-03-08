from Domain.Dtos.dtos import Persoane_zi_DTO, Invitati_DTO, Evenimente_populare_DTO, PersoaneEvenimente_DTO
from Erori.Errors import *
from Domain.domain import *
from Validator.validators import *
import string
from random import *

from sortari.comb import Comb_Sort, Sorter
from sortari.insertion import Insertion_Sorter


class Service_persoane:
    def __init__(self, persoana_validator, repository_persoane):
        self.__persoana_validator = persoana_validator
        self.__repository_persoane = repository_persoane

    def get_all_persoane(self):
        return self.__repository_persoane.get_lista_persoane()

    def adaugare_persoana(self, id_persoana, nume, adress):
        """
        Adauga o persoana in lista repo
        :param id_persoana: str
        :param nume: str
        :param adress: str
        :return: -
        """
        persoana = Persoana(id_persoana, nume, adress)
        validare_persoana = Validare_persoana()
        errors = validare_persoana.validare_persoana(persoana)
        if len(errors) > 0:
            raise Exception(errors)
        persoana = Persoana(id_persoana, nume, adress)
        self.__persoana_validator.validare_persoana(persoana)
        self.__repository_persoane.add_persoana(persoana)

    def cautare_persoana(self, id_persoana):
        """
        Functia cauta un ob de tip persoana in lista repo_persoane
        :param id_persoana: str
        :return: 1 dacaa fost gasita si 0 altfel
        """
        for persoana in self.__repository_persoane.get_lista_persoane():
            if persoana.get_id_persoana() == id_persoana:
                return 1
        return 0

    def cautare_persoana_r(self, i, id):
        if i >= len(self.get_all_persoane()):
            return 0
        else:
            if self.get_all_persoane()[i].get_id_persoana() == id and i < len(self.get_all_persoane()):
                return 1
        return self.cautare_persoana_r(i + 1, id)


    def modifica_nume_persoana(self, nume_initial, nume_final):
        """
        Functia modifica id ul unei persoane cu un altul
        :param nume_initial: str
        :param nume_final: str
        :return: -
        """
        global persoana_cautata
        ok_p = 0
        for persoana in self.__repository_persoane.get_lista_persoane():
            if persoana.get_nume() == nume_initial:
                persoana_cautata = persoana
                ok_p = 1
        if ok_p == 1:
            persoana_cautata.set_nume_persoana(nume_initial, nume_final)
            return 1
        else:
            raise Exception("Persoana cu numele cautat nu exista!")


    def sterge_persoana_lista(self, id_persoana_de_cautat):
        """
        Functia sterge o persoana dupa id ul cautat din lista
        :param id_persoana_de_cautat: str
        :return: -
        """
        self.__repository_persoane.sterge_persoana(id_persoana_de_cautat)


    def random_generate_id_persoana(self):
        return randrange(1, 10000)


    def random_generate_person_name(self):
        person_name_len = randrange(1, 10)
        nume_persoana = ''
        for i in range(person_name_len):
            nume_persoana = nume_persoana + choice(string.ascii_letters)
        return nume_persoana


    def random_generate_person_adress(self):
        person_adress_len = randrange(1, 10)
        person_adress = ''
        for i in range(person_adress_len):
            person_adress = person_adress + choice(string.ascii_letters)
        return person_adress


class Service_evenimente:
    def __init__(self, eveniment_validator, repository_evenimente):
        self.__eveniment_validator = eveniment_validator
        self.__repository_evenimente = repository_evenimente

    def get_all_evenimente(self):
        return self.__repository_evenimente.get_lista_evenimente()

    def adaugare_eveniment(self, id_eveniment, data, timp, descriere):
        """
        Functia adauga un element de tip Eveniment in lista
        :param id_eveniment: str
        :param data:str
        :param timp:str
        :param descriere:str
        :return:-
        """
        eveniment = Eveniment(id_eveniment, data, timp, descriere)
        validare_eveniment = Validare_evenimente()
        errors = validare_eveniment.validare_eveniment(eveniment)
        if len(errors) > 0:
            raise Exception(errors)
        for event in self.__repository_evenimente.get_lista_evenimente():
            if event.get_id_eveniment() == id_eveniment:
                raise id_not_available("Acest eveniment deja exista!")
        eveniment = Eveniment(id_eveniment, data, timp, descriere)
        self.__eveniment_validator.validare_eveniment(eveniment)
        self.__repository_evenimente.add_eveniment(eveniment)

    def cautare_eveniment(self, id_eveniment):
        """
        Functia cauta un eveniment dupa id
        :param id_eveniment: str
        :return: 1 daca a fost gasit si 0 altfel
        """
        for eveniment in self.__repository_evenimente.get_lista_evenimente():
            if eveniment.get_id_eveniment() == id_eveniment:
                return 1
        return 0

    def cautare_eveniment_r(self, i, id_eveniment):
        if i >= len(self.get_all_evenimente()):
            return 0
        else:
            if self.get_all_evenimente()[i].get_id_eveniment() == id_eveniment and i < len(self.get_all_evenimente()):
                return 1
        return self.cautare_eveniment_r(i + 1, id_eveniment)

    def modifica_data_eveniment(self, data_initiala, data_finala):
        """
        Functia modifica data unui eveniment
        :param data_initiala: date string
        :param data_finala: date string
        :return:
        """
        global eveniment_cautat
        ok_e = 0
        for event in self.__repository_evenimente.get_lista_evenimente():
            if event.get_data() == data_initiala:
                eveniment_cautat = event
                ok_e = 1
                break
        if ok_e:
            eveniment_cautat.update_data_eveniment(data_initiala, data_finala)
        else:
            raise Exception("Nu exista vreun eveniment care sa se desfasoare in data_initiala!")

    def sterge_eveniment_din_lista(self, id_event_de_cautat):
        """
        Functia sterge un eveniment dupa id ul introdus
        :param id_event_de_cautat: str
        :return:
        """
        return self.__repository_evenimente.sterge_eveniment(id_event_de_cautat)

    def generate_random_id_eveniment(self):
        return randrange(1, 10000)

    def generate_random_time_event(self):
        return randrange(1, 1000)

    def generate_random_an_event(self):
        return randrange(2000, 2021)

    def generate_random_luna_event(self):
        return randrange(1, 12)

    def generate_random_zi_event(self):
        return randrange(1, 31)

    def generate_random_description_event(self):
        len_adress_event = randrange(1, 100)
        adress_event = ''
        for i in range(len_adress_event):
            adress_event = adress_event + choice(string.ascii_letters)
        return adress_event


class Service_asignare_pers_event:
    def __init__(self, validare_asig, repozitory_persoane, repozitory_evenimente,
                 repository_asig):
        self.__validare_asig = validare_asig
        self.__repository_persoane = repozitory_persoane
        self.__repository_evenimente = repozitory_evenimente
        self.__repository_asig = repository_asig

    def get_all_asignari(self):
        persoane_evenimente_dtos = self.__repository_asig.get_lista_persoane_la_evenimente()
        for pers_event in persoane_evenimente_dtos:
            id_event = pers_event.get_id_event()
            id_pers = pers_event.get_id_pers()
            event = self.__repository_evenimente.cauta_dupa_id(id_event)
            pers = self.__repository_persoane.cauta_dupa_id(id_pers)
            pers_event.set_eveniment(event)
            pers_event.set_persoana(pers)
        return persoane_evenimente_dtos

    def adauga_persoana_la_eveniment(self, id_asig, id_persoana, id_eveniment):
        """
        Functia adauga la lista repository_asignare o pereche de forma [eveniment, persoana] fiecare din repozitoriul sau
        :param id_asig: str
        :param id_persoana: str
        :param id_eveniment: str
        :return:
        """
        asignare = PersoaneEvenimente_DTO(id_asig, id_persoana, id_eveniment)
        self.__repository_asig.add_persoana_la_eveniment(asignare)

    def sterge_persoana_la_eveniment(self, id_asignare):
        """
        Functia sterge din lista repository_asignare perechea [eveniment, persoana] cu id-urile respective. In caz contrar, se produce eroare de stergere
        :param id_asignare: string numeric, cauta asignarea pt a fi stearsa
        :return: -
        """
        return self.__repository_asig.sterge_persoana_eveniment(id_asignare)

    def cauta_persoana_in_evenimente(self, id_asignare):
        """
        Functia cauta perechea [eveniment, persoana] cu id-urile corespunzatoare in lista de asignare
        :param id_asignare: string numeric, invitatul care doreste a fi cautat la un eveniment
        """
        dto_asig = self.__repository_asig.cauta_persoana_eveniment(id_asignare)
        id_pers = dto_asig.get_id_pers()
        id_event = dto_asig.get_id_event()
        pers = self.__repository_persoane.cauta_dupa_id(id_pers)
        event = self.__repository_evenimente.cauta_dupa_id(id_event)
        dto_asig.set_persoana(pers)
        dto_asig.set_eveniment(event)
        return dto_asig

    def raport_top_3_zile(self):
        """
        Functia returneaza primele 3 perechi de forma [zi, numar de invitati], reprezentand zilele in care au participat cele mai multe persoane
        :return: list
        """
        lista_zile = []
        pers_zi = []
        for evenimente in self.__repository_evenimente.get_lista_evenimente():
            zi = evenimente.get_zi()
            if zi not in lista_zile:
                lista_zile.append(zi)
        for zi in lista_zile:
            nr_invitati = 0
            for asig in self.__repository_asig.get_lista_persoane_la_evenimente():
                id_eveniment = asig.get_id_event()
                event = self.__repository_evenimente.cauta_dupa_id(id_eveniment)
                asig.set_eveniment(event)
                if asig.get_eveniment().get_zi() == zi:
                    nr_invitati += 1
            persoana_zi_dto = Persoane_zi_DTO(zi, nr_invitati)
            pers_zi.append(persoana_zi_dto)
        sort = Comb_Sort()
        # sort.QuickSort(pers_zi, key=lambda x: x.get_nr_invitati(), reversed=True)
        sort.sort(pers_zi, key=lambda x: x.get_nr_invitati(), reversed=False)
        # pers_zi.sort(key=lambda x: x.get_nr_invitati(), reverse=True)
        l = len(pers_zi)
        if l >= 3:
            return pers_zi[:3]
        else:
            raise Exception("Lista contine prea putine evenimente!")

    def raport_lista_evenimente_persoana(self, id_persoana):
        """
        Functia returneaza toate evenimentele la care o persoana anume este invitata
        :param id_persoana: string numeric, reprezinta id-ul persoanei a carei lista de evenimente dorim sa o aflam
        :return: list
        """
        list_event_persoana = []  # lista cu evenimente la care participa persoana cu id-ul id_persoana
        asignari = self.__repository_asig.get_lista_persoane_la_evenimente()
        for _asignare in asignari:
            if _asignare.get_id_pers() == id_persoana:
                id_event = _asignare.get_id_event()
                event = self.__repository_evenimente.cauta_dupa_id(id_event)
                pers = self.__repository_persoane.cauta_dupa_id(id_persoana)
                _asignare.set_eveniment(event)
                _asignare.set_persoana(pers)
                list_event_persoana.append(event)
        l_e = len(list_event_persoana)  # lungimea listei de evenimente la care participa persoana
        sorter = Comb_Sort()
        sorterS = Sorter()
        sorter.sort(l_e, key=lambda x:x, cmp=sorterS.cmpNou, reversed=False)
        # for i in range(0, l_e - 1):
        #     for j in range(i + 1, l_e):
        #         if list_event_persoana[i].get_descriere() < list_event_persoana[j].get_descriere():
        #             # primul criteriu de sortare este descrierea evenimentelor
        #             aux = list_event_persoana[i]
        #             list_event_persoana[i] = list_event_persoana[j]
        #             list_event_persoana[j] = aux
        #         elif list_event_persoana[i].get_descriere() == list_event_persoana[j].get_descriere():
        #             # daca evenimentele au aceeasi descriere, data este urmatorul criteriu de sortare
        #             if list_event_persoana[i].get_data() < list_event_persoana[j].get_data():
        #                 aux = list_event_persoana[i]
        #                 list_event_persoana[i] = list_event_persoana[j]
        #                 list_event_persoana[j] = aux

        if len(list_event_persoana) != 0:
            return list_event_persoana
        else:
            raise Exception("Aceasta lista este goala!")

    def raport_persoane_participante_evenimente(self):
        """
        Functia returneaza toate perechile de forma [persoana, numar evenimente] in ordine descrescatoare dupa numarul de eveneminte la care este invitata
        :return: list
        """
        lp = []  # lista de persoane participante la evenimente insotite de numarul de evenimente
        asignari = self.__repository_asig.get_lista_persoane_la_evenimente()
        persoane = self.__repository_persoane.get_lista_persoane()

        for persoana in persoane:
            nr_event = 0
            id_persoana = persoana.get_id_persoana()
            nume = persoana.get_nume()
            for pereche in asignari:
                if pereche.get_id_pers() == id_persoana:
                    pereche.set_persoana(persoana)
                    nr_event += 1
            persoana_dto = Invitati_DTO(nume, nr_event)
            lp.append(persoana_dto)
        # lp.sort(key=lambda x: x.get_nr_evenimente(), reverse=True)
        sort = Insertion_Sorter()
        sort.sort(lp, key=lambda x: x.get_nr_evenimente(), reversed=True)
        l_lp = len(lp)
        if l_lp > 0:
            return lp
        else:
            raise Exception("Nu aveti nicio asignare facuta!")

    def raport_evenimente_populare(self):
        """
        Functia returneaza perechile de forma [descriere, numar invitati] ale primelor 20% din cele mai populare evenimente
        :return: list
        """
        le = []  # lista de evenimente la care participa cele mai multe persoane (se vor stoca doar descrierea si data acestuia)

        asignari = self.__repository_asig.get_lista_persoane_la_evenimente()
        evenimente = self.__repository_evenimente.get_lista_evenimente()

        for eveniment in evenimente:
            nr_participanti = 0
            id_eveniment = eveniment.get_id_eveniment()
            descriere = eveniment.get_descriere()
            for asignare in asignari:
                if asignare.get_id_event() == id_eveniment:
                    asignare.set_eveniment(eveniment)
                    nr_participanti += 1
            event_dto = Evenimente_populare_DTO(descriere, nr_participanti)
            le.append(event_dto)
        l_le = len(le)
        if l_le >= 5:
            l_le = int(l_le / 5)
            return le[:l_le]
        else:
            raise Exception("Lista este goala sau ati introdus mai putin de 5 asignari!")
