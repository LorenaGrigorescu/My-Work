using System.Collections.Generic;
using System.Linq;
using Lab8FacultativCS.model;
using Lab8FacultativCS.repository;

namespace Lab8FacultativCS.Properties.service
{
    public class ServiceMeci
    {
        private IRepository<string, Meci> _repositoryMeci;

        public ServiceMeci(IRepository<string, Meci> repositoryMeci)
        {
            _repositoryMeci = repositoryMeci;
        }

        public List<Meci> GetAll()
        {
            return _repositoryMeci.FindAll().ToList();
        }

        public Meci Save(Meci meci)
        {
            return _repositoryMeci.Save(meci);
        }
    }
}