def adaugare(numar1, numar2, baza):
    """
    Functia calculeaza suma a 2 numere in baza "baza"
    :param numar1: string
    :param numar2: string
    :param baza: int
    :return: suma - string
    """
    conversii_1 = {'0': 0, '1': 1, '2': 2, '3': 3, '4': 4, '5': 5, '6': 6, '7': 7, '8': 8, '9': 9, 'A': 10, 'B': 11,
                   'C': 12, 'D': 13, 'E': 14, 'F': 15}
    conversii_2 = {0: '0', 1: '1', 2: '2', 3: '3', 4: '4', 5: '5', 6: '6', 7: '7', 8: '8', 9: '9', 10: 'A', 11: 'B',
                   12: 'C', 13: 'D', 14: 'E', 15: 'F'}

    len1 = len(numar1)
    len2 = len(numar2)
    zerouri = ""
    suma = ""
    for i in range(0, abs(len1 - len2)):
        zerouri += '0'
    if len1 > len2:
        numar2 = zerouri + numar2
    else:
        numar1 = zerouri + numar1
        len1 = len2
    transport = 0
    for i in range(len1 - 1, -1, -1):
        cifra_rezultat = conversii_1[numar1[i]] + conversii_1[numar2[i]] + transport
        transport = cifra_rezultat // baza
        suma += conversii_2[cifra_rezultat % baza]
    if transport > 0:
        suma += conversii_2[transport]
    suma = suma[::-1]
    return suma

