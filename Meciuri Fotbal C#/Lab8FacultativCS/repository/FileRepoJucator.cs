using Lab8FacultativCS.model;
using Lab8FacultativCS.Properties.validator;

namespace Lab8FacultativCS.repository
{
    public class FileRepoJucator:FileRepository<string, Jucator>
    {
        public FileRepoJucator(IValidator<Jucator> validator, string numeFisier) : base(validator, numeFisier, DelegatesEntitiesFromFile.DelegateJucator)
        {
        }
    }
}