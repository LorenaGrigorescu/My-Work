from ImpartiriSuccesive.impartirisuccesive import impartire_succ


def conversie_baza_intermediara(numar, baza_initiala, baza_finala):
    """
    Functia converteste numarul din baza initiala in baza finala folosind sistemul decimal ca baza intermediara
    :param numar: string
    :param baza_initiala: int
    :param baza_finala: int
    :return: string
    """
    conversii = {0: '0', 1: '1', 2: '2', 3: '3', 4: '4', 5: '5', 6: '6', 7: '7', 8: '8', 9: '9', 10: 'A', 11: 'B',
                 12: 'C', 13: 'D', 14: 'E', 15: 'F'}
    intermediar = impartire_succ(numar, baza_initiala, 10)
    rezultat = impartire_succ(intermediar, 10, baza_finala)
    return rezultat

numar = conversie_baza_intermediara('653', 7, 3)
# print(numar)
