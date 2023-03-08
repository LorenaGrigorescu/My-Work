using Lab8FacultativCS.model;

namespace Lab8FacultativCS.Properties.validator
{
    public class ValidareJucatorActiv:IValidator<JucatorActiv>
    {
        public void Valideaza(JucatorActiv jucatorActiv)
        {
            if (jucatorActiv.NrPuncteInscrise < 0)
            {
                throw new ExceptieValidare("Numar puncte inscris invalid\n");
            }
        }
    }
}