class Persoana:
    def __init__(self, id_persoana, nume, adresa):
        self.__id_persoana = id_persoana
        self.__nume = nume
        self.__adresa = adresa

    def get_id_persoana(self):
        return self.__id_persoana

    def get_nume(self):
        return self.__nume

    def get_adresa(self):
        return self.__adresa

    def set_id_persoana(self, id_persoana1):
        self.__id_persoana = id_persoana1
        return self.__id_persoana

    def set_nume_persoana(self, nume, nume1):
        if self.__nume == nume:
            self.__nume = nume1

    def __str__(self):
        return "id_persoana:{}\nnume:{}\nadresa:{}".format(self.__id_persoana, self.__nume, self.__adresa)

    def __eq__(self, other):
        return self.__id_persoana == other.__id_persoana

    __repr__ = __str__


class Eveniment:
    def __init__(self, id_eveniment, data, timp, descriere):
        self.__id_eveniment = id_eveniment
        self.__data = data
        self.__timp = timp
        self.__descriere = descriere

    def get_id_eveniment(self):
        return self.__id_eveniment

    def get_data(self):
        return self.__data

    def get_zi(self):
        an, zi, luna = self.__data.split('/')
        return zi

    def set_data(self, data_initiala, data_finala):
        if self.__data == data_initiala:
            self.__data = data_finala

    def get_timp(self):
        return self.__timp

    def get_descriere(self):
        return self.__descriere

    def __str__(self):
        return "id_eveniment:{}\ndata:{}\ntimp:{}\ndescriere:{}".format(self.__id_eveniment, self.__data, self.__timp,
                                                                        self.__descriere)

    def __eq__(self, other):
        return self.__id_eveniment == other.get_id_eveniment()

    __repr__ = __str__


class Asignare_per_event():
    def __init__(self, id_asig, persoana, eveniment):
        self.__id_asig = id_asig
        self.__persoana = persoana
        self.__eveniment = eveniment

    def get_id_asig(self):
        return self.__id_asig

    def get_persoana(self):
        return self.__persoana

    def get_eveniment(self):
        return self.__eveniment

    def __str__(self):
        return "id_asig:{}\persoana:{}\neveniment:{}".format(self.__id_asig,
                                                             self.__persoana,
                                                             self.__eveniment,
                                                             )

    __repr__ = __str__


