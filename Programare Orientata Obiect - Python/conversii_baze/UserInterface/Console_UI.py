import Adaugare.adaugare
import ConversieBazaIntermediara.conversie_baza_intermediara
import ConversieSubstitutie.conversie_substitutie
import ConversiiRapide.conversiirapide
import ImpartireLaOCifra.impartirea_la_o_cifra
import ImpartiriSuccesive.impartirisuccesive
import Inmultirea_cu_o_cifra.inmultire_cu_o_cifra
import Scadere.scadere
import Validatori.validatori


class Console:
    def adaugare_ui(self):
        numarul1 = input("Introduceti primul numar: ")
        numarul2 = input("Introduceti al doilea numar: ")
        baza = input("Introduceti baza pentru adaugare: ")
        Validatori.validatori.Validare_baza(baza)
        baza = int(baza)
        Validatori.validatori.Vaidare_numar_pentru_baza(numarul1, baza)
        Validatori.validatori.Vaidare_numar_pentru_baza(numarul2, baza)
        rezultat = Adaugare.adaugare.adaugare(numarul1, numarul2, baza)
        print("Rezultatul adunarii {} + {} = {}".format(numarul1, numarul2, rezultat))

    def scadere_ui(self):
        numarul1 = input("Introduceti primul numar: ")
        numarul2 = input("Introduceti al doilea numar: ")
        baza = input("Introduceti baza pentru scadere: ")
        Validatori.validatori.Validare_baza(baza)
        baza = int(baza)
        Validatori.validatori.Vaidare_numar_pentru_baza(numarul1, baza)
        Validatori.validatori.Vaidare_numar_pentru_baza(numarul2, baza)
        rezultat = Scadere.scadere.scadere(numarul1, numarul2, baza)
        print("Rezultatul scaderii este = {}".format(rezultat))

    def inmultire_cu_o_cifra_ui(self):
        numarul = input("Introduceti numarul: ")
        cifra = input("Introduceti cifra: ")
        baza = input("Introduceti baza pentru inmultire: ")
        Validatori.validatori.Validare_baza(baza)
        baza = int(baza)
        Validatori.validatori.Vaidare_numar_pentru_baza(numarul, baza)
        Validatori.validatori.Vaidare_numar_pentru_baza(cifra, baza)
        rezultat = Inmultirea_cu_o_cifra.inmultire_cu_o_cifra.inmultirea_cu_o_cifra(numarul, cifra, baza)
        print("Rezultatul inmultirii numarului {} cu cifra {} este {}".format(numarul, cifra, rezultat))

    def impartirea_la_o_cifra_ui(self):
        numarul = input("Introduceti numarul: ")
        cifra = input("Introduceti cifra: ")
        baza = input("Introduceti baza pentru impartirii: ")
        Validatori.validatori.Validare_baza(baza)
        baza = int(baza)
        Validatori.validatori.Vaidare_numar_pentru_baza(numarul, baza)
        Validatori.validatori.Vaidare_numar_pentru_baza(cifra, baza)
        rezultat = ImpartireLaOCifra.impartirea_la_o_cifra.impartirea_la_o_cifra(numarul, cifra, baza)
        print("Rezultatul impartirii numarului {} la cifra {} este {}".format(numarul, cifra, rezultat))

    def conversie_prin_impartire_succesiva_ui(self):
        numarul = input("Introduceti numarul: ")
        baza_initiala = input("Introduceti baza initiala in care se afla numarul: ")
        baza_finala = input("Introduceti baza  in care se converteste numarul: ")
        Validatori.validatori.Validare_baza(baza_initiala)
        Validatori.validatori.Validare_baza(baza_finala)
        baza_initiala = int(baza_initiala)
        baza_finala = int(baza_finala)
        Validatori.validatori.Vaidare_numar_pentru_baza(numarul, baza_initiala)
        rezultat = ImpartiriSuccesive.impartirisuccesive.impartire_succ(numarul, baza_initiala, baza_finala)
        print("Rezultatul conversiei din numarului {} din baza {} in baza {} este : {}".format(numarul, baza_initiala,
                                                                                               baza_finala, rezultat))

    def conversie_prin_substitutie_ui(self):
        numarul = input("Introduceti numarul: ")
        baza_initiala = input("Introduceti baza initiala in care se afla numarul: ")
        baza_finala = input("Introduceti baza  in care se converteste numarul: ")
        Validatori.validatori.Validare_baza(baza_initiala)
        Validatori.validatori.Validare_baza(baza_finala)
        baza_initiala = int(baza_initiala)
        baza_finala = int(baza_finala)
        Validatori.validatori.Vaidare_numar_pentru_baza(numarul, baza_initiala)
        rezultat = ConversieSubstitutie.conversie_substitutie.conversie_substitutie(numarul, baza_initiala, baza_finala)
        print("Rezultatul conversiei din numarului {} din baza {} in baza {} este : {}".format(numarul, baza_initiala,
                                                                                               baza_finala, rezultat))

    def conversie_baza_intermediara_ui(self):
        numarul = input("Introduceti numarul: ")
        baza_initiala = input("Introduceti baza initiala in care se afla numarul: ")
        baza_finala = input("Introduceti baza  in care se converteste numarul: ")
        Validatori.validatori.Validare_baza(baza_initiala)
        Validatori.validatori.Validare_baza(baza_finala)
        baza_initiala = int(baza_initiala)
        baza_finala = int(baza_finala)
        Validatori.validatori.Vaidare_numar_pentru_baza(numarul, baza_initiala)
        rezultat = ConversieBazaIntermediara.conversie_baza_intermediara.conversie_baza_intermediara(numarul,
                                                                                                     baza_initiala,
                                                                                                     baza_finala)
        print("Rezultatul conversiei din numarului {} din baza {} in baza {} este : {}".format(numarul, baza_initiala,
                                                                                               baza_finala, rezultat))

    def conversie_rapida_ui(self):
        numarul = input("Introduceti numarul: ")
        baza_initiala = input("Introduceti baza initiala in care se afla numarul: ")
        baza_finala = input("Introduceti baza  in care se converteste numarul: ")
        Validatori.validatori.Validare_baza(baza_initiala)
        Validatori.validatori.Validare_baza(baza_finala)
        try:
            baza_initiala in ['2', '4', '8', '16']
        except ValueError:
            print("Baza initiala este invalida!")
            return
        try:
            baza_finala in ['2', '4', '8', '16']
        except ValueError:
            print("Baza finala este invalida!")
            return
        baza_initiala = int(baza_initiala)
        baza_finala = int(baza_finala)
        Validatori.validatori.Vaidare_numar_pentru_baza(numarul, baza_initiala)
        rezultat = ConversiiRapide.conversiirapide.conversie_rapida(numarul, baza_initiala, baza_finala)
        print("Rezultatul conversiei din numarului {} din baza {} in baza {} este : {}".format(numarul, baza_initiala,
                                                                                               baza_finala, rezultat))

    def run_console(self):
        while True:
            cmd = input("Cititi comanda dumneavoastra:")
            try:
                if cmd == "":
                    continue
                elif cmd == "exit":
                    return 0
                elif cmd == '1':
                    self.adaugare_ui()
                elif cmd == '2':
                    self.scadere_ui()
                elif cmd == '3':
                    self.inmultire_cu_o_cifra_ui()
                elif cmd == '4':
                    self.impartirea_la_o_cifra_ui()
                elif cmd == '5':
                    self.conversie_prin_impartire_succesiva_ui()
                elif cmd == '6':
                    self.conversie_prin_substitutie_ui()
                elif cmd == '7':
                    self.conversie_baza_intermediara_ui()
                elif cmd == '8':
                    self.conversie_rapida_ui()
                else:
                    print("Comanda invalida!")
            except Exception as ex:
                print(str(ex))
