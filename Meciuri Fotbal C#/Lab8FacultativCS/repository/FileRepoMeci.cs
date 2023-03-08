using Lab8FacultativCS.model;
using Lab8FacultativCS.Properties.validator;

namespace Lab8FacultativCS.repository
{
    public class FileRepoMeci:FileRepository<string, Meci>
    {
        public FileRepoMeci(IValidator<Meci> validator, string numeFisier) : base(validator, numeFisier, DelegatesEntitiesFromFile.DelegateMeci)
        {
        }
    }
}