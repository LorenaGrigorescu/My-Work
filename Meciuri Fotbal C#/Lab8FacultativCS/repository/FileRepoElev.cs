using Lab8FacultativCS.model;
using Lab8FacultativCS.Properties.validator;

namespace Lab8FacultativCS.repository
{
    public class FileRepoElev: FileRepository<string, Elev>
    {
        public FileRepoElev(IValidator<Elev> validator, string numeFisier) : base(validator, numeFisier, DelegatesEntitiesFromFile.DelegateElev)
        {
        }
    }
}