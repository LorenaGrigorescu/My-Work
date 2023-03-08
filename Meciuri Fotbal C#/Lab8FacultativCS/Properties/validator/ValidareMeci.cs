using System;
using Lab8FacultativCS.model;

namespace Lab8FacultativCS.Properties.validator
{
    public class ValidareMeci:IValidator<Meci>
    {
        public void Valideaza(Meci meci)
        {
            if (meci.LocalDateTime > DateTime.Now)
            {
                throw new ExceptieValidare("Data invalida\n");
            }
        }
    }
}