def inmultirea_cu_o_cifra(numar, cifra, baza):
    """
    Functia returneaza rezultatul inmultirii dintre numarul "numar" si cifra "cifra"
    :param numar: string
    :param cifra: string
    :param baza: int
    :return: produs - string
    """
    conversii_1 = {'0': 0, '1': 1, '2': 2, '3': 3, '4': 4, '5': 5, '6': 6, '7': 7, '8': 8, '9': 9, 'A': 10, 'B': 11,
                   'C': 12, 'D': 13, 'E': 14, 'F': 15}
    conversii_2 = {0: '0', 1: '1', 2: '2', 3: '3', 4: '4', 5: '5', 6: '6', 7: '7', 8: '8', 9: '9', 10: 'A', 11: 'B',
                   12: 'C', 13: 'D', 14: 'E', 15: 'F'}

    l_nr = len(numar)
    produs = ""
    transport = 0
    for i in range(l_nr - 1, -1, -1):
        cifra_rezultat = conversii_1[cifra] * conversii_1[numar[i]] + transport
        transport = cifra_rezultat // baza
        produs += conversii_2[cifra_rezultat % baza]
    produs += conversii_2[transport]
    produs = produs[::-1]
    while produs[0] == '0' and len(produs) > 1:
        produs = produs[1:]
    return produs
