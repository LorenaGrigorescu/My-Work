using Lab8FacultativCS.model;

namespace Lab8FacultativCS.Properties.validator
{
    public class ValidareElev:IValidator<Elev>
    {
        public void Valideaza(Elev elev)
        {
            string errors = "";
            if (elev.Nume == null || elev.Nume == "")
            {
                errors += "Nume elev invalid\n";
            }

            if (elev.NumeScoala == null || elev.NumeScoala == "")
            {
                errors += "Nume scoala invalid\n";
            }

            if (errors.Length != 0)
            {
                throw new ExceptieValidare(errors);
            }
        }
    }
}