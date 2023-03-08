using Lab8FacultativCS.model;

namespace Lab8FacultativCS.Properties.validator
{
    public class ValidareJucator:IValidator<Jucator>
    {
        public void Valideaza(Jucator jucator)
        {
            if (jucator == null)
                throw new ExceptieValidare("Jucator invalid");
        }
    }
}
