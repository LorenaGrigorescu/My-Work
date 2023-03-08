def impartirea_la_o_cifra(numar, cifra, baza):
    """
    Functia efectueaza impartirea unui numar 'numar' la cifra 'cifra' in baza 'baza'
    :param numar: string
    :param cifra: string
    :param baza: int
    :return: cat si rest - string, string
    """
    conversii_1 = {'0': 0, '1': 1, '2': 2, '3': 3, '4': 4, '5': 5, '6': 6, '7': 7, '8': 8, '9': 9, 'A': 10, 'B': 11,
                   'C': 12, 'D': 13, 'E': 14, 'F': 15}
    conversii_2 = {0: '0', 1: '1', 2: '2', 3: '3', 4: '4', 5: '5', 6: '6', 7: '7', 8: '8', 9: '9', 10: 'A', 11: 'B',
                   12: 'C', 13: 'D', 14: 'E', 15: 'F'}
    cat = ""
    rest = ""
    l_nr = len(numar)
    transport = 0
    for i in range(0, l_nr):
        cifra_rezultat = transport * baza + conversii_1[numar[i]]
        cifra_rezultat_cat = cifra_rezultat // conversii_1[cifra]
        transport = cifra_rezultat % conversii_1[cifra]
        cat += conversii_2[cifra_rezultat_cat]
    rest = conversii_2[transport]
    rest=rest[::-1]
    while cat[0] == '0' and len(cat) > 1:
        cat = cat[1:]
    return cat + " " + rest