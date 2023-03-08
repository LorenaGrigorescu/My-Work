using System.Collections.Generic;
using System.Linq;
using Lab8FacultativCS.model;
using Lab8FacultativCS.repository;

namespace Lab8FacultativCS.Properties.service
{
    public class ServiceJucatorActiv
    {
        private IRepository<string, JucatorActiv> _repositoryJucatorActiv;

        public ServiceJucatorActiv(IRepository<string, JucatorActiv> repositoryJucatorActiv)
        {
            _repositoryJucatorActiv = repositoryJucatorActiv;
        }

        public List<JucatorActiv> GetAll()
        {
            return _repositoryJucatorActiv.FindAll().ToList();
        }

        public JucatorActiv Save(JucatorActiv jucatorActiv)
        {
            return _repositoryJucatorActiv.Save(jucatorActiv);
        }
    }
}