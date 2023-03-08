namespace Lab8FacultativCS.model
{
    public class Jucator:Elev
    {
        public Echipa Echipa { get; set; }

        /*public Jucator(string id, Echipa echipa) : base(id)
        {
            Echipa = echipa;
        }*/

        public Jucator(string id, string nume, string numeScoala, Echipa echipa) : base(id, nume, numeScoala)
        {
            Echipa = echipa;
        }

        /*public Jucator(string id) : base(id)
        {
        }*/

        public override string ToString()
        {
            return "Jucatorul cu id-ul " + Id + " joaca la echipa cu numele " + Echipa.Nume;
        }
    }
}