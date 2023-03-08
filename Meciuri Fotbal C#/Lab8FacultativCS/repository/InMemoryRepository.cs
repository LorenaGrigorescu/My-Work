using System;
using System.Collections.Generic;
using System.Linq;
using Lab8FacultativCS.model;
using Lab8FacultativCS.Properties.validator;

namespace Lab8FacultativCS.repository
{
    public class InMemoryRepository<ID, E> : IRepository<ID, E> where E : Entitate<ID>
    {
        protected IDictionary<ID,E> Entitati = new Dictionary<ID, E>();
        protected IValidator<E> Validator;

        public InMemoryRepository(IValidator<E> validator)
        {
            Validator = validator;
        }

        public E FindOne(ID id)
        {
            throw new NotImplementedException();
            //TO DO
        }

        public IEnumerable<E> FindAll()
        {
            return Entitati.Values.ToList<E>();
        }

        public E Save(E e)
        {
            this.Validator.Valideaza(e);
            if (Entitati.ContainsKey(e.Id))
            {
                return e;
            }

            Entitati.Add(e.Id, e);
            return e;
        }

        public E Delete(ID id)
        {
            throw new NotImplementedException();
            //TO DO
        }
    }

}