from Domain.Dtos.dtos import PersoaneEvenimente_DTO
from Erori.Errors import Repo_Exception
from Domain.domain import Persoana, Asignare_per_event
from Domain.domain import Eveniment


class Repository_persoane:
    def __init__(self):
        self._lista_persoane = []

    def get_lista_persoane(self):
        """
        Functia preia id_ul persoanei dintr-un obiect de tip Persoana
        :return: str
        """
        return self._lista_persoane

    def add_persoana(self, other):
        """
        Functia adauga la lista de persoane un obiect de tip Persoana
        :param other: obiect de tip Persoana
        :return: -
        """
        self._lista_persoane.append(other)

    def sterge_persoana(self, id_other):
        """
        Functia sterge persoana din lista_persoane
        :param id_other: string numeric
        :return:
        """
        persoana = Persoana
        for x in self._lista_persoane:
            if x.get_id_persoana() == id_other:
                persoana = x
                break
        self._lista_persoane.remove(persoana)

    def update_nume_persoana(self, nume_initial, nume_final):
        """
        Functia modifica numeleunei persoane cu alt nume
        :param nume_initial: str
        :param nume_final: str
        :return: True/False
        """
        for x in self._lista_persoane:
            if x.get_nume() == nume_initial:
                x.set_nume_persoana(nume_initial, nume_final)
                return True
        return False

    def cauta_dupa_id(self, id_persoana):  # returneaza persoana
        ok = 0
        for persoana in self._lista_persoane:
            if persoana.get_id_persoana() == id_persoana:
                ok = 1
                return persoana
        if ok == 0:
            raise Repo_Exception("Persoana inexistenta!")


class Repository_persoane_file(Repository_persoane):

    def __init__(self, file_path):
        Repository_persoane.__init__(self)
        self.__file_path = file_path

    def __read_all_from_file(self):  # sincronizez informatia din memorie cu informatia din fisier
        self._lista_persoane = []
        with open(self.__file_path, 'r') as f:
            self._lista_persoane = []
            lines = f.readlines()
            contor = 1
            ok = 0
            for line in lines:  # se intereaza pe toate liniile din fisier
                line = line.strip()  # elimin toate caracterele de la inceputul si finalul fiecarei linii
                if len(line) > 0:
                    if contor % 3 == 1:
                        id_persoana = str(line)
                    elif contor % 3 == 2:
                        nume = str(line)
                    elif contor % 3 == 0:
                        adresa = str(line)
                        ok = 1
                    contor += 1
                if ok == 1:
                    persoana = Persoana(id_persoana, nume, adresa)
                    ok = 0
                    self._lista_persoane.append(persoana)

    def __write_all_to_file(self):
        with open(self.__file_path, 'w') as f:
            for persoana in self._lista_persoane:
                f.write(f"{persoana.get_id_persoana()}\n{persoana.get_nume()}\n{persoana.get_adresa()}\n")

    def __append_to_file(self, persoana):
        with open(self.__file_path, 'a') as f:
            f.write(f"{persoana.get_id_persoana()}\n{persoana.get_nume()}\n{persoana.get_adresa()}\n")

    def add_persoana(self, other):
        self.__read_all_from_file()
        Repository_persoane.add_persoana(self, other)
        self.__append_to_file(other)  # va fi adaugat doar daca trece de validare

    def sterge_persoana(self, id_persoana):
        self.__read_all_from_file()
        Repository_persoane.sterge_persoana(self, id_persoana)
        self.__write_all_to_file()

    def update_nume_persoana(self, nume_initial, nume_final):
        self.__read_all_from_file()
        Repository_persoane.update_nume_persoana(self, nume_initial, nume_final)
        self.__write_all_to_file()

    def cauta_dupa_id(self, id_persoana):
        self.__read_all_from_file()
        return Repository_persoane.cauta_dupa_id(self, id_persoana)

    def get_lista_persoane(self):
        self.__read_all_from_file()
        return Repository_persoane.get_lista_persoane(self)


class Repository_evenimente:
    def __init__(self):
        self._lista_evenimente = []

    def get_lista_evenimente(self):
        """
        Functia preia id_ul persoanei dintr-un obiect de tip Evenimente
        :return: str
        """
        return self._lista_evenimente

    def add_eveniment(self, other):
        """
        Functia adauga la lista de persoane un obiect de tip Eveniment
        :param other:
        :return: -
        """
        self._lista_evenimente.append(other)

    def sterge_eveniment(self, id_other):
        """
         Functia sterge din lista lista_evenimente un obiect de tip Eveniment
        :param id_other: str
        :return:
        """
        eveniment = Eveniment
        for x in self._lista_evenimente:
            if x.get_id_eveniment() == id_other:
                eveniment = x
                break
        self._lista_evenimente.remove(eveniment)

    def update_data_eveniment(self, data_initiala, data_finala):
        """
        Functia actualizeaza din
          lista lista_evenimente un obiect de tip Persoane cu un altul
        :param data_initiala: date
        :param data_finala: date
        :return:
        """
        for x in self._lista_evenimente:
            if x.get_data() == data_initiala:
                x.set_data(data_initiala, data_finala)
                return True
        return False

    def cauta_dupa_id(self, id_eveniment):
        ok = 0
        for eveniment in self._lista_evenimente:
            if eveniment.get_id_eveniment() == id_eveniment:
                ok = 1
                return eveniment
        if ok == 0:
            raise Repo_Exception("Eveniment inexistent!")


