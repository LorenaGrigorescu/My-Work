using System;

namespace Lab8FacultativCS.model
{
    public class DelegatesEntitiesFromFile
    {
        private static char Separator = ';';

        public static Echipa DelegateEchipa(string line)
        {
            string[] splitEchipa = line.Split(Separator);
            Echipa echipa = new Echipa(splitEchipa[0], splitEchipa[1]);
            return echipa;
        }

        public static Elev DelegateElev(string line)
        {
            string[] splitElev = line.Split(Separator);
            Elev elev = new Elev(splitElev[0], splitElev[1], splitElev[2]);
            return elev;
        }

        public static Jucator DelegateJucator(string line)
        {
            string[] splitJucator = line.Split(Separator);
            Echipa echipa =  new Echipa(splitJucator[3], splitJucator[4]);
            Jucator jucator = new Jucator(splitJucator[0], splitJucator[1], splitJucator[2], echipa);
            return jucator;
        }

        public static Meci DelegateMeci(string line)
        {
            string[] splitMeci = line.Split(Separator);
            Echipa echipa1 = new Echipa(splitMeci[1], splitMeci[2]);
            Echipa echipa2 = new Echipa(splitMeci[3], splitMeci[4]);
            Meci meci = new Meci(splitMeci[0], echipa1, echipa2, DateTime.Parse(splitMeci[5]));
            return meci;
        }

        public static JucatorActiv DelegateJucatorActiv(string line)
        {
            string[] splitJucatorActiv = line.Split(Separator);
            JucatorActiv jucatorActiv = new JucatorActiv(splitJucatorActiv[0], splitJucatorActiv[1],
                splitJucatorActiv[2], int.Parse(splitJucatorActiv[3]),
                (Tip)Enum.Parse(typeof(Tip), splitJucatorActiv[4]));
            return jucatorActiv;
        }
    }
}