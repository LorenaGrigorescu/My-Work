from Adaugare.adaugare import adaugare
from ConversieBazaIntermediara.conversie_baza_intermediara import conversie_baza_intermediara
from ConversieSubstitutie.conversie_substitutie import conversie_substitutie
from ConversiiRapide.conversiirapide import conversie_rapida
from ImpartireLaOCifra.impartirea_la_o_cifra import impartirea_la_o_cifra
from ImpartiriSuccesive.impartirisuccesive import impartire_succ
from Inmultirea_cu_o_cifra.inmultire_cu_o_cifra import inmultirea_cu_o_cifra
from Scadere.scadere import scadere
from Validatori.validatori import Validare_baza, Vaidare_numar_pentru_baza


class Teste_Functii:
    def test_validare_baza_numeratie(self):
        try:
            Validare_baza("12")
            assert True
        except Exception:
            assert False
        try:
            Validare_baza('190')
            assert False
        except Exception:
            assert True

    def test_validare_numar_pentru_baza(self):
        try:
            Vaidare_numar_pentru_baza('123', '8')
            assert True
        except Exception:
            assert False

        try:
            Vaidare_numar_pentru_baza('124', '3')
            assert False
        except Exception:
            assert True

    def test_adaugare(self):
        numar1 = '4031'
        numar2 = '344'
        baza = 5
        rezultat = adaugare(numar1, numar2, baza)
        assert rezultat == '4430'

        numar1 = 'AB45'
        numar2 = 'FF9E'
        baza = 16
        rezultat = adaugare(numar1, numar2, baza)
        assert rezultat == '1AAE3'

    def test_scadere(self):
        numar1 = '564'
        numar2 = '79'
        baza = 10
        rezultat = scadere(numar1, numar2, baza)
        assert rezultat == '0485'

        numar1, numar2 = numar2, numar1
        rezultat = scadere(numar1, numar2, baza)
        assert rezultat == '0485'

        numar1 = 'A79'
        numar2 = 'B10'
        baza = 12
        rezultat = scadere(numar1, numar2, baza)
        assert rezultat == '0053'

    def test_inmultire_cu_o_cifra(self):
        numar = '1256'
        cifra = '3'
        baza = 8
        rezultat = inmultirea_cu_o_cifra(numar, cifra, baza)
        assert rezultat == '4012'

        numar = 'AB1'
        cifra = 'C'
        baza = 15
        rezultat = inmultirea_cu_o_cifra(numar, cifra, baza)
        assert rezultat == '88CC'

    def test_impartire_la_o_cifra(self):
        numar = '1873'
        cifra = '6'
        baza = 9
        rezultat = impartirea_la_o_cifra(numar, cifra, baza)
        assert rezultat == '286 3'

    def test_conversie_rapida(self):
        numar = '1100111'
        baza_initiala = 2
        baza_finala = 8
        rezultat = conversie_rapida(numar,baza_initiala,baza_finala)
        assert rezultat == '147'
        numar = '147'
        baza_initiala = 8
        baza_finala = 2
        rezultat = conversie_rapida(numar,baza_initiala,baza_finala)
        assert rezultat == '001100111'
        numar = 'AE3'
        baza_initiala = 16
        baza_finala = 8
        rezultat = conversie_rapida(numar, baza_initiala ,baza_finala)
        assert rezultat == '5343'
        numar = '5343'
        baza_initiala = 8
        baza_finala = 16
        rezultat = conversie_rapida(numar,baza_initiala, baza_finala)
        assert rezultat == 'AE3'

    def test_impartiri_succesive(self):
        numar = '653'
        baza_initiala = 7
        baza_finala = 3
        rezultat = impartire_succ(numar, baza_initiala, baza_finala)
        assert rezultat == '110022'

    def test_conversie_baza_intermediara(self):
        numar = '653'
        baza_initiala = 7
        baza_finala = 3
        rezultat = conversie_baza_intermediara(numar, baza_initiala, baza_finala)
        assert rezultat == '110022'

    def test_conversie_substitutie(self):
        numar = '110022'
        baza_initiala = 3
        baza_finala = 7
        rezultat = conversie_substitutie(numar, baza_initiala, baza_finala)
        assert rezultat == '653'

    def run_all_test(self):
        print("Run all test...")
        self.test_validare_baza_numeratie()
        self.test_validare_numar_pentru_baza()
        self.test_adaugare()
        self.test_scadere()
        self.test_inmultire_cu_o_cifra()
        self.test_impartire_la_o_cifra()
        self.test_conversie_rapida()
        self.test_impartiri_succesive()
        self.test_conversie_baza_intermediara()
        self.test_conversie_substitutie()
        print("Every test has successfully passed!")
