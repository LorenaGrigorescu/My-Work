using System;
using System.Collections;
using System.Collections.Generic;
using Lab8FacultativCS.Properties.service;
using System.Linq;
using System.Security.AccessControl;
using Lab8FacultativCS.model;

namespace Lab8FacultativCS.Properties
{
    public class Console
    {
        private ServiceEchipa serviceEchipa;
        private ServiceElev serviceElev;
        private ServiceMeci serviceMeci;
        private ServiceJucator serviceJucator;
        private ServiceJucatorActiv serviceJucatorActiv;

        public Console(ServiceEchipa serviceEchipa, ServiceElev serviceElev, ServiceMeci serviceMeci,
            ServiceJucator serviceJucator, ServiceJucatorActiv serviceJucatorActiv)
        {
            this.serviceEchipa = serviceEchipa;
            this.serviceElev = serviceElev;
            this.serviceMeci = serviceMeci;
            this.serviceJucator = serviceJucator;
            this.serviceJucatorActiv = serviceJucatorActiv;
        }


        public static void printMenu()
        {
            System.Console.WriteLine("Toti jucatorii unei echipe date - numele echipei");
            System.Console.WriteLine("Toti jucatorii activi ai unei echipe de la un anumit meci - id echipa ");
            System.Console.WriteLine("Toate meciurile dintr-o anumita perioada calendaristica" + 
                                     "format:an-luna-zi-ora-minut-secunda");
            System.Console.WriteLine("Scorul de la un anumit meci - id meci ");
        }

        public void main()
        {
            string cmd = "";
            while (true)
            {
                printMenu();
                System.Console.WriteLine("Enter a command between 1 and 4");
                cmd = System.Console.ReadLine();
                if (cmd == "1")
                {
                    string numeEchipa = System.Console.ReadLine();
                    var echipe = serviceEchipa.GetAll();
                    var jucatori = serviceJucator.GetAll();

                    var query1 = echipe
                        .Select(e => e)
                        .Where(e => e.Nume == numeEchipa);
                    foreach (var obj in query1)
                    {
                        System.Console.WriteLine(obj.ToString());
                    } // toate echipele care au numele "numeEchipa"

                    //facem un inner join intre toti jucatorii si toate echipele 
                    // colectate in query 1
                    var query2 = (from j in jucatori
                        join e in query1 on j.Echipa.ToString() equals e.ToString()
                        select j);

                    foreach (var obj in query2)
                    {
                        System.Console.WriteLine(obj.Nume);
                    }
                }

                if (cmd == "2")
                {
                    var jucatori = serviceJucator.GetAll();
                    var jucatoriactivi = serviceJucatorActiv.GetAll();

                    //jucatorii activi ai unei echipe care joaca la un anume meci
                    System.Console.WriteLine("Introduce the match id:");
                    string idMeci = System.Console.ReadLine();
                    System.Console.WriteLine("Introduce the team id:");
                    string idEchipa = System.Console.ReadLine();
                    var query0 = jucatoriactivi
                        .Select(ja => ja)
                        .Where(ja => (ja.Tip == Tip.REZERVA || ja.Tip == Tip.PARTICIPANT) && ja.IdMeci == idMeci);
                    //am colectat toti jucatorii activi din ambele echipe de la un anume meci

                    var query3 = (from j in jucatori
                        join ja in query0 on j.Id equals ja.Id
                        where j.Echipa.Id == idEchipa
                        select j);
                    // am colectat DOAR jucatorii activi care sunt din echipa ceruta
                    foreach (var obj in query3)
                    {
                        System.Console.WriteLine(obj.Nume);
                    }

                }

                if (cmd == "3")
                {
                    var meciuri = serviceMeci.GetAll();
                    
                    DateTime dte = new DateTime(2022, 12, 26, 13, 20, 00);
                    System.Console.WriteLine("Introduce the start date:");
                    string dateStart = System.Console.ReadLine();
                    string[] dateStartString = dateStart.Split('.');
                    DateTime dateTimeStart = new DateTime(int.Parse(dateStartString[0]),int.Parse(dateStartString[1]),int.Parse(dateStartString[2]),int.Parse(dateStartString[3]),int.Parse(dateStartString[4]),int.Parse(dateStartString[5]));
                    System.Console.WriteLine("Introduce the end date:");
                    string dateEnd = System.Console.ReadLine();
                    string[] dateEndString = dateEnd.Split('.');
                    DateTime dateTimeEnd = new DateTime(int.Parse(dateEndString[0]),int.Parse(dateEndString[1]),int.Parse(dateEndString[2]),int.Parse(dateEndString[3]),int.Parse(dateEndString[4]),int.Parse(dateEndString[5]));
                    //selectam toate meciurile din acest interval orar
                    var query4 = meciuri
                        .Select(m => m)
                        .Where(m => m.LocalDateTime >= dateTimeStart && m.LocalDateTime <= dateTimeEnd);
            
                    foreach (var obj in query4)
                    {
                        System.Console.WriteLine(obj.Id +"-echipele: "+ obj.Echipa1.Nume + "-" + obj.Echipa2.Nume);
                    }
                }

                if (cmd == "4")
                {
                    var meciuri = serviceMeci.GetAll();
                    var elevi = serviceElev.GetAll();
                    var jucatoriactivi = serviceJucatorActiv.GetAll();
                    var jucatori = serviceJucator.GetAll();
                    System.Console.WriteLine("Introduce the match id:");
                    string idMeciRezultate = System.Console.ReadLine();
                    //determinam cele 2 echipe 
                    var query5 = (from m in meciuri
                        where m.Id == idMeciRezultate
                        select (new Tuple<Echipa, Echipa>(m.Echipa1, m.Echipa2)));
                    string idE1, idE2;
                    IEnumerable<int> query6;
                    IEnumerable<int> query7;
                    foreach (var obj in query5)
                    {
                        idE1 = obj.Item1.Id;
                        idE2 = obj.Item2.Id;
                        //System.Console.WriteLine(idE1 + "    " + idE2);


                        //determinam punctajele facute de cele 2 echipe in cadrul meciului dorit
                        query6 = (from j in jucatori
                            from ja in jucatoriactivi
                            where j.Id == ja.Id && ja.IdMeci == idMeciRezultate && j.Echipa.Id == idE1
                            select (ja.NrPuncteInscrise));

                        query7 = (from j in jucatori
                            from ja in jucatoriactivi
                            where j.Id == ja.Id && ja.IdMeci == idMeciRezultate && j.Echipa.Id == idE2
                            select (ja.NrPuncteInscrise));


                        var query8 = query6.Sum();
                        var query9 = query7.Sum();
                        System.Console.WriteLine("Meciul dorit s-a disputat intre echipele\n"+obj.Item1.Nume + "-" + obj.Item2.Nume + ":" + query8 + "-" + query9);
                    }
                    
                }
                else
                {
                    Environment.Exit(0);
                }
            }
        }
    }
}