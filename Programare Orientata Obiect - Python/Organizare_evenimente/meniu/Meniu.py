import user_interface
from Repository import repozitory
from Repository.repozitory import  Repository_asignare_persoana_eveniment_file
from Service import service
from Validator import validators

# teste.run_all_tests()
validare_persoana = validators.Validare_persoana()
validare_evenimente = validators.Validare_evenimente()
validare_asig = validators.Validare_asignare()

repository_persoane = repozitory.Repository_persoane_file("persoane.txt")
repository_evenimente = repozitory.Repository_evenimente_file("evenimente.txt")
repository_asig = Repository_asignare_persoana_eveniment_file("asignari.txt")

service_persoane = service.Service_persoane(validare_persoana, repository_persoane)
service_evenimente = service.Service_evenimente(validare_evenimente, repository_evenimente)
service_asig = service.Service_asignare_pers_event(validare_asig, repository_persoane, repository_evenimente,
                                                   repository_asig)

console = user_interface.Console_ui(service_persoane, service_evenimente, service_asig)
console.run_console()
