using Lab8FacultativCS.model;
using Lab8FacultativCS.Properties.validator;

namespace Lab8FacultativCS.repository
{
    public class FileRepoEchipa : FileRepository<string, Echipa>
    {
        public FileRepoEchipa(IValidator<Echipa> validator, string numeFisier) : base(validator, numeFisier, DelegatesEntitiesFromFile.DelegateEchipa)
        {
        }
    }
}