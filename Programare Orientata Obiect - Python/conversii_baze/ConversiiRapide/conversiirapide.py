def conversie_rapida(numar, baza_initiala, baza_finala):
    """
    Functia realizeaza conversii rapide intre bazele 2, 4, 8, 16
    :param numar: string
    :param baza_initiala: int
    :param baza_finala: int
    :return: rezultat - numarul convertit in baza finala
    """
    conversii_1 = {'0': 0, '1': 1, '2': 2, '3': 3, '4': 4, '5': 5, '6': 6, '7': 7, '8': 8, '9': 9, 'A': 10, 'B': 11,
                   'C': 12, 'D': 13, 'E': 14, 'F': 15}
    conversii_2 = {0: '0', 1: '1', 2: '2', 3: '3', 4: '4', 5: '5', 6: '6', 7: '7', 8: '8', 9: '9', 10: 'A', 11: 'B',
                   12: 'C', 13: 'D', 14: 'E', 15: 'F'}
    rezultat = ""
    if baza_initiala == 2:
        copie_baza_finala = baza_finala
        k = 0
        while copie_baza_finala > 1:
            copie_baza_finala = copie_baza_finala // 2
            k += 1
        # calculam care este putere a lui 2 este baza_finala -
        # ii cream o copie pentru a sti cate grupuri de k elemente grupam de la final spre inceput pentru a converti rapid
        if len(numar) % k != 0:
            # daca lungimea numarului nu reprezinta un multiplu al puterii determinate anterior, atunci completam cu zerouri inaintea numararului -
            # fara ca sa ii afectam valoarea si pentru a fi mai usoara gruparea
            while len(numar) % k != 0:
                numar = "0" + numar

        numar_grupuri = len(numar) // k
        # numar_grupuri reprezinta numarul de cifre ale rezultatului final
        # grupam cate k cifre binare, le convertim pe rand din string in int si calculam care este cifra din baza 2^k
        # corespunzatoare respectivului grup
        i = 0
        while i < numar_grupuri:
            grup = 0
            putere = baza_finala // 2
            for j in range(i * k, k * (i + 1)):
                grup += conversii_1[numar[j]] * putere
                putere = putere // 2
            rezultat += conversii_2[grup]
            i = i + 1
    elif baza_finala == 2:
        conversie_binara = {0: '0000', 1: '0001', 2: '0010', 3: '0011', 4: '0100', 5: '0101', 6: '0110', 7: '0111',
                            8: '1000', 9: '1001', 10: '1010', 11: '1011', 12: '1100', 13: '1101', 14: '1110', 15: '1111'}
        copie_baza_initiala = baza_initiala
        k = 0
        while copie_baza_initiala > 1:
            copie_baza_initiala = copie_baza_initiala // 2
            k += 1
        for i in range(0, len(numar)):
            cifra = conversii_1[numar[i]]
            grup = conversie_binara[cifra][4 - k:]
            rezultat += grup
    else:
        intermediar = conversie_rapida(numar, baza_initiala, 2)
        rezultat = conversie_rapida(intermediar, 2, baza_finala)
    return rezultat


numar = conversie_rapida('5343', 8, 16)
# print(numar)
# 01 100 111 - 001 100 111(2) -> 147(8)
