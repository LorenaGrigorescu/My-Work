from ImpartireLaOCifra.impartirea_la_o_cifra import impartirea_la_o_cifra


def impartire_succ(numar, baza_initiala, baza_finala):
    """
    Functia converteste numarul "numar" din baza_initiala in baza_finala
    :param numar: string
    :param baza_initiala: int
    :param baza_finala: int
    :return:
    """
    conversii = {0: '0', 1: '1', 2: '2', 3: '3', 4: '4', 5: '5', 6: '6', 7: '7', 8: '8', 9: '9', 10: 'A', 11: 'B',
                 12: 'C', 13: 'D', 14: 'E', 15: 'F'}
    # vector_resturi = []
    rezultat = ""
    cat, rest = impartirea_la_o_cifra(numar, conversii[baza_finala], baza_initiala).split(" ")
    rezultat += rest
    # vector_resturi.append(rest)
    while cat != '0':
        cat_curent, rest_curent = impartirea_la_o_cifra(cat, conversii[baza_finala], baza_initiala).split(" ")
        cat = cat_curent
        rest = rest_curent
        # vector_resturi.append(rest)
        rezultat += rest
    rezultat = rezultat[::-1]
    return rezultat


numar = impartire_succ('653', 7, 3)
# print(numar)
