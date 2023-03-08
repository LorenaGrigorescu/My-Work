from Adaugare.adaugare import adaugare
from Inmultirea_cu_o_cifra.inmultire_cu_o_cifra import inmultirea_cu_o_cifra


def conversie_substitutie(numar, baza_initiala, baza_finala):
    """
    Functia converteste cu ajutorul metodei substitutiei un numar dintr-o baza in alta
    :param numar: string
    :param baza_initiala: int
    :param baza_finala: int
    :return: string
    """
    conversii_1 = {'0': 0, '1': 1, '2': 2, '3': 3, '4': 4, '5': 5, '6': 6, '7': 7, '8': 8, '9': 9, 'A': 10, 'B': 11,
                   'C': 12, 'D': 13, 'E': 14, 'F': 15}
    conversii_2 = {0: '0', 1: '1', 2: '2', 3: '3', 4: '4', 5: '5', 6: '6', 7: '7', 8: '8', 9: '9', 10: 'A', 11: 'B',
                   12: 'C', 13: 'D', 14: 'E', 15: 'F'}
    rezultat = "0"
    putere_baza = 0
    for i in range(len(numar) - 1, -1, -1):
        cifra_curenta = numar[i]
        for j in range(0, putere_baza):
            cifra_curenta = inmultirea_cu_o_cifra(cifra_curenta, str(baza_initiala), baza_finala)
        rezultat = adaugare(rezultat, cifra_curenta, baza_finala)
        putere_baza += 1
    return rezultat

numar = conversie_substitutie('110022', 3, 7)
# print(numar)