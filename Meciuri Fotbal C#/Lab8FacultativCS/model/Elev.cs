using System;

namespace Lab8FacultativCS.model
{
    public class Elev:Entitate<string>
    {
        public String Nume { get; set; }
        public String NumeScoala { get; set; }

        public Elev(string id) : base(id)
        {
        }

        public Elev(string id, string nume, string numeScoala) : base(id)
        {
            Nume = nume;
            NumeScoala = numeScoala;
        }

        public override string ToString()
        {
            return Id + " " + Nume + " " + NumeScoala;
        }
    }
}