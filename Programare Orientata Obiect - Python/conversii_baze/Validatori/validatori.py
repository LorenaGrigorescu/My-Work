def Validare_baza(baza):
    """
    Functia valideaza daca baza este un numar natural intre 2 si 16
    :param baza: int
    :return: err - string
    """
    err = ""
    baze = {'2': 2, '3': 3, '4': 4, '5': 5, '6': 6, '7': 7, '8': 8, '9': 9, '10': 10, '11': 11,
                   '12': 12, '13': 13, '14': 14, '15': 15, '16': 16}
    if baza not in baze.keys():
        raise Exception("Baza este invalida!")


def Vaidare_numar_pentru_baza(numar, baza):
    """
    Functia valideaza numarul raportat la baza in care dorim sa efectuam operatii
    Functia verifica daca toate cifrele numarului sunt mai mici strict decat baza.
    Functia arunca ValueError daca parametrii sunt neconformi
    :param numar: string
    :param baza: string
    :return: err - string
    """
    conversii_1 = {'0': 0, '1': 1, '2': 2, '3': 3, '4': 4, '5': 5, '6': 6, '7': 7, '8': 8, '9': 9, 'A': 10, 'B': 11,
                   'C': 12, 'D': 13, 'E': 14, 'F': 15}
    err = ""
    baza = int(baza)
    for i in range(0, len(numar)):
        if conversii_1[numar[i]] >= baza:
            raise Exception("Numarul este invalid pentru aceasta baza!")
