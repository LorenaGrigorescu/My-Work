using Lab8FacultativCS.model;
using Lab8FacultativCS.Properties.validator;

namespace Lab8FacultativCS.repository
{
    public class FileRepoJucatorActiv:FileRepository<string, JucatorActiv>
    {
        public FileRepoJucatorActiv(IValidator<JucatorActiv> validator, string numeFisier) : base(validator, numeFisier, DelegatesEntitiesFromFile.DelegateJucatorActiv)
        {
        }
    }
}