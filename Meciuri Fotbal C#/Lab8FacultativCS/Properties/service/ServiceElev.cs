using System.Collections.Generic;
using System.Linq;
using Lab8FacultativCS.model;
using Lab8FacultativCS.repository;

namespace Lab8FacultativCS.Properties.service
{
    public class ServiceElev
    {
        private IRepository<string, Elev> _repositoryElev;

        public ServiceElev(IRepository<string, Elev> repositoryElev)
        {
            _repositoryElev = repositoryElev;
        }

        public List<Elev> GetAll()
        {
            return _repositoryElev.FindAll().ToList();
        }

        public Elev Save(Elev elev)
        {
            return _repositoryElev.Save(elev);
        }
    }
}