class Repository_evenimente_file(Repository_evenimente):

    def __init__(self, file_path):
        Repository_evenimente.__init__(self)
        self.__file_path = file_path

    def __read_all_from_file(self):
        self._lista_evenimente = []
        with open(self.__file_path, 'r') as f:
            self._lista_evenimente = []
            contor = 1
            ok = 0
            lines = f.readlines()
            for line in lines:
                line = line.strip()
                if len(line) > 0:
                    if contor % 4 == 1:
                        id_event = str(line)
                    elif contor % 4 == 2:
                        data = str(line)
                    elif contor % 4 == 3:
                        durata = str(line)
                    elif contor % 4 == 0:
                        descriere = str(line)
                        ok = 1
                    contor += 1
                if ok == 1:
                    eveniment = Eveniment(id_event, data, durata, descriere)
                    ok = 0
                    self._lista_evenimente.append(eveniment)

    def __write_all_to_file(self):
        with open(self.__file_path, 'w') as f:
            for eveniment in self._lista_evenimente:
                f.write(
                    f"{eveniment.get_id_eveniment()}\n{eveniment.get_data()}\n{eveniment.get_timp()}\n{eveniment.get_descriere()}\n")

    def __append_to_file(self, eveniment):
        with open(self.__file_path, 'a') as f:
            f.write(
                f"{eveniment.get_id_eveniment()}\n{eveniment.get_data()}\n{eveniment.get_timp()}\n{eveniment.get_descriere()}\n")

    def add_eveniment(self, other):
        self.__read_all_from_file()
        Repository_evenimente.add_eveniment(self, other)
        self.__append_to_file(other)

    def sterge_eveniment(self, other):
        self.__read_all_from_file()
        Repository_evenimente.sterge_eveniment(self, other)
        self.__write_all_to_file()

    def cauta_dupa_id(self, id_eveniment):
        self.__read_all_from_file()
        return Repository_evenimente.cauta_dupa_id(self, id_eveniment)

    def update_data_eveniment(self, data_initiala, data_finala):
        self.__read_all_from_file()
        Repository_evenimente.update_data_eveniment(self, data_initiala, data_finala)
        self.__write_all_to_file()

    def get_lista_evenimente(self):
        self.__read_all_from_file()
        return Repository_evenimente.get_lista_evenimente(self)


class Repository_asignare_persoana_eveniment:
    def __init__(self):
        self._lista_persoane_la_evenimente = []

    def get_lista_persoane_la_evenimente(self):
        return self._lista_persoane_la_evenimente

    def add_persoana_la_eveniment(self, other):
        if other in self._lista_persoane_la_evenimente:
            raise Repo_Exception("Asignare existenta!")
        return self._lista_persoane_la_evenimente.append(other)

    def sterge_persoana_eveniment(self, id_asignare):
        asignare_cautata = Asignare_per_event
        for asignare in self._lista_persoane_la_evenimente:
            if asignare.get_id_asig() == id_asignare:
                asignare_cautata = asignare
                break
        self._lista_persoane_la_evenimente.remove(asignare_cautata)

    def modifica_persoana_eveniment(self, eveniment, persoana, persoana1):
        for pereche in self._lista_persoane_la_evenimente:
            if pereche[0] == eveniment and pereche[1] == persoana:
                pereche[1] = persoana1
        raise Repo_Exception("Asignare existenta!")

    def cauta_persoana_eveniment(self, id_asig):
        ok = 0
        for asignari in self._lista_persoane_la_evenimente:
            if asignari.get_id_asig() == id_asig:
                ok = 1
                return asignari
        if ok == 0:
            raise Repo_Exception("Asignare inexistenta!")


class Repository_asignare_persoana_eveniment_file(Repository_asignare_persoana_eveniment):
    def __init__(self, file_path):
        Repository_asignare_persoana_eveniment.__init__(self)
        self.__file_path = file_path

    def __read_all_from_file(self):
        self._lista_persoane_la_evenimente = []
        with open(self.__file_path, 'r') as f:
            lines = f.readlines()
            contor = 1
            ok = 0
            for line in lines:
                line = line.strip()
                if len(line) > 0:
                    if contor % 3 == 1:
                        id_asig = str(line)
                    elif contor % 3 == 2:
                        id_persoana = str(line)
                    elif contor % 3 == 0:
                        id_eveniment = str(line)
                        ok = 1
                    contor += 1
                if ok == 1:
                    asignare = PersoaneEvenimente_DTO(id_asig, id_persoana, id_eveniment)
                    self._lista_persoane_la_evenimente.append(asignare)  # lista este mostenita din clasa de BAZA!

    def __write_all_to_file(self):
        with open(self.__file_path, 'w') as f:
            for asignare in self._lista_persoane_la_evenimente:
                f.write(f"{asignare.get_id_asig()}\n{asignare.get_id_pers()}\n{asignare.get_id_event()}\n")

    def __append_to_file(self, asignare):
        with open(self.__file_path, 'a') as f:
            f.write(f"{asignare.get_id_asig()}\n{asignare.get_id_pers()}\n{asignare.get_id_event()}\n")

    def add_persoana_la_eveniment(self, other):
        self.__read_all_from_file()
        Repository_asignare_persoana_eveniment.add_persoana_la_eveniment(self, other)
        self.__append_to_file(other)

    def sterge_persoana_eveniment(self, id_other):
        self.__read_all_from_file()
        Repository_asignare_persoana_eveniment.sterge_persoana_eveniment(self, id_other)
        self.__write_all_to_file()

    def cauta_persoana_eveniment(self, id_asig):
        self.__read_all_from_file()
        return Repository_asignare_persoana_eveniment.cauta_persoana_eveniment(self, id_asig)

    def get_lista_persoane_la_evenimente(self):
        self.__read_all_from_file()
        return Repository_asignare_persoana_eveniment.get_lista_persoane_la_evenimente(self)
