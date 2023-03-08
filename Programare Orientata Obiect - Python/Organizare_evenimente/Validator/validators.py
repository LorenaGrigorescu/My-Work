class Validare_persoana:
    def validare_persoana(self, persoana):
        errors = ""
        if persoana.get_id_persoana().isnumeric() == False or persoana.get_id_persoana().isnumeric() == True and int(
                persoana.get_id_persoana()) < 0:
            errors += "Invalid id_persoana!"
        if len(persoana.get_nume()) < 1:
            errors += "Invalid name!"
        if len(persoana.get_adresa()) < 1:
            errors += "Invalid address!"
        return errors


class Validare_evenimente:
    def validare_eveniment(self, eveniment):
        errors = ""
        an = ''
        luna = ''
        zi = ''
        luna_mare = ['1', '3', '5', '7', '8', '10', '12']
        luna_mica = ['4', '6', '9', '11']
        if eveniment.get_id_eveniment().isnumeric() == False or eveniment.get_id_eveniment().isnumeric() == True and int(
                eveniment.get_id_eveniment()) < 0:
            errors += "Invalid id_eveniment!"
        if eveniment.get_timp().isnumeric() == False or eveniment.get_timp().isnumeric() == True and int(
                eveniment.get_timp()) < 0:
            errors += "Invalid period of time!"
        if eveniment.get_data().count('/') != 2:
            errors += 'Invalid date time!'
        else:
            an, luna, zi = eveniment.get_data().split('/')
            if an.isnumeric() == False or luna.isnumeric() == False or zi.isnumeric() == False:
                errors += "Invalid date time!"
            elif an.isnumeric() == True and int(an) <= 0:
                errors += "Invalid date time!"
            elif an.isnumeric() == True and int(an) > 0:
                if int(an) % 4 == 0:
                    if luna.isnumeric() == True and luna == '2':
                        if zi.isnumeric() == True and not (1 <= int(zi) <= 29):
                            errors += 'Date out of range!'
                        elif zi.isnumeric() == False:
                            errors += 'Invalid date time!'
                    elif luna.isnumeric() == False:
                        errors += 'Invalid date time!'
                    elif luna.isnumeric() == True and luna in luna_mare:
                        if zi.isnumeric() == False or not (1 <= int(zi) <= 31):
                            errors += 'Invalid date time or date out of range!'
                    elif luna.isnumeric() == True and luna in luna_mica:
                        if zi.isnumeric() == False or not (1 <= int(zi) <= 30):
                            errors += 'Invalid date time or date out of range!'
                else:
                    if luna.isnumeric() == True and luna == '2':
                        if zi.isnumeric() == True and not (1 <= int(zi) <= 28):
                            errors += 'Date out of range!'
                        elif zi.isnumeric() == False:
                            errors += 'Invalid date time!'
                    elif luna.isnumeric() == False:
                        errors += 'Invalid date time!'
                    elif luna.isnumeric() == True and luna in luna_mare:
                        if zi.isnumeric() == False or not (1 <= int(zi) <= 31):
                            errors += 'Invalid date time or date out of range!'
                    elif luna.isnumeric() == True and luna in luna_mica:
                        if zi.isnumeric() == False or not (1 <= int(zi) <= 30):
                            errors += 'Invalid date time or date out of range!'
        if len(eveniment.get_descriere()) < 1:
            errors += "Invalid event description!"
        return errors


class Validare_asignare:
    def validare_asignare(self, asignare):
        errors = ""
        if asignare.get_id_asig().isnumeric() == False or asignare.get_id_asig().isnumeric() == True and int(
                asignare.get_id_asig()) < 0:
            errors += "Invalid id_asignare!"
        if len(errors) > 0:
            raise ValueError(errors)
