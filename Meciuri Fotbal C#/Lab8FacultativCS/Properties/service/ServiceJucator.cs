using System.Collections.Generic;
using System.Linq;
using Lab8FacultativCS.model;
using Lab8FacultativCS.repository;

namespace Lab8FacultativCS.Properties.service
{
    public class ServiceJucator
    {
        private IRepository<string, Jucator> _repositoryJucator;

        public ServiceJucator(IRepository<string, Jucator> repositoryJucator)
        {
            _repositoryJucator = repositoryJucator;
        }

        public List<Jucator> GetAll()
        {
            return _repositoryJucator.FindAll().ToList();
        }

        public Jucator Save(Jucator jucator)
        {
            return _repositoryJucator.Save(jucator);
        }
    }
}