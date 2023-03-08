using System;
using System.Collections.Generic;
using System.ComponentModel.Design;
using System.Data.Common;
using System.Linq;
using Lab8FacultativCS.model;
using Lab8FacultativCS.Properties.service;
using Lab8FacultativCS.Properties.validator;
using Lab8FacultativCS.repository;

namespace Lab8FacultativCS
{
    internal class Program
    {
        public static void Main(string[] args)
        {
            IRepository<string, Echipa> repositoryEchipa =
                new FileRepoEchipa(new ValidareEchipa(), "C:\\Users\\Lorena\\Desktop\\PROIECTE\\Meciuri Fotbal C#\\Lab8FacultativCS/echipe.txt");

            IRepository<string, Elev> repositoryElev =
                new FileRepoElev(new ValidareElev(),
                    "C:\\Users\\Lorena\\Desktop\\PROIECTE\\Meciuri Fotbal C#\\Lab8FacultativCS/elevi.txt");
            
            IRepository<string, Jucator> repositoryJucator =
                new FileRepoJucator(new ValidareJucator(),
                    "C:\\Users\\Lorena\\Desktop\\PROIECTE\\Meciuri Fotbal C#\\Lab8FacultativCS\\jucatori.txt");
            
            IRepository<string, Meci> repositoryMeci = 
                new FileRepoMeci(new ValidareMeci(),
                "C:\\Users\\Lorena\\Desktop\\PROIECTE\\Meciuri Fotbal C#\\Lab8FacultativCS\\meciuri.txt");

            IRepository<string, JucatorActiv> repositoryJucatorActiv =
                new FileRepoJucatorActiv(new ValidareJucatorActiv(),
                    "C:\\Users\\Lorena\\Desktop\\PROIECTE\\Meciuri Fotbal C#\\Lab8FacultativCS\\jucatoriactivi.txt");
            
            ServiceEchipa serviceEchipa = new ServiceEchipa(repositoryEchipa);
            ServiceElev serviceElev = new ServiceElev(repositoryElev);
            ServiceJucator serviceJucator = new ServiceJucator(repositoryJucator);
            ServiceMeci serviceMeci = new ServiceMeci(repositoryMeci);
            ServiceJucatorActiv serviceJucatorActiv = new ServiceJucatorActiv(repositoryJucatorActiv);

            Properties.Console console = new Properties.Console(serviceEchipa, serviceElev, serviceMeci, serviceJucator,
                serviceJucatorActiv);
            console.main();
            
            
        }
    }
}