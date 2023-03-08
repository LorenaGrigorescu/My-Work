def scadere(numar1, numar2, baza):
    """
    Functia efectueaza scaderea a doua numere din baza "baza"
    :param numar1: string
    :param numar2: string
    :param baza: int
    :return: diferenta - string
    """

    conversii1 = {'0': 0, '1': 1, '2': 2, '3': 3, '4': 4, '5': 5, '6': 6, '7': 7, '8': 8, '9': 9, 'A': 10, 'B': 11,
                  'C': 12, 'D': 13, 'E': 14, 'F': 15}
    conversii2 = {0: '0', 1: '1', 2: '2', 3: '3', 4: '4', 5: '5', 6: '6', 7: '7', 8: '8', 9: '9', 10: 'A', 11: 'B',
                  12: 'C', 13: 'D', 14: 'E', 15: 'F'}
    zerouri = ""
    if len(numar1) > len(numar2):
        dif = len(numar1) - len(numar2)
        for i in range(0, dif):
            zerouri += "0"
        numar2 = zerouri + numar2
    elif len(numar1) < len(numar2):
        numar1, numar2 = numar2, numar1
        dif = len(numar1) - len(numar2)
        for i in range(0, dif):
            zerouri += "0"
        numar2 = zerouri + numar2
    else:
        if numar1 < numar2:
            numar1, numar2 = numar2, numar1

    diferenta = ""
    transport = 0
    for i in range(len(numar1) - 1, -1, -1):
        cifra_rezultat = conversii1[numar1[i]] - conversii1[numar2[i]] - transport
        transport = 0
        if cifra_rezultat < 0:
            cifra_rezultat += baza
            transport = 1
        diferenta += conversii2[cifra_rezultat]
    diferenta += conversii2[transport]
    diferenta = diferenta[::-1]
    return diferenta
