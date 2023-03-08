using System;

namespace Lab8FacultativCS.model
{
    public class Meci:Entitate<string>
    {
        public Echipa Echipa1 { get; set; }
        public Echipa Echipa2 { get; set; }
        public DateTime LocalDateTime { get; }

        public Meci(string id, Echipa echipa1, Echipa echipa2, DateTime localDateTime) : base(id)
        {
            Echipa1 = echipa1;
            Echipa2 = echipa2;
            LocalDateTime = localDateTime;
        }
    }
}