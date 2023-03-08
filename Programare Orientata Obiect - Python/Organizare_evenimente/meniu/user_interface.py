from Service.service import *
from Repository.repozitory import *


class Console_ui:
    def __init__(self, serv_p, srv_e, srv_asig):
        self.__serv_p = serv_p
        self.__serv_e = srv_e
        self.__serv_asig = srv_asig

    def parse_command(self, command):
        return command.split("_")

    def atribui_command(self, command):
        list = self.parse_command(command)
        return list

    def validare_commanda(self, command):
        list = self.atribui_command(command)
        n = list[1]
        return n

    def print_menu(self):
        print(">>>Urmatoarele actiuni sunt disponibile in meniu")

        print("1.1 -> Adauga o persoana!")
        print("1.2 -> Adauga un eveniment!")
        print("1.3 -> Adauga o persoana la lista de invitati a unui eveniment")

        print("2.1 -> Cauta o persoana!")
        print("2.2 -> Cauta un eveniment!")
        print("2.3->Cauta o persoana la un eveniment!")

        print("3.1 -> Sterge o persoana din lista!")
        print("3.2 -> Sterge un eveniment din lista!")
        print("3.3 -> Sterge o persoana de la un eveniment!")

        print("4.1-> Modifica numele unei persoane din lista")
        print("4.2 -> Modifica data desfasurarii unui eveniment")

        print("generate_X -> Genereaza X entitati aleatorii atat pentru Persoane cat si pentru Evenimente!")

        print(
            "Raport_top_3 -> Printeaza primele 3 zile cu evenimentele la care participa cele mai multe persoane si numarul de persoane aferent fiecarei zile")
        print("Raport_event_pers -> Printeaza toate evenimentele la care participa o persoana anume")
        print(
            "Raport_pers_part -> Printeaza in ordine descrescatoare persoanele si numarul de evenimente la care fiecare participa")
        print(
            "Raport_event20 -> Printeaza primele 20% din lista celor mai populare evenimente(descriere+numar invitati)")

        print("print_list_pers -> Printeaza lista de persoane existente")
        print("print_list_events -> Printeaza lista de evenimente existente")
        print("print_list_asig -> Printeaza lista de asignari existente")

        print("2.1.1 -> cauta recursiv o persoana dupa id-ul introdus de la tastatura")
        print("2.2.1 -> cauta recursiv un eveniment dupa id-ul introdus de la tastatura")

    def add_persoana_ui(self, id_persoana, nume, adresa):
        self.__serv_p.adaugare_persoana(id_persoana, nume, adresa)
        print("Aceasta persoana a fost adaugata cu succes!")

    def cautare_persoana_ui(self):
        id_persoana = input("Citeste id pentru persoana:")
        return self.__serv_p.cautare_persoana(id_persoana)

    def cauta_persoana_r_ui(self):
        id_persoana = input("Citeste id pentru persoana:")
        return self.__serv_p.cautare_persoana_r(0, id_persoana)

    def sterge_persoana_ui(self):
        id_de_cautat = input("Citeste id-ul persoanei pe care vrei sa o stergi!")
        self.__serv_p.sterge_persoana_lista(id_de_cautat)
        print('Persoana a fost stearsa cu succes!')

    def modifica_persoana_ui(self):
        nume_persoana_initial = input("Citeste numele persoanei pe care vrei sa il schimbi:")
        nume_persoana_final = input("Citeste numele cu care doriti sa inlocuiti:")
        self.__serv_p.modifica_nume_persoana(nume_persoana_initial, nume_persoana_final)
        print("Numele a fost schimbat cu succes!")

    def add_eveniment_ui(self, id_eveniment, data, timp, descriere):
        self.__serv_e.adaugare_eveniment(id_eveniment, data, timp, descriere)
        print('Evenimentul a fost adaugat cu succes!')

    def cautare_eveniment_ui(self):
        id_eveniment = input("Citeste id pentru eveniment")
        return self.__serv_e.cautare_eveniment(id_eveniment)

    def cautare_eveniment_r_ui(self):
        id_eveniment = input("Citeste id pentru eveniment")
        return self.__serv_e.cautare_eveniment_r(0, id_eveniment)

    def stergere_event_ui(self):
        id_de_cautat = input("Citeste id-ul evenimentului pe care vrei sa il stergi!")
        self.__serv_e.sterge_eveniment_din_lista(id_de_cautat)
        print('Evenimentul a fost sters cu succes!')

    def modifica_eveniment_ui(self):
        data_initiala = input('Citeste data evenimentului pe care doriti sa o modificati:')
        data_finala = input("Citeste noua data a evenimentului:")
        self.__serv_e.modifica_data_eveniment(data_initiala, data_finala)
        print("Data evenimentului a fost modificata cu succes!")

    def print_person_ui(self):
        if len(self.__serv_p.get_all_persoane()) == 0:
            print("nu exista nicio persoana!")
            return
        else:
            for persoana in self.__serv_p.get_all_persoane():
                print(persoana)

    def print_event_ui(self):
        if len(self.__serv_e.get_all_evenimente()) == 0:
            print("nu exista niciun eveniment!")
            return
        else:
            for event in self.__serv_e.get_all_evenimente():
                print(event)

    def print_pers_la_event_ui(self):
        asignari = self.__serv_asig.get_all_asignari()
        if len(asignari) == 0:
            print("nu exista nicio persoana invitata la niciun eveniment!")
            return
        for date_event in asignari:
            print(date_event)

    def print_pers_la_event_ui_file(self):
        asignari = self.__serv_asig.get_all_asignari()
        for date_event in asignari:
            print(date_event)

    def add_pers_event_ui(self):
        id_asig = input(">>>Introduceti id-ul asignarii:")
        id_pers = input(">>>Introduceti id-ul invitatului pe care vreti sa il adaugati la eveniment:")
        id_event = input(">>>Introduceti id-ul evenimentului unde vreti sa cautati invitatul:")
        self.__serv_asig.adauga_persoana_la_eveniment(id_asig, id_pers, id_event)
        print("Persoana cu id-ul cautat a fost asignata la evenimentul cu id-ul cautat cu succes!")

    def sterge_asignare_ui(self):
        id_asignare = input(">>>Cititi id-ul de asignare pe care vreti sa o stergeti")
        self.__serv_asig.sterge_persoana_la_eveniment(id_asignare)
        print("Persoana a fost stearsa cu succes de la eveniment!")

    def cautare_pers_in_event_ui(self):
        id_asig = input(">>>Introduceti id-ul asignarii:")
        return self.__serv_asig.cauta_persoana_in_evenimente(id_asig)

    def raport_top_3_ui(self):
        zile = self.__serv_asig.raport_top_3_zile()
        for ziua in zile:
            print(ziua)

    def raport_lista_evenimente_persoana_ui(self):
        id_persoana = input(">>>Introduceti invitatul dupa care vreti sa se formeze lista de evenimente:")
        event_pers = self.__serv_asig.raport_lista_evenimente_persoana(id_persoana)
        for asig in event_pers:
            print(asig)

    def raport_persoane_participante_evenimente_ui(self):
        participanti = self.__serv_asig.raport_persoane_participante_evenimente()
        for participant in participanti:
            print(participant)

    def raport_evenimente_populare_ui(self):
        print(self.__serv_asig.raport_evenimente_populare())

    def run_console(self):
        not_gata = True
        while not_gata:
            try:
                self.print_menu()
                cmd1 = ''
                cmd = input(">>>Citeste comanda")
                if cmd.count("_") == 1:
                    cmd1, n = cmd.split("_")
                if cmd == '1.1':
                    id_persoana = input("Citeste id-ul persoanei!")
                    nume = input("Citeste numele persoanei!")
                    adress = input("Citeste adresa persoanei!")
                    self.add_persoana_ui(id_persoana, nume, adress)
                elif cmd == '1.2':
                    id_eveniment = input("Citeste id pentru eveniment")
                    data = input("Citeste data desfasurarii evenimentului")  # format data ----> yyyy/mm/dd
                    timp = input("Citeste durata evenimentului")
                    descriere = input("Citeste descrierea evenimentului")
                    self.add_eveniment_ui(id_eveniment, data, timp, descriere)
                elif cmd == '1.3':
                    self.add_pers_event_ui()
                elif cmd == '2.1':
                    print(self.cautare_persoana_ui())
                elif cmd == '2.2':
                    print(self.cautare_eveniment_ui())
                elif cmd == '2.3':
                    print(self.cautare_pers_in_event_ui())
                elif cmd == '3.1':
                    self.sterge_persoana_ui()
                    self.print_person_ui()
                elif cmd == '3.2':
                    self.stergere_event_ui()
                    self.print_event_ui()
                elif cmd == '3.3':
                    self.sterge_asignare_ui()
                    self.print_pers_la_event_ui()
                elif cmd == '4.1':
                    self.modifica_persoana_ui()
                    self.print_person_ui()
                elif cmd == '4.2':
                    self.modifica_eveniment_ui()
                    self.print_event_ui()
                elif cmd1 == 'generate':
                    n = int(self.validare_commanda(cmd))
                    n0 = n
                    i = 0
                    validare_eveniment = Validare_evenimente()
                    repozitory_eveniment = Repository_evenimente()
                    while i < n0:
                        srv_e = Service_evenimente(validare_eveniment, repozitory_eveniment)
                        id_eveniment = str(srv_e.generate_random_id_eveniment())
                        while self.__serv_e.cautare_eveniment(id_eveniment) == 1:
                            id_eveniment = str(srv_e.generate_random_id_eveniment())
                        an = str(srv_e.generate_random_an_event())
                        luna = str(srv_e.generate_random_luna_event())
                        zi = str(srv_e.generate_random_zi_event())
                        data = an + '/' + luna + '/' + zi
                        timp = str(srv_e.generate_random_time_event())
                        descriere = srv_e.generate_random_description_event()
                        eveniment = Eveniment(id_eveniment, data, timp, descriere)
                        self.add_eveniment_ui(id_eveniment, data, timp, descriere)
                        i += 1

                    self.print_person_ui()
                    self.print_event_ui()
                elif cmd == 'Raport_top_3':
                    self.raport_top_3_ui()
                elif cmd == 'Raport_event_pers':
                    print(self.raport_lista_evenimente_persoana_ui())
                elif cmd == 'Raport_pers_part':
                    self.raport_persoane_participante_evenimente_ui()
                elif cmd == 'Raport_event20':
                    self.raport_evenimente_populare_ui()
                elif cmd == 'print_list_pers':
                    self.print_person_ui()
                elif cmd == 'print_list_events':
                    self.print_event_ui()
                elif cmd == 'print_list_asig':
                    self.print_pers_la_event_ui()
                elif cmd == 'print_pers_event':
                    self.print_pers_la_event_ui_file()
                elif cmd == '0':
                    not_gata = False
                    print("Comanda nu este valida!")
                elif cmd == '2.1.1':
                    rez = self.cauta_persoana_r_ui()
                    print(rez)
                elif cmd == '2.2.1':
                    rez = self.cautare_eveniment_r_ui()
                    print(rez)
            except Exception as errors:
                print(errors)
