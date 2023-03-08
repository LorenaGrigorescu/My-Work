class Persoane_zi_DTO:
    def __init__(self, zi, nr_invitati):
        self.__zi = zi
        self.__nr_invitati = nr_invitati

    def get_zi(self):
        return self.__zi

    def get_nr_invitati(self):
        return self.__nr_invitati

    def set_nr_invitati(self, other):
        self.__nr_invitati = other
        return self.__nr_invitati

    def __str__(self):
        return f"In ziua de {self.__zi} au fost {str(self.__nr_invitati)} invitati."

    __repr__ = __str__


class Evenimente_persoana_DTO:
    def __init__(self, list_evenimente_persoana):
        self.__list_evenimente_persoana = list_evenimente_persoana
        self.__descriere = ''
        self.__data = ''

    def get_data(self):
        return self.__data

    def get_descriere(self):
        return self.__descriere

    def get_list_event_pers(self):
        return self.__list_evenimente_persoana

    def __str__(self):
        return f"Persoana a fost invitata la aceste evenimente : {self.__list_evenimente_persoana}"

    __repr__ = __str__


class Invitati_DTO:
    def __init__(self, nume, nr_evenimente):
        self.__nume = nume
        self.__nr_evenimente = nr_evenimente

    def get_nr_evenimente(self):
        return self.__nr_evenimente

    def __str__(self):
        return f"Persoana cu numele {self.__nume} a fost invitata la {str(self.__nr_evenimente)} (de) evenimente.\n"

    __repr__ = __str__


class Evenimente_populare_DTO:
    def __init__(self, descriere, nr_invitati):
        self.__descriere = descriere
        self.__nr_invitati = nr_invitati

    def get_nr_participanti(self):
        return self.__nr_invitati

    def get_descriere(self):
        return self.__descriere

    def __str__(self):
        return f"Primele 20% evenimente populare sunt {self.__descriere} si la care participa {self.__nr_invitati}.\n"

    __repr__ = __str__


class PersoaneEvenimente_DTO:
    def __init__(self, id_asig, id_pers, id_event):
        self.__id_asig = id_asig
        self.__id_pers = id_pers
        self.__persoana = None
        self.__id_event = id_event
        self.__eveniment = None

    def get_id_asig(self):
        return self.__id_asig

    def get_id_pers(self):
        return self.__id_pers

    def get_id_event(self):
        return self.__id_event

    def get_persoana(self):
        return self.__persoana

    def get_eveniment(self):
        return self.__eveniment

    def set_persoana(self, other):
        self.__persoana = other

    def set_eveniment(self, other):
        self.__eveniment = other

    def __str__(self):
        return self.__persoana.get_nume() + "[" + str(self.__eveniment.get_descriere()) + "]"

    def __eq__(self, other):
        return self.__id_asig == other.__id_asig

    __repr__ = __str__


class EvenimentePersoane_DTO:
    def __init__(self, nume_event, lista_persoane):
        self.__nume_event = nume_event
        self.__lista_persoane = lista_persoane

    def __str__(self):
        st = ''
        st = st + self.__nume_event + ':\n'
        for persoana in self.__lista_persoane:
            st += '\t' + str(persoana) + '\n'
        return st

    __repr__ = __str__
