namespace Lab8FacultativCS.model
{
    public class Entitate<TID>
    {
        public TID Id { get; set;}

        public Entitate(TID id)
        {
            Id = id;
        }
    }
}