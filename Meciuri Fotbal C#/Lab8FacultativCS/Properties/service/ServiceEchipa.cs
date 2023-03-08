using System.Collections.Generic;
using System.Linq;
using Lab8FacultativCS.model;
using Lab8FacultativCS.repository;

namespace Lab8FacultativCS.Properties.service
{
    public class ServiceEchipa
    {
        private IRepository<string, Echipa> _repositoryEchipa;

        public ServiceEchipa(IRepository<string, Echipa> repositoryEchipa)
        {
            _repositoryEchipa = repositoryEchipa;
        }

        public List<Echipa> GetAll()
        {
            return _repositoryEchipa.FindAll().ToList();
        }

        public Echipa Save(Echipa echipa)
        {
            return _repositoryEchipa.Save(echipa);
        }
    }
}