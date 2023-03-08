using Lab8FacultativCS.model;

namespace Lab8FacultativCS.Properties.validator
{
    public class ValidareEchipa:IValidator<Echipa>
    {
        public void Valideaza(Echipa echipa)
        {
            if (echipa.Nume == null || echipa.Nume == "")
            {
                throw new ExceptieValidare("Numele este vid");
            }
        }
    }
}