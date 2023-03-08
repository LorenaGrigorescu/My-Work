using System;

namespace Lab8FacultativCS.model
{
    public class JucatorActiv:Entitate<string>
    {
        public String IdJucator { get; set; }
        public String IdMeci { get; set; }
        public int NrPuncteInscrise { get; set; }
        public Tip Tip { get; set; }

        public JucatorActiv(string id, string idJucator, string idMeci, int nrPuncteInscrise, Tip tip):base(id)
        {
            IdJucator = idJucator;
            IdMeci = idMeci;
            NrPuncteInscrise = nrPuncteInscrise;
            Tip = tip;
        }

        public override string ToString()
        {
            return IdJucator + " " + IdMeci + " " + NrPuncteInscrise + " " + Tip;
        }
    }
    
}